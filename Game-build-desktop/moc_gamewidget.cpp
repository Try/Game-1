/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/widgets/gamewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      23,   11,   11,   11, 0x0a,
      41,   37,   11,   11, 0x0a,
      67,   11,   11,   11, 0x0a,
      85,   11,   11,   11, 0x0a,
      98,   11,   11,   11, 0x0a,
     109,   11,   11,   11, 0x0a,
     128,  120,   11,   11, 0x0a,
     154,  151,   11,   11, 0x0a,
     178,  173,   11,   11, 0x0a,
     196,   11,   11,   11, 0x0a,
     215,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameWidget[] = {
    "GameWidget\0\0setPlIDE()\0showIDE(bool)\0"
    "str\0showEditorGoroup(QString)\0"
    "setPauseIde(bool)\0groundDown()\0"
    "groundUp()\0groundNo()\0id,size\0"
    "setTailToDraw(int,int)\0id\0setTailToDraw(int)\0"
    "size\0setTailWidth(int)\0setStdTail_Grass()\0"
    "setStdTail_Sand()\0"
};

const QMetaObject GameWidget::staticMetaObject = {
    { &GLWidget::staticMetaObject, qt_meta_stringdata_GameWidget,
      qt_meta_data_GameWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget))
        return static_cast<void*>(const_cast< GameWidget*>(this));
    return GLWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setPlIDE(); break;
        case 1: showIDE((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: showEditorGoroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: setPauseIde((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: groundDown(); break;
        case 5: groundUp(); break;
        case 6: groundNo(); break;
        case 7: setTailToDraw((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: setTailToDraw((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: setTailWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setStdTail_Grass(); break;
        case 11: setStdTail_Sand(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
