#include QMK_KEYBOARD_H

enum my_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
           KC_GRV, KC_1,   KC_2,   KC_3,    KC_4,    KC_5,              /*___*/        /*******/ /*___*/            KC_6,          KC_7,    KC_8,    KC_9,   KC_0,    KC_BSLASH,        \
    ALT_T(KC_EQL), KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,              /*___*/        /*******/ /*___*/            KC_Y,          KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,          \
    CTL_T(KC_TAB), KC_A,   KC_S,   KC_D,    KC_F,    KC_G,              /*___*/        /*******/ /*___*/            KC_H,          KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,          \
    SFT_T(KC_GRV), KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,              _______,       /*******/ XXXXXXX,           KC_N,          KC_M,    KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_BSLASH), \
           /*___*/ /*___*/ /*___*/ _______, _______, LT(_RAISE,KC_SPC), GUI_T(KC_ESC), /*******/ LT(_LOWER,KC_ENT), SFT_T(KC_DEL), _______, _______  \
  ),

  [_LOWER] = LAYOUT( \
    _______, DF(_QWERTY), _______, _______,    _______,    _______, /*___*/  /*******/ /*___*/  _______, _______, _______, _______, _______, _______, \
    _______, KC_1,        KC_2,    KC_3,       KC_4,       KC_5,    /*___*/  /*******/ /*___*/  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, S(KC_1),     S(KC_2), S(KC_3),    S(KC_4),    S(KC_5), /*___*/  /*******/ /*___*/  S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, \
    _______, _______,     _______, S(KC_LBRC), S(KC_RBRC), _______, XXXXXXX, /*******/ XXXXXXX, KC_LBRC, KC_RBRC, _______, _______, _______, _______, \
    /*___*/  /*___*/      /*___*/  _______,    _______,    _______, KC_BSPC, /*******/ _______, _______, _______, _______  \
  ),

  [_RAISE] = LAYOUT( \
    _______, _______, _______,       _______,    _______,    _______,  /*___*/  /*******/ /*___*/  _______, _______,    _______,    _______,  _______,      _______, \
     KC_DEL, _______, S(G(KC_4)),    KC_LBRC,    KC_RBRC,    TG(_NAV), /*___*/  /*******/ /*___*/  KC_MPLY, KC_VOLD,    KC_VOLU,    KC_MNXT,  _______,      KC_DEL,  \
    _______, _______, S(G(C(KC_4))), S(KC_9),    S(KC_0),    KC_HOME,  /*___*/  /*******/ /*___*/  KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT, S(KC_BSLASH), _______, \
    _______, S(KC_3), S(KC_4),       S(KC_LBRC), S(KC_RBRC), KC_END,   XXXXXXX, /*******/ XXXXXXX, _______, KC_MS_BTN1, KC_MS_BTN2, _______,  KC_BSLASH,    _______, \
     /*___*/ /*___*/  /*___*/        _______,    _______,    _______,  _______, /*******/ KC_BSPC, _______, _______,    _______     \
  ),

  [_NAV] = LAYOUT( \
    _______, _______, _______,      _______,       _______,       _______,  /*___*/  /*******/ /*___*/  _______,  _______,      _______,       _______,       _______, _______, \
    _______, _______, LCA(KC_U),    LCA(KC_UP),    LCA(KC_I),     _______,  /*___*/  /*******/ /*___*/  _______,  LCA(KC_U),    LCA(KC_UP),    LCA(KC_I),     _______, _______, \
    _______, _______, LCA(KC_LEFT), LCA(KC_ENT),   LCA(KC_RIGHT), _______,  /*___*/  /*******/ /*___*/  _______,  LCA(KC_LEFT), LCA(KC_ENTER), LCA(KC_RIGHT), _______, _______, \
    _______, _______, LCA(KC_J),    LCA(KC_RIGHT), LCA(KC_K),     _______,  XXXXXXX, /*******/ XXXXXXX, _______,  LCA(KC_J),    LCA(KC_DOWN),  LCA(KC_K),     _______, _______, \
    /*___*/  /*___*/  /*___*/       _______,       _______,       TG(_NAV), _______, /*******/ _______, TG(_NAV), _______,      _______        \
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
