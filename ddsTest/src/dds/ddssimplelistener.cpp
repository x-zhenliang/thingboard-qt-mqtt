#include "ddssimplelistener.h"
#include "ddsmessageevent.h"
#include <QCoreApplication>
#include <QJsonDocument>
#ifdef _DEBUG
#include <QDebug>
#endif

namespace DDS {

DDSSimpleListener::DDSSimpleListener(const int bufferSize, QObject *processer)
    : DDSDataReaderListener()
    , _bufferSize(bufferSize)
    , _processer(processer)
{
}

void DDSSimpleListener::on_data_available(DDSDataReader *reader)
{
    DDSStringDataReader *stringReader = DDSStringDataReader::narrow(reader);
    for(;;) {
        //fixme max_buffer need read from settings;
        QByteArray sample(_bufferSize, '\0');
        DDS_SampleInfo info;
        DDS_ReturnCode_t retcode = stringReader->take_next_sample(sample.data(), info);
        if (retcode == DDS_RETCODE_NO_DATA) {
            break;
        }
        if (retcode != DDS_RETCODE_OK) {
#ifdef _DEBUG
            qWarning() << "Unable to take data from data reader, error " << retcode;
#endif
            break;
        }

        if (info.valid_data) {
            QJsonParseError err;
            sample.truncate(qstrlen(sample.data()));
            auto doc = QJsonDocument::fromJson(sample, &err);

            if (QJsonParseError::NoError != err.error)
                return;

            if (_processer != nullptr) {
                auto *event = new DDSMessageEvent();
                event->message = doc.object();
                QCoreApplication::postEvent(_processer, event);
            }
        }
    }
}

}
