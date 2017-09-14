#ifndef DAEMONAPPLICATION_H
#define DAEMONAPPLICATION_H

#include <QCoreApplication>
#include <QJsonObject>

class QSettings;
class MQTTHandler;


class DaemonApplication : public QCoreApplication
{
public:
    DaemonApplication(int &argc, char **argv);
    virtual ~DaemonApplication();

    virtual void init();
    static int exec();

protected:
    void timerEvent(QTimerEvent *) Q_DECL_OVERRIDE;

protected slots:
    void signDevice(const QString &device);
    void onAttributeReceive(const QString &name, const QString &key, const QVariant &value);
    void onTelemetryReceive(const QString &name, const qint64 time, const QString &key, const QVariant &value);

private:
    QSettings *_settings;
    MQTTHandler *_mqttHandler = Q_NULLPTR;


    QStringList _devices;
    QJsonObject _attributes;
    QJsonObject _telemetry;
};

#endif // DAEMONAPPLICATION_H
