/****************************************************************************
** Meta object code from reading C++ file 'unitctrl.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/game/control/unitctrl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unitctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UnitCtrl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      20,    9,    9,    9, 0x08,
      31,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UnitCtrl[] = {
    "UnitCtrl\0\0setMove()\0setAtack()\0"
    "stopMove()\0"
};

const QMetaObject UnitCtrl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UnitCtrl,
      qt_meta_data_UnitCtrl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UnitCtrl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UnitCtrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UnitCtrl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnitCtrl))
        return static_cast<void*>(const_cast< UnitCtrl*>(this));
    return QWidget::qt_metacast(_clname);
}

int UnitCtrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setMove(); break;
        case 1: setAtack(); break;
        case 2: stopMove(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
