#include QMK_KEYBOARD_H

enum my_layers {
	_QWERTY = 0,
	_COLEMAKDH,
	_L1,
	_L2,
	_NUM,
};

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum {
	SCLN = 0,
	SINGLE_QUOT,
	DOUBLE_QUOT,
	LBRC,
	LCURLY,
	LPARENS,
	GRV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT( \
			XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,        /*___*/         /*******/ /*___*/         XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, \
			XXXXXXX, KC_Q,        KC_W,        KC_E,        KC_R,    KC_T,           /*___*/         /*******/ /*___*/         KC_Y,          KC_U,    KC_I,    KC_O,    KC_P,     XXXXXXX, \
			XXXXXXX, SFT_T(KC_A), CTL_T(KC_S), CTL_T(KC_D), KC_F,    KC_G,           /*___*/         /*******/ /*___*/         KC_H,          KC_J,    KC_K,    KC_L,    TD(SCLN), XXXXXXX, \
			XXXXXXX, ALT_T(KC_Z), KC_X,        KC_C,        KC_V,    KC_B,           XXXXXXX,        /*******/ XXXXXXX,        KC_N,          KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  XXXXXXX, \
			/*___*/ /*___*/      /*___*/       _______,     _______, GUI_T(KC_MINS), LT(_L2,KC_SPC), /*******/ LT(_L1,KC_ENT), SFT_T(KC_ESC), _______, _______  \
			),

	[_COLEMAKDH] = LAYOUT( \
			XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, /*___*/  /*******/ /*___*/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, \
			_______, _______, _______,     KC_F,        KC_P,    KC_B,    /*___*/  /*******/ /*___*/  KC_J,    KC_L,    KC_U,    KC_Y,    TD(SCLN), _______, \
			_______, _______, CTL_T(KC_R), CTL_T(KC_S), KC_T,    KC_G,    /*___*/  /*******/ /*___*/  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,     _______, \
			_______, _______, _______,     _______,     KC_D,    KC_V,    XXXXXXX, /*******/ XXXXXXX, KC_K,    KC_H,    _______, _______, _______,  _______, \
			/*___*/ /*___*/  /*___*/      _______,     _______, _______, _______, /*******/ _______, _______, _______, _______  \
			),

	[_L1] = LAYOUT( \
			_______, _______,   _______,      _______,    _______,    _______,   /*___*/  /*******/ /*___*/  _______, _______,     _______, _______,         _______,         _______, \
			_______, KC_1,      KC_2,         KC_3,       KC_4,       KC_5,      /*___*/  /*******/ /*___*/  KC_6,    KC_7,        KC_8,    KC_9,            KC_0,            _______, \
			_______, S(KC_1),   S(KC_2),      S(KC_3),    S(KC_4),    S(KC_5),   /*___*/  /*******/ /*___*/  S(KC_6), S(KC_7),     S(KC_8), TD(DOUBLE_QUOT), TD(SINGLE_QUOT), _______, \
			_______, KC_BSLASH, S(KC_BSLASH), TD(LCURLY), S(KC_RBRC), S(KC_EQL), XXXXXXX, /*******/ XXXXXXX, KC_EQL,  TD(LPARENS), S(KC_0), TD(LBRC),        KC_RBRC,         _______, \
			/*___*/  /*___*/    /*___*/       _______,    _______,    _______,   KC_BSPC, /*******/ _______, _______, _______,     _______  \
			),

	[_L2] = LAYOUT( \
			_______, _______,   _______, _______,       _______,        _______, /*___*/  /*******/ /*___*/  _______, _______,       _______,        _______,     _______,        _______, \
			_______, S(KC_GRV), TD(GRV), KC_MS_WH_UP,   KC_MS_WH_DOWN,  KC_DEL,  /*___*/  /*******/ /*___*/  KC_MPLY, KC_VOLD,       KC_VOLU,        KC_MNXT,     TG(_NUM),       _______, \
			_______, S(KC_TAB), KC_TAB,  C(S(KC_LEFT)), C(S(KC_RIGHT)), _______, /*___*/  /*******/ /*___*/  KC_LEFT, KC_DOWN,       KC_UP,          KC_RIGHT,    _______,        _______, \
			_______, _______,   _______, SS_COPY,       SS_FILE,        RESET,   XXXXXXX, /*******/ XXXXXXX, _______, C(A(KC_LEFT)), C(A(KC_RIGHT)), DF(_QWERTY), DF(_COLEMAKDH), _______, \
			/*___*/ /*___*/    /*___*/  _______,       _______,        _______, _______, /*******/ _______, _______, _______,       _______         \
			),

	[_NUM] = LAYOUT( \
			_______, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  _______,        _______, _______, _______, _______,  _______, \
			_______, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  KC_KP_ASTERISK, KC_7,    KC_8,    KC_9,    TG(_NUM), _______, \
			_______, _______, _______, _______, _______, _______, /*___*/  /*******/ /*___*/  KC_KP_PLUS,     KC_4,    KC_5,    KC_6,    KC_COMM,  _______, \
			_______, _______, _______, _______, _______, _______, XXXXXXX, /*******/ XXXXXXX, KC_EQL,         KC_1,    KC_2,    KC_3,    _______,  _______, \
			/*___*/  /*___*/  /*___*/  _______, _______, _______, _______, /*******/ _______, KC_0,           _______, _______  \
			),

};

