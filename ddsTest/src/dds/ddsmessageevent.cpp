#include "ddsmessageevent.h"

namespace DDS {

const int DDSMESSAGEEVENT = QEvent::User;

DDSMessageEvent::DDSMessageEvent()
    : QEvent(static_cast<Type>(DDSMESSAGEEVENT))
{
    QEvent::registerEventType(DDSMESSAGEEVENT);
}

DDSMessageEvent::~DDSMessageEvent()
{

}

}
