#include "mqttbroker.h"
#include "nmqttmessagebuild.h"
#include "mqtt/mqtttopic.h"
#include <QJsonParseError>
#include <QJsonDocument>

//#ifdef DIS_DEBUG_INFO
#include <QDebug>
//#endif

extern const QHostAddress DEFAULT_HOST = QHostAddress::Any;
extern const quint16 DEFAULT_PORT = 1883;

MqttBroker::MqttBroker(const QHostAddress &host, const quint16 port, QObject *parent)
    : QMQTT::Client(host, port, parent)
{

    connect(this, &MqttBroker::connected,    this , &MqttBroker::slotBrokerConnect);
    connect(this, &MqttBroker::disconnected, this , &MqttBroker::slotBrokerDisConnect);
    connect(this, &MqttBroker::error,        this , &MqttBroker::slotBrokerError);
    connect(this, &MqttBroker::subscribed,   this , &MqttBroker::slotBrokerSubscribed);
    connect(this, &MqttBroker::unsubscribed, this , &MqttBroker::slotBrokerUnSubscribed);
    connect(this, &MqttBroker::received,     this , &MqttBroker::slotBrokerReceived);

    this->AddSubscribe(MQTT_GATEWAY_ATTRIBUTES);
    //this->AddSubscribe(MQTT_GATEWAY_ATTRIBUTES_RESPONSE);
    //this->AddSubscribe(MQTT_GATEWAY_RPC);
}

MqttBroker::~MqttBroker()
{
}


void MqttBroker::slotBrokerConnect()
{

   foreach(QString topic, slMqttTopics)
   {
       qDebug() << topic;
       this->subscribe(topic, 0);
   }

//  这几个内容需要直接发布到thingsboard服务器节点
    QJsonObject joInitValue;
    joInitValue["devicesOnline"] = devicesOnline;
    joInitValue["attributesUploaded"] = attributesUploaded;
    joInitValue["telemetryUploadedts"] = telemetryUploaded;
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_DEVICE_TELEMETRY_UPLOAD, joInitValue));
    qDebug() << "Mqtt Broker has been connected Iot Gateway";
}

void MqttBroker::slotBrokerDisConnect()
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker disconnect from Iot GateWay...";
#endif
    emit signalConnectIotGateway(false);
}

void MqttBroker::slotBrokerError(const QMQTT::ClientError error)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker Connect Error" << error;
#endif
}

void MqttBroker::slotBrokerSubscribed(const QString& topic)
{
    qDebug() << "Mqtt Broker onSubscribed" << topic;
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onSubscribed" << topic;
#endif
    emit signalConnectIotGateway(true);
}

void MqttBroker::slotBrokerUnSubscribed(const QString& topic)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onUnsubscribed" << topic;
#endif
}

void MqttBroker::slotBrokerPublished(const QMQTT::Message& message)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onPublished" << message.payload();
#endif
}

void MqttBroker::slotBrokerReceived(const QMQTT::Message& message)
{

#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onReceived" << message.topic();
#endif

    qDebug() << "Mqtt Broker onReceived" << message.topic();
    QString topic = message.topic();
    if (!slMqttTopics.contains(topic))
    {
        return;
    }
    QByteArray payload = message.payload();
    QJsonParseError err;
    QJsonObject infoObject = QJsonDocument::fromJson(payload, &err).object();
    qDebug() << infoObject;

    if (err.error != QJsonParseError::NoError)
    {
        return ;
    }

    if (topic == MQTT_GATEWAY_ATTRIBUTES)
    {
        if (!infoObject.contains("device"))
        {
            return ;
        }
        emit signalAttributesChanged( infoObject["device"].toString(),
                                      infoObject["data"].toObject());
    }
    else if (topic == MQTT_GATEWAY_ATTRIBUTES_RESPONSE)
    {
        emit signalAttributesResponse( infoObject["id"].toInt(),
                                       infoObject["device"].toString(),
                                       infoObject["value"].toVariant());
    }
    else if (topic == MQTT_GATEWAY_RPC)
    {
        if (infoObject.contains("id"))
        {
            return ;
        }
        auto data = infoObject["data"].toObject();
        emit signalRpcCall( data["id"].toInt(),
                            infoObject["device"].toString(),
                            data["method"].toString(),
                            data["params"].toObject());
    }
}

void MqttBroker::AddSubscribe(const QString &topic)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker AddSubscribe:" << topic;
#endif

    if (slMqttTopics.contains(topic))
    {
        return;
    }
    slMqttTopics.append(topic);
    if (this->isConnectedToHost())
    {
        //this->subscribe(topic);
    }
}

void MqttBroker::RemoveSubscribe(const QString &topic)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker RemoveSubscribe:" << topic;
#endif
    if (!slMqttTopics.contains(topic))
    {
        return;
    }
    slMqttTopics.removeAll(topic);
    if (this->isConnectedToHost())
    {
        this->unsubscribe(topic);
    }
}

void MqttBroker::StopBroker()
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker Stop";
#endif

    foreach(QString sTopic, slMqttTopics)
    {
        this->unsubscribe(sTopic);
    }
    this->disconnectFromHost();
}

void MqttBroker:: PublishDeviceConnected(const QString &device)
{

#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onDeviceConnected" << device;
#endif
    QJsonObject joData;
    joData["device"] = device;
    this->publish(NMqttMessageBuild::BuildMessage("MQTT_GATEWAY_DEVICE_CONNECT", joData));
}

void MqttBroker::slotPublishDeviceDisconnected(const QString &device)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker onDeviceConnected" << device;
#endif
    QJsonObject joData;
    joData["device"] = device;
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_GATEWAY_DEVICE_DISCONNECT, joData));
}

void MqttBroker::PublishClientAttributes(const QJsonObject &data)
{
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker pubClientAttributes" << data;
#endif
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_GATEWAY_ATTRIBUTES, data));
}

void MqttBroker::slotRequestAttributes(int id, const QString &device, bool client, const QString &key)
{
    QJsonObject joData;
    joData["id"] = id;
    joData["device"] = device;
    joData["client"] = client;
    joData["key"] = key;
#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker requestAttribute" << joData;
#endif
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_GATEWAY_ATTRIBUTES_REQUEST, joData));
}

void MqttBroker::PublishTelemetry(const QJsonObject &data)
{

#ifdef DIS_DEBUG_INFO
    qDebug() << "Mqtt Broker pubTelemetry" << data;
#endif
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_GATEWAY_TELEMETRY_UPLOAD, data));
}

void MqttBroker::slotResponseRPC(int id, const QString &device, const QJsonObject &value)
{
    QJsonObject joData;
    joData["device"] = device;
    joData["id"] = id;
    joData["data"] = value;
#ifdef DIS_DEBUG_INFO
    qDebug() << " Mqtt Broker responseRPC" << joData;
#endif
    this->publish(NMqttMessageBuild::BuildMessage(MQTT_GATEWAY_RPC, joData));
}



