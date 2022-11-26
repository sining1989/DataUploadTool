/****************************************************************************
** Meta object code from reading C++ file 'visualization_frame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Include/visualization_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualization_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataUploadTool__QReplyTimeout_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataUploadTool__QReplyTimeout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataUploadTool__QReplyTimeout_t qt_meta_stringdata_DataUploadTool__QReplyTimeout = {
    {
QT_MOC_LITERAL(0, 0, 29), // "DataUploadTool::QReplyTimeout"
QT_MOC_LITERAL(1, 30, 7), // "timeout"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9) // "onTimeout"

    },
    "DataUploadTool::QReplyTimeout\0timeout\0"
    "\0onTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataUploadTool__QReplyTimeout[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DataUploadTool::QReplyTimeout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QReplyTimeout *_t = static_cast<QReplyTimeout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->onTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QReplyTimeout::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QReplyTimeout::timeout)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DataUploadTool::QReplyTimeout::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DataUploadTool__QReplyTimeout.data,
      qt_meta_data_DataUploadTool__QReplyTimeout,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataUploadTool::QReplyTimeout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataUploadTool::QReplyTimeout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataUploadTool__QReplyTimeout.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataUploadTool::QReplyTimeout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DataUploadTool::QReplyTimeout::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_DataUploadTool__VisualizationFrame_t {
    QByteArrayData data[36];
    char stringdata0[649];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataUploadTool__VisualizationFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataUploadTool__VisualizationFrame_t qt_meta_stringdata_DataUploadTool__VisualizationFrame = {
    {
QT_MOC_LITERAL(0, 0, 34), // "DataUploadTool::Visualization..."
QT_MOC_LITERAL(1, 35, 17), // "closeEvent_Signal"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 12), // "QCloseEvent*"
QT_MOC_LITERAL(4, 67, 5), // "event"
QT_MOC_LITERAL(5, 73, 10), // "commitSlot"
QT_MOC_LITERAL(6, 84, 17), // "onDockPanelChange"
QT_MOC_LITERAL(7, 102, 16), // "refreshIssueList"
QT_MOC_LITERAL(8, 119, 11), // "itemClicked"
QT_MOC_LITERAL(9, 131, 5), // "index"
QT_MOC_LITERAL(10, 137, 20), // "deleteFileByNameSlot"
QT_MOC_LITERAL(11, 158, 11), // "strFileName"
QT_MOC_LITERAL(12, 170, 19), // "showContextMenuSlot"
QT_MOC_LITERAL(13, 190, 3), // "pos"
QT_MOC_LITERAL(14, 194, 24), // "setDisplayConfigModified"
QT_MOC_LITERAL(15, 219, 15), // "showIssueWidget"
QT_MOC_LITERAL(16, 235, 28), // "getPostIssueParamResposeSlot"
QT_MOC_LITERAL(17, 264, 14), // "QNetworkReply*"
QT_MOC_LITERAL(18, 279, 5), // "reply"
QT_MOC_LITERAL(19, 285, 27), // "getPostIssueDataResposeSlot"
QT_MOC_LITERAL(20, 313, 27), // "getGetAllIssueIdResposeSlot"
QT_MOC_LITERAL(21, 341, 22), // "getGetParamResposeSlot"
QT_MOC_LITERAL(22, 364, 24), // "getGetPictureResposeSlot"
QT_MOC_LITERAL(23, 389, 22), // "getGetVideoResposeSlot"
QT_MOC_LITERAL(24, 412, 23), // "getGet8DFileResposeSlot"
QT_MOC_LITERAL(25, 436, 24), // "deleteAllDataResposeSlot"
QT_MOC_LITERAL(26, 461, 21), // "deleteFileResposeSlot"
QT_MOC_LITERAL(27, 483, 19), // "requestFinishedSlot"
QT_MOC_LITERAL(28, 503, 18), // "uploadProgressSlot"
QT_MOC_LITERAL(29, 522, 9), // "bytesSent"
QT_MOC_LITERAL(30, 532, 10), // "bytesTotal"
QT_MOC_LITERAL(31, 543, 17), // "getParamErrorSlot"
QT_MOC_LITERAL(32, 561, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(33, 589, 9), // "errorCode"
QT_MOC_LITERAL(34, 599, 22), // "getAllIssueIdErrorSlot"
QT_MOC_LITERAL(35, 622, 26) // "deleteAllDataByIssueIDSlot"

    },
    "DataUploadTool::VisualizationFrame\0"
    "closeEvent_Signal\0\0QCloseEvent*\0event\0"
    "commitSlot\0onDockPanelChange\0"
    "refreshIssueList\0itemClicked\0index\0"
    "deleteFileByNameSlot\0strFileName\0"
    "showContextMenuSlot\0pos\0"
    "setDisplayConfigModified\0showIssueWidget\0"
    "getPostIssueParamResposeSlot\0"
    "QNetworkReply*\0reply\0getPostIssueDataResposeSlot\0"
    "getGetAllIssueIdResposeSlot\0"
    "getGetParamResposeSlot\0getGetPictureResposeSlot\0"
    "getGetVideoResposeSlot\0getGet8DFileResposeSlot\0"
    "deleteAllDataResposeSlot\0deleteFileResposeSlot\0"
    "requestFinishedSlot\0uploadProgressSlot\0"
    "bytesSent\0bytesTotal\0getParamErrorSlot\0"
    "QNetworkReply::NetworkError\0errorCode\0"
    "getAllIssueIdErrorSlot\0"
    "deleteAllDataByIssueIDSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataUploadTool__VisualizationFrame[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  132,    2, 0x0a /* Public */,
       6,    0,  133,    2, 0x09 /* Protected */,
       7,    0,  134,    2, 0x08 /* Private */,
       8,    1,  135,    2, 0x08 /* Private */,
      10,    1,  138,    2, 0x08 /* Private */,
      12,    1,  141,    2, 0x08 /* Private */,
      14,    0,  144,    2, 0x08 /* Private */,
      15,    0,  145,    2, 0x08 /* Private */,
      16,    1,  146,    2, 0x08 /* Private */,
      19,    1,  149,    2, 0x08 /* Private */,
      20,    1,  152,    2, 0x08 /* Private */,
      21,    1,  155,    2, 0x08 /* Private */,
      22,    1,  158,    2, 0x08 /* Private */,
      23,    1,  161,    2, 0x08 /* Private */,
      24,    1,  164,    2, 0x08 /* Private */,
      25,    1,  167,    2, 0x08 /* Private */,
      26,    1,  170,    2, 0x08 /* Private */,
      27,    0,  173,    2, 0x08 /* Private */,
      28,    2,  174,    2, 0x08 /* Private */,
      31,    1,  179,    2, 0x08 /* Private */,
      34,    1,  182,    2, 0x08 /* Private */,
      35,    0,  185,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QPoint,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,

       0        // eod
};

