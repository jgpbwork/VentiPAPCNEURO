/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainScreen_t {
    QByteArrayData data[20];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainScreen_t qt_meta_stringdata_MainScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainScreen"
QT_MOC_LITERAL(1, 11, 12), // "menu_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "alarmOn"
QT_MOC_LITERAL(4, 33, 8), // "alarmOff"
QT_MOC_LITERAL(5, 42, 9), // "alarmType"
QT_MOC_LITERAL(6, 52, 23), // "ThrAlarm::AlarmPriority"
QT_MOC_LITERAL(7, 76, 14), // "setOxygenValue"
QT_MOC_LITERAL(8, 91, 5), // "value"
QT_MOC_LITERAL(9, 97, 7), // "setDate"
QT_MOC_LITERAL(10, 105, 4), // "date"
QT_MOC_LITERAL(11, 110, 7), // "setTime"
QT_MOC_LITERAL(12, 118, 4), // "time"
QT_MOC_LITERAL(13, 123, 22), // "setBlockedDisplayValue"
QT_MOC_LITERAL(14, 146, 1), // "b"
QT_MOC_LITERAL(15, 148, 22), // "getBlockedDisplayValue"
QT_MOC_LITERAL(16, 171, 15), // "emitMenuClicked"
QT_MOC_LITERAL(17, 187, 14), // "hideWidgetMenu"
QT_MOC_LITERAL(18, 202, 14), // "showWidgetMenu"
QT_MOC_LITERAL(19, 217, 14) // "setAlarmLimits"

    },
    "MainScreen\0menu_clicked\0\0alarmOn\0"
    "alarmOff\0alarmType\0ThrAlarm::AlarmPriority\0"
    "setOxygenValue\0value\0setDate\0date\0"
    "setTime\0time\0setBlockedDisplayValue\0"
    "b\0getBlockedDisplayValue\0emitMenuClicked\0"
    "hideWidgetMenu\0showWidgetMenu\0"
    "setAlarmLimits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   85,    2, 0x0a /* Public */,
       9,    1,   88,    2, 0x0a /* Public */,
      11,    1,   91,    2, 0x0a /* Public */,
      13,    1,   94,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    0,  100,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QDate,   10,
    QMetaType::Void, QMetaType::QTime,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainScreen *_t = static_cast<MainScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->menu_clicked(); break;
        case 1: _t->alarmOn(); break;
        case 2: _t->alarmOff(); break;
        case 3: _t->alarmType((*reinterpret_cast< ThrAlarm::AlarmPriority(*)>(_a[1]))); break;
        case 4: _t->setOxygenValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 6: _t->setTime((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 7: _t->setBlockedDisplayValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: { bool _r = _t->getBlockedDisplayValue();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->emitMenuClicked(); break;
        case 10: _t->hideWidgetMenu(); break;
        case 11: _t->showWidgetMenu(); break;
        case 12: _t->setAlarmLimits(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::menu_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::alarmOn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainScreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::alarmOff)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainScreen::*)(ThrAlarm::AlarmPriority );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainScreen::alarmType)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainScreen.data,
      qt_meta_data_MainScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainScreen::menu_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainScreen::alarmOn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainScreen::alarmOff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainScreen::alarmType(ThrAlarm::AlarmPriority _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
