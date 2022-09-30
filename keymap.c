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
  _LAYER_BRACKETS
};

// Tap Dance declarations
enum {
    TD_CNTL_E,
    TD_ALT_F4,
    TD_CNTL_ALT_DEL
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CNTL_E] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_E)),
    [TD_ALT_F4] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, LALT(KC_F4)),
    [TD_CNTL_ALT_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(LALT(KC_DEL)))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER_BASE] = LAYOUT_planck_1x2uC(
    LT(_LAYER_MEDIA,KC_ESC), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_TAB, LT(_LAYER_ARITHMETIC,KC_A), LT(_LAYER_SYMBOL,KC_S), LT(_LAYER_NAVIGATION,KC_D), LT(_LAYER_FUNCTION_KEY,KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_BTN5, KC_Z, KC_X, KC_C, KC_V, LT(_LAYER_BRACKETS,KC_B), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_BTN4, TD(TD_CNTL_E), TD(TD_ALT_F4), KC_APP, TD(TD_CNTL_ALT_DEL), KC_SPC, KC_RSFT, KC_HOME, KC_END, RGUI(RSFT(KC_S)), KC_DEL
  ),

  [_LAYER_ARITHMETIC] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_PMNS, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PPLS, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_PSLS, KC_ENT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_EQL, KC_DOT, KC_PAST, KC_DEL
  ),

  [_LAYER_NAVIGATION] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_PGDN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_LAYER_FUNCTION_KEY] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_LAYER_SYMBOL] = LAYOUT_planck_1x2uC(
    KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AMPR, KC_ASTR, KC_NO, KC_MINS, KC_BSLS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DLR, KC_PERC, KC_CIRC, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_EQL, KC_DOT, KC_NO, KC_DEL
  ),

  [_LAYER_MEDIA] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    RGB_HUI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_NO,
    RGB_HUD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_BRID, KC_VOLU
  ),

  [_LAYER_BRACKETS] = LAYOUT_planck_1x2uC(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL
  ),
};
