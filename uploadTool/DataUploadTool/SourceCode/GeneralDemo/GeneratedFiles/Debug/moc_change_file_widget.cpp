/****************************************************************************
** Meta object code from reading C++ file 'change_file_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Include/change_file_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'change_file_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataUploadTool__ChangeFileWidget_t {
    QByteArrayData data[9];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataUploadTool__ChangeFileWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataUploadTool__ChangeFileWidget_t qt_meta_stringdata_DataUploadTool__ChangeFileWidget = {
    {
QT_MOC_LITERAL(0, 0, 32), // "DataUploadTool::ChangeFileWidget"
QT_MOC_LITERAL(1, 33, 16), // "deleteFileSignal"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 14), // "showChangeFile"
QT_MOC_LITERAL(4, 66, 9), // "file_name"
QT_MOC_LITERAL(5, 76, 11), // "strFileName"
QT_MOC_LITERAL(6, 88, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 105, 4), // "item"
QT_MOC_LITERAL(8, 110, 14) // "deleteFileSlot"

    },
    "DataUploadTool::ChangeFileWidget\0"
    "deleteFileSignal\0\0showChangeFile\0"
    "file_name\0strFileName\0QListWidgetItem*\0"
    "item\0deleteFileSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataUploadTool__ChangeFileWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   30,    2, 0x0a /* Public */,
       8,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void,

       0        // eod
};

void DataUploadTool::ChangeFileWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangeFileWidget *_t = static_cast<ChangeFileWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteFileSignal(); break;
        case 1: _t->showChangeFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[3]))); break;
        case 2: _t->deleteFileSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChangeFileWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChangeFileWidget::deleteFileSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DataUploadTool::ChangeFileWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataUploadTool__ChangeFileWidget.data,
      qt_meta_data_DataUploadTool__ChangeFileWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataUploadTool::ChangeFileWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataUploadTool::ChangeFileWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataUploadTool__ChangeFileWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DataUploadTool::ChangeFileWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void DataUploadTool::ChangeFileWidget::deleteFileSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
