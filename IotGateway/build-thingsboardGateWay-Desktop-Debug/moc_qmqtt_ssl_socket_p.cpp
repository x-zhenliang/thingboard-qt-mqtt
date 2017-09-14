/****************************************************************************
** Meta object code from reading C++ file 'qmqtt_ssl_socket_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/mqtt/qmqtt_ssl_socket_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmqtt_ssl_socket_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMQTT__SslSocket_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMQTT__SslSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMQTT__SslSocket_t qt_meta_stringdata_QMQTT__SslSocket = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QMQTT::SslSocket"
QT_MOC_LITERAL(1, 17, 9), // "sslErrors"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "QList<QSslError>"
QT_MOC_LITERAL(4, 45, 6) // "errors"

    },
    "QMQTT::SslSocket\0sslErrors\0\0"
    "QList<QSslError>\0errors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMQTT__SslSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void QMQTT::SslSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SslSocket *_t = static_cast<SslSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QMQTT::SslSocket::staticMetaObject = {
    { &SocketInterface::staticMetaObject, qt_meta_stringdata_QMQTT__SslSocket.data,
      qt_meta_data_QMQTT__SslSocket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMQTT::SslSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMQTT::SslSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMQTT__SslSocket.stringdata0))
        return static_cast<void*>(const_cast< SslSocket*>(this));
    return SocketInterface::qt_metacast(_clname);
}

int QMQTT::SslSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SocketInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
