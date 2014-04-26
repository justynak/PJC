/****************************************************************************
** Meta object code from reading C++ file 'area.h'
**
** Created: Fri Apr 4 21:36:23 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "area.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'area.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Area[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      31,    5,    5,    5, 0x0a,
      39,    5,    5,    5, 0x0a,
      47,    5,    5,    5, 0x0a,
      56,   54,    5,    5, 0x0a,
      75,    5,    5,    5, 0x0a,
      94,    5,    5,    5, 0x0a,
     117,    5,  109,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Area[] = {
    "Area\0\0paintEvent(QPaintEvent*)\0Clear()\0"
    "Start()\0Stop()\0p\0SetPixmap(QPixmap)\0"
    "UpdateGeneration()\0UpdatePixmap()\0"
    "QPixmap\0GetPixmap()\0"
};

void Area::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Area *_t = static_cast<Area *>(_o);
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->Clear(); break;
        case 2: _t->Start(); break;
        case 3: _t->Stop(); break;
        case 4: _t->SetPixmap((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 5: _t->UpdateGeneration(); break;
        case 6: _t->UpdatePixmap(); break;
        case 7: { QPixmap _r = _t->GetPixmap();
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Area::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Area::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Area,
      qt_meta_data_Area, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Area::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Area::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Area::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Area))
        return static_cast<void*>(const_cast< Area*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Area::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
