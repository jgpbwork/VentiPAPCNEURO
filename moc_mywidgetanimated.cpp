/****************************************************************************
** Meta object code from reading C++ file 'mywidgetanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywidgetanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidgetanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyWidgetAnimated_t {
    QByteArrayData data[20];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyWidgetAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyWidgetAnimated_t qt_meta_stringdata_MyWidgetAnimated = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MyWidgetAnimated"
QT_MOC_LITERAL(1, 17, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "mouseRightClicked"
QT_MOC_LITERAL(4, 55, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(5, 72, 7), // "clicked"
QT_MOC_LITERAL(6, 80, 7), // "hideAll"
QT_MOC_LITERAL(7, 88, 12), // "mouseEntered"
QT_MOC_LITERAL(8, 101, 17), // "showWithAnimation"
QT_MOC_LITERAL(9, 119, 8), // "hideMenu"
QT_MOC_LITERAL(10, 128, 13), // "focusOutEvent"
QT_MOC_LITERAL(11, 142, 12), // "QFocusEvent*"
QT_MOC_LITERAL(12, 155, 5), // "event"
QT_MOC_LITERAL(13, 161, 12), // "focusInEvent"
QT_MOC_LITERAL(14, 174, 15), // "setAnimationEnd"
QT_MOC_LITERAL(15, 190, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(16, 210, 12), // "resizeWidget"
QT_MOC_LITERAL(17, 223, 9), // "setOnIcon"
QT_MOC_LITERAL(18, 233, 22), // "finalizadaAnimacionEnd"
QT_MOC_LITERAL(19, 256, 11) // "setSizeInit"

    },
    "MyWidgetAnimated\0doubleClickedLabel\0"
    "\0mouseRightClicked\0mouseLeftClicked\0"
    "clicked\0hideAll\0mouseEntered\0"
    "showWithAnimation\0hideMenu\0focusOutEvent\0"
    "QFocusEvent*\0event\0focusInEvent\0"
    "setAnimationEnd\0finalizadaAnimacion\0"
    "resizeWidget\0setOnIcon\0finalizadaAnimacionEnd\0"
    "setSizeInit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWidgetAnimated[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  102,    2, 0x0a /* Public */,
       9,    0,  103,    2, 0x0a /* Public */,
      10,    1,  104,    2, 0x09 /* Protected */,
      13,    1,  107,    2, 0x09 /* Protected */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyWidgetAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyWidgetAnimated *_t = static_cast<MyWidgetAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseRightClicked(); break;
        case 2: _t->mouseLeftClicked(); break;
        case 3: _t->clicked(); break;
        case 4: _t->hideAll(); break;
        case 5: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->showWithAnimation(); break;
        case 7: _t->hideMenu(); break;
        case 8: _t->focusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 9: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 10: _t->setAnimationEnd(); break;
        case 11: _t->finalizadaAnimacion(); break;
        case 12: _t->resizeWidget(); break;
        case 13: _t->setOnIcon(); break;
        case 14: _t->finalizadaAnimacionEnd(); break;
        case 15: _t->setSizeInit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyWidgetAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyWidgetAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::mouseRightClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyWidgetAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::mouseLeftClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyWidgetAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyWidgetAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::hideAll)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyWidgetAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyWidgetAnimated::mouseEntered)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyWidgetAnimated::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidgetAnimated.data,
      qt_meta_data_MyWidgetAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyWidgetAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWidgetAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidgetAnimated.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyWidgetAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MyWidgetAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyWidgetAnimated::mouseRightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyWidgetAnimated::mouseLeftClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyWidgetAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyWidgetAnimated::hideAll()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MyWidgetAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
