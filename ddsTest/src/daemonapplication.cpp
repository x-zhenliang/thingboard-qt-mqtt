#include "daemonapplication.h"
#include <mqtt/mqtthandler.h>
#include <dds/ddshandler.h>
#include <QSettings>
#include <QJsonArray>
#ifdef Q_OS_LINUX
#include <signal.h>
#endif
#ifdef _DEBUG
#include <QDebug>
#endif

DaemonApplication::DaemonApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
    , _settings(new QSettings)
    , _mqttHandler(new MQTTHandler(DEFAULT_HOST, DEFAULT_PORT, this))
{
    QCoreApplication::setOrganizationName("nfschina");
    QCoreApplication::setOrganizationDomain("www.nfschina.com");
    QCoreApplication::setApplicationName("EThings-gateway");
}

DaemonApplication::~DaemonApplication()
{
    _mqttHandler->stop();
    delete _settings;
}

void DaemonApplication::init()
{
    QSettings settings;

    auto hostname = settings.value("gateway/host", "127.0.0.1").toString();
    _mqttHandler->setHostName(hostname);
    auto port = settings.value("gateway/port", 1883).toInt();
    _mqttHandler->setPort(port);
    auto token = settings.value("gateway/accessToken").toString();
    _mqttHandler->setUsername(token);
    _mqttHandler->setAutoReconnect(true);
    auto reconnectInterval = settings.value("gateway/retryInterval", 3000).toInt();
    _mqttHandler->setAutoReconnectInterval(reconnectInterval);
    _mqttHandler->connectToHost();


    //int reportingInterval = settings.value("gateway/reporting", 60000).toInt();
    //startTimer(reportingInterval);

#ifdef _TEST
    connect(_ddsHandler, &DDSHandler::dataRecv, _mqttHandler, &MQTTHandler::test);
#endif
}

int DaemonApplication::exec()
{
    dynamic_cast<DaemonApplication*>(instance())->init();
    return QCoreApplication::exec();
}

void DaemonApplication::timerEvent(QTimerEvent *event)
{
    if (!_attributes.isEmpty()) {
        _mqttHandler->pubClientAttributes(_attributes);
        _attributes = QJsonObject();
    }

    if (!_telemetry.isEmpty()) {
        QJsonObject telemetry;
        auto devices = _telemetry.keys();
        for (auto device : devices) {
            //auto timestamps =
            auto _datas = _telemetry[device].toObject();
            auto _timestamps = _datas.keys();
            QJsonArray datas;
            for (auto _timestamp : _timestamps) {
                int ts = _timestamp.toLongLong();
                QJsonObject data;
                data["ts"] = ts;
                data["values"] = _datas[_timestamp];
                datas.append(data);
            }
            telemetry[device] = datas;
        }
        _mqttHandler->pubTelemetry(telemetry);
        _telemetry = QJsonObject();
    }

    QCoreApplication::timerEvent(event);
}

void DaemonApplication::signDevice(const QString &device)
{
    if (_devices.contains(device))
        return;
    _devices.append(device);
    _mqttHandler->pubDeviceConnected(device);
}

void DaemonApplication::onAttributeReceive(const QString &name, const QString &key, const QVariant &value)
{
    signDevice(name);
    auto deviceObject = _attributes[name].toObject();
    deviceObject[key] = QJsonValue::fromVariant(value);
    _attributes[name] = deviceObject;
}

void DaemonApplication::onTelemetryReceive(const QString &name, const qint64 time, const QString &key, const QVariant &value)
{
    signDevice(name);
    auto telemetryDatas = _telemetry[name].toObject();
    QString timeString = QString::number(time);
    auto vaules = telemetryDatas[timeString].toObject();
    vaules[key] = QJsonValue::fromVariant(value);
    telemetryDatas[timeString] = vaules;
    _telemetry[name] = telemetryDatas;
}
