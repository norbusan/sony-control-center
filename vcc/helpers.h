#ifndef  HELPERS_INC
#define  HELPERS_INC

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static char const*const SONY_BATTERY_CHARGE_LIMITER = "/sys/devices/platform/sony-laptop/battery_charge_limiter";
static char const*const SONY_ALS_POWER = "/sys/devices/platform/sony-laptop/als_power";
static char const*const SONY_ALS_BL = "/sys/devices/platform/sony-laptop/als_backlight";
static char const*const SONY_ALS_LUX_THRESHOLD = "/sys/devices/platform/sony-laptop/als_lux_threshold";
static char const*const SONY_KBD_BL = "/sys/devices/platform/sony-laptop/kbd_backlight";
static char const*const SONY_KBD_BL_TIMEOUT = "/sys/devices/platform/sony-laptop/kbd_backlight_timeout";
static char const*const SONY_TOUCHPAD = "/sys/devices/platform/sony-laptop/touchpad";

FILE* open_file(char const* path, char const* mode);

int read_int_from_file(char const* path);
void write_int_to_file(char const* path, int val);

#endif   /* ----- #ifndef HELPERS_INC  ----- */

