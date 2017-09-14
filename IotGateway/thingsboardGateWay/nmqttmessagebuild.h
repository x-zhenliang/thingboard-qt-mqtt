#ifndef NMQTTMESSAGEBUILD_H
#define NMQTTMESSAGEBUILD_H

#include "mqtt/qmqtt_message.h"

class NMqttMessageBuild
{
public:
    static QMQTT::Message BuildMessage(const QString &topic, const QByteArray  &payload);
    static QMQTT::Message BuildMessage(const QString &topic, const QJsonObject &payload);
    static QByteArray ToJson(const QJsonObject &obj);
};

#endif // NMQTTMESSAGEBUILD_H
