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
  _KANA = 0,
  _ALPHA,
  _MACROS
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
  TD_21L,
  TD_21C,
  TD_21R,
  TD_22L,
  TD_22C,
  TD_22R,
  TD_23L,
  TD_23C,
  TD_23R,
  TD_24L,
  TD_24C,
  TD_24R,
  TD_31L,
  TD_31C,
  TD_31R,
  TD_32L,
  TD_32C,
  TD_32R,
  TD_33L,
  TD_33C,
  TD_33R,
  TD_34L,
  TD_34C,
  TD_34R,
};

#define KANA TO(_KANA)
#define ALPHA TO(_ALPHA)
#define MACROS TO(_MACROS)

#define KC_1L TD(TD_1L)
#define KC_1C TD(TD_1C)
#define KC_1R TD(TD_1R)
#define KC_2L TD(TD_2L)
#define KC_2C TD(TD_2C)
#define KC_2R TD(TD_2R)
#define KC_3L TD(TD_3L)
#define KC_3C TD(TD_3C)
#define KC_3R TD(TD_3R)
#define KC_4L TD(TD_4L)
#define KC_4C TD(TD_4C)
#define KC_4R TD(TD_4R)


#define KC_21L TD(TD_21L)
#define KC_21C TD(TD_21C)
#define KC_21R TD(TD_21R)
#define KC_22L TD(TD_22L)
#define KC_22C TD(TD_22C)
#define KC_22R TD(TD_22R)
#define KC_23L TD(TD_23L)
#define KC_23C TD(TD_23C)
#define KC_23R TD(TD_23R)
#define KC_24L TD(TD_24L)
#define KC_24C TD(TD_24C)
#define KC_24R TD(TD_24R)


#define KC_31L TD(TD_31L)
#define KC_31C TD(TD_31C)
#define KC_31R TD(TD_31R)
#define KC_32L TD(TD_32L)
#define KC_32C TD(TD_32C)
#define KC_32R TD(TD_32R)
#define KC_33L TD(TD_33L)
#define KC_33C TD(TD_33C)
#define KC_33R TD(TD_33R)
#define KC_34L TD(TD_34L)
#define KC_34C TD(TD_34C)
#define KC_34R TD(TD_34R)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_KANA] = LAYOUT(
    KANA,   ALPHA,   MACROS,
    KC_1L,    KC_1C,    KC_1R,
    KC_2L,    KC_2C,    KC_2R,
    KC_3L,    KC_3C,    KC_3R,
    KC_ENT,   KC_BSPC,    KC_ENT
  ),
  [_ALPHA] = LAYOUT( 
    KANA,   ALPHA,   MACROS,
    KC_21L,    KC_21C,    KC_21R,
    KC_22L,    KC_22C,    KC_22R,
    KC_23L,    KC_23C,    KC_23R,
    KC_ENT,    KC_BSPC,   KC_ENT
  ), 
  [_MACROS] = LAYOUT( 
    KANA,   ALPHA,   MACROS,
    KC_31L,    KC_31C,    KC_31R,
    KC_32L,    KC_32C,    KC_32R,
    KC_33L,    KC_33C,    KC_33R,
    KC_34L,    KC_34C,    KC_34R
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
	SEND_STRING(SS_LALT("`"));
    break;
    case TD(TD_4C):
	SEND_STRING(SS_LALT("`"));
    break;
    case TD(TD_4R):
	SEND_STRING(SS_LALT("`"));
    break;

    case TD(TD_21L):
  	SEND_STRING(SS_LALT("`"));
    break;
    case TD(TD_21C):
      if (state->count == 1) {
	SEND_STRING("a");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("b");
      } else if (state->count == 3) {
	SEND_STRING("c");
      }
    break;
    case TD(TD_21R):
      if (state->count == 1) {
	SEND_STRING("d"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("e");
      } else if (state->count == 3) {
	SEND_STRING("f");
      }
    break;
    case TD(TD_22L):
      if (state->count == 1) {
	SEND_STRING("g"); // keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("h");
      } else if (state->count == 3) {
	SEND_STRING("i");
      }
    break;
    case TD(TD_22C):
      if (state->count == 1) {
	SEND_STRING("j");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("k");
      } else if (state->count == 3) {
	SEND_STRING("l");
      }
     break;
     case TD(TD_22R):
      if (state->count == 1) {
	SEND_STRING("m");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("n");
      } else if (state->count == 3) {
	SEND_STRING("o");
      }
    break;
    case TD(TD_23L):
      if (state->count == 1) {
	SEND_STRING("p");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("q");
      } else if (state->count == 3) {
	SEND_STRING("r");
      } else if (state->count == 4) {
	SEND_STRING("s");
      }
    break;
    case TD(TD_23C):
      if (state->count == 1) {
	SEND_STRING("t");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("u");
      } else if (state->count == 3) {
	SEND_STRING("v");
      } 
    break;
    case TD(TD_23R):
      if (state->count == 1) {
	SEND_STRING("w");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("x");
      } else if (state->count == 3) {
	SEND_STRING("y");
      } else if (state->count == 4) {
	SEND_STRING("z");
      }
    break;
    case TD(TD_24L):
      if (state->count == 1) {
	SEND_STRING("w");// keydown時の動作(''と入力)
      } else if (state->count == 2) {
	SEND_STRING("x");
      } else if (state->count == 3) {
	SEND_STRING("y");
      } else if (state->count == 4) {
	SEND_STRING("z");
      }
    break;
    case TD(TD_24C):
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
    case TD(TD_24R):
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

    case TD(TD_31L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("1");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_31C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("2");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_31R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("3");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_32L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("4");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_32C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("5");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_32R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("6");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_33L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("7");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_33C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("8");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_33R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("9");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_34L):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("10");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_34C):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("11");//
	_delay_ms(100);
	SEND_STRING(SS_TAP(X_ENTER));//Enter
    break;
    case TD(TD_34R):
	SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(100);
	SEND_STRING("12");//
	_delay_ms(100);
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

  [TD_21L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_21C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_21R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_22L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_22C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_22R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_23L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_23C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_23R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_24L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_24C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_24R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),

  [TD_31L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_31C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_31R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_32L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_32C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_32R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_33L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_33C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_33R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_34L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_34C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_34R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)

};