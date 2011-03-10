/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created: Thu Mar 10 02:00:48 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_battery;
    QFormLayout *formLayout_2;
    QRadioButton *rad_battery_max_protection;
    QRadioButton *rad_battery_medium_protection;
    QRadioButton *rad_battery_no_protection;
    QWidget *tab_kbd_bl;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *chk_enable_kbd_bl;
    QFormLayout *formLayout_4;
    QLabel *lbl_kbd_timeout;
    QSlider *hslider_kbd_timeout;
    QLabel *lbl_kbd_timeout_val;
    QWidget *tab_touchpad;
    QFormLayout *formLayout_3;
    QCheckBox *chk_enable_touchpad;
    QWidget *tab_als;
    QFormLayout *formLayout;
    QLabel *lbl_als_lux_threshold;
    QSpinBox *spin_als_lux_threshold;
    QCheckBox *chk_enable_als_power;
    QButtonGroup *btngrp_battery_protection;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(448, 252);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_battery = new QWidget();
        tab_battery->setObjectName(QString::fromUtf8("tab_battery"));
        formLayout_2 = new QFormLayout(tab_battery);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rad_battery_max_protection = new QRadioButton(tab_battery);
        btngrp_battery_protection = new QButtonGroup(MainWindow);
        btngrp_battery_protection->setObjectName(QString::fromUtf8("btngrp_battery_protection"));
        btngrp_battery_protection->addButton(rad_battery_max_protection);
        rad_battery_max_protection->setObjectName(QString::fromUtf8("rad_battery_max_protection"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rad_battery_max_protection);

        rad_battery_medium_protection = new QRadioButton(tab_battery);
        btngrp_battery_protection->addButton(rad_battery_medium_protection);
        rad_battery_medium_protection->setObjectName(QString::fromUtf8("rad_battery_medium_protection"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rad_battery_medium_protection);

        rad_battery_no_protection = new QRadioButton(tab_battery);
        btngrp_battery_protection->addButton(rad_battery_no_protection);
        rad_battery_no_protection->setObjectName(QString::fromUtf8("rad_battery_no_protection"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, rad_battery_no_protection);

        tabWidget->addTab(tab_battery, QString());
        tab_kbd_bl = new QWidget();
        tab_kbd_bl->setObjectName(QString::fromUtf8("tab_kbd_bl"));
        verticalLayout_3 = new QVBoxLayout(tab_kbd_bl);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        chk_enable_kbd_bl = new QCheckBox(tab_kbd_bl);
        chk_enable_kbd_bl->setObjectName(QString::fromUtf8("chk_enable_kbd_bl"));

        verticalLayout_3->addWidget(chk_enable_kbd_bl);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lbl_kbd_timeout = new QLabel(tab_kbd_bl);
        lbl_kbd_timeout->setObjectName(QString::fromUtf8("lbl_kbd_timeout"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lbl_kbd_timeout);

        hslider_kbd_timeout = new QSlider(tab_kbd_bl);
        hslider_kbd_timeout->setObjectName(QString::fromUtf8("hslider_kbd_timeout"));
        hslider_kbd_timeout->setMaximum(3);
        hslider_kbd_timeout->setTracking(false);
        hslider_kbd_timeout->setOrientation(Qt::Horizontal);
        hslider_kbd_timeout->setInvertedControls(false);
        hslider_kbd_timeout->setTickPosition(QSlider::TicksBelow);
        hslider_kbd_timeout->setTickInterval(0);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, hslider_kbd_timeout);

        lbl_kbd_timeout_val = new QLabel(tab_kbd_bl);
        lbl_kbd_timeout_val->setObjectName(QString::fromUtf8("lbl_kbd_timeout_val"));
        lbl_kbd_timeout_val->setAlignment(Qt::AlignCenter);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lbl_kbd_timeout_val);


        verticalLayout_3->addLayout(formLayout_4);

        tabWidget->addTab(tab_kbd_bl, QString());
        tab_touchpad = new QWidget();
        tab_touchpad->setObjectName(QString::fromUtf8("tab_touchpad"));
        formLayout_3 = new QFormLayout(tab_touchpad);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        chk_enable_touchpad = new QCheckBox(tab_touchpad);
        chk_enable_touchpad->setObjectName(QString::fromUtf8("chk_enable_touchpad"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, chk_enable_touchpad);

        tabWidget->addTab(tab_touchpad, QString());
        tab_als = new QWidget();
        tab_als->setObjectName(QString::fromUtf8("tab_als"));
        formLayout = new QFormLayout(tab_als);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lbl_als_lux_threshold = new QLabel(tab_als);
        lbl_als_lux_threshold->setObjectName(QString::fromUtf8("lbl_als_lux_threshold"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_als_lux_threshold);

        spin_als_lux_threshold = new QSpinBox(tab_als);
        spin_als_lux_threshold->setObjectName(QString::fromUtf8("spin_als_lux_threshold"));
        spin_als_lux_threshold->setMaximum(999);

        formLayout->setWidget(1, QFormLayout::FieldRole, spin_als_lux_threshold);

        chk_enable_als_power = new QCheckBox(tab_als);
        chk_enable_als_power->setObjectName(QString::fromUtf8("chk_enable_als_power"));

        formLayout->setWidget(0, QFormLayout::LabelRole, chk_enable_als_power);

        tabWidget->addTab(tab_als, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VAIO Control Center", 0, QApplication::UnicodeUTF8));
        rad_battery_max_protection->setText(QApplication::translate("MainWindow", "Maximum Battery Protection (50% charge)", 0, QApplication::UnicodeUTF8));
        rad_battery_medium_protection->setText(QApplication::translate("MainWindow", "Medium Battery Protection (80% charge)", 0, QApplication::UnicodeUTF8));
        rad_battery_no_protection->setText(QApplication::translate("MainWindow", "No Battery Protection (100% charge)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_battery), QApplication::translate("MainWindow", "Battery Charge", 0, QApplication::UnicodeUTF8));
        chk_enable_kbd_bl->setText(QApplication::translate("MainWindow", "Enable Keyboard Backlight", 0, QApplication::UnicodeUTF8));
        lbl_kbd_timeout->setText(QApplication::translate("MainWindow", "Timeout:", 0, QApplication::UnicodeUTF8));
        lbl_kbd_timeout_val->setText(QApplication::translate("MainWindow", "10 seconds", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_kbd_bl), QApplication::translate("MainWindow", "Keyboard Backlight", 0, QApplication::UnicodeUTF8));
        chk_enable_touchpad->setText(QApplication::translate("MainWindow", "Enable Touchpad", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_touchpad), QApplication::translate("MainWindow", "Touchpad", 0, QApplication::UnicodeUTF8));
        lbl_als_lux_threshold->setText(QApplication::translate("MainWindow", "Luminance Threshold: ", 0, QApplication::UnicodeUTF8));
        chk_enable_als_power->setText(QApplication::translate("MainWindow", "Enable Ambient Light Sensor", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_als), QApplication::translate("MainWindow", "ALS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
