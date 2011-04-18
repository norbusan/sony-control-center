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

#ifndef  HELPERS_INC
#define  HELPERS_INC

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

static char const*const SONY_BATTERY_CHARGE_LIMITER = "/sys/devices/platform/sony-laptop/battery_care_limiter";
static char const*const SONY_BATTERY_HIGHSPEED_CHRG = "/sys/devices/platform/sony-laptop/battery_highspeed_charging";
static char const*const SONY_ALS_POWER = "/sys/devices/platform/sony-laptop/als_power";
static char const*const SONY_ALS_LUX = "/sys/devices/platform/sony-laptop/als_lux";
static char const*const SONY_ALS_KELVIN = "/sys/devices/platform/sony-laptop/als_kelvin";
static char const*const SONY_KBD_BL = "/sys/devices/platform/sony-laptop/kbd_backlight";
static char const*const SONY_KBD_BL_TIMEOUT = "/sys/devices/platform/sony-laptop/kbd_backlight_timeout";
static char const*const SONY_TOUCHPAD = "/sys/devices/platform/sony-laptop/touchpad";
static char const*const SONY_LID_CTRL = "/sys/devices/platform/sony-laptop/lid_resume_control";
static char const*const SONY_OPTICAL_DEV = "/sys/devices/platform/sony-laptop/odd_power";
static char const*const SONY_THERMAL = "/sys/devices/platform/sony-laptop/thermal_control";
static char const*const SONY_THERMAL_NUM = "/sys/devices/platform/sony-laptop/thermal_profiles";

int check_file(char const* path);

FILE* open_file(char const* path, char const* mode);

int read_int_from_file(char const* path);
void write_int_to_file(char const* path, int val);

char const* read_str_from_file(char const* path, char* buf, size_t buf_size);

#endif   /* ----- #ifndef HELPERS_INC  ----- */

