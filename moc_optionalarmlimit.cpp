/****************************************************************************
** Meta object code from reading C++ file 'optionalarmlimit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionalarmlimit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionalarmlimit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionAlarmLimit_t {
    QByteArrayData data[8];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionAlarmLimit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionAlarmLimit_t qt_meta_stringdata_OptionAlarmLimit = {
    {
QT_MOC_LITERAL(0, 0, 16), // "OptionAlarmLimit"
QT_MOC_LITERAL(1, 17, 7), // "closing"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "on_l_save_clicked"
QT_MOC_LITERAL(4, 44, 26), // "on_pb_min_limit_up_clicked"
QT_MOC_LITERAL(5, 71, 28), // "on_pb_min_limit_down_clicked"
QT_MOC_LITERAL(6, 100, 26), // "on_pb_max_limit_up_clicked"
QT_MOC_LITERAL(7, 127, 28) // "on_pb_max_limit_down_clicked"

    },
    "OptionAlarmLimit\0closing\0\0on_l_save_clicked\0"
    "on_pb_min_limit_up_clicked\0"
    "on_pb_min_limit_down_clicked\0"
    "on_pb_max_limit_up_clicked\0"
    "on_pb_max_limit_down_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionAlarmLimit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionAlarmLimit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionAlarmLimit *_t = static_cast<OptionAlarmLimit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closing(); break;
        case 1: _t->on_l_save_clicked(); break;
        case 2: _t->on_pb_min_limit_up_clicked(); break;
        case 3: _t->on_pb_min_limit_down_clicked(); break;
        case 4: _t->on_pb_max_limit_up_clicked(); break;
        case 5: _t->on_pb_max_limit_down_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionAlarmLimit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionAlarmLimit::closing)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OptionAlarmLimit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionAlarmLimit.data,
      qt_meta_data_OptionAlarmLimit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionAlarmLimit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionAlarmLimit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionAlarmLimit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OptionAlarmLimit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void OptionAlarmLimit::closing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
