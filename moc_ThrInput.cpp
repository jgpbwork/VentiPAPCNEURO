/****************************************************************************
** Meta object code from reading C++ file 'ThrInput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ThrInput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThrInput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThrInput_t {
    QByteArrayData data[17];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThrInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThrInput_t qt_meta_stringdata_ThrInput = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ThrInput"
QT_MOC_LITERAL(1, 9, 17), // "updateOxygenLevel"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "updateBatteryLevel"
QT_MOC_LITERAL(4, 47, 19), // "updateRealTimeClock"
QT_MOC_LITERAL(5, 67, 7), // "inRange"
QT_MOC_LITERAL(6, 75, 10), // "outOfRange"
QT_MOC_LITERAL(7, 86, 14), // "updateReadings"
QT_MOC_LITERAL(8, 101, 12), // "std::float_t"
QT_MOC_LITERAL(9, 114, 9), // "oxygenVal"
QT_MOC_LITERAL(10, 124, 7), // "battVal"
QT_MOC_LITERAL(11, 132, 14), // "updateDateTime"
QT_MOC_LITERAL(12, 147, 10), // "QDateTime&"
QT_MOC_LITERAL(13, 158, 8), // "refValue"
QT_MOC_LITERAL(14, 167, 15), // "setMinimumValue"
QT_MOC_LITERAL(15, 183, 5), // "value"
QT_MOC_LITERAL(16, 189, 15) // "setMaximumValue"

    },
    "ThrInput\0updateOxygenLevel\0\0"
    "updateBatteryLevel\0updateRealTimeClock\0"
    "inRange\0outOfRange\0updateReadings\0"
    "std::float_t\0oxygenVal\0battVal\0"
    "updateDateTime\0QDateTime&\0refValue\0"
    "setMinimumValue\0value\0setMaximumValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThrInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   70,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      14,    1,   78,    2, 0x0a /* Public */,
      16,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDateTime,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void ThrInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThrInput *_t = static_cast<ThrInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateOxygenLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->updateBatteryLevel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateRealTimeClock((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 3: _t->inRange(); break;
        case 4: _t->outOfRange(); break;
        case 5: _t->updateReadings((*reinterpret_cast< std::float_t(*)>(_a[1])),(*reinterpret_cast< std::float_t(*)>(_a[2]))); break;
        case 6: _t->updateDateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 7: _t->setMinimumValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setMaximumValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ThrInput::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThrInput::updateOxygenLevel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThrInput::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThrInput::updateBatteryLevel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThrInput::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThrInput::updateRealTimeClock)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ThrInput::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThrInput::inRange)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ThrInput::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThrInput::outOfRange)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThrInput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThrInput.data,
      qt_meta_data_ThrInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThrInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThrInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThrInput.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<ThrInput>"))
        return static_cast< Singleton<ThrInput>*>(this);
    return QObject::qt_metacast(_clname);
}

int ThrInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ThrInput::updateOxygenLevel(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThrInput::updateBatteryLevel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThrInput::updateRealTimeClock(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThrInput::inRange()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ThrInput::outOfRange()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
