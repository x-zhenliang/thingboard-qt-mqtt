#ifndef MQTTMESSAGEBUILDER_H
#define MQTTMESSAGEBUILDER_H
#include <qmqtt_message.h>

class QJsonObject;

class MQTTMessageBuilder
{
public:
    static QMQTT::Message buildMessage(const QString &topic, const QByteArray &payload);
    static QMQTT::Message buildMessage(const QString &topic, const QJsonObject &payload);
    static QByteArray toJson(const QJsonObject &obj);

};

#endif // MQTTMESSAGEBUILDER_H
