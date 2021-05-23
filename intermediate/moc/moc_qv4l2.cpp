/****************************************************************************
** Meta object code from reading C++ file 'qv4l2.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/qv4l2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qv4l2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   18,   18,   18, 0x08,
      50,   18,   18,   18, 0x08,
      68,   18,   18,   18, 0x08,
      80,   18,   18,   18, 0x0a,
      95,   18,   18,   18, 0x0a,
     106,   18,   18,   18, 0x0a,
     131,   18,   18,   18, 0x0a,
     142,   18,   18,   18, 0x0a,
     151,   18,   18,   18, 0x08,
     164,   18,   18,   18, 0x08,
     180,   18,   18,   18, 0x08,
     188,   18,   18,   18, 0x08,
     197,   18,   18,   18, 0x08,
     208,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationWindow[] = {
    "ApplicationWindow\0\0Photocapturing()\0"
    "closeDevice()\0closeCaptureWin()\0"
    "ShowImage()\0capStart(bool)\0capFrame()\0"
    "paintEvent(QPaintEvent*)\0closeApp()\0"
    "LCD_ON()\0openrawdev()\0ctrlAction(int)\0"
    "about()\0sample()\0paintRun()\0paintRun1()\0"
};

void ApplicationWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationWindow *_t = static_cast<ApplicationWindow *>(_o);
        switch (_id) {
        case 0: _t->Photocapturing(); break;
        case 1: _t->closeDevice(); break;
        case 2: _t->closeCaptureWin(); break;
        case 3: _t->ShowImage(); break;
        case 4: _t->capStart((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->capFrame(); break;
        case 6: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 7: _t->closeApp(); break;
        case 8: _t->LCD_ON(); break;
        case 9: _t->openrawdev(); break;
        case 10: _t->ctrlAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->about(); break;
        case 12: _t->sample(); break;
        case 13: _t->paintRun(); break;
        case 14: _t->paintRun1(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ApplicationWindow,
      qt_meta_data_ApplicationWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationWindow))
        return static_cast<void*>(const_cast< ApplicationWindow*>(this));
    if (!strcmp(_clname, "v4l2"))
        return static_cast< v4l2*>(const_cast< ApplicationWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ApplicationWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void ApplicationWindow::Photocapturing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_FaceDetectThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      28,   17,   17,   17, 0x05,
      39,   17,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_FaceDetectThread[] = {
    "FaceDetectThread\0\0sigtest()\0sigtest1()\0"
    "keyString()\0"
};

void FaceDetectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FaceDetectThread *_t = static_cast<FaceDetectThread *>(_o);
        switch (_id) {
        case 0: _t->sigtest(); break;
        case 1: _t->sigtest1(); break;
        case 2: _t->keyString(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FaceDetectThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FaceDetectThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FaceDetectThread,
      qt_meta_data_FaceDetectThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FaceDetectThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FaceDetectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FaceDetectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FaceDetectThread))
        return static_cast<void*>(const_cast< FaceDetectThread*>(this));
    return QThread::qt_metacast(_clname);
}

int FaceDetectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FaceDetectThread::sigtest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FaceDetectThread::sigtest1()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FaceDetectThread::keyString()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
