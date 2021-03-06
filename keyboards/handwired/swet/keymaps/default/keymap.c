#include QMK_KEYBOARD_H

enum my_layers {
  _BASE = 0,
  _GAMING,
  _COLEMAK,
  _COLEMAKDH,
  _L1,
  _L2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default( \
    KC_F1,          KC_F2,  KC_F3,  KC_F4,  KC_F5,          KC_F6,          /*******/ KC_F7,          KC_F8,         KC_F9,   KC_F10, KC_F11,  KC_F12,          \
    KC_GRV,         KC_1,   KC_2,   KC_3,   KC_4,           KC_5,           /*******/ KC_6,           KC_7,          KC_8,    KC_9,   KC_0,    KC_BSLASH,       \
    LALT_T(KC_EQL), KC_Q,   KC_W,   KC_E,   KC_R,           KC_T,           /*******/ KC_Y,           KC_U,          KC_I,    KC_O,   KC_P,    LALT_T(KC_MINS), \
    LSFT_T(KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,           KC_G,           /*******/ KC_H,           KC_J,          KC_K,    KC_L,   KC_SCLN, LSFT_T(KC_QUOT), \
    KC_GRV,         KC_Z,   KC_X,   KC_C,   KC_V,           KC_B,           /*******/ KC_N,           KC_M,          KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH,       \
            /*___*/ /*___*/ /*___*/ /*___*/ LCTL_T(KC_ESC), LT(_L2,KC_SPC), /*******/ LT(_L1,KC_ENT), LGUI_T(KC_DEL) \
  ),

  [_GAMING] = LAYOUT_default( \
    _______, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    KC_LGUI, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    KC_TAB,  _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    KC_LSFT, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    KC_LCTL, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    /*___*/  /*___*/  /*___*/  /*___*/  KC_ESC,  KC_SPC,  /*******/ _______, _______  \
  ),

  [_COLEMAK] = LAYOUT_default( \
    _______, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_F,    KC_P,    KC_G,    /*******/ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
    _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    /*******/ _______, KC_N,    KC_E,    KC_I,    KC_O,    _______, \
    _______, _______, _______, _______, _______, _______, /*******/ KC_K,    _______, _______, _______, _______, _______, \
    /*___*/  /*___*/  /*___*/  /*___*/  _______, _______, /*******/ _______, _______  \
  ),

  [_COLEMAKDH] = LAYOUT_default( \
    _______, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, /*******/ _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_F,    KC_P,    KC_B,    /*******/ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
    _______, _______, KC_R,    KC_S,    KC_T,    KC_G,    /*******/ KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    _______, \
    _______, _______, _______, _______, KC_D,    KC_V,    /*******/ KC_M,    KC_H,    _______, _______, _______, _______, \
    /*___*/  /*___*/  /*___*/  /*___*/  _______, _______, /*******/ _______, _______  \
  ),

  [_L1] = LAYOUT_default( \
    DF(_BASE), DF(_GAMING), DF(_COLEMAK), DF(_COLEMAKDH), _______,    RESET,      /*******/ RESET,      _______,    _______,    _______,    _______,    KC_SLEP, \
      _______, _______,     _______,      _______,        _______,    _______,    /*******/ _______,    _______,    _______,    _______,    _______,    _______, \
      _______, KC_1,        KC_2,         KC_3,           KC_4,       KC_5,       /*******/ KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______, \
      _______, LSFT(KC_1),  LSFT(KC_2),   LSFT(KC_3),     LSFT(KC_4), LSFT(KC_5), /*******/ LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, \
      _______, _______,     _______,      _______,        _______,    _______,    /*******/ _______,    _______,    _______,    _______,    _______,    _______, \
       /*___*/ /*___*/      /*___*/       /*___*/         _______,    KC_BSPC,    /*******/ _______,    _______     \
  ),

  [_L2] = LAYOUT_default( \
    _______, _______, _______, _______,       _______,       _______, /*******/ _______, _______, _______, _______,  _______,      _______, \
    _______, _______, _______, _______,       _______,       _______, /*******/ _______, _______, _______, _______,  _______,      KC_DEL,  \
    _______, _______, _______, KC_LBRC,       KC_RBRC,       _______, /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______,      KC_DEL,  \
    _______, _______, _______, LSFT(KC_9),    LSFT(KC_0),    KC_HOME, /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, S(KC_BSLASH), _______, \
    _______, _______, _______, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_END,  /*******/ _______, _______, _______, _______,  KC_BSLASH,    _______, \
    /*___*/  /*___*/  /*___*/  /*___*/        _______,       _______, /*******/ KC_BSPC, _______  \
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SFT_T(KC_QUOT):
			return 250;
		default:
			return TAPPING_TERM;
	}
}
