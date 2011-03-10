/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created: Thu Mar 10 12:43:27 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "vcc/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
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
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x08,
      67,   61,   11,   11, 0x08,
     108,  104,   11,   11, 0x08,
     147,   61,   11,   11, 0x08,
     186,   61,   11,   11, 0x08,
     226,  104,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0id\0"
    "btngrp_battery_protection_button_clicked(int)\0"
    "state\0chk_enable_kbd_bl_state_changed(int)\0"
    "val\0hslider_kbd_timeout_value_changed(int)\0"
    "chk_enable_touchpad_state_changed(int)\0"
    "chk_enable_als_power_state_changed(int)\0"
    "spin_als_lux_threshold_value_changed(int)\0"
    "update_als_data()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
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
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: btngrp_battery_protection_button_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: chk_enable_kbd_bl_state_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: hslider_kbd_timeout_value_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: chk_enable_touchpad_state_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: chk_enable_als_power_state_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: spin_als_lux_threshold_value_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: update_als_data(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
