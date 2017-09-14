#ifndef DDSSIMPLELISTENER_H
#define DDSSIMPLELISTENER_H

#include <QObject>
#include <QJsonObject>
#include <ndds/ndds_cpp.h>

class DDSHandler;

namespace DDS {

class DDSSimpleListener : public DDSDataReaderListener
{
public:
    DDSSimpleListener(const int bufferSize = 4096, QObject *handler = 0);
    void on_data_available(DDSDataReader *reader) Q_DECL_OVERRIDE;

private:
    int _bufferSize;
    QObject *_processer;
};
}

#endif // DDSSIMPLELISTENER_H
