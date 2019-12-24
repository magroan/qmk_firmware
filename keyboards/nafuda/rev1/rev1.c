#include "nafuda.h"


#ifdef SSD1306OLED

void led_set_kb(uint8_t usb_led) {
}
#endif

void matrix_init_kb(void) {

	matrix_init_user();
};
