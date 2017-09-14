#include "mqttmessagebuilder.h"
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>

static quint16 id = 1;

QMQTT::Message MQTTMessageBuilder::buildMessage(const QString &topic, const QByteArray &payload)
{
    return QMQTT::Message(id++, topic, payload);
}

QMQTT::Message MQTTMessageBuilder::buildMessage(const QString &topic, const QJsonObject &payload)
{
    return QMQTT::Message(id++, topic, toJson(payload));
}

QByteArray MQTTMessageBuilder::toJson(const QJsonObject &obj)
{
    return QJsonDocument(obj).toJson();
}