typedef struct {
	uint16_t begin_kc;
	uint16_t end_kc;
	bool shifted;
	bool skip_three;
} td_config;

// Edit this to add a td_config
// These are the definitions for what the keys do
static const td_config td_configs[] = {
	[LBRC] = {
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = false,
	},
	[LCURLY] = {
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = true,
	},
	[LPARENS] = {
		.begin_kc = KC_9,
		.end_kc = KC_0,
		.shifted = true,
	},
	[SINGLE_QUOT] = {
		.begin_kc = KC_QUOT,
		.end_kc = KC_QUOT,
		.shifted = false,
	},
	[DOUBLE_QUOT] = {
		.begin_kc = KC_QUOT,
		.end_kc = KC_QUOT,
		.shifted = true,
	},
	[GRV] = {
		.begin_kc = KC_GRV,
		.end_kc = KC_GRV,
		.shifted = false,
		.skip_three = true,
	},
};

void double_your_pleasure(qk_tap_dance_state_t *state, void *user_data) {
	uint16_t stateKeycode = state->keycode - QK_TAP_DANCE;
	td_config config = td_configs[stateKeycode];
	switch(state->count) {
		case 1:
			if (config.shifted) {
				register_code(KC_LSFT);
			}
			register_code(config.begin_kc); unregister_code(config.begin_kc);
			if (config.shifted) {
				unregister_code(KC_LSFT);
			}
			break;
		case 2:
			if (config.shifted) {
				register_code(KC_LSFT);
			}
			register_code(config.begin_kc); unregister_code(config.begin_kc);
			register_code(config.end_kc); unregister_code(config.end_kc);
			if (config.shifted) {
				unregister_code(KC_LSFT);
			}
			register_code(KC_LEFT); unregister_code(KC_LEFT);
			break;
		case 3:
			if (config.skip_three) {
				register_code(config.begin_kc); unregister_code(config.begin_kc);
				register_code(config.begin_kc); unregister_code(config.begin_kc);
				register_code(config.begin_kc); unregister_code(config.begin_kc);
			} else {
				if (config.shifted) {
					register_code(KC_LSFT);
				}
				register_code(config.begin_kc); unregister_code(config.begin_kc);
				if (config.shifted) {
					unregister_code(KC_LSFT);
				}

				register_code(KC_ENT); unregister_code(KC_ENT);
				register_code(KC_ENT); unregister_code(KC_ENT);

				if (config.shifted) {
					register_code(KC_LSFT);
				}
				register_code(config.end_kc); unregister_code(config.end_kc);
				if (config.shifted) {
					unregister_code(KC_LSFT);
				}

				register_code(KC_UP); unregister_code(KC_UP);
				register_code(KC_TAB); unregister_code(KC_TAB);
			}
			break;
	}
}

void scln_equals(qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			register_code(KC_SCLN); unregister_code(KC_SCLN);
			break;
		case 2:
			register_code(KC_LSFT);
			register_code(KC_SCLN); unregister_code(KC_SCLN);
			unregister_code(KC_LSFT);
			register_code(KC_EQL); unregister_code(KC_EQL);
			break;
	}
}

// would still like to get this working S-backspace
/* enum custom_keycodes { */
/*   SPC_BS = SAFE_RANGE, */
/* }; */

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case CTL_T(KC_S): // qwerty and colemak
			return 175;
		case CTL_T(KC_D): // qwerty middle finger
			return 175;
		case CTL_T(KC_R): // colemak ring finger
			return 175;
		case SFT_T(KC_A):
			return 250;
		case ALT_T(KC_Z):
			return 250;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SFT_T(KC_QUOT):
			return true;
		case SFT_T(KC_A):
			return true;
		case CTL_T(KC_S):
			return true;
		case CTL_T(KC_D):
			return true;
		case CTL_T(KC_R):
			return true;
		case ALT_T(KC_Z):
			return true;
		default:
			// Force the mod-tap key press to be handled as a modifier if any
			// other key was pressed while the mod-tap key is held down.
			return false;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[SCLN] = ACTION_TAP_DANCE_FN(scln_equals),
	[DOUBLE_QUOT] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[SINGLE_QUOT] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LBRC] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LCURLY] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LPARENS] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[GRV] = ACTION_TAP_DANCE_FN(double_your_pleasure),
};
