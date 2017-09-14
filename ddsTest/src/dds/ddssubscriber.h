#ifndef DDS_DDSSUBSCRIBER_H
#define DDS_DDSSUBSCRIBER_H

#include <QObject>
#include "ddssimplelistener.h"

class DDSDataReader;
namespace DDS {

class DDSSubscriber : public QObject
{
    Q_OBJECT
public:
    explicit DDSSubscriber(const QString &topicName, DDSDataReader *reader, const int bufferSize, QObject *parent = 0);

signals:
    void dataRecv(const QString &topic, const QJsonObject &message);

protected:
    bool event(QEvent *e) Q_DECL_OVERRIDE;

private:
    QString _topicName;
    DDSDataReader *_reader;
    DDSSimpleListener _listener;
};

} // namespace DDS

#endif // DDS_DDSSUBSCRIBER_H
