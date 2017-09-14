#ifndef DDSCLIENT_H
#define DDSCLIENT_H

#include <QObject>
#include <QMap>

class DDSDomainParticipant;
class DDSTopic;

namespace DDS {

enum ClientError
{
    UnknownError = -1,
    CreateParticipantFailed = 1,
    CreateTopicFailed,
    CreateDataReaderFailed,
    CreateDataWriterFailed
};

class DDSSubscriber;
class DDSPublisher;
class DDSClient : public QObject
{
    Q_OBJECT
public:
    explicit DDSClient(qint32 domainId = 0, QObject *parent = 0);
    virtual ~DDSClient();

signals:
    void error(const ClientError error);
    void subscribed(const QString& topic);
    void unsubscribed(const QString& topic);
    void published(const QString& topic, const QJsonObject &message);
    void received(const QString& topic, const QJsonObject &message);

public slots:
    void start();
    void subscribe(const QString& topic);
    quint16 publish(const QString& topic, const QJsonObject &message);
    void stop();
    void setBufferSize(qint32 size);

protected:
    qint32 _domainId = 0;
    qint32 _bufferSize = 4096;
    DDSDomainParticipant *_participant = nullptr;
    QMap<QString, DDSTopic*> _topics;
    QMap<QString, DDSSubscriber*> _subscribers;
    QMap<QString, DDSPublisher*> _publishers;
};

}

Q_DECLARE_METATYPE(DDS::ClientError)

#endif // DDSCLIENT_H
