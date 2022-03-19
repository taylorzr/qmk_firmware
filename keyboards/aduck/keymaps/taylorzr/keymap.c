#include QMK_KEYBOARD_H

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum my_layers {
	_COLEMAKDH = 0,
	_QWERTY,
	_GAME,
	_SFT,
	_SYM,
	_NAV,
	_FUN,
};

enum {
	SCLN = 0,
	CLN,
	SINGLE_QUOT,
	DOUBLE_QUOT,
	LBRC,
	RBRC,
	LCURLY,
	LPARENS,
	LESS,
};


// dont forget to update combo count in config.h
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM dv_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM kh_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(fp_combo, KC_DEL),
    COMBO(cd_combo, KC_TAB),
    COMBO(dv_combo, S(KC_EQL)),
    COMBO(lu_combo, S(KC_GRV)),
    COMBO(kh_combo, KC_EQL),
    COMBO(hcomma_combo, KC_ENT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDH] = LAYOUT( \
			KC_Q,        KC_W,        KC_F,        KC_P,          KC_B,             /*******/ KC_J,            KC_L,            KC_U,        KC_Y,        KC_MINS,     \
			ALT_T(KC_A), GUI_T(KC_R), SFT_T(KC_S), KC_T,          KC_G,             /*******/ KC_M,            KC_N,            SFT_T(KC_E), GUI_T(KC_I), ALT_T(KC_O), \
			KC_Z,        KC_X,        KC_C,        KC_D,          KC_V,             /*******/ KC_K,            KC_H,            KC_COMM,     KC_DOT,      KC_SLSH,     \
			/*___*/      /*___*/      /*___*/      CTL_T(KC_ESC), LT(_SFT,KC_BSPC), /*******/ LT(_SYM,KC_SPC), LT(_NAV,KC_SCLN) \
			),

	[_QWERTY] = LAYOUT( \
			KC_Q,        KC_W,        KC_E,        KC_R,          KC_T,            /*******/ KC_Y,             KC_U,            KC_I,    KC_O,   KC_P,    \
			ALT_T(KC_A), GUI_T(KC_S), SFT_T(KC_D), KC_F,          KC_G,            /*******/ KC_H,             KC_J,            KC_K,    KC_L,   KC_MINS, \
			KC_Z,        KC_X,        KC_C,        KC_V,          KC_B,            /*******/ KC_N,             KC_M,            KC_COMM, KC_DOT, KC_SLSH, \
			/*___*/      /*___*/      /*___*/      CTL_T(KC_ESC), LT(_SFT,KC_SPC), /*******/ LT(_SYM,KC_BSPC), LT(_NAV,KC_SCLN) \
			),

	[_GAME] = LAYOUT( \
			KC_ESC,  KC_Q,   KC_W,   KC_E,    KC_R,   /*******/ KC_Y,             KC_U,            KC_I,    KC_O,   KC_P,     \
			KC_LSFT, KC_A,   KC_S,   KC_D,    KC_F,   /*******/ KC_H,             KC_J,            KC_K,    KC_L,   TD(SCLN), \
			KC_TAB,  KC_Z,   KC_X,   KC_C,    KC_V,   /*******/ KC_N,             KC_M,            KC_COMM, KC_DOT, KC_SLSH,  \
			/*___*/  /*___*/ /*___*/ KC_LCTL, KC_SPC, /*******/ LT(_SYM,KC_BSPC), LT(_NAV,KC_MINS) \
			),

	// https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/#a-workaround-for-mod-tap
	// add mod taps to this layer see article
	[_SFT] = LAYOUT( \
			S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B), /*******/ S(KC_J),         S(KC_L), S(KC_U),         S(KC_Y),         S(KC_MINS), \
			S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G), /*******/ S(KC_M),         S(KC_N), S(KC_E),         S(KC_I),         S(KC_O),    \
			S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V), /*******/ S(KC_K),         S(KC_H), TD(DOUBLE_QUOT), TD(SINGLE_QUOT), S(KC_SLSH), \
			/*___*/  /*___*/  /*___*/  _______, _______, /*******/ LT(_FUN,KC_SPC), TD(CLN)  \
			),

	[_SYM] = LAYOUT( \
			KC_1,     KC_2,     KC_3,       KC_4,       KC_5,             /*******/ KC_6,    KC_7,        KC_8,    KC_9,         KC_0,      \
			S(KC_1),  S(KC_2),  S(KC_3),    S(KC_4),    S(KC_5),          /*******/ S(KC_6), S(KC_7),     S(KC_8), S(KC_BSLASH), KC_BSLASH, \
			TD(LBRC), TD(RBRC), TD(LCURLY), S(KC_RBRC), S(KC_EQL),        /*******/ KC_EQL,  TD(LPARENS), S(KC_0), TD(LESS),     S(KC_DOT), \
			/*___*/   /*___*/   /*___*/     KC_GRV,     LT(_FUN,KC_BSPC), /*******/ _______, _______      \
			),

	[_NAV] = LAYOUT( \
			_______, _______, SS_COPY,       SS_FILE,        _______, /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______, \
			_______, _______, C(S(KC_LEFT)), C(S(KC_RIGHT)), _______, /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, \
			_______, _______, C(A(KC_LEFT)), C(A(KC_RIGHT)), _______, /*******/ KC_SLEP, _______, _______, _______,  _______, \
			/*___*/  /*___*/  /*___*/        _______,        KC_ENT,  /*******/ _______, _______  \
			),

	[_FUN] = LAYOUT( \
			KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /*******/ KC_F6,   KC_F7,       KC_F8,          KC_F9,     KC_F10,  \
			KC_F11,  KC_F12,  _______, _______, _______, /*******/ _______, DF(_QWERTY), DF(_COLEMAKDH), DF(_GAME), _______, \
			_______, _______, _______, _______, _______, /*******/ _______, _______,     _______,        _______,   _______, \
			/*___*/  /*___*/  /*___*/  _______, _______, /*******/ _______, _______      \
			),
};

