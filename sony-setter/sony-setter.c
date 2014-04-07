/*


this small cmdline utility is used to set various parameters
of the sony-laptop module. It allows to be set suid, allowing 
normal users to change the laptop settings.

sony-setter battery-care off
sony-setter battery-care on	no change to value
sony-setter battery-care limit [50,80,100]

sony-setter thermal-profile list	lists all
sony-setter thermal-profile current	lists current
sony-setter thermal-profile <name>	sets <name> if available

sony-setter touchpad on|off

sony-setter usb-charge on|off

sony-setter kbd-backlight on|off|<int> 0-3

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>

const char sony_setter_version[] = "0.1";
static const char *argv0;

static char const*const SONY_BATTERY_CHARGE_LIMITER = "/sys/devices/platform/sony-laptop/battery_care_limiter";
static char const*const SONY_BATTERY_HIGHSPEED_CHRG = "/sys/devices/platform/sony-laptop/battery_highspeed_charging";
static char const*const SONY_ALS_POWER = "/sys/devices/platform/sony-laptop/als_power";
static char const*const SONY_ALS_LUX = "/sys/devices/platform/sony-laptop/als_lux";
static char const*const SONY_ALS_KELVIN = "/sys/devices/platform/sony-laptop/als_kelvin";
static char const*const SONY_KBD_BL = "/sys/devices/platform/sony-laptop/kbd_backlight";
static char const*const SONY_KBD_BL_TIMEOUT = "/sys/devices/platform/sony-laptop/kbd_backlight_timeout";
static char const*const SONY_TOUCHPAD = "/sys/devices/platform/sony-laptop/touchpad";
static char const*const SONY_USB_CHARGE = "/sys/devices/platform/sony-laptop/usb_charge";
static char const*const SONY_LID_CTRL = "/sys/devices/platform/sony-laptop/lid_resume_control";
static char const*const SONY_OPTICAL_DEV = "/sys/devices/platform/sony-laptop/odd_power";
static char const*const SONY_THERMAL = "/sys/devices/platform/sony-laptop/thermal_control";
static char const*const SONY_THERMAL_NUM = "/sys/devices/platform/sony-laptop/thermal_profiles";


FILE* open_file(char const* path, char const* mode) {
    FILE* const fd = fopen(path, mode);
    if (!fd) {
        fprintf(stderr, "open_file: can't open %s: %s\n",
                path, strerror(errno));
        exit(1);
    }

    return fd;
}

void write_sys_int(char const* path, int val) {
    FILE* const fd = open_file(path, "w");
    if (fprintf(fd, "%i", val) < 0) {
        fprintf(stderr, "write_str_int (%s): fprintf failed - %s\n",
                path, strerror(errno));
        exit(1);
    }
    fclose(fd);
}


static void usage(void)
{
        fprintf(stderr, "Usage:\t%s [options] command\n", argv0);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "\t--version\tshow version (%s)\n", sony_setter_version);
        fprintf(stderr, "Commands:\n");
        fprintf(stderr, "\tbattery-care <opts>\n");
        fprintf(stderr, "\ttouchpad [on|off]\n");
        fprintf(stderr, "\tthermal-profile <opts>\n");
        fprintf(stderr, "\tusb-charge [on|off]\n");
        fprintf(stderr, "\tkbd-backlight <opts>\n");
}

static void version(void)
{
        printf("sony-setter %s\n", sony_setter_version);
}

static void do_battery_care(int argc, char **argv) {
        if (argc != 1) {
                usage();
                exit(1);
        }
        if (strcmp(*argv, "off") == 0) {
                write_sys_int(SONY_BATTERY_CHARGE_LIMITER, 0);
                return;
        } else if (strcmp(*argv, "50")) {
                write_sys_int(SONY_BATTERY_CHARGE_LIMITER, 50);
                return;
        } else if (strcmp(*argv, "80")) {
                write_sys_int(SONY_BATTERY_CHARGE_LIMITER, 80);
                return;
        } else if (strcmp(*argv, "100")) {
                write_sys_int(SONY_BATTERY_CHARGE_LIMITER, 100);
                return;
        } else {
                usage();
                exit(1);
        }
}
static void do_thermal_profile(int argc, char **argv) {
        fprintf(stderr, "not implemented yet\n");
        return;
}
static void do_on_off(char const* path, int argc, char **argv) {
        if (argc != 1) {
                usage();
                exit(1);
        }
        if (strcmp(*argv, "on") == 0) {
                write_sys_int(path, 1);
                return;
        } else if (strcmp(*argv, "off") == 0) {
                write_sys_int(path, 0);
                return;
        } else {
                usage();
                exit(1);
        }
}
static void do_touchpad(int argc, char **argv) {
        do_on_off(SONY_TOUCHPAD, argc, argv);
        return;
}
static void do_usb_charge(int argc, char **argv) {
        do_on_off(SONY_USB_CHARGE, argc, argv);
        return;
}
static void do_kbd_backlight(int argc, char **argv) {
        fprintf(stderr, "not implemented yet\n");
        return;
}

int main (int argc, char **argv) {
        /* strip off self */
        argc--;
        argv0 = *argv++;

        if (argc > 0 && strcmp(*argv, "--version") == 0) {
                version();
                return 0;
        }

        if (argc == 0 || strcmp(*argv, "help") == 0 || strcmp(*argv, "--help") == 0) {
                usage();
                return 0;
        }

        if (strcmp(*argv, "battery-care") == 0) {
                argc--; argv++;
                do_battery_care(argc, argv);
        } else if (strcmp(*argv, "thermal-profile") == 0) {
                argc--; argv++;
                do_thermal_profile(argc, argv);
        } else if (strcmp(*argv, "touchpad") == 0) {
                argc--; argv++;
                do_touchpad(argc, argv);
        } else if (strcmp(*argv, "usb-charge") == 0) {
                argc--; argv++;
                do_usb_charge(argc, argv);
        } else if (strcmp(*argv, "kbd-backlight") == 0) {
                argc--; argv++;
                do_kbd_backlight(argc, argv);
        } else {
                usage();
                return 1;
        }

        return 0;
}


