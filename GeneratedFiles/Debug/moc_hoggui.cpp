/****************************************************************************
** Meta object code from reading C++ file 'hoggui.h'
**
** Created: Sat May 26 16:56:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hoggui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hoggui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HogGui[] = {

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
       8,    7,    7,    7, 0x0a,
      33,    7,    7,    7, 0x0a,
      56,    7,    7,    7, 0x0a,
      80,    7,    7,    7, 0x0a,
      98,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HogGui[] = {
    "HogGui\0\0process_picture_detect()\0"
    "process_video_detect()\0process_picture_train()\0"
    "process_picture()\0load_path()\0"
};

void HogGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HogGui *_t = static_cast<HogGui *>(_o);
        switch (_id) {
        case 0: _t->process_picture_detect(); break;
        case 1: _t->process_video_detect(); break;
        case 2: _t->process_picture_train(); break;
        case 3: _t->process_picture(); break;
        case 4: _t->load_path(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData HogGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HogGui::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HogGui,
      qt_meta_data_HogGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HogGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HogGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HogGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HogGui))
        return static_cast<void*>(const_cast< HogGui*>(this));
    return QDialog::qt_metacast(_clname);
}

int HogGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
