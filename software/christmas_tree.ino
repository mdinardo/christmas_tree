#include <stdint.h>
#include <stdbool.h>

#include "systick.h"
#include "leds.h"

#define LED_STRENGTH_MAX 0xf // must be 2^n - 1 for some n > 0
static volatile uint8_t led_intensity_ramp = 0;
static volatile uint32_t tick_ms = 0;
static volatile uint32_t task_max_time_ms = 0;
static volatile bool led_task_switch_req = false;
static volatile bool led_task_update_req = false;

#define NUM_TASKS 1
static volatile bool randomize_tasks = false;
static volatile uint8_t task_id;

#define NUM_LEDS_TASKS (sizeof(led_tasks) / sizeof(led_tasks[0]))
static volatile uint8_t led_task_id;
static const led_task_t *led_tasks[];

void current_led_task_update() {
    switch(task_id) {
        case 0:
            break
        default:
            break
    }
}

void set_random_task() {
    // TODO: Not Implemented
    task_id = random(NUM_TASKS);
}

void update_leds() {
    int i;
    for(i = 0; i < NUM_LEDS; i++) {
        uint8_t new_state = led_intensity_ramp;
        digitalWrite(led_pins[i], new_state);
    }
}

void systick_handler(void *arg) {
    led_task_update_req |= (led_intensity_ramp == LED_STRENGTH_MAX);
    led_intensity_ramp = (led_intensity_ramp + 1) & LED_STRENGTH_MAX;
    ++tick_ms;

    update_leds();
} 

/*
 * User button cycles between tasks.  One button press increments the task id by 1.
 * if after incrementing, the task id is larger then the last task, then switch to task randomization mode.
 * if in task randomization mode when the button is pressed, go back into static 
 */
ISR(BUTTON_INTERRUPT) {
    if(randomize_tasks) {
        randomize_tasks = false;
        task_id = 0;
    } else if(task_id >= (NUM_TASKS - 1)) {
        randomize_tasks = true;
        set_random_task();
    } else {
        ++task_id;
    }
    led_task_switch_req = true;
}

void setup() {
    systick_set_handler(&systick_handler, NULL);
    systick_init();
}

void loop() {
    if(led_task_switch_req) {
        led_task_switch_req = false;
        led_task_update_req = true;
        set_random_task();
    }
    if(led_task_update_req) {
        led_task_update_req = false;
        current_led_task_update();
    }
}

