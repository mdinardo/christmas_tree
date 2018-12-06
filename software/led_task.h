#ifndef _LED_TASK_H_INCLUDED_
#define _LED_TASK_H_INCLUDED_
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "systick.h"

typedef struct {
    void (*init_handler)(void*);
    systick_handle_t systick_handler;
    void (*update_handler)(void*);
} led_task_t;

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //_LED_TASK_H_INCLUDED_