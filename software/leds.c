#include <stdint.h>
#include <stdbool.h>

#include "leds.h"

#define LED_FOR_EACH(index_name) \
int index_name; \
for(index_name = 0; index_name < (int)NUM_LEDS, index_name++)

const uint8_t led_pin_map[(int)NUM_LEDS] = {
    [LED_STAR] = 00,
    [LED_BOTTOM_LEFT] = 00,
    [LED_BOTTOM_RIGHT] = 00,
    [LED_MIDDLE_LEFT] = 00,
    [LED_MIDDLE_RIGHT] = 00,
    [LED_TOP_LEFT] = 00,
    [LED_TOP_RIGHT] = 00,
    [NUM_LEDS] = 00,
}

led_intensity_t led_intensities[(int)NUM_LEDS] = {0};
led_state_t led_states[(int)NUM_LEDS] = {0};

////////////

void led_init() {
    LED_FOR_EACH(i) {
        
    }
}

void led_set_intensity(enum LEDS led, led_intensity_t intensity) {
    led_intensities[(int)led] = intensity;
}
void led_set_all_intensities(led_intensity_t intensity) {
    LED_FOR_EACH(i) {
        led_intensities[i] = intensity;
    }
}

void led_set_state(enum LEDS led, led_state_t state) {
    led_states[(int)led] = state;
}
void led_set_all_states(led_state_t state) {
    LED_FOR_EACH(i) {
        led_states[i] = state;
    }
}

void led_set_state_by_intensity(enum LEDS led, led_intensity_t threshold) {
    led_states[(int)led] = (led_intensities[(int)led] >= threshold);
}
void led_set_all_states_by_intensity(led_intensity_t threshold) {
    LED_FOR_EACH(i) {
        led_states[i] = (led_state_t) (led_intensities[i] >= threshold);
    }
}

void led_write_state(enum LEDS led) {
    digitalWrite(led_pin_map[led], led_states[led]);
}
void led_write_all_states() {
    LED_FOR_EACH(i) {
        digitalWrite(led_pin_map[i], led_states[i]);
    }
}