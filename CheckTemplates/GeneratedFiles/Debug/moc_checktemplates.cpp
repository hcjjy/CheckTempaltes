/****************************************************************************
** Meta object code from reading C++ file 'checktemplates.h'
**
** Created: Wed Dec 2 15:21:21 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../checktemplates.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checktemplates.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CheckTemplates[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      23,   15,   15,   15, 0x0a,
      32,   15,   15,   15, 0x0a,
      41,   15,   15,   15, 0x0a,
      64,   52,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CheckTemplates[] = {
    "CheckTemplates\0\0save()\0saveAs()\0"
    "cancel()\0showItem()\0item,column\0"
    "showItem(QTreeWidgetItem*,int)\0"
};

void CheckTemplates::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckTemplates *_t = static_cast<CheckTemplates *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->saveAs(); break;
        case 2: _t->cancel(); break;
        case 3: _t->showItem(); break;
        case 4: _t->showItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CheckTemplates::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckTemplates::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CheckTemplates,
      qt_meta_data_CheckTemplates, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckTemplates::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckTemplates::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckTemplates::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckTemplates))
        return static_cast<void*>(const_cast< CheckTemplates*>(this));
    return QDialog::qt_metacast(_clname);
}

int CheckTemplates::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
