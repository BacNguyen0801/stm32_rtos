#pragma once
#include "base_types.h"

typedef enum {
	os_timer_e,
} err_src_ten;

#define err_runtime_no_issue 				0xFF
#define err_runtime_task2ms_issue			0x01
#define err_runtime_task16ms_issue			0x02
#define err_runtime_task64ms_issue			0x03
#define err_runtime_task240ms_issue			0x04