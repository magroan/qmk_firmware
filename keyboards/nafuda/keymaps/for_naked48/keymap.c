/* Copyright 2018 Salicylic_Acid
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
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _MOUSE 1
#define _BROWSER 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MOUSE,
  BROWSER,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC_MOUSE MOUSE
#define KC_BROWSER BROWSER

#define KC_ADJUST ADJUST

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO

#define KC_RST   RESET
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_JCLON KC_QUOT  // : and +
#define KC_JAT   KC_LBRC  // @ and `
#define KC_JHAT  KC_EQL   // ^ and ~
#define KC_JENUN KC_RO    // \ and _ (EN mark and UNder score)
#define KC_JENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define KC_JLBRC KC_RBRC  // [ and {
#define KC_JRBRC KC_BSLS  // ] and }
#define KC_JAMPR KC_CIRC  // &
#define KC_JQUES LSFT(KC_SLSH)  // ?
#define KC_JTILD LSFT(KC_EQL)  // ~
#define KC_JQUOT LSFT(KC_7)  // '
#define KC_JLPRN KC_ASTR  // (
#define KC_JRPRN KC_LPRN  // )
#define KC_JLCBR KC_RCBR  // {
#define KC_JRCBR KC_PIPE  // }
#define KC_JPIPE LSFT(KC_JYEN)  // |
#define KC_JASTR LSFT(KC_QUOT)  // *
#define KC_JEQL LSFT(KC_MINS)  // =
#define KC_JPLUS LSFT(KC_SCLN)  // +
#define KC_JDQUO LSFT(KC_2)  // "
#define KC_SF11 SFT_T(KC_F11)
#define KC_SF12 LCTL_T(KC_F12)
#define KC_LEN LT(_LOWER, KC_ENT)
#define KC_RSP LT(_RAISE, KC_SPC)
#define KC_CAD LCA(KC_DEL)
#define KC_APSCR LALT(KC_PSCR)

#define KC_RTAB LCTL(KC_TAB)
#define KC_LTAB LCTL(LSFT(KC_TAB))
#define KC_CTAB LCTL(KC_W)
#define KC_RETAB LCTL(LSFT(KC_T))

#define KC_TGMO TG(_MOUSE)
#define KC_TGBR TG(_BROWSER)
#define KC_BSAD LT(_ADJUST, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_for_Naked48_kc( \
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        TAB,     Q,     W,     E,     R,     T,                   Y,     U,     I,     O,     P, JLBRC,                TGMO,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       LSFT,     A,     S,     D,     F,     G,                   H,     J,     K,     L,  MINS, JRBRC,         BSAD,    UP,  TGBR, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
      LCTRL,     Z,     X,     C,     V,     B,                   N,     M,  COMM,   DOT,  SLSH, JENUN,         LEFT,  DOWN, RIGHT, \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
              LEFT, RIGHT,  LGUI,  MHEN,   LEN,  BSPC,   DEL,   RSP,  HENK,  LALT,    UP,  DOWN  \
          //`----------------------------------------------------------------------------------|
  ),

  [_MOUSE] = LAYOUT_for_Naked48_kc( \
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        TAB,     Q,     W,     E,     R,     T,                   Y,     U,     I,     O,     P, JLBRC,                TGMO,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       LSFT,     A,     S,     D,     F,     G,                   H,     J,     K,     L,  MINS, JRBRC,         BTN1,  MS_U,  BTN2, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
      LCTRL,     Z,     X,     C,     V,     B,                   N,     M,  COMM,   DOT,  SLSH, JENUN,         MS_L,  MS_D,  MS_R, \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
              LEFT, RIGHT,  LGUI,  MHEN,   LEN,  BSPC,   DEL,   RSP,  HENK,  LALT,    UP,  DOWN  \
          //`----------------------------------------------------------------------------------|
  ),

  [_BROWSER] = LAYOUT_for_Naked48_kc( \
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        TAB,     Q,     W,     E,     R,     T,                   Y,     U,     I,     O,     P, JLBRC,                CTAB,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       LSFT,     A,     S,     D,     F,     G,                   H,     J,     K,     L,  MINS, JRBRC,        RETAB,  WH_U,  TGBR, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
      LCTRL,     Z,     X,     C,     V,     B,                   N,     M,  COMM,   DOT,  SLSH, JENUN,         LTAB,  WH_D,  RTAB, \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
              LEFT, RIGHT,  LGUI,  MHEN,   LEN,  BSPC,   DEL,   RSP,  HENK,  LALT,    UP,  DOWN  \
          //`----------------------------------------------------------------------------------|
  ),

  [_LOWER] = LAYOUT_for_Naked48_kc( \
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        ESC,  EXLM, JQUES, JLBRC, JRBRC, JTILD,                   6,     7,     8,     9, JASTR,  SLSH,                TGMO,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
      JQUOT,  HASH, JDQUO, JLPRN, JRPRN,   JAT,               XXXXX,     4,     5,     6, _____,  JEQL,         BSAD,    UP,  TGBR, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       JHAT,  PERC, JAMPR,  SCLN, JCLON, JPIPE,                   0,     1,     2,     3, JPLUS,   ENT,         LEFT,  DOWN, RIGHT,  \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
             _____, _____, _____,  ZKHK, LOWER, _____, _____, RAISE,     0,   DOT, _____, _____  \
          //`----------------------------------------------------------------------------------|
  ),


  [_RAISE] = LAYOUT_for_Naked48_kc( \
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        ESC,     1,     2,     3,     4,     5,                   6, XXXXX,    UP, XXXXX,  PGUP,  BSPC,                TGMO,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       SF11,    F1,    F2,    F3,    F4,    F5,               XXXXX,  LEFT,  DOWN, RIGHT,  LSFT,   ENT,         BSAD,    UP,  TGBR, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       SF12,    F6,    F7,    F8,    F9,   F10,               XXXXX, XXXXX, XXXXX, XXXXX,  PGDN, XXXXX,         LEFT,  DOWN, RIGHT,  \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
             _____, _____, _____, _____, LOWER, _____, _____, RAISE, _____, _____, _____, _____  \
          //`----------------------------------------------------------------------------------|
  ),


  [_ADJUST] = LAYOUT_for_Naked48_kc( /* Base */
  //,-----------------------------------------|             |-----------------------------------------|      |--------------------|
        ESC,     1,     2,     3,     4,     5,                   6,     7,     8,     9,     0,   DEL,                LVAD,        \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       SF11,    F1,    F2,    F3,    F4,    F5,                LTOG,  LMOD, XXXXX,   CAD, APSCR,  PSCR,       ADJUST,  LSAD,  LVAI, \
  //|------+------+------+------+------+------|             |------+------+------+------+------+------|      |------+------+------|
       SF12,    F6,    F7,    F8,    F9,   F10,                LVAD,  LVAI,  LHUD,  LHUI,  LSAD,  LSAI,         LMOD,  LTOG,  LSAI, \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|             |--------------------|
             _____, _____, _____, _____, LOWER, _____, _____, RAISE, _____, _____, _____, _____  \
          //`----------------------------------------------------------------------------------|
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;
  }
  return true;
}
