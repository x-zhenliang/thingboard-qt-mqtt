#ifndef DDSPUBLISHER_H
#define DDSPUBLISHER_H

#include <QObject>
#include <QJsonObject>

class DDSDataWriter;
namespace DDS {

class DDSPublisher : public QObject
{
    Q_OBJECT
public:
    explicit DDSPublisher(const QString &topicName, DDSDataWriter *writer, QObject *parent = 0);

public slots:
    qint32 write(const QJsonObject &message);

signals:
    void dataPublished(const QString &topicName, const QJsonObject &message);

private:
    QString _topicName;
    DDSDataWriter *_writer;
};

} // namespace DDS

#endif // DDSPUBLISHER_H
