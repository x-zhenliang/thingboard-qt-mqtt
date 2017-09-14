QT += core network
QT -= gui

TARGET = thingsboardGateWay
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mqtt/qmqtt_client.cpp \
    mqtt/qmqtt_client_p.cpp \
    mqtt/qmqtt_frame.cpp \
    mqtt/qmqtt_message.cpp \
    mqtt/qmqtt_message_p.cpp \
    mqtt/qmqtt_network.cpp \
    mqtt/qmqtt_routedmessage.cpp \
    mqtt/qmqtt_router.cpp \
    mqtt/qmqtt_routesubscription.cpp \
    mqtt/qmqtt_socket.cpp \
    mqtt/qmqtt_ssl_socket.cpp \
    mqtt/qmqtt_timer.cpp \
    nthingboard.cpp \
    mqttbroker.cpp \
    nmqttmessagebuild.cpp \
    ftpdownload/ftpclient.cpp \
    tcptrans/tcpclient.cpp \
    tcptrans/tcpserver.cpp \
    udptrans/udptrans.cpp

HEADERS += \
    mqtt/qmqtt.h \
    mqtt/qmqtt_client.h \
    mqtt/qmqtt_client_p.h \
    mqtt/qmqtt_frame.h \
    mqtt/qmqtt_global.h \
    mqtt/qmqtt_message.h \
    mqtt/qmqtt_message_p.h \
    mqtt/qmqtt_network_p.h \
    mqtt/qmqtt_networkinterface.h \
    mqtt/qmqtt_routedmessage.h \
    mqtt/qmqtt_router.h \
    mqtt/qmqtt_routesubscription.h \
    mqtt/qmqtt_socket_p.h \
    mqtt/qmqtt_socketinterface.h \
    mqtt/qmqtt_ssl_socket_p.h \
    mqtt/qmqtt_timer_p.h \
    mqtt/qmqtt_timerinterface.h \
    nthingboard.h \
    mqttbroker.h \
    mqtt/mqtttopic.h \
    nmqttmessagebuild.h \
    ftpdownload/ftpclient.h \
    tcptrans/tcpclient.h \
    tcptrans/tcpserver.h \
    udptrans/udptrans.h

