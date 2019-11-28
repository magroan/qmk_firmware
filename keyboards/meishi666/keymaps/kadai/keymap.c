/* Copyright 2019 %YOUR_NAME%
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
#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif
//Sleep?
#include <unistd.h>

#ifdef SSD1306OLED
  #include "ssd1306.h"
  #include <string.h>
  #include "print.h"
  #include "common/glcdfont.c"
  #include "sendchar.h"
  #include "common/oled_helper.h"
#endif
enum {
  TD_1L = 0,
  TD_1C,
  TD_1R,
  TD_2L,
  TD_2C,
  TD_2R,
};

//マクロ定義
enum custom_keycodes {
  macro1L = SAFE_RANGE,
  macro1C,
  macro1R,
  macro2L,
  macro2C,
  macro2R,
  };

enum layer_number {
  _CTL = 0,
  _MOUSE
};

#define KC_1L TD(TD_1L)
#define KC_1C TD(TD_1C)
#define KC_1R TD(TD_1R)
#define KC_2L TD(TD_2L)
#define KC_2C TD(TD_2C)
#define KC_2R TD(TD_2R)

#define CTL    TO(_CTL)
#define MOUSE  TO(_MOUSE)
#define CP     M(0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CTL] = LAYOUT(
    KC_1L, MOUSE,  macro1R,
           KC_1C,
    KC_2L, KC_2C, KC_WBAK
  ),
  [_MOUSE] = LAYOUT(
    KC_MS_BTN1, CTL,        KC_MS_BTN2,
                KC_MS_UP,
    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
  )
};


void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
 //   stop_all_notes();
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_CTL 0
#define L_MOUSE (1<<_MOUSE)

void render_status(struct CharacterMatrix *matrix) {
  render_logo(matrix);
  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf, sizeof(buf), "Undef-%ld", layer_state);
  switch (layer_state) {
     case L_CTL:
      matrix_write_P(matrix, PSTR("Control Mode\n"));
      break;
    case L_MOUSE:
      matrix_write_P(matrix, PSTR("Mouse Mode\n"));
      break;
    default:
      break;
      matrix_write(matrix, buf);
  }
  UPDATE_LED_STATUS();
  RENDER_LED_STATUS(matrix);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  render_status(&matrix);
  matrix_update(&display, &matrix);
}
#endif

//マクロ定義

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case macro1R:
//ここに動作を記述していく
//例:       SEND_STRING(SS_LALT(SS_TAP(X_TAB)));//Win+TAB

                return false;
	    break;
        }
    }
    return true;
};


//タップダンス
void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
    case TD(TD_1L):
      if (state->count == 1) {
       SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(500);
       SEND_STRING("notepad.exe");//メモ帳
	_delay_ms(500);
       SEND_STRING(SS_TAP(X_ENTER));//Enter
      } 
    break;
    case TD(TD_1C):
      if (state->count == 1) {
       SEND_STRING(SS_LGUI(SS_TAP(X_UP)));//Win+UP
	
      }
    break;
    case TD(TD_1R):
      if (state->count == 1) {
	SEND_STRING(""); // keydown時の動作("入力")
      } 
    break;
    
    case TD(TD_2L):
      if (state->count == 1) {
       SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(500);
       SEND_STRING("osk");//on screen keybord
	_delay_ms(500);
       SEND_STRING(SS_TAP(X_ENTER));//Enter


      } 
    break;
    case TD(TD_2C):
      if (state->count == 1) {
       SEND_STRING(SS_LGUI("r"));//Win+r
	_delay_ms(500);
       SEND_STRING("https'//www.youtube.com/");//メモ帳
	_delay_ms(500);
       SEND_STRING(SS_TAP(X_ENTER));//Enter

      }          
    break;
    case TD(TD_2R):
      if (state->count == 1) {
	SEND_STRING(""); // keydown時の動作("入力")
      } 
    break;
  }
};

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {  // TapDanceの最後のリセット処理で実行される
  switch (state->keycode) {
      break;
  }
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_1C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_1R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_2L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_2C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
  [TD_2R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
};
