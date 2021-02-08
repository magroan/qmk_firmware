#include QMK_KEYBOARD_H

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

#define _QWERTY 0

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  macro1,                          
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   4  |   5  |   6  |                    |   A  |   A  |   A  |   A  |   A  |  A   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   T  |   Q  |   W  |   E  |   R  |                    |   A  |   A  |   A  |   A  |   A  |  A   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Shift |   S  | F¨Q |   S  |   D  |   F  |-------.    ,-------|   A  |   A  |   A  |   A  |   A  |  A   |
 * |------+------+------+------+------+------|   P   |    |    A  |------+------+------+------+------+------|
 * |LCtrl |   F2 |  F3  |   F4 |   F5 |   B  |-------|    |-------|   A  |   A  |   A  |   A  |   A  |  A   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   B  |   7  | LALT | /Space  /       \   A  \| A  |   A  |   A  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_4,    KC_5,    KC_6,                     KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
  KC_LSHIFT, KC_S,   macro1,  KC_S, KC_D, KC_F,                     KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
  KC_LCTRL,  KC_F2,  KC_F3,KC_F4,   KC_F5,   KC_B,  KC_P,     KC_A,  KC_A,    KC_A,    KC_A,    KC_A,    KC_A,    KC_A,
                             KC_B, KC_7,KC_LALT, KC_SPC,     KC_A,  KC_A,    KC_A, KC_A \
)
};


int RGB_current_mode;

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
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case macro1:
      if (record->event.pressed) {
      	SEND_STRING("f");
	_delay_ms(1);
	SEND_STRING("q");
//	_delay_ms(5);
//	SEND_STRING("d");
      } 
      return false;
      break;
  }
  return true;
}


