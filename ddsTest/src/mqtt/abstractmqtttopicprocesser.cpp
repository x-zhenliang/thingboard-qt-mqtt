#include "abstractmqtttopicprocesser.h"

AbstractMqttTopicProcesser::AbstractMqttTopicProcesser(const QString &_topic, QObject *parent)
    : QObject(parent)
{
    setTopic(_topic);
}

QString AbstractMqttTopicProcesser::getTopic() const
{
    return _topic;
}

void AbstractMqttTopicProcesser::setTopic(const QString &topic)
{
    _topic = topic;
}

int AbstractMqttTopicProcesser::process(const QMQTT::Message &message)
{
    int ret = 0;
    onProcess(message);
    return ret;
}
