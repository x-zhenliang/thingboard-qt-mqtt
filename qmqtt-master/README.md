QMQTT
=====

mqtt client for Qt

**Please compile the library with Qt >= 5.3 version. On Windows you need to specify `CONFIG += NO_UNIT_TESTS`, since gtest is not supported.**

Usage
=====

    #include "qmqtt.h"

    QMQTT::Client *client = new QMQTT::Client(QHostAddress::LocalHost, 1883);
    client->setClientId("clientId");
    client->setUsername("user");
    client->setPassword("password");
    client->connectToHost();

Slots
=====

    void setHost(const QHostAddress& host);
    void setPort(const quint16 port);
    void setClientId(const QString& clientId);
    void setUsername(const QString& username);
    void setPassword(const QString& password);
    void setKeepAlive(const int keepAlive);
    void setCleanSession(const bool cleansess);
    void setAutoReconnect(const bool value);
    void setAutoReconnectInterval(const int autoReconnectInterval);
    void setWillTopic(const QString& willTopic);
    void setWillQos(const quint8 willQos);
    void setWillRetain(const bool willRetain);
    void setWillMessage(const QString& willMessage);

    void connectToHost();
    void disconnectFromHost();

    quint16 subscribe(const QString& topic, const quint8 qos);
    void unsubscribe(const QString& topic);

    quint16 publish(const Message& message);

Signals
=======

    void connected();
    void disconnected();
    void error(const QMQTT::ClientError error);

    void subscribed(const QString& topic, const quint8 qos);
    void unsubscribed(const QString& topic);
    void published(const quint16 msgid, const quint8 qos);
    void pingresp();
    void received(const QMQTT::Message& message);


License
=======

New BSD License


Contributors
=============

[@Kampfgnom](https://github.com/Kampfgnom)

[@rafaeldelucena](https://github.com/rafaeldelucena)

[@Vortex375](https://github.com/Vortex375)

[@mwallnoefer](https://github.com/mwallnoefer)

[@KonstantinRitt](https://github.com/KonstantinRitt)

[@cncap](https://github.com/cncap)

[@Psy-Kai](https://github.com/Psy-Kai)

[@ejvr](https://github.com/ejvr)

[@keytee](https://github.com/keytee)


Authors
=======

[@emqplus](https://github.com/emqplus) Feng Lee <feng@emqtt.io>

[@wguynes](https://github.com/wguynes) William Guynes <wguynes@gmail.com>

[@wuming123057](https://github.com/wuming123057) Xuan <huacai123057@163.com>
