/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Game/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      29,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      88,   75,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0resetSelection()\0"
    "upsetObjectData()\0autors()\0"
    "playMultiplayler()\0mapfile,info\0"
    "startDemo(QString,std::vector<StartFFAWidget::PlInfo>&)\0"
    "showSettings()\0save()\0load()\0"
    "showMainMenu()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resetSelection(); break;
        case 1: upsetObjectData(); break;
        case 2: autors(); break;
        case 3: playMultiplayler(); break;
        case 4: startDemo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::vector<StartFFAWidget::PlInfo>(*)>(_a[2]))); break;
        case 5: showSettings(); break;
        case 6: save(); break;
        case 7: load(); break;
        case 8: showMainMenu(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
