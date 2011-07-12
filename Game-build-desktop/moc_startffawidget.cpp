/****************************************************************************
** Meta object code from reading C++ file 'startffawidget.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/widgets/startffawidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startffawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StartFFAWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      42,   29,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   15,   15,   15, 0x08,
     115,   15,   15,   15, 0x08,
     131,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StartFFAWidget[] = {
    "StartFFAWidget\0\0backToMenu()\0mapfile,info\0"
    "startGame(QString,std::vector<StartFFAWidget::PlInfo>&)\0"
    "backToMenuSlot()\0startGameSlot()\0"
    "updateDir()\0"
};

const QMetaObject StartFFAWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StartFFAWidget,
      qt_meta_data_StartFFAWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StartFFAWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StartFFAWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StartFFAWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StartFFAWidget))
        return static_cast<void*>(const_cast< StartFFAWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int StartFFAWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: backToMenu(); break;
        case 1: startGame((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::vector<StartFFAWidget::PlInfo>(*)>(_a[2]))); break;
        case 2: backToMenuSlot(); break;
        case 3: startGameSlot(); break;
        case 4: updateDir(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void StartFFAWidget::backToMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void StartFFAWidget::startGame(QString _t1, std::vector<StartFFAWidget::PlInfo> & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
