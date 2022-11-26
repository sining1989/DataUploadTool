/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Include/settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataUploadTool__DUSettings_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataUploadTool__DUSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataUploadTool__DUSettings_t qt_meta_stringdata_DataUploadTool__DUSettings = {
    {
QT_MOC_LITERAL(0, 0, 26), // "DataUploadTool::DUSettings"
QT_MOC_LITERAL(1, 27, 5), // "value"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "key"
QT_MOC_LITERAL(4, 38, 12), // "defaultValue"
QT_MOC_LITERAL(5, 51, 8) // "setValue"

    },
    "DataUploadTool::DUSettings\0value\0\0key\0"
    "defaultValue\0setValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataUploadTool__DUSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x0a /* Public */,
       1,    1,   34,    2, 0x2a /* Public | MethodCloned */,
       5,    2,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QVariant, QMetaType::QString, QMetaType::QVariant,    3,    4,
    QMetaType::QVariant, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    3,    1,

       0        // eod
};

void DataUploadTool::DUSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DUSettings *_t = static_cast<DUSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariant _r = _t->value((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariant _r = _t->value((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject DataUploadTool::DUSettings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataUploadTool__DUSettings.data,
      qt_meta_data_DataUploadTool__DUSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataUploadTool::DUSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataUploadTool::DUSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataUploadTool__DUSettings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataUploadTool::DUSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
