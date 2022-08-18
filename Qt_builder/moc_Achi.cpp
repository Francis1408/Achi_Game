/****************************************************************************
** Meta object code from reading C++ file 'Achi.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Achi/Achi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Achi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Achi_t {
    const uint offsetsAndSize[32];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Achi_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Achi_t qt_meta_stringdata_Achi = {
    {
QT_MOC_LITERAL(0, 4), // "Achi"
QT_MOC_LITERAL(5, 8), // "gameOver"
QT_MOC_LITERAL(14, 0), // ""
QT_MOC_LITERAL(15, 6), // "Player"
QT_MOC_LITERAL(22, 6), // "player"
QT_MOC_LITERAL(29, 4), // "play"
QT_MOC_LITERAL(34, 2), // "id"
QT_MOC_LITERAL(37, 5), // "reset"
QT_MOC_LITERAL(43, 9), // "showAbout"
QT_MOC_LITERAL(53, 12), // "showGameOver"
QT_MOC_LITERAL(66, 15), // "updateStatusBar"
QT_MOC_LITERAL(82, 9), // "RedPlayer"
QT_MOC_LITERAL(92, 10), // "BluePlayer"
QT_MOC_LITERAL(103, 5), // "Phase"
QT_MOC_LITERAL(109, 9), // "DropPhase"
QT_MOC_LITERAL(119, 9) // "MovePhase"

    },
    "Achi\0gameOver\0\0Player\0player\0play\0id\0"
    "reset\0showAbout\0showGameOver\0"
    "updateStatusBar\0RedPlayer\0BluePlayer\0"
    "Phase\0DropPhase\0MovePhase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Achi[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       2,   62, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   53,    2, 0x08,    2 /* Private */,
       7,    0,   56,    2, 0x08,    4 /* Private */,
       8,    0,   57,    2, 0x08,    5 /* Private */,
       9,    1,   58,    2, 0x08,    6 /* Private */,
      10,    0,   61,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       3,    3, 0x0,    2,   72,
      13,   13, 0x0,    2,   76,

 // enum data: key, value
      11, uint(Achi::RedPlayer),
      12, uint(Achi::BluePlayer),
      14, uint(Achi::DropPhase),
      15, uint(Achi::MovePhase),

       0        // eod
};

void Achi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Achi *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gameOver((*reinterpret_cast< Player(*)>(_a[1]))); break;
        case 1: _t->play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->reset(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->showGameOver((*reinterpret_cast< Player(*)>(_a[1]))); break;
        case 5: _t->updateStatusBar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Achi::*)(Player );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achi::gameOver)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Achi::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Achi.offsetsAndSize,
    qt_meta_data_Achi,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Achi_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Player, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Player, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Achi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Achi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Achi.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Achi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Achi::gameOver(Player _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
