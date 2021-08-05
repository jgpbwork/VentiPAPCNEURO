/****************************************************************************
** Meta object code from reading C++ file 'optioncalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optioncalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optioncalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionCalibration_t {
    QByteArrayData data[14];
    char stringdata0[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionCalibration_t qt_meta_stringdata_OptionCalibration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "OptionCalibration"
QT_MOC_LITERAL(1, 18, 7), // "closing"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "minCalibrationEnded"
QT_MOC_LITERAL(4, 47, 19), // "maxCalibrationEnded"
QT_MOC_LITERAL(5, 67, 29), // "on_l_calibration_back_clicked"
QT_MOC_LITERAL(6, 97, 37), // "on_l_calibration_state_button..."
QT_MOC_LITERAL(7, 135, 41), // "on_l_calibration_state_button..."
QT_MOC_LITERAL(8, 177, 44), // "on_l_calibration_state_button..."
QT_MOC_LITERAL(9, 222, 18), // "initMaxCalibration"
QT_MOC_LITERAL(10, 241, 18), // "initMinCalibration"
QT_MOC_LITERAL(11, 260, 25), // "incProgressMinCalibration"
QT_MOC_LITERAL(12, 286, 25), // "incProgressMaxCalibration"
QT_MOC_LITERAL(13, 312, 17) // "navigateNextState"

    },
    "OptionCalibration\0closing\0\0"
    "minCalibrationEnded\0maxCalibrationEnded\0"
    "on_l_calibration_back_clicked\0"
    "on_l_calibration_state_button_clicked\0"
    "on_l_calibration_state_button_out_clicked\0"
    "on_l_calibration_state_button_repeat_clicked\0"
    "initMaxCalibration\0initMinCalibration\0"
    "incProgressMinCalibration\0"
    "incProgressMaxCalibration\0navigateNextState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionCalibration[] = {

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
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionCalibration *_t = static_cast<OptionCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closing(); break;
        case 1: _t->minCalibrationEnded(); break;
        case 2: _t->maxCalibrationEnded(); break;
        case 3: _t->on_l_calibration_back_clicked(); break;
        case 4: _t->on_l_calibration_state_button_clicked(); break;
        case 5: _t->on_l_calibration_state_button_out_clicked(); break;
        case 6: _t->on_l_calibration_state_button_repeat_clicked(); break;
        case 7: _t->initMaxCalibration(); break;
        case 8: _t->initMinCalibration(); break;
        case 9: _t->incProgressMinCalibration(); break;
        case 10: _t->incProgressMaxCalibration(); break;
        case 11: _t->navigateNextState(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionCalibration::closing)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OptionCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionCalibration::minCalibrationEnded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (OptionCalibration::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionCalibration::maxCalibrationEnded)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OptionCalibration::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionCalibration.data,
      qt_meta_data_OptionCalibration,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionCalibration.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OptionCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OptionCalibration::closing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OptionCalibration::minCalibrationEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void OptionCalibration::maxCalibrationEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
