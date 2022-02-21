#include QMK_KEYBOARD_H

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum my_layers {
	_QWERTY = 0,
	_COLEMAKDH,
	_L1,
	_L2,
};

enum {
	SEMI_EQL = 0
};

// would still like to get this working S-backspace
/* enum custom_keycodes { */
/*   SPC_BS = SAFE_RANGE, */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
 // ALT_T(KC_EQL), KC_MINS
 // SFT_T(KC_TAB), SFT_T(KC_QUOT)
    XXXXXXX, KC_Q,   KC_W,        KC_E,   KC_R,           KC_T,           /*******/ KC_Y,           KC_U,         KC_I,    KC_O,   KC_P,           XXXXXXX, \
    XXXXXXX, KC_A,   CTL_T(KC_S), KC_D,   KC_F,           KC_G,           /*******/ KC_H,           KC_J,         KC_K,    KC_L,   TD(SEMI_EQL),   XXXXXXX, \
    XXXXXXX, KC_Z,   KC_X,        KC_C,   KC_V,           KC_B,           /*******/ KC_N,           KC_M,         KC_COMM, KC_DOT, ALT_T(KC_SLSH), XXXXXXX, \
    /*___*/  /*___*/ /*___*/      /*___*/ GUI_T(KC_MINS), LT(_L2,KC_SPC), /*******/ LT(_L1,KC_ENT), SFT_T(KC_ESC) \
  ),

  // try modtap && tapdance together:
  // https://docs.qmk.fm/#/feature_tap_dance?id=example-4

  [_COLEMAKDH] = LAYOUT( \
    _______, _______, _______,     KC_F,    KC_P,    KC_B,    /*******/ KC_J,    KC_L,   KC_U,    KC_Y,    TD(SEMI_EQL), _______, \
    _______, _______, CTL_T(KC_R), KC_S,    KC_T,    KC_G,    /*******/ KC_M,    KC_N,   KC_E,    KC_I,    KC_O,            _______, \
    _______, _______, _______,     _______, KC_D,    KC_V,    /*******/ KC_K,    KC_H,   _______, _______, _______,         _______, \
    /*___*/  /*___*/  /*___*/      /*___*/  _______, _______, /*******/ _______, _______ \
  ),

  [_L1] = LAYOUT( \
    _______, KC_1,    KC_2,      KC_3,       KC_4,       KC_5,    /*******/ KC_6,      KC_7,    KC_8,    KC_9,    KC_0,       _______, \
    _______, S(KC_1), S(KC_2),   S(KC_3),    S(KC_4),    S(KC_5), /*******/ S(KC_6),   S(KC_7), S(KC_8), S(KC_9), S(KC_0),    _______, \
    _______, KC_GRV,  S(KC_GRV), S(KC_LBRC), S(KC_RBRC), KC_EQL,  /*******/ S(KC_EQL), KC_LBRC, KC_RBRC, KC_QUOT, S(KC_QUOT), _______, \
    /*___*/  /*___*/  /*___*/    /*___*/     _______,    KC_BSPC, /*******/ _______,   _______  \
  ),

  [_L2] = LAYOUT( \
    _______, DF(_QWERTY), DF(_COLEMAKDH), G(KC_C),     G(KC_V),       SS_FILE,     /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______,      _______, \
    _______, C(KC_LEFT),  KC_MS_BTN2,     KC_MS_BTN3,  KC_MS_BTN1,    C(KC_RIGHT), /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, S(KC_BSLASH), _______, \
    _______, KC_CAPS,     KC_DEL,         KC_MS_WH_UP, KC_MS_WH_DOWN, SS_COPY,     /*******/ _______, _______, _______, _______,  KC_BSLASH,    _______, \
     /*___*/ /*___*/      /*___*/         /*___*/      _______,       _______,     /*******/ KC_TAB,  KC_CAPS  \
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case CTL_T(KC_S):
			return 200;
		case CTL_T(KC_R):
			return 200;
		case ALT_T(KC_SLSH):
			return 250;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_QUOT):
            return true;
		case CTL_T(KC_S):
            return true;
		case CTL_T(KC_R):
            return true;
		case ALT_T(KC_SLSH):
			return true;
        default:
            // Force the mod-tap key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return false;
    }
}

void semi_eql(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_SCLN); unregister_code(KC_SCLN);
    break;
  case 2:
    register_code(KC_LSFT); register_code(KC_SCLN); unregister_code(KC_SCLN); unregister_code(KC_LSFT); register_code(KC_EQL); unregister_code(KC_EQL);
    break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SEMI_EQL] = ACTION_TAP_DANCE_FN(semi_eql)
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     static uint8_t saved_mods   = 0; */
/*     uint16_t       temp_keycode = keycode; */

/*     // Filter out the actual keycode from MT and LT keys. */
/*     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { */
/*         temp_keycode &= 0xFF; */
/*     } */

/*     switch (temp_keycode) { */
/*         case SPC_BS: */
/*             if (record->event.pressed) { */
/*                 saved_mods = get_mods() & MOD_MASK_SHIFT; */

/*                 if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed */
/*                     register_code(KC_BSPC); */
/*                 } else if (saved_mods) {   // One shift pressed */
/*                     del_mods(saved_mods);  // Remove any Shifts present */
/*                     register_code(KC_BSPC); */
/*                     add_mods(saved_mods);  // Add shifts again */
/*                 } else { */
/*                     register_code(KC_SPC); */
/*                 } */
/*             } else { */
/*                 unregister_code(KC_BSPC); */
/*                 unregister_code(KC_SPC); */
/*             } */
/*             return true; */
/*     } */

/*     return true; */
/* } */
