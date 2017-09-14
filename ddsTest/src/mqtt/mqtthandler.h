#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <qmqtt.h>
#include <QStringList>
#include <QJsonObject>
#include "mqtttopic.h"

extern const QHostAddress DEFAULT_HOST;
extern const quint16 DEFAULT_PORT;

class MQTTHandler : public QMQTT::Client
{
    Q_OBJECT
public:
    explicit MQTTHandler(const QHostAddress& host = DEFAULT_HOST,
                         const quint16 port = DEFAULT_PORT,
                         QObject *parent = Q_NULLPTR);

public slots:
    void addSubscribe(const QString& topic);
    void removeSubscribe(const QString& topic);
    void stop();

#ifdef _TEST
    void test(const QJsonObject & obj);
#endif

protected slots:
    void onConnected();
    void onDisconnected();
    void onError(const QMQTT::ClientError error);
    void onSubscribed(const QString& topic);
    void onUnsubscribed(const QString& topic);
    void onPublished(const QMQTT::Message& message);
    void onReceived(const QMQTT::Message& message);

public slots:
    void pubDeviceConnected(const QString &device);
    void pubDeviceDisonnected(const QString &device);
    void pubClientAttributes(const QJsonObject &data);
    void requestAttribute(int id, const QString &device, bool client, const QString &key);
    void pubTelemetry(const QJsonObject &data);
    void responseRPC(int id, const QString &device, const QJsonObject &data);

signals:
    void attributesChanged(const QString &device, const QJsonObject &data);
    void attributesResponse(const int id, const QString &device, const QVariant &data);
    void rpcCall(const int id, const QString &device, const QString &method, const QJsonObject &params);

protected:
    QStringList _topics;
    int devicesOnline = 0;
    int attributesUploaded = 0;
    int telemetryUploaded = 0;
};

#endif // MQTTHANDLER_H
