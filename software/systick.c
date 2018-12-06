
#include <avr/isr.h>
#include <avr/interrupt.h>

#include "systick.h"

static volatile systick_handle_t systick_handler = NULL;
static volatile void *handler_arg = NULL;

void systick_init() {
    // setup Timer for systick ISR

    // Timer0 is already used for millis() - we'll just interrupt somewhere
    // in the middle and call the "Compare A" function below
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
}

void systick_set_handler(systick_handle_t handler, void *arg) {
    systick_handler = handler;
    handler_arg = arg;
}

ISR(TIMER0_COMPA_vect, ISR_BLOCK) {
    if(NULL != systick_handler) systick_handler(handler_arg);
}