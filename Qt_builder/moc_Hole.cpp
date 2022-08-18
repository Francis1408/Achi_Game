/****************************************************************************
** Meta object code from reading C++ file 'Hole.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Achi/Hole.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Hole.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Hole_t {
    const uint offsetsAndSize[28];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Hole_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Hole_t qt_meta_stringdata_Hole = {
    {
QT_MOC_LITERAL(0, 4), // "Hole"
QT_MOC_LITERAL(5, 12), // "stateChanged"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "Hole::State"
QT_MOC_LITERAL(31, 5), // "state"
QT_MOC_LITERAL(37, 5), // "reset"
QT_MOC_LITERAL(43, 10), // "updateHole"
QT_MOC_LITERAL(54, 3), // "row"
QT_MOC_LITERAL(58, 3), // "col"
QT_MOC_LITERAL(62, 5), // "State"
QT_MOC_LITERAL(68, 5), // "Empty"
QT_MOC_LITERAL(74, 3), // "Red"
QT_MOC_LITERAL(78, 4), // "Blue"
QT_MOC_LITERAL(83, 10) // "Selectable"

    },
    "Hole\0stateChanged\0\0Hole::State\0state\0"
    "reset\0updateHole\0row\0col\0State\0Empty\0"
    "Red\0Blue\0Selectable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Hole[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   39, // properties
       1,   54, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   35,    2, 0x0a,    5 /* Public */,
       6,    1,   36,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00015103, uint(-1), 0,
       8, QMetaType::Int, 0x00015103, uint(-1), 0,
       4, 0x80000000 | 3, 0x0001510b, uint(0), 0,

 // enums: name, alias, flags, count, data
       9,    9, 0x0,    4,   59,

 // enum data: key, value
      10, uint(Hole::Empty),
      11, uint(Hole::Red),
      12, uint(Hole::Blue),
      13, uint(Hole::Selectable),

       0        // eod
};

void Hole::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Hole *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< Hole::State(*)>(_a[1]))); break;
        case 1: _t->reset(); break;
        case 2: _t->updateHole((*reinterpret_cast< Hole::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Hole::*)(Hole::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Hole::stateChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Hole *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->row(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->col(); break;
        case 2: *reinterpret_cast< Hole::State*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Hole *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRow(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCol(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setState(*reinterpret_cast< Hole::State*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Hole::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_Hole.offsetsAndSize,
    qt_meta_data_Hole,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Hole_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<Hole::State, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole::State, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole::State, std::false_type>


>,
    nullptr
} };


const QMetaObject *Hole::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Hole::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Hole.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int Hole::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Hole::stateChanged(Hole::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
