QT += core network
QT -= gui

TARGET = app
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


CONFIG(debug, debug|release) DEFINES += _DEBUG

INCLUDEPATH += /home/xiaoxie/thingsboard/ddsTest/include/qmqtt
DEPENDPATH += /home/xiaoxie/thingsboard/ddsTest/lib
LIBS += "-L/home/xiaoxie/thingsboard/ddsTest/lib" -lqmqtt
#LIBS += -lmqtt


SOURCES += main.cpp \
    daemonapplication.cpp \
    mqtt/mqtthandler.cpp \
    mqtt/mqttmessagebuilder.cpp \
    mqtt/abstractmqtttopicprocesser.cpp \

!win32 {
SOURCES += sigwatch.cpp
}

HEADERS += \
    daemonapplication.h \
    mqtt/mqtthandler.h \
    mqtt/mqtttopic.h \
    mqtt/mqttmessagebuilder.h \
    mqtt/abstractmqtttopicprocesser.h \

!win32 {
HEADERS += sigwatch.h
}
