#include QMK_KEYBOARD_H

enum my_layers {
	_BASE = 0,
	_SYM,
	_NUM,
};

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

const uint16_t PROGMEM ent_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM spaste_combo[] = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM untab_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM play_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM next_combo[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM save_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ss_copy_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ss_file_combo[] = {KC_C, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(untab_combo, LSFT(KC_TAB)),
    COMBO(copy_combo, LGUI(KC_C)),
    COMBO(paste_combo, LGUI(KC_V)),
    COMBO(cut_combo, LGUI(KC_X)),
    COMBO(spaste_combo, LSFT(LGUI(KC_V))),
    COMBO(ss_copy_combo, LCTL(LSFT(LGUI(KC_4)))),
    COMBO(ss_file_combo, LSFT(LGUI(KC_4))),
    COMBO(play_combo, KC_MPLY),
    COMBO(next_combo, KC_MNXT),
    COMBO(save_combo, LCTL(KC_S)),
    COMBO(ent_combo, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT( \
			XXXXXXX, KC_1,   KC_2,        KC_3,        KC_4,    KC_5,           /*___*/        /*******/ /*___*/           KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    XXXXXXX, \
			XXXXXXX, KC_Q,   KC_W,        KC_F,        KC_P,    KC_B,           /*___*/        /*******/ /*___*/           KC_J,    KC_L,     KC_U,    KC_Y,   KC_QUOT, XXXXXXX, \
			XXXXXXX, KC_A,   ALT_T(KC_R), GUI_T(KC_S), KC_T,    KC_G,           /*___*/        /*******/ /*___*/           KC_M,    KC_N,     KC_E,    KC_I,   KC_O,    XXXXXXX, \
			XXXXXXX, KC_Z,   KC_X,        KC_C,        KC_D,    KC_V,           XXXXXXX,       /*******/ XXXXXXX,          KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH, XXXXXXX, \
			/*___*/  /*___*/ /*___*/      _______,     _______, CTRL_T(KC_ESC), SFT_T(KC_SPC), /*******/ LT(_SYM,KC_BSPC), LT(_NUM, KC_MINS), _______, _______ \
			),

	[_SYM] = LAYOUT( \
			XXXXXXX, _______,   _______, _______, _______, _______, /*___*/  /*******/ /*___*/  _______,   _______, _______, _______,   _______,    XXXXXXX, \
			XXXXXXX, S(KC_1),   S(KC_2), S(KC_3), S(KC_4), S(KC_5), /*___*/  /*******/ /*___*/  S(KC_6),   S(KC_7), S(KC_8), S(KC_EQL), KC_BSLS,    XXXXXXX, \
			XXXXXXX, S(KC_GRV), MY_BKT,  MY_BRC,  MY_PAR,  KC_BSLS, /*___*/  /*******/ /*___*/  KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT,  S(KC_BSLS), XXXXXXX, \
			XXXXXXX, S(KC_GRV), KC_GRV,  MY_SQT,  MY_DQT,  KC_SCLN, XXXXXXX, /*******/ XXXXXXX, S(KC_SCLN) KC_EQL,  _______, _______),  KC_BSLS,    XXXXXXX, \
			/*___*/  /*___*/    /*___*/  _______, _______, _______, _______, /*******/ _______, _______,   _______, _______  \
			),

	[_NUM] = LAYOUT( \
			XXXXXXX, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  _______, _______, _______, _______, _______, XXXXXXX, \
			XXXXXXX, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  _______, _______, _______, _______, _______, XXXXXXX, \
			XXXXXXX, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  _______, _______, _______, _______, _______, XXXXXXX, \
			XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, /*******/ XXXXXXX, _______, _______, _______, _______, _______, XXXXXXX, \
			/*___*/  /*___*/  /*___*/  _______, _______, _______, _______, /*******/ _______, _______, _______, _______  \
			),

};

const uint16_t PROGMEM ent_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM spaste_combo[] = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM untab_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM play_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM next_combo[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM save_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ss_copy_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ss_file_combo[] = {KC_C, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(untab_combo, LSFT(KC_TAB)),
    COMBO(copy_combo, LGUI(KC_C)),
    COMBO(paste_combo, LGUI(KC_V)),
    COMBO(cut_combo, LGUI(KC_X)),
    COMBO(spaste_combo, LSFT(LGUI(KC_V))),
    COMBO(ss_copy_combo, LCTL(LSFT(LGUI(KC_4)))),
    COMBO(ss_file_combo, LSFT(LGUI(KC_4))),
    COMBO(play_combo, KC_MPLY),
    COMBO(next_combo, KC_MNXT),
    COMBO(save_combo, LCTL(KC_S)),
    COMBO(ent_combo, KC_ENT),
};

enum custom_keycodes {
  MY_PAR = SAFE_RANGE,
  MY_BRC,
  MY_BKT,
  MY_DQT,
  MY_SQT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_PAR:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("()" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case MY_BRC:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("{}" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case MY_BKT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("[]" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case MY_DQT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("\"\"" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case MY_SQT:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("''" SS_TAP(X_LEFT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GUI_T(KC_S):
			return 175;
		case ALT_T(KC_R):
			return 175;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GUI_T(KC_S):
			return true;
		case ALT_T(KC_R):
			return true;
		default:
			// Force the mod-tap key press to be handled as a modifier if any
			// other key was pressed while the mod-tap key is held down.
			return false;
	}
}
