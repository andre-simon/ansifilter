/****************************************************************************
** Meta object code from reading C++ file 'mydialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mydialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyDialog_t {
    QByteArrayData data[16];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyDialog_t qt_meta_stringdata_MyDialog = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyDialog"
QT_MOC_LITERAL(1, 9, 19), // "on_pbSaveAs_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_pbFileOpen_clicked"
QT_MOC_LITERAL(4, 52, 18), // "on_pbAbout_clicked"
QT_MOC_LITERAL(5, 71, 22), // "on_pbClipboard_clicked"
QT_MOC_LITERAL(6, 94, 26), // "on_pbSelectMapFile_clicked"
QT_MOC_LITERAL(7, 121, 33), // "on_cbIgnoreSequences_stateCha..."
QT_MOC_LITERAL(8, 155, 29), // "on_cbCodepage437_stateChanged"
QT_MOC_LITERAL(9, 185, 27), // "on_cbWatchFile_stateChanged"
QT_MOC_LITERAL(10, 213, 32), // "on_comboFont_currentIndexChanged"
QT_MOC_LITERAL(11, 246, 3), // "idx"
QT_MOC_LITERAL(12, 250, 36), // "on_comboEncoding_currentIndex..."
QT_MOC_LITERAL(13, 287, 13), // "onFileChanged"
QT_MOC_LITERAL(14, 301, 4), // "path"
QT_MOC_LITERAL(15, 306, 12) // "plausibility"

    },
    "MyDialog\0on_pbSaveAs_clicked\0\0"
    "on_pbFileOpen_clicked\0on_pbAbout_clicked\0"
    "on_pbClipboard_clicked\0"
    "on_pbSelectMapFile_clicked\0"
    "on_cbIgnoreSequences_stateChanged\0"
    "on_cbCodepage437_stateChanged\0"
    "on_cbWatchFile_stateChanged\0"
    "on_comboFont_currentIndexChanged\0idx\0"
    "on_comboEncoding_currentIndexChanged\0"
    "onFileChanged\0path\0plausibility"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,

       0        // eod
};

void MyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyDialog *_t = static_cast<MyDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pbSaveAs_clicked(); break;
        case 1: _t->on_pbFileOpen_clicked(); break;
        case 2: _t->on_pbAbout_clicked(); break;
        case 3: _t->on_pbClipboard_clicked(); break;
        case 4: _t->on_pbSelectMapFile_clicked(); break;
        case 5: _t->on_cbIgnoreSequences_stateChanged(); break;
        case 6: _t->on_cbCodepage437_stateChanged(); break;
        case 7: _t->on_cbWatchFile_stateChanged(); break;
        case 8: _t->on_comboFont_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_comboEncoding_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onFileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->plausibility(); break;
        default: ;
        }
    }
}

const QMetaObject MyDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MyDialog.data,
      qt_meta_data_MyDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyDialog.stringdata0))
        return static_cast<void*>(const_cast< MyDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
