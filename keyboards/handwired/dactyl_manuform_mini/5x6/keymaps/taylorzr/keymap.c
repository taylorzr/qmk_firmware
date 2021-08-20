/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

#define _QWERTY_4x6 0
#define _QWERTY_5x6 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4

#define RAISE MO(_RAISE)
#define LOWER MO(_RAISE)

/* const uint16_t PROGMEM aquote_combo[] = {KC_A, KC_QUOT, COMBO_END}; */
/* const uint16_t PROGMEM amins_combo[] = {KC_A, KC_MINS, COMBO_END}; */

// Don't forget to update the count in config.h
// Combos make typing on those common keys, e.g. jk, feel laggy, avoid those
// parens () -> ?
// Bad combo list
// Combo | Why
// ui    | typing words like build
// df    | vim delete forward
//
/* combo_t key_combos[COMBO_COUNT] = { */
/*   [0] = COMBO(aquote_combo, LSFT(KC_BSLASH)), */
/*   [1] = COMBO(amins_combo, LSFT(KC_GRV)) */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_4x6] = LAYOUT_5x6(
     _______,         _______, _______, _______, _______,        _______,         /***S***/ _______,           _______,           _______, _______, _______, _______,
     KC_EQL,          KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,            /***P***/ KC_Y,              KC_U,              KC_I,    KC_O,    KC_P,    KC_MINS,
     LCTL_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,           KC_G,            /***L***/ KC_H,              KC_J,              KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     LSFT_T(KC_LBRC), KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,            /***I***/ KC_N,              KC_M,              KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_RBRC),
     /*___*/          /*___*/  _______, _______, LALT_T(KC_ESC), LGUI_T(KC_BSPC), /***T***/ LT(_LOWER,KC_SPC), LT(_RAISE,KC_ENT), _______, _______,
     /*___*/          /*___*/  /*___*/  _______, _______,        KC_GRV,          /***!***/ KC_BSLASH,         _______,           _______
  ),

  [_QWERTY_5x6] = LAYOUT_5x6(
     KC_GRV,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    /***S***/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLASH,
     _______, _______, _______, _______,  _______, _______, /***P***/ _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______,  _______, _______, /***L***/ _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______,  _______, _______, /***I***/ _______, _______, _______, _______, _______, _______,
     /*___*/  /*___*/  KC_LEFT, KC_RIGHT, _______, _______, /***T***/ _______, _______, KC_DOWN, KC_UP,
     /*___*/  /*___*/  /*___*/  _______,  _______, _______, /***!***/ _______, _______, _______
  ),

  [_COLEMAK] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______, /***S***/ _______, _______, _______, _______, _______, _______,
     _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    /***P***/ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
     _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    /***P***/ KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
     _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    /***L***/ KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
     /*___*/  /*___*/  _______, _______, _______, _______, /***T***/ _______, _______, _______, _______,
     /*___*/  /*___*/  /*___*/  _______, _______, _______, /***!***/ _______, _______, _______
  ),

  [_LOWER] = LAYOUT_5x6(
     _______, DF(_QWERTY_4x6), DF(_QWERTY_5x6), DF(_COLEMAK), _______,    _______,    /***S***/ _______,    _______,    _______,    _______,    _______,    _______,
     _______, KC_1,            KC_2,            KC_3,         KC_4,       KC_5,       /***P***/ KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
     _______, LSFT(KC_1),      LSFT(KC_2),      LSFT(KC_3),   LSFT(KC_4), LSFT(KC_5), /***L***/ LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
     _______, _______,         _______,         _______,      _______,    _______,    /***I***/ _______,    _______,    _______,    _______,    KC_BSLASH,  _______,
     /*___*/  /*___*/          _______,         _______,      _______,    KC_BSPC,    /***T***/ _______,    _______,    _______,    _______,
     /*___*/  /*___*/          /*___*/          _______,      _______,    _______,    /***!***/ _______,    _______,    _______
  ),


  [_RAISE] = LAYOUT_5x6(
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /***S***/ KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
     _______, KC_F11,  KC_F12,  _______, _______, _______, /***P***/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______, _______,
     _______, _______, _______, KC_DEL,  _______, _______, /***L***/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, /***I***/ _______, _______, _______, _______,  _______, _______,
     /*___*/  /*___*/  _______, _______, _______, _______, /***T***/ _______, _______, _______, _______,
     /*___*/  /*___*/  /*___*/  _______, _______, _______, /***!***/ _______, _______, _______
  ),
};
