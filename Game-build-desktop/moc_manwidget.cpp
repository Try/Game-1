/****************************************************************************
** Meta object code from reading C++ file 'manwidget.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/manwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManWidget[] = {

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
      11,   10,   10,   10, 0x0a,
      28,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ManWidget[] = {
    "ManWidget\0\0updateEvent(int)\0"
    "showHelp(QListWidgetItem*)\0"
};

const QMetaObject ManWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ManWidget,
      qt_meta_data_ManWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManWidget))
        return static_cast<void*>(const_cast< ManWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ManWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: showHelp((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
