/****************************************************************************
** Meta object code from reading C++ file 'optionsetdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "optionsetdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsetdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OptionSetDate_t {
    QByteArrayData data[13];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionSetDate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionSetDate_t qt_meta_stringdata_OptionSetDate = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionSetDate"
QT_MOC_LITERAL(1, 14, 7), // "closing"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "dateSetted"
QT_MOC_LITERAL(4, 34, 22), // "on_pb_day_down_clicked"
QT_MOC_LITERAL(5, 57, 20), // "on_pb_day_up_clicked"
QT_MOC_LITERAL(6, 78, 24), // "on_pb_month_down_clicked"
QT_MOC_LITERAL(7, 103, 22), // "on_pb_month_up_clicked"
QT_MOC_LITERAL(8, 126, 23), // "on_pb_year_down_clicked"
QT_MOC_LITERAL(9, 150, 21), // "on_pb_year_up_clicked"
QT_MOC_LITERAL(10, 172, 17), // "on_l_save_clicked"
QT_MOC_LITERAL(11, 190, 29), // "on_l_define_date_back_clicked"
QT_MOC_LITERAL(12, 220, 14) // "updateDateInfo"

    },
    "OptionSetDate\0closing\0\0dateSetted\0"
    "on_pb_day_down_clicked\0on_pb_day_up_clicked\0"
    "on_pb_month_down_clicked\0"
    "on_pb_month_up_clicked\0on_pb_year_down_clicked\0"
    "on_pb_year_up_clicked\0on_l_save_clicked\0"
    "on_l_define_date_back_clicked\0"
    "updateDateInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionSetDate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   73,    2, 0x08 /* Private */,
       5,    0,   74,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    2,

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

void OptionSetDate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionSetDate *_t = static_cast<OptionSetDate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closing(); break;
        case 1: _t->dateSetted((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 2: _t->on_pb_day_down_clicked(); break;
        case 3: _t->on_pb_day_up_clicked(); break;
        case 4: _t->on_pb_month_down_clicked(); break;
        case 5: _t->on_pb_month_up_clicked(); break;
        case 6: _t->on_pb_year_down_clicked(); break;
        case 7: _t->on_pb_year_up_clicked(); break;
        case 8: _t->on_l_save_clicked(); break;
        case 9: _t->on_l_define_date_back_clicked(); break;
        case 10: _t->updateDateInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OptionSetDate::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionSetDate::closing)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (OptionSetDate::*)(QDateTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OptionSetDate::dateSetted)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OptionSetDate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionSetDate.data,
      qt_meta_data_OptionSetDate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OptionSetDate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionSetDate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionSetDate.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OptionSetDate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void OptionSetDate::closing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void OptionSetDate::dateSetted(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