typedef struct {
	uint16_t single;
	uint16_t begin_kc;
	uint16_t end_kc;
	bool shifted;
} td_config;

static const td_config td_configs[] = {
	[LBRC] = {
		.single = KC_LBRC,
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = false,
	},
	[RBRC] = {
		.single = KC_RBRC,
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = false,
	},
	[LCURLY] = {
		.single = KC_LBRC,
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = true,
	},
	[LPARENS] = {
		.single = KC_9,
		.begin_kc = KC_9,
		.end_kc = KC_0,
		.shifted = true,
	},
	[LESS] = {
		.single = KC_COMM,
		.begin_kc = KC_COMM,
		.end_kc = KC_DOT,
		.shifted = true,
	},
	[SINGLE_QUOT] = {
		.single = KC_QUOT,
		.begin_kc = KC_QUOT,
		.end_kc = KC_QUOT,
		.shifted = false,
	},
	[DOUBLE_QUOT] = {
		.single = KC_QUOT,
		.begin_kc = KC_QUOT,
		.end_kc = KC_QUOT,
		.shifted = true,
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
			register_code(config.single); unregister_code(config.single);
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

void cln_equals(qk_tap_dance_state_t *state, void *user_data) {
	switch (state->count) {
		case 1:
			register_code(KC_LSFT);
			register_code(KC_SCLN); unregister_code(KC_SCLN);
			unregister_code(KC_LSFT);
			break;
		case 2:
			register_code(KC_LSFT);
			register_code(KC_SCLN); unregister_code(KC_SCLN);
			unregister_code(KC_LSFT);
			register_code(KC_EQL); unregister_code(KC_EQL);
			break;
	}
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SFT_T(KC_S):
			return TAPPING_TERM + 50;
		case SFT_T(KC_E):
			return TAPPING_TERM + 50;
		case GUI_T(KC_R):
			return TAPPING_TERM + 50;
		case GUI_T(KC_I):
			return TAPPING_TERM + 50;
		case ALT_T(KC_A):
			return TAPPING_TERM + 50;
		case ALT_T(KC_O):
			return TAPPING_TERM + 50;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SFT_T(KC_S):
			return true;
		case SFT_T(KC_E):
			return true;
		case GUI_T(KC_R):
			return true;
		case GUI_T(KC_I):
			return true;
		case ALT_T(KC_A):
			return true;
		case ALT_T(KC_O):
			return true;
		default:
			return false;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[CLN] = ACTION_TAP_DANCE_FN(cln_equals),
	[SCLN] = ACTION_TAP_DANCE_FN(scln_equals),
	[DOUBLE_QUOT] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[SINGLE_QUOT] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LBRC] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[RBRC] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LCURLY] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LPARENS] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[LESS] = ACTION_TAP_DANCE_FN(double_your_pleasure),
};
