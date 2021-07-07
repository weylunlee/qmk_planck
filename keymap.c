/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _LAYER_BASE,
  _LAYER_ARITHMETIC,
  _LAYER_NAVIGATION,
  _LAYER_FUNCTION_KEY,
  _LAYER_SYMBOL,
  _LAYER_MEDIA,
  _LAYER_NAVIGATION_ALT,
  _LAYER_ENCODER_WORD_SELECT
};

// Tap Dance declarations
enum {
    TD_EXPLORER,
    TD_CLOSE_APP
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_EXPLORER] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
    [TD_CLOSE_APP] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_F4))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER_BASE] = LAYOUT_planck_1x2uC(
    LT(1,KC_ESC), KC_Q, KC_W, LT(6,KC_E), KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    LT(2,KC_TAB), LT(1,KC_A), LT(4,KC_S), LT(2,KC_D), LT(3,KC_F), KC_G, KC_H, LT(7,KC_J), KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_BTN5, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, LT(5,KC_M), KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_BTN4, TD(TD_EXPLORER), TD(TD_CLOSE_APP), KC_APP, KC_LCTL, KC_SPC, KC_RSFT, KC_HOME, KC_END, KC_WH_U, KC_WH_D
  ),

  [_LAYER_ARITHMETIC] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_PMNS, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PPLS, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_PSLS, KC_ENT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_EQL, KC_DOT, KC_PAST, KC_NO
  ),

  [_LAYER_NAVIGATION] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_INS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_DEL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_LAYER_FUNCTION_KEY] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_LAYER_SYMBOL] = LAYOUT_planck_1x2uC(
    KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AMPR, KC_ASTR, KC_NO, KC_MINS, KC_BSLS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_LCBR, KC_RCBR,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_EQL, KC_DOT, KC_LBRC, KC_RBRC
  ),

  [_LAYER_MEDIA] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_HUI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_NO,
    RGB_HUD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_BRID, KC_VOLU
  ),

  [_LAYER_NAVIGATION_ALT] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_END, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  )

  [_LAYER_ENCODER_WORD_SELECT] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  )
};

void encoder_update(bool clockwise) {
  if (IS_LAYER_ON(_LAYER_NAVIGATION)) {
    if (clockwise) {
      tap_code(KC_MS_WH_DOWN);
    }
    else {
      tap_code(KC_MS_WH_UP);
    }
  }
  else if (IS_LAYER_ON(_LAYER_MEDIA)) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  else if (IS_LAYER_ON(_LAYER_ENCODER_WORD_SELECT)) {
    if (clockwise) {
      tap_code16(C(S(KC_RIGHT)));
    } else {
      tap_code16(C(S(KC_LEFT)));
    }
  }
  else {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  }
}
