/****************************************************************************
** Meta object code from reading C++ file 'mylabelanimated.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mylabelanimated.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mylabelanimated.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyLabelAnimated_t {
    QByteArrayData data[13];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabelAnimated_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabelAnimated_t qt_meta_stringdata_MyLabelAnimated = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MyLabelAnimated"
QT_MOC_LITERAL(1, 16, 18), // "doubleClickedLabel"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "mouseLeftClicked"
QT_MOC_LITERAL(4, 53, 7), // "pressed"
QT_MOC_LITERAL(5, 61, 7), // "clicked"
QT_MOC_LITERAL(6, 69, 9), // "send_text"
QT_MOC_LITERAL(7, 79, 12), // "mouseEntered"
QT_MOC_LITERAL(8, 92, 10), // "hideChilds"
QT_MOC_LITERAL(9, 103, 15), // "setAnimationEnd"
QT_MOC_LITERAL(10, 119, 19), // "finalizadaAnimacion"
QT_MOC_LITERAL(11, 139, 11), // "setFotoInit"
QT_MOC_LITERAL(12, 151, 13) // "emitirClicked"

    },
    "MyLabelAnimated\0doubleClickedLabel\0\0"
    "mouseLeftClicked\0pressed\0clicked\0"
    "send_text\0mouseEntered\0hideChilds\0"
    "setAnimationEnd\0finalizadaAnimacion\0"
    "setFotoInit\0emitirClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabelAnimated[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       4,    0,   73,    2, 0x06 /* Public */,
       5,    0,   74,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    1,   84,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QPoint,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void MyLabelAnimated::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLabelAnimated *_t = static_cast<MyLabelAnimated *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedLabel(); break;
        case 1: _t->mouseLeftClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->pressed(); break;
        case 3: _t->clicked(); break;
        case 4: _t->send_text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->mouseEntered((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->hideChilds(); break;
        case 7: _t->setAnimationEnd(); break;
        case 8: _t->finalizadaAnimacion(); break;
        case 9: _t->setFotoInit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->emitirClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::doubleClickedLabel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyLabelAnimated::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::mouseLeftClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::pressed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyLabelAnimated::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::clicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyLabelAnimated::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::send_text)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MyLabelAnimated::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyLabelAnimated::mouseEntered)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyLabelAnimated::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabelAnimated.data,
      qt_meta_data_MyLabelAnimated,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyLabelAnimated::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabelAnimated::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabelAnimated.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int MyLabelAnimated::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void MyLabelAnimated::doubleClickedLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyLabelAnimated::mouseLeftClicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyLabelAnimated::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyLabelAnimated::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyLabelAnimated::send_text(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyLabelAnimated::mouseEntered(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
