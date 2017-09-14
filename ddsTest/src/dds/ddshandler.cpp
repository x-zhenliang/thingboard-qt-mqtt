#include "ddshandler.h"
#include "ddsclient.h"
#include <QDateTime>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

DDSHandler::DDSHandler(QObject *parent)
    : QObject(parent)
    , _client(nullptr)
{
}

DDSHandler::~DDSHandler()
{
    if (_client != nullptr)
        delete _client;
}

void DDSHandler::init(int domainId, int bufferSize)
{
    _client = new DDS::DDSClient(domainId, this);
    connect(_client, &DDS::DDSClient::received, this, &DDSHandler::onReceived);
    _client->setBufferSize(bufferSize);
    _client->start();
    _client->subscribe("sensors");
}

void DDSHandler::onReceived(const QString &topic, const QJsonObject &message)
{
    if (topic == "sensors") {
        onSensorsDataReceive(message);
    }
}

void DDSHandler::publish(const QString &topic, const QJsonObject &message)
{
    //fixme notify error from client
    if (_client->publish(topic, message) != 0)
        return;
}

void DDSHandler::onSensorsDataReceive(const QJsonObject &message)
{
    if (!message.contains("serialNumber"))
        return;

    QString name = message["serialNumber"].toString();
    if (message.contains("attributes")) {
        auto attributes = message["attributes"].toObject();
        onAttributesDataReceive(name, attributes);
    }

    if (message.contains("timeseries")) {
        auto attributes = message["timeseries"].toObject();
        onTimeseriesDataReceive(name, attributes);
    }
}

void DDSHandler::onAttributesDataReceive(const QString &name, const QJsonObject &message)
{
    for (auto key : message.keys()) {
        emit attribute(name, key, message[key].toVariant());
    }
}

void DDSHandler::onTimeseriesDataReceive(const QString &name, const QJsonObject &message)
{
    qint64 ts = 0;
    QJsonObject values;
    if (message.contains("ts")) {
        ts = (qint64)(message["ts"].toDouble());
        values = message["values"].toObject();
    }
    else {
        ts = QDateTime::currentDateTime().toMSecsSinceEpoch();
        values = message;
    }

    for (auto key : values.keys()) {
        emit telemetry(name, ts, key, values[key].toVariant());
    }
}

