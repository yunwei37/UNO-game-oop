/****************************************************************************
** Meta object code from reading C++ file 'playerthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../backend/playerthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_playerThread_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_playerThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_playerThread_t qt_meta_stringdata_playerThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "playerThread"
QT_MOC_LITERAL(1, 13, 10), // "chooseDraw"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "choosePlay"
QT_MOC_LITERAL(4, 36, 6), // "cardID"
QT_MOC_LITERAL(5, 43, 11), // "Card::COLOR"
QT_MOC_LITERAL(6, 55, 5), // "color"
QT_MOC_LITERAL(7, 61, 9) // "chooseUno"

    },
    "playerThread\0chooseDraw\0\0choosePlay\0"
    "cardID\0Card::COLOR\0color\0chooseUno"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_playerThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    2,   30,    2, 0x06 /* Public */,
       7,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

void playerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<playerThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chooseDraw(); break;
        case 1: _t->choosePlay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Card::COLOR(*)>(_a[2]))); break;
        case 2: _t->chooseUno(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (playerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playerThread::chooseDraw)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (playerThread::*)(int , Card::COLOR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playerThread::choosePlay)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (playerThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playerThread::chooseUno)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject playerThread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_playerThread.data,
    qt_meta_data_playerThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *playerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *playerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_playerThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int playerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void playerThread::chooseDraw()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void playerThread::choosePlay(int _t1, Card::COLOR _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void playerThread::chooseUno()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
