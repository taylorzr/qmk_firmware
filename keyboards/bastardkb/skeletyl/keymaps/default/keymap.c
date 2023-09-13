/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// row 1
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM wp_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM wfp_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM fb_combo[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM ju_combo[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
// row 2
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rs_combo[] = {ALT_T(KC_R), KC_S, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
//row 3
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xd_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM xcd_combo[] = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM hdot_combo[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM hcommadot_combo[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};
// thumb
const uint16_t PROGMEM spacedash_combo[] = {LT(1,KC_SPC), LT(2,KC_MINS), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // row 1
    COMBO(fp_combo, KC_TAB),
    COMBO(wf_combo, LSFT(KC_TAB)),
    COMBO(wp_combo, LSFT(LCTL(LGUI(KC_4)))),
    COMBO(wfp_combo, KC_DEL),
    COMBO(fb_combo, KC_MPLY),
    COMBO(ju_combo, KC_MNXT),
    COMBO(lu_combo, LCTL(KC_S)),
    COMBO(uy_combo, KC_QUOT),
    // row 2
    COMBO(rs_combo, LSFT(LCTL(KC_LEFT))),
    COMBO(st_combo, LSFT(LCTL(KC_RIGHT))),
    COMBO(ne_combo, KC_ENT),
    COMBO(ei_combo, KC_COLN),
    // row 3
    COMBO(xc_combo, KC_LBRC),
    COMBO(cd_combo, KC_LPRN),
    COMBO(xcd_combo, KC_LCBR),
    COMBO(hcomma_combo, KC_RPRN),
    COMBO(commadot_combo, KC_RBRC),
    COMBO(hcommadot_combo, KC_RCBR),
    // thumb
    COMBO(spacedash_combo, KC_UNDERSCORE),
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
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case MY_BRC:
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
        case MY_BKT:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case MY_DQT:
            if (record->event.pressed) {
                SEND_STRING("\"\"" SS_TAP(X_LEFT));
            }
            break;
        case MY_SQT:
            if (record->event.pressed) {
                SEND_STRING("''" SS_TAP(X_LEFT));
            }
            break;
    }
    return true;
};

// Testing changes
// - swap single/double quote
// - pane switching below arrows (F keys removed)
// - window resizing below desktop swapping

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // TODO: Better use of right side 3rd thumb key?
  [0] = LAYOUT_split_3x5_3(
      KC_Q, KC_W,        KC_F,          KC_P,          KC_B,           /***/ KC_J,         KC_L,          KC_U,    KC_Y,   KC_QUOTE,
      KC_A, ALT_T(KC_R), KC_S,          KC_T,          KC_G,           /***/ KC_M,         KC_N,          KC_E,    KC_I,   KC_O,
      KC_Z, KC_X,        KC_C,          KC_D,          KC_V,           /***/ KC_K,         KC_H,          KC_COMM, KC_DOT, KC_SLSH,
      /***/ /***/        GUI_T(KC_DEL), CTL_T(KC_ESC), SFT_T(KC_BSPC), /***/ LT(1,KC_SPC), LT(2,KC_MINS), ALT_T(KC_SCLN)
      ),

  [1] = LAYOUT_split_3x5_3(
      KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC, /***/ KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS,  KC_MINS,
      KC_TILDE, KC_GRV, MY_SQT,  MY_DQT,  KC_PIPE, /***/ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BSLS,
      _______,  MY_BKT, MY_BRC,  MY_PAR,  KC_SCLN, /***/ KC_COLN, KC_EQL,  _______, _______,  _______,
      /***/     /***/   _______, _______, _______, /***/ _______, _______, _______
      ),

  [2] = LAYOUT_split_3x5_3(
      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, /***/ KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS,  KC_MINS,
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /***/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      _______, _______, _______, _______, _______, /***/ _______, _______, _______, _______, _______,
      /***/    /***/    _______, _______, _______, /***/ _______, _______, _______
      ),
};
