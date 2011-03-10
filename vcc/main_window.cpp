#include "main_window.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setup_ui();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setup_ui() {
    // Battery Charge
    ui->btngrp_battery_protection->setId(ui->rad_battery_max_protection, 2);
    ui->btngrp_battery_protection->setId(ui->rad_battery_medium_protection, 1);
    ui->btngrp_battery_protection->setId(ui->rad_battery_no_protection, 0);
    switch(read_int_from_file(SONY_BATTERY_CHARGE_LIMITER)) {
        case 2:
            ui->rad_battery_max_protection->setChecked(true);
            break;
        case 1:
            ui->rad_battery_medium_protection->setChecked(true);
            break;
        case 0:
            ui->rad_battery_no_protection->setChecked(true);
            break;
    }

    // Keyboard Backlight
    int const kbd_backlight = read_int_from_file(SONY_KBD_BL);
    ui->chk_enable_kbd_bl->setChecked(kbd_backlight);
    ui->hslider_kbd_timeout->setEnabled(kbd_backlight);
    int const kbd_backlight_timeout = read_int_from_file(SONY_KBD_BL_TIMEOUT);
    ui->hslider_kbd_timeout->setValue(kbd_backlight_timeout);
    hslider_kbd_timeout_value_changed(kbd_backlight_timeout);

    // Touchpad
    ui->chk_enable_touchpad->setChecked(read_int_from_file(SONY_TOUCHPAD));

    // ALS
    int const als_power = read_int_from_file(SONY_ALS_POWER);
    ui->chk_enable_als_power->setChecked(als_power);
    ui->spin_als_lux_threshold->setEnabled(als_power);
    ui->spin_als_lux_threshold->setValue(read_int_from_file(SONY_ALS_LUX_THRESHOLD));

    // Connect everything
    connect(ui->btngrp_battery_protection, SIGNAL(buttonClicked(int)), this, SLOT(btngrp_battery_protection_button_clicked(int)));

    connect(ui->chk_enable_kbd_bl, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_kbd_bl_state_changed(int)));
    connect(ui->hslider_kbd_timeout, SIGNAL(valueChanged(int)), this, SLOT(hslider_kbd_timeout_value_changed(int)));

    connect(ui->chk_enable_touchpad, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_touchpad_state_changed(int)));

    connect(ui->chk_enable_als_power, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_als_power_state_changed(int)));
    connect(ui->spin_als_lux_threshold, SIGNAL(valueChanged(int)), this, SLOT(spin_als_lux_threshold_value_changed(int)));
}

void MainWindow::btngrp_battery_protection_button_clicked(int id) {
    write_int_to_file(SONY_BATTERY_CHARGE_LIMITER, id);
}


void MainWindow::chk_enable_kbd_bl_state_changed(int state) {
    ui->hslider_kbd_timeout->setEnabled(state);
    write_int_to_file(SONY_KBD_BL, state == 2 ? 1 : 0);
}

void MainWindow::chk_enable_touchpad_state_changed(int state) {
    write_int_to_file(SONY_TOUCHPAD, state == 2 ? 1 : 0);
}

void MainWindow::hslider_kbd_timeout_value_changed(int val) {
    char const* txt = NULL;
    switch (val) {
        case 0:
            txt = "10 seconds";
            break;
        case 1:
            txt = "30 seconds";
            break;
        case 2:
            txt = "60 seconds";
            break;
        case 3:
            txt = "Always on";
            break;
    }
    ui->lbl_kbd_timeout_val->setText(txt);
    write_int_to_file(SONY_KBD_BL_TIMEOUT, val);
}

void MainWindow::chk_enable_als_power_state_changed(int state) {
    ui->spin_als_lux_threshold->setEnabled(state);
    write_int_to_file(SONY_ALS_POWER, state == 2 ? 1 : 0);
}

void MainWindow::spin_als_lux_threshold_value_changed(int val) {
    write_int_to_file(SONY_ALS_LUX_THRESHOLD, val);
}
