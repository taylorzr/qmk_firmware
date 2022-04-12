#pragma once

#include "config_common.h"

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER taylorzr // change to dude who made it
#define PRODUCT aduck

#define MASTER_LEFT
#define USE_SERIAL
#define SOFT_SERIAL_PIN D1

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define DIRECT_PINS { \
    { C6,     D2,     F7,     B2, F4 }, \
    { D7,     D0,     F6,     B3, F5 }, \
    { E6,     D4,     D3,     B1, B6 }, \
    { NO_PIN, NO_PIN, NO_PIN, B4, B5 }  \
}