void DataUploadTool::VisualizationFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VisualizationFrame *_t = static_cast<VisualizationFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeEvent_Signal((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->commitSlot(); break;
        case 2: _t->onDockPanelChange(); break;
        case 3: _t->refreshIssueList(); break;
        case 4: _t->itemClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->deleteFileByNameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->showContextMenuSlot((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->setDisplayConfigModified(); break;
        case 8: _t->showIssueWidget(); break;
        case 9: _t->getPostIssueParamResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->getPostIssueDataResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->getGetAllIssueIdResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 12: _t->getGetParamResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->getGetPictureResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 14: _t->getGetVideoResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 15: _t->getGet8DFileResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 16: _t->deleteAllDataResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 17: _t->deleteFileResposeSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 18: _t->requestFinishedSlot(); break;
        case 19: _t->uploadProgressSlot((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 20: _t->getParamErrorSlot((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 21: _t->getAllIssueIdErrorSlot((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 22: _t->deleteAllDataByIssueIDSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (VisualizationFrame::*_t)(QCloseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VisualizationFrame::closeEvent_Signal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DataUploadTool::VisualizationFrame::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DataUploadTool__VisualizationFrame.data,
      qt_meta_data_DataUploadTool__VisualizationFrame,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DataUploadTool::VisualizationFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataUploadTool::VisualizationFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataUploadTool__VisualizationFrame.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DataUploadTool::VisualizationFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void DataUploadTool::VisualizationFrame::closeEvent_Signal(QCloseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
