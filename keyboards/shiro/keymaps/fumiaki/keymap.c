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
};

enum custom_keycodes {
	macro1 = SAFE_RANGE,
	macro2,
	macro3,
	macro4,
	macro5,
	macro6,
	macro7,
	macro8,
	macro9,
	macro10,
	macro11,
	macro12,
	macro13,
	macro14,
	macro15
};

#define NUMBER TO(_NUMBER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_NUMBER] = LAYOUT(
	macro1, macro2, macro3,
	macro4, KC_PSCR, macro6,
	macro7, macro8, KC_NLCK,
	KC_ESC, KC_LCTL, KC_LSFT,
	macro13, macro14, macro15
	),
};


//MACRO

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			//ここから
		case macro1:
			//ここに動作を記述し
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("https'//www.youtube.com");//youtube
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
			//ここまでコピペ

			//ここから
		case macro2:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("https'//www.google.com");//グーグル
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
			//ここまでコピペ

			//ここから
		case macro3:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("https'//www.yahoo.co.jp");//ヤフー
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
			//ここまでコピペ
		case macro4:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("line.me");// ←わからない
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro5:
			//ここに動作を記述していく
//		SEND_STRING(SS_LGUI("r"));//Win+r
//			_delay_ms(500);
//		SEND_STRING("KC_PSCR");//スクショ
//			_delay_ms(500);
//		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro6:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("calc");//電卓
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro7:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("https'//twitter.com/");//ツイッター
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro8:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("notepad.exe");//メモ帳
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;



		case macro13:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("excel");//youtube
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro14:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("winword");//youtube
			_delay_ms(500);
       SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		case macro15:
			//ここに動作を記述していく
		SEND_STRING(SS_LGUI("r"));//Win+r
			_delay_ms(500);
		SEND_STRING("powerpnt");//youtube
			_delay_ms(500);
		SEND_STRING(SS_TAP(X_ENTER));//Enter

			return false;
			break;
		}
	}
	return true;
};
