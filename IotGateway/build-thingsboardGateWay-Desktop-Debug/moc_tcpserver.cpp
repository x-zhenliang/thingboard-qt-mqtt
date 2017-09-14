/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/tcptrans/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerTcp_t {
    QByteArrayData data[11];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerTcp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerTcp_t qt_meta_stringdata_ServerTcp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ServerTcp"
QT_MOC_LITERAL(1, 10, 16), // "AcceptConnection"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "UpdateServerProgress"
QT_MOC_LITERAL(4, 49, 12), // "DisplayError"
QT_MOC_LITERAL(5, 62, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(6, 91, 11), // "socketError"
QT_MOC_LITERAL(7, 103, 20), // "UpdateClientProgress"
QT_MOC_LITERAL(8, 124, 8), // "numBytes"
QT_MOC_LITERAL(9, 133, 14), // "SendFileHeader"
QT_MOC_LITERAL(10, 148, 8) // "fileName"

    },
    "ServerTcp\0AcceptConnection\0\0"
    "UpdateServerProgress\0DisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "UpdateClientProgress\0numBytes\0"
    "SendFileHeader\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerTcp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    1,   44,    2, 0x08 /* Private */,
       9,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void ServerTcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerTcp *_t = static_cast<ServerTcp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AcceptConnection(); break;
        case 1: _t->UpdateServerProgress(); break;
        case 2: _t->DisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: _t->UpdateClientProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->SendFileHeader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject ServerTcp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerTcp.data,
      qt_meta_data_ServerTcp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerTcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerTcp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerTcp.stringdata0))
        return static_cast<void*>(const_cast< ServerTcp*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerTcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
