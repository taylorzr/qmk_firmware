/* Copyright 2021 Zach Taylor
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

enum card_board_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

#define RAISE MO(_RAISE)
#define LOWER MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_default(
     KC_EQL,         KC_Q,   KC_W,   KC_E,   KC_R,           KC_T,            KC_Y,              KC_U,              KC_I,    KC_O,   KC_P,    KC_MINS,
     LCTL_T(KC_TAB), KC_A,   KC_S,   KC_D,   KC_F,           KC_G,            KC_H,              KC_J,              KC_K,    KC_L,   KC_SCLN, KC_QUOT,
     LSFT_T(KC_GRV), KC_Z,   KC_X,   KC_C,   KC_V,           KC_B,            KC_N,              KC_M,              KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLASH),
     /*___*/         /*___*/ /*___*/ KC_DEL, LALT_T(KC_ESC), LGUI_T(KC_BSPC), LT(_LOWER,KC_SPC), LT(_RAISE,KC_ENT), KC_BSLASH
  ),

    [_LOWER] = LAYOUT_default(
     _______, KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
     _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), _______,
     _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,
     /*___*/  /*___*/     /*___*/     _______,    _______,    KC_BSPC,    _______,    _______,    _______
  ),


  [_RAISE] = LAYOUT_default(
     _______, _______, _______, LSFT(KC_LBRC), LSFT(KC_RBRC), _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT,  _______, KC_DEL,
     _______, _______, _______, KC_LBRC,       KC_RBRC,       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
     _______, _______, _______, LSFT(KC_9),    LSFT(KC_0),    _______, _______, _______, _______, _______,  _______, _______,
     /*___*/  /*___*/  /*___*/  _______,       _______,       _______, _______, _______, _______
  ),
};
