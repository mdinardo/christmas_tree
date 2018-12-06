#ifndef _LEDS_H_INCLUDED_
#define _LEDS_H_INCLUDED_
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include <stdint.h>
#include <stdbool.h>

enum {
    LED_STAR = 0,
    LED_BOTTOM_LEFT,
    LED_BOTTOM_RIGHT,
    LED_MIDDLE_LEFT,
    LED_MIDDLE_RIGHT,
    LED_TOP_LEFT,
    LED_TOP_RIGHT,
    NUM_LEDS
} LEDS;

#define LED_MAX_INTENSITY ((led_intensity_t) -1)

typedef uint8_t led_intensity_t;
typedef bool led_state_t;

extern const uint8_t led_pin_map[];
extern led_intensity_t led_intensities[]; 
extern led_state_t led_states[];

void led_init();

void led_set_intensity(enum LEDS led, led_intensity_t intensity);
void led_set_all_intensities(led_intensity_t intensity);

void led_set_state(enum LEDS led, uinit8_t state);
void led_set_all_states(uinit8_t state);

void led_state_state_by_intensity(enum LEDS led, led_intensity_t threshold);
void led_state_all_states_by_intensity(led_intensity_t threshold);

void led_write_state(enum LEDS led);
void led_write_all_states();

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //_LEDS_H_INCLUDED_