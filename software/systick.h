#ifndef __SYSTICK_H_INCLUDED__
#define __SYSTICK_H_INCLUDED__
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#define SYSTICK_FREQ 1000
#define SYSTICK_PERIOD (1.0 / ((float) SYSTICK_FREQ))
#define SYSTICK_PERIOD_MS (SYSTICK_PERIOD * 1e3)
#define SYSTICK_PERIOD_US (SYSTICK_PERIOD * 1e6)
typedef void (*systick_handle)(void*) systick_handle_t;

void systick_init();
void systick_set_handle(systick_handle_t handler, void *handle_arg);

extern volatile const uint32_t systick_counter;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif// __SYSTICK_H_INCLUDED__