/****************************************************************************
** Meta object code from reading C++ file 'nthingboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/nthingboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nthingboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NThingBoard_t {
    QByteArrayData data[10];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NThingBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NThingBoard_t qt_meta_stringdata_NThingBoard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NThingBoard"
QT_MOC_LITERAL(1, 12, 22), // "slotOnAttributeReceive"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "name"
QT_MOC_LITERAL(4, 41, 3), // "key"
QT_MOC_LITERAL(5, 45, 5), // "value"
QT_MOC_LITERAL(6, 51, 22), // "slotOnTelemetryReceive"
QT_MOC_LITERAL(7, 74, 4), // "time"
QT_MOC_LITERAL(8, 79, 23), // "slotSetupConnectedState"
QT_MOC_LITERAL(9, 103, 5) // "state"

    },
    "NThingBoard\0slotOnAttributeReceive\0\0"
    "name\0key\0value\0slotOnTelemetryReceive\0"
    "time\0slotSetupConnectedState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NThingBoard[] = {

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
       1,    3,   29,    2, 0x0a /* Public */,
       6,    4,   36,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QVariant,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::QString, QMetaType::QVariant,    3,    7,    4,    5,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void NThingBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NThingBoard *_t = static_cast<NThingBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotOnAttributeReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 1: _t->slotOnTelemetryReceive((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const qint64(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QVariant(*)>(_a[4]))); break;
        case 2: _t->slotSetupConnectedState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NThingBoard::staticMetaObject = {
    { &QCoreApplication::staticMetaObject, qt_meta_stringdata_NThingBoard.data,
      qt_meta_data_NThingBoard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NThingBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NThingBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NThingBoard.stringdata0))
        return static_cast<void*>(const_cast< NThingBoard*>(this));
    return QCoreApplication::qt_metacast(_clname);
}

int NThingBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCoreApplication::qt_metacall(_c, _id, _a);
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
