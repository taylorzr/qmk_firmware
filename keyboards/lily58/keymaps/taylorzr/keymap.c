#include QMK_KEYBOARD_H

enum my_layers {
  _QWERTY = 0,
  _COLEMAK,
  _KYRIA,
  _RAISE,
  _ADJUST,
};

enum my_keycodes {
  NEWLINE = SAFE_RANGE,
};

enum my_tapdances {
  TD_LBRC_HOME = 0,
  TD_RBRC_END,
  TD_5_COPY,
  TD_6_PSTE,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_HOME),
  [TD_RBRC_END]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_END),
  [TD_5_COPY]    = ACTION_TAP_DANCE_DOUBLE(KC_5, RGUI(KC_C)),
  [TD_6_PSTE]    = ACTION_TAP_DANCE_DOUBLE(KC_6, RGUI(KC_V)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Maybe use shift as home / end?
  // Double tag tab -> alt-tab?
  [_QWERTY] = LAYOUT( \
    KC_EQL,             KC_1,   KC_2,   KC_3,    KC_4,     TD(TD_5_COPY),  /*___*/           /*___*/          TD(TD_6_PSTE),     KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,            \
    LALT_T(KC_TAB),     KC_Q,   KC_W,   KC_E,    KC_R,     KC_T,           /*___*/           /*___*/          KC_Y,              KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLASH,          \
    LCTL_T(KC_GRV),     KC_A,   KC_S,   KC_D,    KC_F,     KC_G,           /*___*/           /*___*/          KC_H,              KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,            \
    LSFT_T(LSFT(KC_9)), KC_Z,   KC_X,   KC_C,    KC_V,     KC_B,           TD(TD_LBRC_HOME), TD(TD_RBRC_END), KC_N,              KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(LSFT(KC_0)), \
    /*___*/             /*___*/ /*___*/ KC_LEFT, KC_RIGHT, LGUI_T(KC_ESC), KC_BSPC,          KC_SPC,          LT(_RAISE,KC_ENT), KC_DOWN, KC_UP    \
  ),

  [_COLEMAK] = LAYOUT( \
    KC_EQL,             KC_1,   KC_2,   KC_3,    KC_4,     TD(TD_5_COPY),  /*___*/           /*___*/          TD(TD_6_PSTE),     KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,            \
    LALT_T(KC_TAB),     KC_Q,   KC_W,   KC_F,    KC_P,     KC_B,           /*___*/           /*___*/          KC_J,              KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSLASH,          \
    LCTL_T(KC_GRV),     KC_A,   KC_R,   KC_S,    KC_T,     KC_G,           /*___*/           /*___*/          KC_M,              KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,            \
    LSFT_T(LSFT(KC_9)), KC_Z,   KC_X,   KC_C,    KC_D,     KC_V,           TD(TD_LBRC_HOME), TD(TD_RBRC_END), KC_K,              KC_H,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(LSFT(KC_0)), \
    /*___*/             /*___*/ /*___*/ KC_LEFT, KC_RIGHT, LGUI_T(KC_ESC), KC_BSPC,          KC_SPC,          LT(_RAISE,KC_ENT), KC_DOWN, KC_UP    \
  ),

  [_KYRIA] = LAYOUT( \
    KC_EQL,             KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_NO,          /*___*/           /*___*/          KC_NO,             KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_MINS,            \
    LALT_T(KC_TAB),     KC_Q,   KC_W,   KC_E,    KC_R,     KC_T,           /*___*/           /*___*/          KC_Y,              KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLASH,          \
    LCTL_T(KC_GRV),     KC_A,   KC_S,   KC_D,    KC_F,     KC_G,           /*___*/           /*___*/          KC_H,              KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,            \
    LSFT_T(LSFT(KC_9)), KC_Z,   KC_X,   KC_C,    KC_V,     KC_B,           TD(TD_LBRC_HOME), TD(TD_RBRC_END), KC_N,              KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(LSFT(KC_0)), \
    /*___*/             /*___*/ /*___*/ KC_LEFT, KC_RIGHT, LGUI_T(KC_ESC), KC_BSPC,          KC_SPC,          LT(_RAISE,KC_ENT), KC_DOWN, KC_UP    \
  ),

  [_RAISE] = LAYOUT( \
    _______, DF(_QWERTY), DF(_COLEMAK), DF(_KYRIA), KC_MPLY,    KC_MNXT,    /*___*/     /*___*/     KC_VOLD,    KC_VOLU,    _______,    _______,    _______,    _______, \
    _______, KC_1,        KC_2,         KC_3,       KC_4,       KC_5,       /*___*/     /*___*/     KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______, \
    KC_SLEP, LSFT(KC_1),  LSFT(KC_2),   LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), /*___*/     /*___*/     LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______, \
    _______, _______,     _______,      KC_LEFT,    KC_RIGHT,   _______,    LSFT(KC_9), LSFT(KC_0), _______,    KC_DOWN,    KC_UP,      _______,    _______,    _______, \
     /*___*/ /*___*/      /*___*/       _______,    _______,    KC_DEL,     _______,    _______,    _______,    _______,    _______     \
  ),

  [_ADJUST] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               _______, _______, _______, _______, _______,  _______, _______, _______ \
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

// TODO: Do I need this?!?! Don't think so?
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if (record->event.pressed) { */
/* #ifdef OLED_DRIVER_ENABLE */
/*     set_keylog(keycode, record); */
/* #endif */
/*     // set_timelog(); */
/*   } */
/*   return true; */
/* } */

// TODO: Figure out how to use macros
// https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case NEWLINE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("\\n");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

