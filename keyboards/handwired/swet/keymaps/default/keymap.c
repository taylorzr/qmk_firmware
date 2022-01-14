#include QMK_KEYBOARD_H

enum my_layers {
  _BASE = 0,
  _LOWER,
  _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default( \
    KC_F1,          KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F6,           /*******/ KC_F7,             KC_F8,             KC_F9,   KC_F10, KC_F11,  KC_F12,            \
    KC_GRV,         KC_1,   KC_2,   KC_3,   KC_4,           KC_5,            /*******/ KC_6,              KC_7,              KC_8,    KC_9,   KC_0,    KC_BSLASH,         \
    KC_EQL,         KC_Q,   KC_W,   KC_E,   KC_R,           KC_T,            /*******/ KC_Y,              KC_U,              KC_I,    KC_O,   KC_P,    KC_MINS,           \
    LCTL_T(KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,           KC_G,            /*******/ KC_H,              KC_J,              KC_K,    KC_L,   KC_SCLN, KC_QUOT,           \
    LSFT_T(KC_GRV), KC_Z,   KC_X,   KC_C,   KC_V,           KC_B,            /*******/ KC_N,              KC_M,              KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH), \
    /*___*/         /*___*/ /*___*/ /*___*/ LALT_T(KC_ESC), LGUI_T(KC_BSPC), /*******/ LT(_LOWER,KC_SPC), LT(_RAISE,KC_ENT) \
  ),

  [_LOWER] = LAYOUT_default( \
    _______, _______,    _______,    _______,    _______,    _______,    /*******/ _______,    _______,    _______,    _______,    _______,    _______, \
    _______, DF(_BASE),  _______,    _______,    _______,    _______,    /*******/ _______,    _______,    _______,    _______,    _______,    _______, \
    _______, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       /*******/ KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______, \
    _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), /*******/ LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, \
    _______, _______,    _______,    _______,    _______,    _______,    /*******/ _______,    _______,    _______,    _______,    _______,    _______, \
    /*___*/  /*___*/     /*___*/     /*___*/     _______,    KC_BSPC,    /*******/ _______,    _______     \
  ),

  [_RAISE] = LAYOUT_default( \
    _______, _______, _______, _______,       _______,       _______, /*******/ _______, _______, _______, _______,  _______, _______, \
    _______, _______, _______, _______,       _______,       _______, /*******/ _______, _______, _______, _______,  _______, _______, \
    _______, _______, _______, LSFT(KC_LBRC), LSFT(KC_RBRC), _______, /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______, KC_DEL,  \
    _______, _______, _______, KC_LBRC,       KC_RBRC,       _______, /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
    _______, _______, _______, LSFT(KC_9),    LSFT(KC_0),    _______, /*******/ _______, _______, _______, _______,  _______, _______, \
    /*___*/  /*___*/  /*___*/  /*___*/        _______,       _______, /*******/ _______, _______ \
  ),
};
