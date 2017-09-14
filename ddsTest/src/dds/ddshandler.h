#ifndef DDSHANDLER_H
#define DDSHANDLER_H

#include <QObject>

namespace DDS {
class DDSClient;
}
class DDSHandler : public QObject
{
    Q_OBJECT
public:
    explicit DDSHandler(QObject *parent = 0);
    ~DDSHandler();

signals:
    void dataRecv(const QJsonObject &data);
    void attribute(const QString &name, const QString &key, const QVariant &value);
    void telemetry(const QString &name, const qint64 time, const QString &key, const QVariant &value);

public slots:
    void init(int domainId, int bufferSize = 4096);
    void onReceived(const QString &topic, const QJsonObject& message);
    void publish(const QString &topic, const QJsonObject& message);

protected:
    void onSensorsDataReceive(const QJsonObject& message);
    void onAttributesDataReceive(const QString &name, const QJsonObject& message);
    void onTimeseriesDataReceive(const QString &name, const QJsonObject& message);

protected:
    DDS::DDSClient *_client;
};

#endif // DDSHANDLER_H
