/*
 * Sony Control Center for Linux
 *
 * Copyright (C) 2011 Tu Vuong <vanhtu1987@gmail.com>
 * Copyright (C) 2014 Norbert Preining <norbert@preining.info>
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

#ifndef  MAIN_WINDOW_INC
#define  MAIN_WINDOW_INC

#include <QtGui>
#include <string>

#include "ui_main_window.h"
#include "spicturewidget.h"

extern "C" {
#include "helpers.h"
}

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = NULL);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer _als_timer;

    void setup_ui();

private slots:
    void chk_battery_fast_charge_changed(int state);
    void btngrp_battery_protection_button_clicked(int id);

    void chk_enable_kbd_bl_state_changed(int state);
    void hslider_kbd_timeout_value_changed(int val);

    void chk_enable_touchpad_state_changed(int state);

    void chk_enable_als_power_state_changed(int state);
    void update_als_data();

    void chk_lid_s3_changed(int state);
    void chk_lid_s4_changed(int state);

    void chk_enable_optdev_state_changed(int state);

    void btngrp_thermal_button_clicked(int id);

    void list_index_changed( int index );

private:
    SPictureWidget *picture;
    SPictureWidget *icon;
    QLabel         *item_label;
    QHBoxLayout    *layout;
};

#endif   /* ----- #ifndef MAIN_WINDOW_INC  ----- */

