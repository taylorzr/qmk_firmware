#include QMK_KEYBOARD_H

enum my_layers {
	_COLEMAKDH = 0,
	_QWERTY,
	_SFT,
	_SYM,
	_NAV,
	_NUM,
};

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum custom_keycodes {
  KC_SPC_ENT = SAFE_RANGE,
};

enum {
	X_DEL = 0,
	SCLN,
	CLN,
	SINGLE_QUOT,
	DOUBLE_QUOT,
	LBRC,
	RBRC,
	LCURLY,
	LPARENS,
	LESS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDH] = LAYOUT( \
			KC_Q,        KC_W,        KC_F,        KC_P,          KC_B,            /*******/ KC_J,             KC_L,            KC_U,    KC_Y,        KC_MINS, \
			ALT_T(KC_A), GUI_T(KC_R), SFT_T(KC_S), KC_T,          KC_G,            /*******/ KC_M,             KC_N,            KC_E,    GUI_T(KC_I), KC_O,    \
			KC_Z,        TD(X_DEL),   KC_C,        KC_D,          KC_V,            /*******/ KC_K,             KC_H,            KC_COMM, KC_DOT,      KC_SLSH, \
			/*___*/      /*___*/      /*___*/      CTL_T(KC_ESC), LT(_SFT,KC_SPC), /*******/ LT(_SYM,KC_BSPC), LT(_NAV,KC_SCLN) \
			),

	[_QWERTY] = LAYOUT( \
			KC_Q,        KC_W,        KC_E,   KC_R,          KC_T,          /*******/ KC_Y,             KC_U,            KC_I,    KC_O,   KC_P,     \
			SFT_T(KC_A), GUI_T(KC_S), KC_D,   KC_F,          KC_G,          /*******/ KC_H,             KC_J,            KC_K,    KC_L,   TD(SCLN), \
			ALT_T(KC_Z), KC_X,        KC_C,   KC_V,          KC_B,          /*******/ KC_N,             KC_M,            KC_COMM, KC_DOT, KC_SLSH,  \
			/*___*/      /*___*/      /*___*/ CTL_T(KC_ESC), SFT_T(KC_SPC), /*******/ LT(_SYM,KC_BSPC), LT(_NAV,KC_MINS) \
			),

	[_SFT] = LAYOUT( \
			S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B), /*******/ S(KC_J), S(KC_L), S(KC_U),         S(KC_Y),         S(KC_MINS), \
			S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G), /*******/ S(KC_M), S(KC_N), S(KC_E),         S(KC_I),         S(KC_O),    \
			S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V), /*******/ S(KC_K), S(KC_H), TD(DOUBLE_QUOT), TD(SINGLE_QUOT), S(KC_SLSH), \
			/*___*/  /*___*/  /*___*/  _______, _______, /*******/ KC_ENT,  TD(CLN)  \
			),

	[_SYM] = LAYOUT( \
			KC_1,     KC_2,     KC_3,       KC_4,       KC_5,      /*******/ KC_6,    KC_7,        KC_8,    KC_9,         KC_0,      \
			S(KC_1),  S(KC_2),  S(KC_3),    S(KC_4),    S(KC_5),   /*******/ S(KC_6), S(KC_7),     S(KC_8), S(KC_BSLASH), KC_BSLASH, \
			TD(LBRC), TD(RBRC), TD(LCURLY), S(KC_RBRC), S(KC_EQL), /*******/ KC_EQL,  TD(LPARENS), S(KC_0), TD(LESS),     S(KC_DOT), \
			/*___*/   /*___*/   /*___*/     KC_GRV,     KC_ENT,    /*******/ _______, S(KC_GRV)    \
			),

	[_NAV] = LAYOUT( \
			_______,   _______, SS_COPY,       SS_FILE,        TG(_NUM), /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  KC_DEL,  \
			S(KC_TAB), KC_TAB,  C(S(KC_LEFT)), C(S(KC_RIGHT)), _______,  /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, \
			_______,   _______, C(A(KC_LEFT)), C(A(KC_RIGHT)), _______,  /*******/ _______, _______, _______, _______,  _______, \
			/*___*/    /*___*/  /*___*/        _______,        KC_ENT,   /*******/ _______, _______  \
			),

	[_NUM] = LAYOUT( \
			DF(_QWERTY), DF(_COLEMAKDH), _______, _______,  TG(_NUM), /*******/ KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_KP_MINUS, \
			_______,     _______,        _______, _______,  _______,  /*******/ KC_COMM,        KC_4, KC_5, KC_6, KC_KP_PLUS,  \
			_______,     _______,        _______, _______,  _______,  /*******/ KC_EQL,         KC_1, KC_2, KC_3, _______,     \
			/*___*/      /*___*/         /*___*/  TG(_NUM), _______,  /*******/ _______,        KC_0  \
			),
};

uint16_t custom_lt_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if(keycode == KC_SPC_ENT) {
		if(record->event.pressed) {
			custom_lt_timer = timer_read();
			layer_on(_SYM);
		}else{
			layer_off(_SYM);
			if (timer_elapsed(custom_lt_timer)<200) {
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_ENT);
        } else {
          register_code(KC_SPC);
        }
        unregister_code(KC_ENT);
        unregister_code(KC_SPC);
			}
		}
	}
	return true;
}

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
		case GUI_T(KC_R):
			return 250;
		case SFT_T(KC_S):
			return 250;
		case ALT_T(KC_A):
			return 250;
		case GUI_T(KC_I):
			return 250;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GUI_T(KC_R):
			return true;
		case SFT_T(KC_S):
			return true;
		case ALT_T(KC_A):
			return true;
		case GUI_T(KC_I):
			return true;
		default:
			return false;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_DEL),
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
