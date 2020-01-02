#pragma once
#include "base_types.h"

typedef enum {
	os_timer_e,
} err_src_ten;

#define err_runtime_task2ms_issue			0x01
#define err_runtime_task4ms_issue			0x02
#define err_runtime_task8ms_issue			0x03
#define err_runtime_task16ms_issue			0x04
#define err_runtime_task64ms_issue			0x05
#define err_runtime_task128ms_issue			0x06
#define	err_queue_task_over  		0x02