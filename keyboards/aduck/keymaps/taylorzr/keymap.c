#include QMK_KEYBOARD_H
#include "features/caps_word.h"

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum my_layers {
	_COLEMAKDH = 0,
	_GAME,
	_SYM,
	_FUN,
};

enum {
	SCLN = 0,
	CLN,
	SINGLE_QUOT,
	DOUBLE_QUOT,
	BRACS,
	CURLY,
	PARENS,
};

enum combo_events {
  DEL_COMBO,
  CAPS_COMBO,
  COPY_COMBO,
  TAB_COMBO,
  PLAY_COMBO,
  NEXT_COMBO,
  ENT_COMBO,
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

// dont forget to update combo count in config.h
const uint16_t PROGMEM fb_combo[]     = {KC_F,        KC_B,    COMBO_END};
const uint16_t PROGMEM fp_combo[]     = {KC_F,        KC_P,    COMBO_END};
const uint16_t PROGMEM sg_combo[]     = {GUI_T(KC_S), KC_G,    COMBO_END};
const uint16_t PROGMEM cd_combo[]     = {KC_C,        KC_D,    COMBO_END};
const uint16_t PROGMEM dv_combo[]     = {KC_D,        KC_V,    COMBO_END};
const uint16_t PROGMEM lu_combo[]     = {KC_L,        KC_U,    COMBO_END};
const uint16_t PROGMEM ju_combo[]     = {KC_J,        KC_U,    COMBO_END};
const uint16_t PROGMEM nu_combo[]     = {KC_N,        KC_U,    COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {KC_H,        KC_COMM, COMBO_END};

combo_t key_combos[] = {
  [DEL_COMBO]          = COMBO(fb_combo,     KC_DEL),
  [CAPS_COMBO]         = COMBO_ACTION(fp_combo),
  [COPY_COMBO]         = COMBO(sg_combo,     KC_COPY),
  [TAB_COMBO]          = COMBO(cd_combo,     KC_TAB),
  [PLAY_COMBO]         = COMBO(lu_combo,     KC_MPLY),
  [NEXT_COMBO]         = COMBO(ju_combo,     KC_MNXT),
  [ENT_COMBO]          = COMBO(hcomma_combo, KC_ENT),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_set(true);
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDH] = LAYOUT( \
			KC_Q,   KC_W,        KC_F,        KC_P,          KC_B,           /*******/ KC_J,            KC_L,            KC_U,        KC_Y,        KC_QUOT,  \
			KC_A,   ALT_T(KC_R), GUI_T(KC_S), KC_T,          KC_G,           /*******/ KC_M,            KC_N,            GUI_T(KC_E), ALT_T(KC_I), KC_O,    \
			KC_Z,   KC_X,        KC_C,        KC_D,          KC_V,           /*******/ KC_K,            KC_H,            KC_COMM,     KC_DOT,      KC_SLSH, \
			/*___*/ /*___*/      /*___*/      CTL_T(KC_ESC), SFT_T(KC_BSPC), /*******/ LT(_SYM,KC_SPC), LT(_FUN,KC_MINS) \
			),

	[_GAME] = LAYOUT( \
			KC_TAB,  KC_Q,   KC_W,   KC_E,            KC_R,   /*******/ KC_Y,             KC_U,            KC_I,    KC_O,   KC_P,    \
			KC_LSFT, KC_A,   KC_S,   KC_D,            KC_F,   /*******/ KC_H,             KC_J,            KC_K,    KC_L,   KC_MINS, \
			KC_LCTL, KC_Z,   KC_X,   KC_C,            KC_V,   /*******/ KC_N,             KC_M,            KC_COMM, KC_DOT, KC_SLSH, \
			/*___*/  /*___*/ /*___*/ LT(_SYM,KC_ESC), KC_SPC, /*******/ LT(_SYM,KC_BSPC), LT(_FUN,KC_MINS) \
			),

	[_SYM] = LAYOUT( \
			KC_1,      KC_2,    KC_3,            KC_4,    KC_5,         /*******/ KC_6,      KC_7,       KC_8,      KC_9,      KC_0,       \
			S(KC_1),   S(KC_2), S(KC_3),         S(KC_4), S(KC_5),      /*******/ S(KC_6),   S(KC_7),    S(KC_8),   KC_EQL,    S(KC_SCLN), \
			S(KC_GRV), _______, TD(DOUBLE_QUOT), KC_QUOT, S(KC_BSLASH), /*******/ S(KC_EQL), TD(PARENS), TD(CURLY), TD(BRACS), KC_BSLASH,  \
			/*___*/    /*___*/  /*___*/          KC_GRV,  _______,      /*******/ _______,   _______     \
			),

	[_FUN] = LAYOUT( \
			_______, _______, C(A(KC_LEFT)), C(A(KC_RIGHT)), _______, /*******/ KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  TG(_GAME), \
			KC_F11,  KC_F12,  C(S(KC_LEFT)), C(S(KC_RIGHT)), _______, /*******/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, SS_FILE, \
			KC_F1,   KC_F2,   KC_F3,         KC_F4,          KC_F5,   /*******/ KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  \
			/*___*/  /*___*/  /*___*/        SS_COPY,        KC_ENT,  /*******/ KC_SLEP, _______  \
			),

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  return true;
}

typedef struct {
	uint16_t single;
	uint16_t begin_kc;
	uint16_t end_kc;
	bool shifted;
} td_config;

static const td_config td_configs[] = {
	[BRACS] = {
		.single = KC_LBRC,
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = false,
	},
	[CURLY] = {
		.single = KC_LBRC,
		.begin_kc = KC_LBRC,
		.end_kc = KC_RBRC,
		.shifted = true,
	},
	[PARENS] = {
		.single = KC_9,
		.begin_kc = KC_9,
		.end_kc = KC_0,
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
			register_code(config.begin_kc); unregister_code(config.begin_kc);
			register_code(config.end_kc); unregister_code(config.end_kc);
			if (config.shifted) {
				unregister_code(KC_LSFT);
			}
			register_code(KC_LEFT); unregister_code(KC_LEFT);
			break;
		case 2:
			if (config.shifted) {
				register_code(KC_LSFT);
			}
			register_code(config.end_kc); unregister_code(config.end_kc);
			if (config.shifted) {
				unregister_code(KC_LSFT);
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
		case GUI_T(KC_S):
			return TAPPING_TERM + 50;
		case GUI_T(KC_E):
			return TAPPING_TERM + 50;
		case ALT_T(KC_R):
			return TAPPING_TERM + 50;
		case ALT_T(KC_I):
			return TAPPING_TERM + 50;
		default:
			return TAPPING_TERM;
	}
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GUI_T(KC_S):
			return true;
		case GUI_T(KC_E):
			return true;
		case ALT_T(KC_R):
			return true;
		case ALT_T(KC_I):
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
	[BRACS] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[CURLY] = ACTION_TAP_DANCE_FN(double_your_pleasure),
	[PARENS] = ACTION_TAP_DANCE_FN(double_your_pleasure),
};
