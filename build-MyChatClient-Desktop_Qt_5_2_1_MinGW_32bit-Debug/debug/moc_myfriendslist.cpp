/****************************************************************************
** Meta object code from reading C++ file 'myfriendslist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyChatClient/myfriendslist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myfriendslist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myFriendsList_t {
    QByteArrayData data[8];
    char stringdata[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_myFriendsList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_myFriendsList_t qt_meta_stringdata_myFriendsList = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 12),
QT_MOC_LITERAL(5, 54, 12),
QT_MOC_LITERAL(6, 67, 10),
QT_MOC_LITERAL(7, 78, 19)
    },
    "myFriendsList\0slotAddGroup\0\0slotDelGroup\0"
    "slotAddBuddy\0slotDelBuddy\0slotRename\0"
    "slotRenameEditFshed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myFriendsList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a,
       3,    0,   45,    2, 0x0a,
       4,    0,   46,    2, 0x0a,
       5,    0,   47,    2, 0x0a,
       6,    0,   48,    2, 0x0a,
       7,    0,   49,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myFriendsList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myFriendsList *_t = static_cast<myFriendsList *>(_o);
        switch (_id) {
        case 0: _t->slotAddGroup(); break;
        case 1: _t->slotDelGroup(); break;
        case 2: _t->slotAddBuddy(); break;
        case 3: _t->slotDelBuddy(); break;
        case 4: _t->slotRename(); break;
        case 5: _t->slotRenameEditFshed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject myFriendsList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_myFriendsList.data,
      qt_meta_data_myFriendsList,  qt_static_metacall, 0, 0}
};


const QMetaObject *myFriendsList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myFriendsList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myFriendsList.stringdata))
        return static_cast<void*>(const_cast< myFriendsList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int myFriendsList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
