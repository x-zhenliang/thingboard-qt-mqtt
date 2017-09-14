/****************************************************************************
** Meta object code from reading C++ file 'qmqtt_networkinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/mqtt/qmqtt_networkinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmqtt_networkinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMQTT__NetworkInterface_t {
    QByteArrayData data[15];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMQTT__NetworkInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMQTT__NetworkInterface_t qt_meta_stringdata_QMQTT__NetworkInterface = {
    {
QT_MOC_LITERAL(0, 0, 23), // "QMQTT::NetworkInterface"
QT_MOC_LITERAL(1, 24, 9), // "connected"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 12), // "disconnected"
QT_MOC_LITERAL(4, 48, 8), // "received"
QT_MOC_LITERAL(5, 57, 12), // "QMQTT::Frame"
QT_MOC_LITERAL(6, 70, 5), // "frame"
QT_MOC_LITERAL(7, 76, 5), // "error"
QT_MOC_LITERAL(8, 82, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 111, 13), // "connectToHost"
QT_MOC_LITERAL(10, 125, 12), // "QHostAddress"
QT_MOC_LITERAL(11, 138, 4), // "host"
QT_MOC_LITERAL(12, 143, 4), // "port"
QT_MOC_LITERAL(13, 148, 8), // "hostName"
QT_MOC_LITERAL(14, 157, 18) // "disconnectFromHost"

    },
    "QMQTT::NetworkInterface\0connected\0\0"
    "disconnected\0received\0QMQTT::Frame\0"
    "frame\0error\0QAbstractSocket::SocketError\0"
    "connectToHost\0QHostAddress\0host\0port\0"
    "hostName\0disconnectFromHost"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMQTT__NetworkInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       7,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   57,    2, 0x0a /* Public */,
       9,    2,   62,    2, 0x0a /* Public */,
      14,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, QMetaType::UShort,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   13,   12,
    QMetaType::Void,

       0        // eod
};

void QMQTT::NetworkInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkInterface *_t = static_cast<NetworkInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->received((*reinterpret_cast< const QMQTT::Frame(*)>(_a[1]))); break;
        case 3: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->connectToHost((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 5: _t->connectToHost((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 6: _t->disconnectFromHost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Frame >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkInterface::connected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (NetworkInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkInterface::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (NetworkInterface::*_t)(const QMQTT::Frame & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkInterface::received)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (NetworkInterface::*_t)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkInterface::error)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject QMQTT::NetworkInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QMQTT__NetworkInterface.data,
      qt_meta_data_QMQTT__NetworkInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMQTT::NetworkInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMQTT::NetworkInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMQTT__NetworkInterface.stringdata0))
        return static_cast<void*>(const_cast< NetworkInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int QMQTT::NetworkInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QMQTT::NetworkInterface::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QMQTT::NetworkInterface::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QMQTT::NetworkInterface::received(const QMQTT::Frame & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMQTT::NetworkInterface::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
