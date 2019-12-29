#pragma once
#include "base_types.h"

/* Typedef area */
typedef enum {
	task_base_e,	/* base task upon timer config interrupt */
	task_x2_e,		/* x2 task cyclic */
	task_x8_e,		/* x8 task cyclic */
	task_x16_e,		/* x16 task cyclic */
	task_x64_e,		/* x64 task cyclic */
	task_x128_e,	/* x128 task cyclic */
	task_max_e	/* invalid task cyclic */
} os_tasktype_ten;
typedef enum {
	os_init_e,		/* init state of os */
	os_normal_e,	/* normal state cyclic */
	os_idle_e,		/* no task active */
	os_error_e		/* error handle state */
} os_state_ten;
typedef void (*task_fp)(void);
typedef void (*interupt_handler_fp)(void);
/* End of typedef area */

/* Definition area */
#define MAX_SIZE_OF_INTERRUPT_TABLE 60u
#define DEFINE_BASE_TASK_MODULO		0x01
#define DEFINE_X2_TASK_MODULO		0x03
#define DEFINE_X8_TASK_MODULO		0x0F
#define DEFINE_X16_TASK_MODULO		0x1F
#define DEFINE_X64_TASK_MODULO		0x7F
#define DEFINE_X128_TASK_MODULO		0xFF
#define NUM_TASK_DEF				task_max_e
#define MAX_NUMBER_FUNC_PER_TASKS	0x0F
/* End of definition area */



