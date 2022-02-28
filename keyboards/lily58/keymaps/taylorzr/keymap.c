#include QMK_KEYBOARD_H

enum my_layers {
  _QWERTY = 0,
  _COLEMAKDH,
  _L1,
  _L2,
};

#define SS_COPY S(G(C(KC_4)))
#define SS_FILE S(G(KC_4))

enum {
	SEMI_EQL = 0,
	SINGLE_QUOT,
	DOUBLE_QUOT,
	BRACKETS,
	CURLIES,
	PARENS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,        /*___*/         /*******/ /*___*/         XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, \
    XXXXXXX, KC_Q,        KC_W,        KC_E,        KC_R,    KC_T,           /*___*/         /*******/ /*___*/         KC_Y,          KC_U,    KC_I,    KC_O,    KC_P,         XXXXXXX, \
    XXXXXXX, SFT_T(KC_A), CTL_T(KC_S), CTL_T(KC_D), KC_F,    KC_G,           /*___*/         /*******/ /*___*/         KC_H,          KC_J,    KC_K,    KC_L,    TD(SEMI_EQL), XXXXXXX, \
    XXXXXXX, ALT_T(KC_Z), KC_X,        KC_C,        KC_V,    KC_B,           XXXXXXX,        /*******/ XXXXXXX,        KC_N,          KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      XXXXXXX, \
     /*___*/ /*___*/      /*___*/      _______,     _______, GUI_T(KC_MINS), LT(_L2,KC_SPC), /*******/ LT(_L1,KC_ENT), SFT_T(KC_ESC), _______, _______  \
  ),

  [_COLEMAKDH] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, /*___*/  /*******/ /*___*/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, \
    _______, _______, _______,     KC_F,        KC_P,    KC_B,    /*___*/  /*******/ /*___*/  KC_J,    KC_L,    KC_U,    KC_Y,    TD(SEMI_EQL), _______, \
    _______, _______, CTL_T(KC_R), CTL_T(KC_S), KC_T,    KC_G,    /*___*/  /*******/ /*___*/  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,         _______, \
    _______, _______, _______,     _______,     KC_D,    KC_V,    XXXXXXX, /*******/ XXXXXXX, KC_K,    KC_H,    _______, _______, _______,      _______, \
     /*___*/ /*___*/  /*___*/      _______,     _______, _______, _______, /*******/ _______, _______, _______, _______  \
  ),

  [_L1] = LAYOUT( \
    _______, _______,   _______,      _______,     _______,    _______,   /*___*/  /*******/ /*___*/  _______, _______,    _______, _______,         _______,         _______, \
    _______, KC_1,      KC_2,         KC_3,        KC_4,       KC_5,      /*___*/  /*******/ /*___*/  KC_6,    KC_7,       KC_8,    KC_9,            KC_0,            _______, \
    _______, S(KC_1),   S(KC_2),      S(KC_3),     S(KC_4),    S(KC_5),   /*___*/  /*******/ /*___*/  S(KC_6), S(KC_7),    S(KC_8), TD(DOUBLE_QUOT), TD(SINGLE_QUOT), _______, \
    _______, KC_BSLASH, S(KC_BSLASH), TD(CURLIES), S(KC_RBRC), S(KC_EQL), XXXXXXX, /*******/ XXXXXXX, KC_EQL,  TD(PARENS), S(KC_0), TD(BRACKETS),    KC_RBRC,         _______, \
    /*___*/  /*___*/    /*___*/       _______,     _______,    _______,   KC_BSPC, /*******/ _______, _______, _______,    _______  \
  ),

  [_L2] = LAYOUT( \
    _______, _______,   _______,   _______,       _______,        _______, /*___*/  /*******/ /*___*/  _______, _______,       _______,        _______,  _______,        _______, \
    _______, KC_GRV,    S(KC_GRV), KC_MS_WH_UP,   KC_MS_WH_DOWN,  KC_DEL,  /*___*/  /*******/ /*___*/  KC_MPLY, KC_VOLD,       KC_VOLU,        KC_MNXT,  DF(_QWERTY),    _______, \
    _______, KC_TAB,    _______,   C(S(KC_LEFT)), C(S(KC_RIGHT)), _______, /*___*/  /*******/ /*___*/  KC_LEFT, KC_DOWN,       KC_UP,          KC_RIGHT, DF(_COLEMAKDH), _______, \
    _______, S(KC_TAB), _______,   SS_COPY,       SS_FILE,        _______, XXXXXXX, /*******/ XXXXXXX, _______, C(A(KC_LEFT)), C(A(KC_RIGHT)), _______,  _______,        _______, \
     /*___*/ /*___*/    /*___*/    _______,       _______,        _______, _______, /*******/ _______, _______, _______,       _______         \
  ),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
/* } */

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

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

void semi_eql(qk_tap_dance_state_t *state, void *user_data) {
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

void single_quoting(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_QUOT); unregister_code(KC_QUOT);
    break;
  case 2:
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  }
}

void double_quoting(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	unregister_code(KC_LSFT);
    break;
  case 2:
    register_code(KC_LSFT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	unregister_code(KC_LSFT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  case 3:
    register_code(KC_LSFT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	register_code(KC_QUOT); unregister_code(KC_QUOT);
	register_code(KC_SCLN); unregister_code(KC_SCLN);
	unregister_code(KC_LSFT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  }
}

void brackets(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LBRC); unregister_code(KC_LBRC);
    break;
  case 2:
	register_code(KC_LBRC); unregister_code(KC_LBRC);
	register_code(KC_RBRC); unregister_code(KC_RBRC);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  }
}

// TODO combine these functions, can you inspect the keys being pressed?
// or actually you could double tap the matching key e.g. } instead of {
void curlies(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
	register_code(KC_LBRC); unregister_code(KC_LBRC);
	unregister_code(KC_LSFT);
    break;
  case 2:
    register_code(KC_LSFT);
	register_code(KC_LBRC); unregister_code(KC_LBRC);
	register_code(KC_RBRC); unregister_code(KC_RBRC);
	unregister_code(KC_LSFT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  case 3:
    register_code(KC_LSFT);
	register_code(KC_LBRC); unregister_code(KC_LBRC);
	unregister_code(KC_LSFT);

	register_code(KC_ENT); unregister_code(KC_ENT);
	register_code(KC_ENT); unregister_code(KC_ENT);

    register_code(KC_LSFT);
	register_code(KC_RBRC); unregister_code(KC_RBRC);
	unregister_code(KC_LSFT);

	register_code(KC_UP); unregister_code(KC_UP);
	register_code(KC_TAB); unregister_code(KC_TAB);
    break;
  }
}

void parens(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
	register_code(KC_9); unregister_code(KC_9);
	unregister_code(KC_LSFT);
    break;
  case 2:
    register_code(KC_LSFT);
	register_code(KC_9); unregister_code(KC_9);
	register_code(KC_0); unregister_code(KC_0);
	unregister_code(KC_LSFT);
	register_code(KC_LEFT); unregister_code(KC_LEFT);
    break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SEMI_EQL] = ACTION_TAP_DANCE_FN(semi_eql),
  [DOUBLE_QUOT] = ACTION_TAP_DANCE_FN(double_quoting),
  [SINGLE_QUOT] = ACTION_TAP_DANCE_FN(single_quoting),
  [BRACKETS] = ACTION_TAP_DANCE_FN(brackets),
  [CURLIES] = ACTION_TAP_DANCE_FN(curlies),
  [PARENS] = ACTION_TAP_DANCE_FN(parens),
};
