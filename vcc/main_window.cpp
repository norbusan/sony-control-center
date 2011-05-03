/*
 * Sony VAIO Control Center for Linux
 *
 * Copyright (C) 2011 Tu Vuong <vanhtu1987@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

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
    if (check_file(SONY_BATTERY_HIGHSPEED_CHRG)) {
        ui->chk_battery_fast_charge->setChecked(read_int_from_file(SONY_BATTERY_HIGHSPEED_CHRG));

        connect(ui->chk_battery_fast_charge, SIGNAL(stateChanged(int)), this, SLOT(chk_battery_fast_charge_changed(int)));
    }
    else ui->chk_battery_fast_charge->setEnabled(false);
    if (check_file(SONY_BATTERY_CHARGE_LIMITER)) {
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

        connect(ui->btngrp_battery_protection, SIGNAL(buttonClicked(int)), this, SLOT(btngrp_battery_protection_button_clicked(int)));
    }
    else ui->frm_battery_protection->setEnabled(false);

    // Keyboard Backlight
    if (check_file(SONY_KBD_BL)) {
        int const kbd_backlight = read_int_from_file(SONY_KBD_BL);
        ui->chk_enable_kbd_bl->setChecked(kbd_backlight);
        ui->hslider_kbd_timeout->setEnabled(kbd_backlight);
        int const kbd_backlight_timeout = read_int_from_file(SONY_KBD_BL_TIMEOUT);
        ui->hslider_kbd_timeout->setValue(kbd_backlight_timeout);
        hslider_kbd_timeout_value_changed(kbd_backlight_timeout);

        connect(ui->chk_enable_kbd_bl, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_kbd_bl_state_changed(int)));
        connect(ui->hslider_kbd_timeout, SIGNAL(valueChanged(int)), this, SLOT(hslider_kbd_timeout_value_changed(int)));
    }
    else ui->frm_kbd_bl->setEnabled(false);

    // Touchpad
    if (check_file(SONY_TOUCHPAD)) {
        ui->chk_enable_touchpad->setChecked(read_int_from_file(SONY_TOUCHPAD));

        connect(ui->chk_enable_touchpad, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_touchpad_state_changed(int)));
    }
    else ui->chk_enable_touchpad->setEnabled(false);

    // ALS
    if (check_file(SONY_ALS_POWER)) {
        int const als_power = read_int_from_file(SONY_ALS_POWER);
        ui->chk_enable_als_power->setChecked(als_power);

        connect(ui->chk_enable_als_power, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_als_power_state_changed(int)));
        connect(&_als_timer, SIGNAL(timeout()), this, SLOT(update_als_data()));
        _als_timer.start(500);
    }
    else ui->frm_als->setEnabled(false);

    // Lid
    if (check_file(SONY_LID_CTRL)) {
        int const lid = read_int_from_file(SONY_LID_CTRL);
        ui->chk_lid_s3->setChecked(lid & 2);
        ui->chk_lid_s4->setChecked(lid & 1);

        connect(ui->chk_lid_s3, SIGNAL(stateChanged(int)), this, SLOT(chk_lid_s3_changed(int)));
        connect(ui->chk_lid_s4, SIGNAL(stateChanged(int)), this, SLOT(chk_lid_s4_changed(int)));
    }
    else ui->frm_lid->setEnabled(false);

    // Optical device
    if (check_file(SONY_OPTICAL_DEV)) {
        ui->chk_enable_optdev->setChecked(read_int_from_file(SONY_OPTICAL_DEV));

        connect(ui->chk_enable_optdev, SIGNAL(stateChanged(int)), this, SLOT(chk_enable_optdev_state_changed(int)));
    }
    else ui->chk_enable_optdev->setEnabled(false);

    // Thermal Control
    if (check_file(SONY_THERMAL_NUM)) {
        int const profiles = read_int_from_file(SONY_THERMAL_NUM);

        if (profiles > 2)
            ui->btngrp_thermal->setId(ui->rad_thermal_silent, 2);
        else
            ui->rad_thermal_silent->setEnabled(0);

        ui->btngrp_thermal->setId(ui->rad_thermal_performance, 1);
        ui->btngrp_thermal->setId(ui->rad_thermal_balanced, 0);
        switch(read_int_from_file(SONY_THERMAL)) {
            case 2:
                ui->rad_thermal_silent->setChecked(true);
                break;
            case 1:
                ui->rad_thermal_performance->setChecked(true);
                break;
            case 0:
                ui->rad_thermal_balanced->setChecked(true);
                break;
        }

        connect(ui->btngrp_thermal, SIGNAL(buttonClicked(int)), this, SLOT(btngrp_thermal_button_clicked(int)));
    }
    else ui->frm_thermal->setEnabled(false);
}

void MainWindow::chk_battery_fast_charge_changed(int state) {
    write_int_to_file(SONY_BATTERY_HIGHSPEED_CHRG, state == 2 ? 1 : 0);
}
void MainWindow::btngrp_battery_protection_button_clicked(int id) {
    write_int_to_file(SONY_BATTERY_CHARGE_LIMITER, id);
}

void MainWindow::chk_enable_kbd_bl_state_changed(int state) {
    ui->hslider_kbd_timeout->setEnabled(state);
    write_int_to_file(SONY_KBD_BL, state == 2 ? 1 : 0);
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

void MainWindow::chk_enable_touchpad_state_changed(int state) {
    write_int_to_file(SONY_TOUCHPAD, state == 2 ? 1 : 0);
}

void MainWindow::chk_enable_als_power_state_changed(int state) {
    write_int_to_file(SONY_ALS_POWER, state == 2 ? 1 : 0);
}
void MainWindow::update_als_data() {
    char buf[64];
    ui->lbl_als_lux_val->setText(read_str_from_file(SONY_ALS_LUX, buf, sizeof(buf)/sizeof(buf[0])));
    ui->lbl_als_kelvin_val->setText(read_str_from_file(SONY_ALS_KELVIN, buf, sizeof(buf)/sizeof(buf[0])));
}

void MainWindow::chk_lid_s3_changed(int state) {
    int const lid = read_int_from_file(SONY_LID_CTRL);
    
    write_int_to_file(SONY_LID_CTRL, state == 2 ? (lid | 2) : (lid & ~2));
}
void MainWindow::chk_lid_s4_changed(int state) {
    int const lid = read_int_from_file(SONY_LID_CTRL);
    
    write_int_to_file(SONY_LID_CTRL, state == 2 ? (lid | 1) : (lid & ~1));
}

void MainWindow::chk_enable_optdev_state_changed(int state) {
    write_int_to_file(SONY_OPTICAL_DEV, state == 2 ? 1 : 0);
}

void MainWindow::btngrp_thermal_button_clicked(int id) {
    int profiles = read_int_from_file(SONY_THERMAL_NUM);

    if (id < profiles)
        write_int_to_file(SONY_THERMAL, id);
}
