#ifndef DDSMESSAGEEVENT_H
#define DDSMESSAGEEVENT_H

#include <QEvent>
#include <QJsonObject>

namespace DDS {

extern const int DDSMESSAGEEVENT;

class DDSMessageEvent : public QEvent
{
public:
    DDSMessageEvent();
    virtual ~DDSMessageEvent();

    QJsonObject message;
};

}

#endif // DDSMESSAGEEVENT_H
