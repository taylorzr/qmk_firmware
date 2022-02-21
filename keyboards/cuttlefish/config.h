#pragma once

#include "config_common.h"

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER taylorzr
#define PRODUCT cuttlefish

#define DIODE_DIRECTION COL2ROW
#define SOFT_SERIAL_PIN D2
#define TAPPING_TERM 150
/* #define TAPPING_TERM_PER_KEY */
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY


#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

// wired first one backwards...
/* #define MATRIX_COL_PINS_RIGHT { B6, B2, B3, B1, F7, F6 } */

/* #define MK_3_SPEED */

#define MOUSEKEY_WHEEL_INTERVAL 75
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#define MOUSEKEY_WHEEL_MAX_SPEED 10


