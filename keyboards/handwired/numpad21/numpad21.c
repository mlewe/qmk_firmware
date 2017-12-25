#include "numpad21.h"

#ifdef USE_I2C
#include "LUFA/Drivers/Peripheral/TWI.h"
#include "i2c.h"
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
#ifdef USE_I2C
    i2c_master_init();
#ifdef SSD1306OLED
    // calls code for the SSD1306 OLED
    _delay_ms(400);
    TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
    iota_gfx_init();   // turns on the display
#endif
#endif
}

void matrix_scan_kb(void) {
    matrix_scan_user();
#ifdef USE_I2C
#ifdef SSD1306OLED
    iota_gfx_task();  // this is what updates the display continuously
#endif
#endif
}

void led_set_kb(uint8_t usb_led) {
    led_set_user(usb_led);
#ifdef USE_I2C
#ifdef SSD1306OLED
    iota_gfx_clear_screen();
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        iota_gfx_write("Num Lock\n");
    }
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        iota_gfx_write("Caps Lock\n");
    }
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        iota_gfx_write("Scroll Lock\n");
    }
#endif
#endif
}
