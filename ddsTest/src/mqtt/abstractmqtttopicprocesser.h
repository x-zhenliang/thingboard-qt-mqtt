#ifndef ABSTRACTMQTTTOPICPROCESSER_H
#define ABSTRACTMQTTTOPICPROCESSER_H
#include <QObject>
#include <qmqtt.h>

class AbstractMqttTopicProcesser : public QObject
{
    Q_OBJECT
public:
    AbstractMqttTopicProcesser(const QString &_topic = QString(), QObject *parent = Q_NULLPTR);

    QString getTopic() const;
    void setTopic(const QString & topic);

    int process(const QMQTT::Message &message);
    virtual void onProcess(const QMQTT::Message &message) = 0;

Q_SIGNALS:

protected:
    QString _topic;
};

#endif // ABSTRACTMQTTTOPICPROCESSER_H
