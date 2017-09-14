#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include "nmqttmessagebuild.h"

static qint16 id = 1;

QMQTT::Message NMqttMessageBuild::BuildMessage(const QString &topic, const QByteArray  &payload)
{
    return QMQTT::Message(id++, topic, payload);
}

QMQTT::Message NMqttMessageBuild::BuildMessage(const QString &topic, const QJsonObject &payload)
{
     return QMQTT::Message(id++, topic, ToJson(payload));
}

QByteArray NMqttMessageBuild::ToJson(const QJsonObject &obj)
{
    return QJsonDocument(obj).toJson();
}
