#ifndef NTHINGBOARD_H
#define NTHINGBOARD_H

#include <QCoreApplication>
#include <QSettings>
#include <QJsonArray>
#include "mqttbroker.h"

class NThingBoard : public QCoreApplication
{
    Q_OBJECT

public:
    NThingBoard(int argc, char **argv);
    ~NThingBoard();

    void init();
    static int exec();
    void AddConnectDevice(const QString &device);



public:
    QSettings  *settings;
    MqttBroker *mqttBroker = Q_NULLPTR;

    QStringList slDevices;
    QJsonObject joAttributes;
    QJsonObject joTelemetry;

protected:
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
private:
    bool bMqttConnectState;

public slots:
     void slotOnAttributeReceive(const QString &name, const QString &key, const QVariant &value);
     void slotOnTelemetryReceive(const QString &name, const qint64 time, const QString &key, const QVariant &value);
     void slotSetupConnectedState(bool state);
};

#endif // NTHINGBOARD_H
