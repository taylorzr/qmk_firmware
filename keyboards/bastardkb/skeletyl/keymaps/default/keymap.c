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

// TODO Macros for parens and what not

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

// Testing changes
// - swap single/double quote
// - pane switching below arrows (F keys removed)
// - window resizing below desktop swapping

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // TODO: Better use of right side 3rd thumb key?
  [0] = LAYOUT_split_3x5_3(
      KC_Q, KC_W, KC_F,          KC_P,           KC_B,          KC_J,           KC_L,         KC_U,    KC_Y,   KC_QUOTE,
      KC_A, KC_R, KC_S,          KC_T,           KC_G,          KC_M,           KC_N,         KC_E,    KC_I,   KC_O,
      KC_Z, KC_X, KC_C,          KC_D,           KC_V,          KC_K,           KC_H,         KC_COMM, KC_DOT, KC_SLSH,
      /***/ /***/ CTL_T(KC_ESC), SFT_T(KC_BSPC), GUI_T(KC_DEL), ALT_T(KC_SCLN), LT(1,KC_SPC), LT(2,KC_MINS)
      ),

  [1] = LAYOUT_split_3x5_3(
      KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
      KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL, KC_COLN,
      KC_TILDE, KC_SCLN, MY_SQT,  MY_DQT,  KC_PIPE, KC_PLUS, MY_PAR,  MY_BRC,  MY_BKT, KC_BSLS,
      /***/     /***/    KC_GRV,  _______, _______, _______, _______, _______
      ),
  
  [2] = LAYOUT_split_3x5_3(
      _______, _______, _______,             _______,              _______, _______,       KC_VOLD,       KC_VOLU,     _______,        _______,
      _______, _______, LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_RIGHT)), _______, KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       _______,
      _______, _______, LCTL(LALT(KC_LEFT)), LCTL(LALT(KC_RIGHT)), _______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), _______,
      /***/    /***/    _______,             _______,              _______, _______,       _______,       _______
      ),
};
