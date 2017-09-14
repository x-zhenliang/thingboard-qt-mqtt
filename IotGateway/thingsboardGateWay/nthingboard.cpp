#include "nthingboard.h"
#include "nmqttmessagebuild.h"
#include "mqtt/mqtttopic.h"
#include "mqtt/qmqtt.h"
#include <QTimer>
#include <QSettings>






NThingBoard::NThingBoard(int argc, char **argv)
    : QCoreApplication(argc, argv)
    , settings(new QSettings)
    , bMqttConnectState(false)
{
    QCoreApplication::setOrganizationName("nfschina");
    QCoreApplication::setOrganizationDomain("www.nfschina.com");
    QCoreApplication::setApplicationName("NThingsGateway");

    mqttBroker = new MqttBroker(DEFAULT_HOST,DEFAULT_PORT, this);
    connect(mqttBroker, &MqttBroker::signalConnectIotGateway , this , &NThingBoard::slotSetupConnectedState);
}

NThingBoard::~NThingBoard()
{
    mqttBroker->StopBroker();
    delete settings;
}

void NThingBoard::init()
{

    Publisher publisher;
    //publisher.setUsername();
    publisher.setUsername("LVxma1mqXGPwaeWQupCG");
    publisher.connectToHost();

//    QString sHostname = settings->value("gateway/host", "10.50.200.232").toString();
//    mqttBroker->setHostName(sHostname);
//    qint16 port = settings->value("gateway/port", 1883).toInt();
//    mqttBroker->setPort(port);
//    QString sToken = settings->value("gateway/accessToken", "LVxma1mqXGPwaeWQupCG").toString();
//    mqttBroker->setUsername(sToken);
//    mqttBroker->setAutoReconnect(true);
//    auto reconnectInterval = settings->value("gateway/retryInterval", 3000).toInt();
//    mqttBroker->setAutoReconnectInterval(reconnectInterval);
//    mqttBroker->connectToHost();
//    qDebug() << mqttBroker->host();
//    qDebug() <<  mqttBroker->hostName();
//    qDebug() <<  mqttBroker->port();

//    int ddsDomainId = settings->value("dds/domainId", 0).toInt();
//    int ddsBufferSize = settings->value("dds/bufferSize", 4096).toInt();
//    mqttBroker->init(ddsDomainId, ddsBufferSize);
//    int reportingInterval = settings->value("gateway/reporting", 60000).toInt();
//    startTimer(reportingInterval);



}

int NThingBoard::exec()
{
    dynamic_cast<NThingBoard *>(instance())->init();
    return QCoreApplication::exec();
}

void NThingBoard::timerEvent(QTimerEvent *event)
{
    /*
    QStringList slDevices;
    QJsonObject joAttributes;
    QJsonObject joTelemetry;
    */
    if (!joAttributes.isEmpty())
    {
        mqttBroker->PublishClientAttributes(joAttributes);
        joAttributes = QJsonObject();
    }

    if (!joTelemetry.isEmpty())
    {
        QJsonObject telemetry;
        auto devices = joTelemetry.keys();
        for (auto device : devices)
        {
            auto _datas = joTelemetry[device].toObject();
            auto _timestamps = _datas.keys();
            QJsonArray datas;
            for (auto _timestamp : _timestamps)
            {
                int ts = _timestamp.toLongLong();
                QJsonObject data;
                data["ts"] = ts;
                data["values"] = _datas[_timestamp];
                datas.append(data);
            }
            telemetry[device] = datas;
        }
        mqttBroker->PublishTelemetry(telemetry);
        joTelemetry = QJsonObject();
    }
    QCoreApplication::timerEvent(event);
}

void NThingBoard::AddConnectDevice(const QString &device)
{
    if (slDevices.contains(device))
           return;
       slDevices.append(device);
       mqttBroker->PublishDeviceConnected(device);

}

void NThingBoard::slotOnAttributeReceive(const QString &name, const QString &key, const QVariant &value)
{
    this->AddConnectDevice(name);
    auto deviceObject = joAttributes[name].toObject();
    deviceObject[key] = QJsonValue::fromVariant(value);
    joAttributes[name] = deviceObject;
}

void NThingBoard::slotOnTelemetryReceive(const QString &name, const qint64 time, const QString &key, const QVariant &value)
{
    this->AddConnectDevice(name);
    auto telemetryDatas = joTelemetry[name].toObject();
    QString timeString = QString::number(time);
    auto vaules = telemetryDatas[timeString].toObject();
    vaules[key] = QJsonValue::fromVariant(value);
    telemetryDatas[timeString] = vaules;
    joTelemetry[name] = telemetryDatas;
}

void NThingBoard::slotSetupConnectedState(bool state)
{
    if(state)
    {
        this->bMqttConnectState = true;

    }
    else
    {
        this->bMqttConnectState = false;
    }
}
