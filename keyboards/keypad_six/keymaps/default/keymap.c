#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = { { KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, SAFE_RANGE, SAFE_RANGE+1 } }
};

// Linux scancodes 183-188
// from /usr/include/linux/input-event-codes.h
// #define KEY_F13			183
// #define KEY_F14			184
// #define KEY_F15			185
// #define KEY_F16			186
// #define KEY_F17			187
// #define KEY_F18			188

// X11 uses 191-196
// 191 XF86Tools
// 192 XF86Launch5
// 193 XF86Launch6
// 194 XF86Launch7
// 195 XF86Launch8
// 196 XF86Launch9

static uint8_t modifier = 0;

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u modifier %d\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count, modifier);
#endif

    switch (keycode) {
        case SAFE_RANGE:
            if (record->event.pressed) {
                if (modifier == 7) {
                    modifier = 0;
                } else {
                    modifier++;
                }
            }
            break;
        case SAFE_RANGE+1:
            if (record->event.pressed) {
                if (modifier == 0) {
                    modifier = 7;
                } else {
                    modifier--;
                }
            }
            break;
        case KC_F13:
        case KC_F14:
        case KC_F15:
        case KC_F16:
        case KC_F17:
        case KC_F18:
            if (record->event.pressed) {
                if (modifier & 1) {
                    // send shift down
                    SEND_STRING(SS_DOWN(X_LSHIFT));
                };
                if (modifier & 2) {
                    // send ctrl down
                    SEND_STRING(SS_DOWN(X_LCTRL));
                };
                if (modifier & 4) {
                    // send alt down
                    SEND_STRING(SS_DOWN(X_LALT));
                };
            }
            break;
        default:
            break;
    }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F13:
        case KC_F14:
        case KC_F15:
        case KC_F16:
        case KC_F17:
        case KC_F18:
            if (!record->event.pressed) {
                if (modifier & 1) {
                    // send shift up
                    SEND_STRING(SS_UP(X_LSHIFT));
                };
                if (modifier & 2) {
                    // send ctrl up
                    SEND_STRING(SS_UP(X_LCTRL));
                };
                if (modifier & 4) {
                    // send alt up
                    SEND_STRING(SS_UP(X_LALT));
                };
            }
            break;
        default:
            break;
    }
}
