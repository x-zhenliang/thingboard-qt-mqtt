/****************************************************************************
** Meta object code from reading C++ file 'qmqtt_network_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/mqtt/qmqtt_network_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmqtt_network_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMQTT__Network_t {
    QByteArrayData data[13];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMQTT__Network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMQTT__Network_t qt_meta_stringdata_QMQTT__Network = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QMQTT::Network"
QT_MOC_LITERAL(1, 15, 13), // "connectToHost"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "QHostAddress"
QT_MOC_LITERAL(4, 43, 4), // "host"
QT_MOC_LITERAL(5, 48, 4), // "port"
QT_MOC_LITERAL(6, 53, 8), // "hostName"
QT_MOC_LITERAL(7, 62, 18), // "disconnectFromHost"
QT_MOC_LITERAL(8, 81, 13), // "onSocketError"
QT_MOC_LITERAL(9, 95, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(10, 124, 11), // "socketError"
QT_MOC_LITERAL(11, 136, 17), // "onSocketReadReady"
QT_MOC_LITERAL(12, 154, 14) // "onDisconnected"

    },
    "QMQTT::Network\0connectToHost\0\0"
    "QHostAddress\0host\0port\0hostName\0"
    "disconnectFromHost\0onSocketError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "onSocketReadReady\0onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMQTT__Network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       1,    2,   54,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x09 /* Protected */,
      11,    0,   63,    2, 0x09 /* Protected */,
      12,    0,   64,    2, 0x09 /* Protected */,
       1,    0,   65,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UShort,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    6,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QMQTT::Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Network *_t = static_cast<Network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectToHost((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 1: _t->connectToHost((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 2: _t->disconnectFromHost(); break;
        case 3: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->onSocketReadReady(); break;
        case 5: _t->onDisconnected(); break;
        case 6: _t->connectToHost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject QMQTT::Network::staticMetaObject = {
    { &NetworkInterface::staticMetaObject, qt_meta_stringdata_QMQTT__Network.data,
      qt_meta_data_QMQTT__Network,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMQTT::Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMQTT::Network::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMQTT__Network.stringdata0))
        return static_cast<void*>(const_cast< Network*>(this));
    return NetworkInterface::qt_metacast(_clname);
}

int QMQTT::Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NetworkInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
