#include "mqtthandler.h"
#include "mqtttopic.h"
#include "mqttmessagebuilder.h"
#include <QJsonDocument>
#include <QDateTime>

#ifdef _DEBUG
#include <QDebug>
#endif

extern const QHostAddress DEFAULT_HOST = QHostAddress::LocalHost;
extern const quint16 DEFAULT_PORT = 1883;

MQTTHandler::MQTTHandler(const QHostAddress &host, const quint16 port, QObject *parent)
    : QMQTT::Client(host, port, parent)
{
    connect(this, &MQTTHandler::connected, this, &MQTTHandler::onConnected);
    connect(this, &MQTTHandler::disconnected, this, &MQTTHandler::onDisconnected);
//    connect(this, &MQTTHandler::error, this, &MQTTHandler::onError);
//    connect(this, &MQTTHandler::subscribe, this, &MQTTHandler::onSubscribed);
//    connect(this, &MQTTHandler::unsubscribed, this, &MQTTHandler::onUnsubscribed);
//    connect(this, &MQTTHandler::received, this, &MQTTHandler::onReceived);

}

void MQTTHandler::addSubscribe(const QString &topic)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::addSubscribe:" << topic;
#endif
    if (_topics.contains(topic))
        return;
    _topics.append(topic);
    if (isConnectedToHost()) {
        subscribe(topic, 0);
    }
}

void MQTTHandler::removeSubscribe(const QString &topic)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::removeSubscribe:" << topic;
#endif
    if (!_topics.contains(topic))
        return;
    _topics.removeAll(topic);
    if (isConnectedToHost()) {
        unsubscribe(topic);
    }
}

void MQTTHandler::stop()
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::stop";
#endif
    for(auto topic : _topics) {
        unsubscribe(topic);
    }
    disconnectFromHost();
}

#ifdef _TEST
void MQTTHandler::test(const QJsonObject &obj)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::test" << obj;
#endif

    QString device = obj["device"].toString();
    onDeviceConnected(device);
    QJsonObject data;
    data[device] = obj[device];
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_TELEMETRY_UPLOAD, data));
}
#endif //_TEST

void MQTTHandler::onConnected()
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onConnected";
#endif

    addSubscribe(MQTT_GATEWAY_ATTRIBUTES);
    addSubscribe(MQTT_GATEWAY_ATTRIBUTES_RESPONSE);
    addSubscribe(MQTT_GATEWAY_RPC);

    for(auto topic : _topics) {
        subscribe(topic, 0);
    }

    QJsonObject value;
    value["devicesOnline"] = devicesOnline;
    value["attributesUploaded"] = attributesUploaded;
    value["telemetryUploaded"] = telemetryUploaded;
    publish(MQTTMessageBuilder::buildMessage(MQTT_DEVICE_TELEMETRY_UPLOAD, value));
}

void MQTTHandler::onDisconnected()
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onDisconnected";
#endif
}

void MQTTHandler::onError(const QMQTT::ClientError error)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onError:" <<error;
#endif
}

void MQTTHandler::onSubscribed(const QString &topic)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onSubscribed" << topic;
#endif
}

void MQTTHandler::onUnsubscribed(const QString &topic)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onUnsubscribed" << topic;
#endif
}

void MQTTHandler::onPublished(const QMQTT::Message &message)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onPublished" << message.payload();
#endif
}

void MQTTHandler::onReceived(const QMQTT::Message &message)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onReceived" << message.topic();
#endif
    auto topic = message.topic();
    if (!_topics.contains(topic))
        return;
    auto payload = message.payload();
    QJsonParseError err;
    auto infoObject = QJsonDocument::fromJson(payload, &err).object();
    if (err.error != QJsonParseError::NoError)
        return;

    if (topic == MQTT_GATEWAY_ATTRIBUTES) {
        if (!infoObject.contains("device"))
            return;
        emit attributesChanged(infoObject["device"].toString(), infoObject["data"].toObject());
    }
    else if (topic == MQTT_GATEWAY_ATTRIBUTES_RESPONSE) {
        emit attributesResponse(infoObject["id"].toInt(),
                infoObject["device"].toString(), infoObject["value"].toVariant());
    }
    else if (topic == MQTT_GATEWAY_RPC) {
        if (infoObject.contains("id"))
            return;
        auto data = infoObject["data"].toObject();
        emit rpcCall(data["id"].toInt(), infoObject["device"].toString(),
                data["method"].toString(), data["params"].toObject());
    }
}

void MQTTHandler::pubDeviceConnected(const QString &device)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onDeviceConnected" << device;
#endif
    QJsonObject data;
    data["device"] = device;
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_DEVICE_CONNECT, data));
}

void MQTTHandler::pubDeviceDisonnected(const QString &device)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::onDeviceConnected" << device;
#endif
    QJsonObject data;
    data["device"] = device;
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_DEVICE_DISCONNECT, data));
}

void MQTTHandler::pubClientAttributes(const QJsonObject &data)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::pubClientAttributes" << data;
#endif
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_ATTRIBUTES, data));
}

void MQTTHandler::requestAttribute(int id, const QString &device, bool client, const QString &key)
{
    QJsonObject data;
    data["id"] = id;
    data["device"] = device;
    data["client"] = client;
    data["key"] = key;
#ifdef _DEBUG
    qDebug() << "MQTTHandler::requestAttribute" << data;
#endif
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_ATTRIBUTES_REQUEST, data));
}

void MQTTHandler::pubTelemetry(const QJsonObject &data)
{
#ifdef _DEBUG
    qDebug() << "MQTTHandler::pubTelemetry" << data;
#endif
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_TELEMETRY_UPLOAD, data));
}

void MQTTHandler::responseRPC(int id, const QString &device, const QJsonObject &value)
{
    QJsonObject data;
    data["device"] = device;
    data["id"] = id;
    data["data"] = value;
#ifdef _DEBUG
    qDebug() << "MQTTHandler::responseRPC" << data;
#endif
    publish(MQTTMessageBuilder::buildMessage(MQTT_GATEWAY_RPC, data));
}
