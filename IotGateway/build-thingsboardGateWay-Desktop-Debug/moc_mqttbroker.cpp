/****************************************************************************
** Meta object code from reading C++ file 'mqttbroker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/mqttbroker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mqttbroker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MqttBroker_t {
    QByteArrayData data[29];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MqttBroker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MqttBroker_t qt_meta_stringdata_MqttBroker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MqttBroker"
QT_MOC_LITERAL(1, 11, 23), // "signalAttributesChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "device"
QT_MOC_LITERAL(4, 43, 4), // "data"
QT_MOC_LITERAL(5, 48, 24), // "signalAttributesResponse"
QT_MOC_LITERAL(6, 73, 2), // "id"
QT_MOC_LITERAL(7, 76, 13), // "signalRpcCall"
QT_MOC_LITERAL(8, 90, 6), // "method"
QT_MOC_LITERAL(9, 97, 6), // "params"
QT_MOC_LITERAL(10, 104, 23), // "signalConnectIotGateway"
QT_MOC_LITERAL(11, 128, 29), // "slotPublishDeviceDisconnected"
QT_MOC_LITERAL(12, 158, 21), // "slotRequestAttributes"
QT_MOC_LITERAL(13, 180, 6), // "client"
QT_MOC_LITERAL(14, 187, 3), // "key"
QT_MOC_LITERAL(15, 191, 15), // "slotResponseRPC"
QT_MOC_LITERAL(16, 207, 5), // "value"
QT_MOC_LITERAL(17, 213, 17), // "slotBrokerConnect"
QT_MOC_LITERAL(18, 231, 20), // "slotBrokerDisConnect"
QT_MOC_LITERAL(19, 252, 15), // "slotBrokerError"
QT_MOC_LITERAL(20, 268, 18), // "QMQTT::ClientError"
QT_MOC_LITERAL(21, 287, 5), // "error"
QT_MOC_LITERAL(22, 293, 20), // "slotBrokerSubscribed"
QT_MOC_LITERAL(23, 314, 5), // "topic"
QT_MOC_LITERAL(24, 320, 22), // "slotBrokerUnSubscribed"
QT_MOC_LITERAL(25, 343, 18), // "slotBrokerReceived"
QT_MOC_LITERAL(26, 362, 14), // "QMQTT::Message"
QT_MOC_LITERAL(27, 377, 7), // "message"
QT_MOC_LITERAL(28, 385, 19) // "slotBrokerPublished"

    },
    "MqttBroker\0signalAttributesChanged\0\0"
    "device\0data\0signalAttributesResponse\0"
    "id\0signalRpcCall\0method\0params\0"
    "signalConnectIotGateway\0"
    "slotPublishDeviceDisconnected\0"
    "slotRequestAttributes\0client\0key\0"
    "slotResponseRPC\0value\0slotBrokerConnect\0"
    "slotBrokerDisConnect\0slotBrokerError\0"
    "QMQTT::ClientError\0error\0slotBrokerSubscribed\0"
    "topic\0slotBrokerUnSubscribed\0"
    "slotBrokerReceived\0QMQTT::Message\0"
    "message\0slotBrokerPublished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MqttBroker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    3,   89,    2, 0x06 /* Public */,
       7,    4,   96,    2, 0x06 /* Public */,
      10,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  108,    2, 0x0a /* Public */,
      12,    4,  111,    2, 0x0a /* Public */,
      15,    3,  120,    2, 0x0a /* Public */,
      17,    0,  127,    2, 0x09 /* Protected */,
      18,    0,  128,    2, 0x09 /* Protected */,
      19,    1,  129,    2, 0x09 /* Protected */,
      22,    1,  132,    2, 0x09 /* Protected */,
      24,    1,  135,    2, 0x09 /* Protected */,
      25,    1,  138,    2, 0x09 /* Protected */,
      28,    1,  141,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonObject,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QVariant,    6,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QJsonObject,    6,    3,    8,    9,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    6,    3,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QJsonObject,    6,    3,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 26,   27,

       0        // eod
};

void MqttBroker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MqttBroker *_t = static_cast<MqttBroker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAttributesChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonObject(*)>(_a[2]))); break;
        case 1: _t->signalAttributesResponse((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 2: _t->signalRpcCall((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QJsonObject(*)>(_a[4]))); break;
        case 3: _t->signalConnectIotGateway((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->slotPublishDeviceDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->slotRequestAttributes((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 6: _t->slotResponseRPC((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3]))); break;
        case 7: _t->slotBrokerConnect(); break;
        case 8: _t->slotBrokerDisConnect(); break;
        case 9: _t->slotBrokerError((*reinterpret_cast< const QMQTT::ClientError(*)>(_a[1]))); break;
        case 10: _t->slotBrokerSubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->slotBrokerUnSubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->slotBrokerReceived((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        case 13: _t->slotBrokerPublished((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::ClientError >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MqttBroker::*_t)(const QString & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MqttBroker::signalAttributesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MqttBroker::*_t)(const int , const QString & , const QVariant & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MqttBroker::signalAttributesResponse)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MqttBroker::*_t)(const int , const QString & , const QString & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MqttBroker::signalRpcCall)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MqttBroker::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MqttBroker::signalConnectIotGateway)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MqttBroker::staticMetaObject = {
    { &QMQTT::Client::staticMetaObject, qt_meta_stringdata_MqttBroker.data,
      qt_meta_data_MqttBroker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MqttBroker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MqttBroker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MqttBroker.stringdata0))
        return static_cast<void*>(const_cast< MqttBroker*>(this));
    return QMQTT::Client::qt_metacast(_clname);
}

int MqttBroker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMQTT::Client::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MqttBroker::signalAttributesChanged(const QString & _t1, const QJsonObject & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MqttBroker::signalAttributesResponse(const int _t1, const QString & _t2, const QVariant & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MqttBroker::signalRpcCall(const int _t1, const QString & _t2, const QString & _t3, const QJsonObject & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MqttBroker::signalConnectIotGateway(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_Publisher_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Publisher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Publisher_t qt_meta_stringdata_Publisher = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Publisher"
QT_MOC_LITERAL(1, 10, 11), // "onConnected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "onTimeout"
QT_MOC_LITERAL(4, 33, 14) // "onDisconnected"

    },
    "Publisher\0onConnected\0\0onTimeout\0"
    "onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Publisher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Publisher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Publisher *_t = static_cast<Publisher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onConnected(); break;
        case 1: _t->onTimeout(); break;
        case 2: _t->onDisconnected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Publisher::staticMetaObject = {
    { &QMQTT::Client::staticMetaObject, qt_meta_stringdata_Publisher.data,
      qt_meta_data_Publisher,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Publisher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Publisher::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Publisher.stringdata0))
        return static_cast<void*>(const_cast< Publisher*>(this));
    return QMQTT::Client::qt_metacast(_clname);
}

int Publisher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMQTT::Client::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
