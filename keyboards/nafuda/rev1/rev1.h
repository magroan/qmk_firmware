#pragma once

#include "../nafuda.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);
/*
 * ,-----------------.
 * |     | L01 |     |
 * |-----------------+
 * | L10 | L11 | L12 |
 * |-----------------+
 * | L20 | L21 | L22 |
 * |-----------------'
 */

#define LAYOUT( \
         L01,      \
    L10, L11, L12, \
    L20, L21, L22  \
  ) \
  { \
    {KC_NO,  L01,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {  L10,  L11,  L12,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {  L20,  L21,  L22,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  }   \
  }

#define LAYOUT_kc( \
         L01,      \
    L10, L11, L12, \
    L20, L21, L22 \
  ) \
  LAYOUT( \
              KC_##L01,           \
    KC_##L10, KC_##L11, KC_##L12, \
    KC_##L20, KC_##L21, KC_##L22  \
  )



#define LAYOUT_for_Naked48( \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A, L0B,         R01,      \
    L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A, L1B,    R10, R11, R12, \
    L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A, L2B,    R20, R21, R22, \
    L30, L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A, L3B  \
  ) \
  { \
    {  L00,  L01,  L02,  L03,  L04,  L05,  L06,  L07,  L08,  L09,  L0A,  L0B,KC_NO,KC_NO  },  \
    {  L10,  L11,  L12,  L13,  L14,  L15,  L16,  L17,  L18,  L19,  L1A,  L1B,KC_NO,KC_NO  },  \
    {  L20,  L21,  L22,  L23,  L24,  L25,  L26,  L27,  L28,  L29,  L2A,  L2B,KC_NO,KC_NO  },  \
    {  L30,  L31,  L32,  L33,  L34,  L35,  L36,  L37,  L38,  L39,  L3A,  L3B,KC_NO,KC_NO  },  \
    {KC_NO,  R01,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,  R10,  R11,  R12,KC_NO,KC_NO,KC_NO  },  \
    {  R20,  R21,  R22,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  },  \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO  }   \
  }

#define LAYOUT_for_Naked48_kc( \
    L00, L01, L02, L03, L04, L05, L06, L07, L08, L09, L0A, L0B,         R01,      \
    L10, L11, L12, L13, L14, L15, L16, L17, L18, L19, L1A, L1B,    R10, R11, R12, \
    L20, L21, L22, L23, L24, L25, L26, L27, L28, L29, L2A, L2B,    R20, R21, R22, \
    L30, L31, L32, L33, L34, L35, L36, L37, L38, L39, L3A, L3B  \
  ) \
  LAYOUT_for_Naked48( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##L06, KC_##L07, KC_##L08, KC_##L09, KC_##L0A, KC_##L0B,                  KC_##R01,           \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15,                     KC_##L16, KC_##L17, KC_##L18, KC_##L19, KC_##L1A, KC_##L1B,        KC_##R10, KC_##R11, KC_##R12, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25,                     KC_##L26, KC_##L27, KC_##L28, KC_##L29, KC_##L2A, KC_##L2B,        KC_##R20, KC_##R21, KC_##R22, \
              KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##L36, KC_##L37, KC_##L38, KC_##L39, KC_##L3A, KC_##L3B  \
  )
