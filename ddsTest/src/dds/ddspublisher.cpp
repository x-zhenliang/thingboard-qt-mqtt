#include "ddspublisher.h"
#include <QJsonDocument>
#include <QByteArray>
#include <ndds/ndds_cpp.h>

namespace DDS {

DDSPublisher::DDSPublisher(const QString &topicName, DDSDataWriter *writer, QObject *parent)
    : QObject(parent)
    , _topicName(topicName)
    , _writer(writer)
{
}

qint32 DDSPublisher::write(const QJsonObject &message)
{
    auto string_writer = DDSStringDataWriter::narrow(_writer);
    QByteArray data = QJsonDocument(message).toJson(QJsonDocument::Compact);
    data.append((char)0);

    auto ret = string_writer->write(data.constData(), DDS_HANDLE_NIL);
    if (ret == DDS_RETCODE_OK)
        emit dataPublished(_topicName, message);
    return ret;
}

}
