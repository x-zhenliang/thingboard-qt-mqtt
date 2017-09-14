/****************************************************************************
** Meta object code from reading C++ file 'ftpdownload.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../thingsboardGateWay/ftpdownload/ftpdownload.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpdownload.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FtpDownLoad_t {
    QByteArrayData data[16];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FtpDownLoad_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FtpDownLoad_t qt_meta_stringdata_FtpDownLoad = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FtpDownLoad"
QT_MOC_LITERAL(1, 12, 19), // "signalReplyFinished"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "num"
QT_MOC_LITERAL(4, 37, 14), // "signalFileName"
QT_MOC_LITERAL(5, 52, 4), // "name"
QT_MOC_LITERAL(6, 57, 22), // "signalDownloadProgress"
QT_MOC_LITERAL(7, 80, 1), // "o"
QT_MOC_LITERAL(8, 82, 1), // "c"
QT_MOC_LITERAL(9, 84, 17), // "slotReplyFinished"
QT_MOC_LITERAL(10, 102, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 117, 5), // "reply"
QT_MOC_LITERAL(12, 123, 13), // "slotReadyRead"
QT_MOC_LITERAL(13, 137, 25), // "slotAuthenticationRequest"
QT_MOC_LITERAL(14, 163, 15), // "QAuthenticator*"
QT_MOC_LITERAL(15, 179, 13) // "authenticator"

    },
    "FtpDownLoad\0signalReplyFinished\0\0num\0"
    "signalFileName\0name\0signalDownloadProgress\0"
    "o\0c\0slotReplyFinished\0QNetworkReply*\0"
    "reply\0slotReadyRead\0slotAuthenticationRequest\0"
    "QAuthenticator*\0authenticator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FtpDownLoad[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   55,    2, 0x08 /* Private */,
      12,    0,   58,    2, 0x08 /* Private */,
      13,    2,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 14,   11,   15,

       0        // eod
};

void FtpDownLoad::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FtpDownLoad *_t = static_cast<FtpDownLoad *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalReplyFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->slotReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->slotReadyRead(); break;
        case 5: _t->slotAuthenticationRequest((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FtpDownLoad::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpDownLoad::signalReplyFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FtpDownLoad::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpDownLoad::signalFileName)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FtpDownLoad::*_t)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FtpDownLoad::signalDownloadProgress)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FtpDownLoad::staticMetaObject = {
    { &QNetworkAccessManager::staticMetaObject, qt_meta_stringdata_FtpDownLoad.data,
      qt_meta_data_FtpDownLoad,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FtpDownLoad::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FtpDownLoad::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FtpDownLoad.stringdata0))
        return static_cast<void*>(const_cast< FtpDownLoad*>(this));
    return QNetworkAccessManager::qt_metacast(_clname);
}

int FtpDownLoad::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FtpDownLoad::signalReplyFinished(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FtpDownLoad::signalFileName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FtpDownLoad::signalDownloadProgress(qint64 _t1, qint64 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
