// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keypad_six_rp2040.h"

#if 0
#include <qp.h>

static deferred_token backlight_token = 0;
static bool backlight_is_on = false;
static painter_device_t display1;

static void backlight_off(void) {
    uprintf("%s\n", __func__);
    backlight_is_on = false;

    writePinLow(PIN_BACKLIGHT);
}

static void backlight_on(void) {
    uprintf("%s\n", __func__);
    backlight_is_on = true;

    writePinHigh(PIN_BACKLIGHT);
}

static uint32_t backlight_off_cb(uint32_t trigger_time, void* notused) {
    uprintf("%s(%lu)\n", __func__, trigger_time);
    backlight_off();

    return 0;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // restart backlight off timer
    extend_deferred_exec(backlight_token, BACKLIGHT_DURATION_MS);

    // keys only work when backlight is on
    static uint16_t backlight_keycode = 0;
    if (record->event.pressed && !backlight_is_on) {
        backlight_on();
        backlight_keycode = keycode;
        return false;
    }
    if (!record->event.pressed && backlight_keycode == keycode) {
        backlight_keycode = 0;
        return false;
    }

    return process_record_user(keycode, record);
}

void keyboard_pre_init_user(void) {
    setPinOutput(PIN_BACKLIGHT);
    backlight_off();
}

void keyboard_post_init_kb(void) {
#ifdef CONSOLE_ENABLE
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
#endif

    backlight_token = defer_exec(BACKLIGHT_DURATION_MS, backlight_off_cb, NULL);

    display1 = qp_st7735_make_spi_device(80, 160, PIN_DISPLAY_CS1, PIN_DISPLAY_DC, PIN_DISPLAY_RESET, 8, 1);
    qp_init(display1, QP_ROTATION_0);
    
    keyboard_post_init_user();
}
#endif
