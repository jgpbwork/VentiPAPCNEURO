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
    QByteArrayData data[18];
    char stringdata0[198];
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
QT_MOC_LITERAL(5, 42, 14), // "setOxygenValue"
QT_MOC_LITERAL(6, 57, 5), // "value"
QT_MOC_LITERAL(7, 63, 7), // "setDate"
QT_MOC_LITERAL(8, 71, 4), // "date"
QT_MOC_LITERAL(9, 76, 7), // "setTime"
QT_MOC_LITERAL(10, 84, 4), // "time"
QT_MOC_LITERAL(11, 89, 22), // "setBlockedDisplayValue"
QT_MOC_LITERAL(12, 112, 1), // "b"
QT_MOC_LITERAL(13, 114, 22), // "getBlockedDisplayValue"
QT_MOC_LITERAL(14, 137, 15), // "emitMenuClicked"
QT_MOC_LITERAL(15, 153, 14), // "hideWidgetMenu"
QT_MOC_LITERAL(16, 168, 14), // "showWidgetMenu"
QT_MOC_LITERAL(17, 183, 14) // "setAlarmLimits"

    },
    "MainScreen\0menu_clicked\0\0alarmOn\0"
    "alarmOff\0setOxygenValue\0value\0setDate\0"
    "date\0setTime\0time\0setBlockedDisplayValue\0"
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   77,    2, 0x0a /* Public */,
       7,    1,   80,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::QDate,    8,
    QMetaType::Void, QMetaType::QTime,   10,
    QMetaType::Void, QMetaType::Bool,   12,
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
        case 3: _t->setOxygenValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setDate((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 5: _t->setTime((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 6: _t->setBlockedDisplayValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { bool _r = _t->getBlockedDisplayValue();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->emitMenuClicked(); break;
        case 9: _t->hideWidgetMenu(); break;
        case 10: _t->showWidgetMenu(); break;
        case 11: _t->setAlarmLimits(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
