#ifndef  MAIN_WINDOW_INC
#define  MAIN_WINDOW_INC

#include <QtGui>

#include "ui_main_window.h"
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

    void setup_ui();

private slots:
    void btngrp_battery_protection_button_clicked(int id);

    void chk_enable_kbd_bl_state_changed(int state);
    void hslider_kbd_timeout_value_changed(int val);

    void chk_enable_touchpad_state_changed(int state);

    void chk_enable_als_power_state_changed(int state);
    void spin_als_lux_threshold_value_changed(int val);
};

#endif   /* ----- #ifndef MAIN_WINDOW_INC  ----- */

