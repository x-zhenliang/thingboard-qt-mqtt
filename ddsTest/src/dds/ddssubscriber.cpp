#include "ddssubscriber.h"
#include "ddsmessageevent.h"

namespace DDS {

DDSSubscriber::DDSSubscriber(const QString &topicName, DDSDataReader *reader, const int bufferSize, QObject *parent)
    : QObject(parent)
    , _topicName(topicName)
    , _reader(reader)
    , _listener(DDSSimpleListener(bufferSize, this))
{
    reader->set_listener(&_listener);
}

bool DDSSubscriber::event(QEvent *e)
{
    if (e->type() == DDSMESSAGEEVENT) {
        auto messageEvent = dynamic_cast<DDSMessageEvent*>(e);
        emit dataRecv(_topicName, messageEvent->message);
        messageEvent->accept();
        return true;
    }

    return QObject::event(e);
}

} // namespace DDS

