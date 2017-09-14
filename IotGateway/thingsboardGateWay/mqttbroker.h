#ifndef MQTTBROKER_H
#define MQTTBROKER_H

#include "mqtt/qmqtt.h"
#include <QStringList>
#include <QJsonObject>
#include <QTimer>
#include <QCoreApplication>

extern const QHostAddress DEFAULT_HOST;
extern const quint16 DEFAULT_PORT;

class MqttBroker : public QMQTT::Client
{
    Q_OBJECT
public:
    explicit MqttBroker(const QHostAddress& host = DEFAULT_HOST,
                        const quint16  port = DEFAULT_PORT,
                              QObject *parent = Q_NULLPTR);

    ~MqttBroker();
    void AddSubscribe(const QString &topic);
    void RemoveSubscribe(const QString &topic);
    void StopBroker();

    void PublishClientAttributes(const QJsonObject &data);
    void PublishTelemetry(const QJsonObject &data);
    void PublishDeviceConnected(const QString &device);

protected:
    QStringList slMqttTopics;
    int devicesOnline = 0;
    int attributesUploaded = 0;
    int telemetryUploaded = 0;

public slots:

    void slotPublishDeviceDisconnected(const QString &device);
    void slotRequestAttributes(int id, const QString &device, bool client, const QString &key);
    void slotResponseRPC(int id, const QString &device, const QJsonObject &value);

protected slots:
    void slotBrokerConnect();
    void slotBrokerDisConnect();
    void slotBrokerError(const QMQTT::ClientError error);
    void slotBrokerSubscribed(const QString& topic);
    void slotBrokerUnSubscribed(const QString& topic);
    void slotBrokerReceived(const QMQTT::Message& message);
    void slotBrokerPublished(const QMQTT::Message& message);

signals:
    void signalAttributesChanged(const QString &device, const QJsonObject &data);
    void signalAttributesResponse(const int id, const QString &device, const QVariant &data);
    void signalRpcCall(const int id, const QString &device, const QString &method, const QJsonObject &params);
    void signalConnectIotGateway(bool);
};


const QHostAddress EXAMPLE_HOST = QHostAddress::LocalHost;
const quint16 EXAMPLE_PORT = 1883;
const QString EXAMPLE_TOPIC = "qmqtt/exampletopic";

class Publisher : public QMQTT::Client
{
    Q_OBJECT

public:
    explicit Publisher(const QHostAddress& host = EXAMPLE_HOST,
                       const quint16 port = EXAMPLE_PORT,
                       QObject* parent = NULL)
        : QMQTT::Client(host, port, parent)
        , _number(0)
    {
        connect(this, &Publisher::connected, this, &Publisher::onConnected);
        connect(&_timer, &QTimer::timeout, this, &Publisher::onTimeout);
        connect(this, &Publisher::disconnected, this, &Publisher::onDisconnected);
    }

    QTimer _timer;
    quint16 _number;

public slots:
    void onConnected()
    {
        qDebug() << "connect sucess...";
        //subscribe(EXAMPLE_TOPIC, 0);
        _timer.start(1000);
    }

    void onTimeout()
    {
        QMQTT::Message message(_number, EXAMPLE_TOPIC,
                               QString("Number is %1").arg(_number).toUtf8());
        publish(message);
        _number++;
        if(_number >= 10)
        {
            _timer.stop();
            disconnectFromHost();
        }
    }

    void onDisconnected()
    {
        QTimer::singleShot(0, qApp, &QCoreApplication::quit);
    }
};

#endif // MQTTBROKER_H
