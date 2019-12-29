#pragma once
#include "os_timer_cfg.h"
#include "sys_sta.h"

void os_timer_set_state(os_state_ten new_state);
void os_timer_delay();
os_state_ten os_timer_handle_tasks();
os_state_ten os_timer_handle_error();
void os_timer_run();
void os_timer_init();
void os_timer_handle_irq_empty();
