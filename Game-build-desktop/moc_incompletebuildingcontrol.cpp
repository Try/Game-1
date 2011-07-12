/****************************************************************************
** Meta object code from reading C++ file 'incompletebuildingcontrol.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/game/control/incompletebuildingcontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'incompletebuildingcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IncompleteBuildingControl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x08,
      39,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IncompleteBuildingControl[] = {
    "IncompleteBuildingControl\0\0updateGui()\0"
    "canselBuild()\0"
};

const QMetaObject IncompleteBuildingControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IncompleteBuildingControl,
      qt_meta_data_IncompleteBuildingControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IncompleteBuildingControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IncompleteBuildingControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IncompleteBuildingControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IncompleteBuildingControl))
        return static_cast<void*>(const_cast< IncompleteBuildingControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int IncompleteBuildingControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateGui(); break;
        case 1: canselBuild(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
