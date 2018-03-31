/****************************************************************************
** Meta object code from reading C++ file 'cameraget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cameraGet/cameraget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cameraGet_t {
    QByteArrayData data[18];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cameraGet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cameraGet_t qt_meta_stringdata_cameraGet = {
    {
QT_MOC_LITERAL(0, 0, 9), // "cameraGet"
QT_MOC_LITERAL(1, 10, 10), // "opencamera"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "readFarme"
QT_MOC_LITERAL(4, 32, 11), // "closecamera"
QT_MOC_LITERAL(5, 44, 14), // "takingPictures"
QT_MOC_LITERAL(6, 59, 14), // "savingPictures"
QT_MOC_LITERAL(7, 74, 16), // "openningPictures"
QT_MOC_LITERAL(8, 91, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 113, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 137, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(11, 161, 33), // "on_verticalSlider_actionTrigg..."
QT_MOC_LITERAL(12, 195, 6), // "action"
QT_MOC_LITERAL(13, 202, 30), // "on_verticalSlider_rangeChanged"
QT_MOC_LITERAL(14, 233, 3), // "min"
QT_MOC_LITERAL(15, 237, 3), // "max"
QT_MOC_LITERAL(16, 241, 30), // "on_verticalSlider_valueChanged"
QT_MOC_LITERAL(17, 272, 5) // "value"

    },
    "cameraGet\0opencamera\0\0readFarme\0"
    "closecamera\0takingPictures\0savingPictures\0"
    "openningPictures\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_verticalSlider_actionTriggered\0"
    "action\0on_verticalSlider_rangeChanged\0"
    "min\0max\0on_verticalSlider_valueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cameraGet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      13,    2,   86,    2, 0x08 /* Private */,
      16,    1,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void cameraGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cameraGet *_t = static_cast<cameraGet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->opencamera(); break;
        case 1: _t->readFarme(); break;
        case 2: _t->closecamera(); break;
        case 3: _t->takingPictures(); break;
        case 4: _t->savingPictures(); break;
        case 5: _t->openningPictures(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject cameraGet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_cameraGet.data,
      qt_meta_data_cameraGet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cameraGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cameraGet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cameraGet.stringdata0))
        return static_cast<void*>(const_cast< cameraGet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int cameraGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
