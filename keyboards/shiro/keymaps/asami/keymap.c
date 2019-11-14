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
  _NUMBER = 0,
  _CURSOL,
  _TOGGLE
};

enum {
  TD_1L = 0,
  TD_1C,
  TD_1R,

  TD_2L,
  TD_2C,
  TD_2R,

  TD_3L,
  TD_3C,
  TD_3R,

  TD_4L,
  TD_4C,
  TD_4R,
};

#define NUMBER TO(_NUMBER)
#define CURSOL TO(_CURSOL)
#define TOGGLE TO(_TOGGLE)

#define KC_1L TD(TD_1L)
#define KC_1C TD(TD_1C)
#define KC_1R TD(TD_1R)

#define KC_2L TD(TD_2L)
#define KC_2C TD(TD_2C)
#define KC_2R TD(TD_2R)

#define KC_3L TD(TD_3L)
#define KC_3C TD(TD_3C)
#define KC_3R TD(TD_3R)

//#define KC_4L TD(TD_4L)
#define KC_4C TD(TD_4C)
//#define KC_4R TD(TD_4R)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NUMBER] = LAYOUT( 
    NUMBER,   CURSOL,   TOGGLE,
    KC_P7,    KC_P8,    KC_P9,
    KC_P4,    KC_P5,    KC_P6,
    KC_P1,    KC_P2,    KC_P3,
    KC_BSPC,  KC_P0,    KC_ENT
  ),
  [_CURSOL] = LAYOUT( 
    NUMBER,   CURSOL,   TOGGLE,
    KC_HOME,  KC_UP,    KC_PGUP,
    KC_LEFT,  KC_ESC,   KC_RIGHT,
    KC_END,   KC_DOWN,  KC_PGDN,
    KC_BSPC,  KC_DEL,   KC_ENT
  ), 
  [_TOGGLE] = LAYOUT( 
    NUMBER,   CURSOL,   TOGGLE,
    KC_1L,    KC_1C,    KC_1R,
    KC_2L,    KC_2C,    KC_2R,
    KC_3L,    KC_3C,    KC_3R,
    KC_BSPC,  KC_4C,    KC_ENT
  ),
};


void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
    case TD(TD_1L):
      if (state->count == 1) {
	SEND_STRING("a"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("i");
      } else if (state->count == 3) {
	SEND_STRING("u");
      } else if (state->count == 4) {
	SEND_STRING("e");
      } else if (state->count == 5) {
	SEND_STRING("o");
      }
    break;
    case TD(TD_1C):
      if (state->count == 1) {
	SEND_STRING("ka");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("ki");
      } else if (state->count == 3) {
	SEND_STRING("ku");
      } else if (state->count == 4) {
	SEND_STRING("ke");
      } else if (state->count == 5) {
	SEND_STRING("ko");
      }
    break;
    case TD(TD_1R):
      if (state->count == 1) {
	SEND_STRING("sa"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("si");
      } else if (state->count == 3) {
	SEND_STRING("su");
      } else if (state->count == 4) {
	SEND_STRING("se");
      } else if (state->count == 5) {
	SEND_STRING("so");
      }
    break;
    case TD(TD_2L):
      if (state->count == 1) {
	SEND_STRING("ta"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("ti");
      } else if (state->count == 3) {
	SEND_STRING("tu");
      } else if (state->count == 4) {
	SEND_STRING("te");
      } else if (state->count == 5) {
	SEND_STRING("to");
      }
    break;
    case TD(TD_2C):
      if (state->count == 1) {
	SEND_STRING("na");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("ni");
      } else if (state->count == 3) {
	SEND_STRING("nu");
      } else if (state->count == 4) {
	SEND_STRING("ne");
      } else if (state->count == 5) {
	SEND_STRING("no");
      }
     break;
     case TD(TD_2R):
      if (state->count == 1) {
	SEND_STRING("ha");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("hi");
      } else if (state->count == 3) {
	SEND_STRING("hu");
      } else if (state->count == 4) {
	SEND_STRING("he");
      } else if (state->count == 5) {
	SEND_STRING("ho");
      }
    break;
    case TD(TD_3L):
      if (state->count == 1) {
	SEND_STRING("ma");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("mi");
      } else if (state->count == 3) {
	SEND_STRING("mu");
      } else if (state->count == 4) {
	SEND_STRING("me");
      } else if (state->count == 5) {
	SEND_STRING("mo");
      }
    break;
    case TD(TD_3C):
      if (state->count == 1) {
	SEND_STRING("ya");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("xi");
      } else if (state->count == 3) {
	SEND_STRING("yu");
      } else if (state->count == 4) {
	SEND_STRING("xe");
      } else if (state->count == 5) {
	SEND_STRING("yo");
      }
    break;
    case TD(TD_3R):
      if (state->count == 1) {
	SEND_STRING("ra");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("ri");
      } else if (state->count == 3) {
	SEND_STRING("ru");
      } else if (state->count == 4) {
	SEND_STRING("re");
      } else if (state->count == 5) {
	SEND_STRING("ro");
      }
    break;
    case TD(TD_4L):
      if (state->count == 1) {
	SEND_STRING("xa");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("xi");
      } else if (state->count == 3) {
	SEND_STRING("xu");
      } else if (state->count == 4) {
	SEND_STRING("xe");
      } else if (state->count == 5) {
	SEND_STRING("xo");
      }
    break;
    case TD(TD_4C):
      if (state->count == 1) {
	SEND_STRING("wa");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("wo");
      } else if (state->count == 3) {
	SEND_STRING("nn");
      } else if (state->count == 4) {
	SEND_STRING("xtu");
      } else if (state->count == 5) {
	SEND_STRING(SS_LALT("`"));
      }
    break;
    case TD(TD_4R):
      if (state->count == 1) {
	SEND_STRING("Yes"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("No");
      } else if (state->count == 3) {
	SEND_STRING("Hello");
      } else if (state->count == 4) {
	SEND_STRING("Bye");
      } else if (state->count == 5) {
	SEND_STRING("one more please");
      }
    break;
 }
}


void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {  // TapDanceの最後のリセット処理で実行される
  switch (state->keycode) {
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_1C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_1R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),

  [TD_2L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_2C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_2R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),

  [TD_3L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_3C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_3R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),

  [TD_4L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_4C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_4R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
};