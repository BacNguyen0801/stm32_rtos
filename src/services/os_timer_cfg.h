#pragma once
#include "base_types.h"

/* Typedef area */
typedef enum {
	task_2ms_e,	/* base task upon timer config interrupt */
	task_16ms_e,		/* x8 task cyclic */
	task_64ms_e,		/* x32 task cyclic */
	task_128ms_e,	/* x128 task cyclic */
	task_max_e	/* invalid task cyclic */
} os_tasktype_ten;
typedef enum {
	os_init_e,		/* init state of os */
	os_normal_e,	/* normal state cyclic */
	os_idle_e,		/* no task active */
} os_state_ten;
typedef void (*task_fp)(void);
typedef void (*interupt_handler_fp)(void);
/* End of typedef area */

/* Definition area */
#define MAX_SIZE_OF_INTERRUPT_TABLE 60u
#define DEFINE_2_TASK_MODULO		0x01
#define DEFINE_16_TASK_MODULO		0x0F
#define DEFINE_64_TASK_MODULO		0x3F
#define DEFINE_128_TASK_MODULO		0x7F
#define NUM_TASK_DEF				task_max_e
/* End of definition area */



