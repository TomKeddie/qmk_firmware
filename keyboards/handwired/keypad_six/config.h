#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x2171
#define MANUFACTURER    Tom Keddie
#define PRODUCT         Keypad Six

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 8

/* key matrix pins */

#define DIRECT_PINS { { D6, D4, D5, D3, D2, D1, D0, D7 } }

#define DEVICE_VER      0x0001
