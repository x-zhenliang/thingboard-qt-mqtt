#include "ddsclient.h"
#include "ddssubscriber.h"
#include "ddspublisher.h"
#include <ndds/ndds_cpp.h>

namespace DDS {

DDSClient::DDSClient(qint32 domainId, QObject *parent)
    : QObject(parent)
    , _domainId(domainId)
{
}

DDSClient::~DDSClient()
{
    stop();
}

void DDSClient::start()
{
    if (_participant != nullptr)
        return;

    _participant = DDSDomainParticipantFactory::get_instance()->
            create_participant(_domainId, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);

    if (_participant == nullptr) {
#ifdef _DEBUG
        qFatal("DDSClient::start: Unable to create domain participant.");
#endif
        emit error(CreateParticipantFailed);
        return;
    }

}

void DDSClient::subscribe(const QString &topicName)
{
    // only need register it when dds is not started
    if (_participant == nullptr) {
        _topics[topicName] = nullptr;
        return;
    }

    DDSTopic *topic = nullptr;
    // already registered
    if (!_topics.contains(topicName) || _topics[topicName] == nullptr) {
        topic = _participant->create_topic(topicName.toUtf8().constData(),
                                        DDSStringTypeSupport::get_type_name(),
                                        DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
        if (topic == nullptr) {
#ifdef _DEBUG
            qFatal("DDSClient::subscribed:Unable to create topic.");
#endif
            emit error(CreateTopicFailed);
            return;
        }
        _topics[topicName] = topic;
    }
    else {
        topic = _topics[topicName];
    }

    if (!_subscribers.contains(topicName)) {
        auto dataReader = _participant->create_datareader(topic, DDS_DATAREADER_QOS_DEFAULT,
                                                          nullptr, DDS_DATA_AVAILABLE_STATUS);
        if (dataReader == nullptr) {
#ifdef _DEBUG
            qFatal("Unable to create data reader.");
#endif
            emit error(CreateDataReaderFailed);
            return;
        }

        auto subscriber = new DDSSubscriber(topicName, dataReader, _bufferSize, this);
        connect(subscriber, &DDSSubscriber::dataRecv, this, &DDSClient::received);
        _subscribers[topicName] = subscriber;

        emit subscribed(topicName);
    }
}

quint16 DDSClient::publish(const QString &topicName, const QJsonObject &message)
{
    if (_participant == nullptr) {
        return CreateParticipantFailed;
    }

    DDSTopic *topic = nullptr;
    // already registered
    if (!_topics.contains(topicName) || _topics[topicName] == nullptr) {
        topic = _participant->create_topic(topicName.toUtf8().constData(),
                                        DDSStringTypeSupport::get_type_name(),
                                        DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
        if (topic == nullptr) {
#ifdef _DEBUG
            qFatal("DDSClient::publish:Unable to create topic.");
#endif
            emit error(CreateTopicFailed);
            return CreateTopicFailed;
        }
        _topics[topicName] = topic;
    }
    else {
        topic = _topics[topicName];
    }

    DDSPublisher *publisher = nullptr;
    if (!_publishers.contains(topicName)) {
        auto dataWriter = _participant->create_datawriter(topic, DDS_DATAWRITER_QOS_DEFAULT,
                                                          nullptr, DDS_STATUS_MASK_NONE);
        if (dataWriter == nullptr) {
#ifdef _DEBUG
            qFatal("Unable to create data reader.");
#endif
            emit error(CreateDataWriterFailed);
            return CreateDataWriterFailed;
        }

        publisher = new DDSPublisher(topicName, dataWriter, this);
        connect(publisher, &DDSPublisher::dataPublished, this, &DDSClient::published);
        _publishers[topicName] = publisher;
    }
    else {
        publisher = _publishers[topicName];
    }

    auto ret = publisher->write(message);
    if (DDS_RETCODE_OK == ret)
        return 0;
    else
        return ret+100;
}

void DDSClient::stop()
{
    if (_participant != nullptr) {
        _participant->delete_contained_entities();
        DDSDomainParticipantFactory::get_instance()->delete_participant(_participant);
        _participant = nullptr;
    }
    _topics.clear();
    qDeleteAll(_subscribers);
    _subscribers.clear();
    qDeleteAll(_publishers);
    _publishers.clear();
    _domainId = 0;
}

void DDSClient::setBufferSize(qint32 size)
{
    _bufferSize = size;
}

}
