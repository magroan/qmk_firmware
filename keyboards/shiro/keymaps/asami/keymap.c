/* Copyright 2019 T.Shinohara
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

enum layer_number {
  _MACROS = 0,
};

enum {
  TD_01L = 0,
  TD_01C,
  TD_01R,
  TD_02L,
  TD_02C,
  TD_02R,
  TD_03L,
  TD_03C,
  TD_03R,
  TD_04L,
  TD_04C,
  TD_04R,
  TD_05L,
  TD_05C,
  TD_05R,
};

#define MACROS TO(_MACROS)
#define KC_01L TD(TD_01L)
#define KC_01C TD(TD_01C)
#define KC_01R TD(TD_01R)
#define KC_02L TD(TD_02L)
#define KC_02C TD(TD_02C)
#define KC_02R TD(TD_02R)
#define KC_03L TD(TD_03L)
#define KC_03C TD(TD_03C)
#define KC_03R TD(TD_03R)
#define KC_04L TD(TD_04L)
#define KC_04C TD(TD_04C)
#define KC_04R TD(TD_04R)
#define KC_05L TD(TD_05L)
#define KC_05C TD(TD_05C)
#define KC_05R TD(TD_05R)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MACROS] = LAYOUT( 
    KC_01L,    KC_01C,    KC_01R,
    KC_02L,    KC_02C,    KC_02R,
    KC_03L,    KC_03C,    KC_03R,
    KC_04L,    KC_04C,    KC_04R,
    KC_05L,    KC_05C,    KC_05R
  )
};


void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
    case TD(TD_01L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("1");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_01C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("2");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_01R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("3");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_02L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("4");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_02C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("5");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_02R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("6");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_03L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("7");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_03C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("8");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_03R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("9");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_04L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("10");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_04C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("11");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_04R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("12");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_05L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("13");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_05C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("14");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_05R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(150);
	SEND_STRING("15");//
	_delay_ms(150);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
 }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {  // TapDanceの最後のリセット処理で実行される
  switch (state->keycode) {
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_01L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_01C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_01R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_02L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_02C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_02R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_03L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_03C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_03R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_04L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_04C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_04R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_05L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_05C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_05R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)
};