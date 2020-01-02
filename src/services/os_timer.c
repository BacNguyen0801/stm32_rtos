#include "os_timer.h"
#include "sys_init.h"
#include "systick_timer.h"

#include "warning_indicator.h"

/* Declare local variables */
static os_state_ten os_state;
static DWORD timer_tick;
static DWORD task_indicator;
static ERROR_CODE	error_code;

static void os_timer_task_2ms();
static void os_timer_task_16ms();
static void os_timer_task_32ms();
static void os_timer_task_240ms();

static task_fp	os_timer_array_tasks[NUM_TASK_DEF] = {
	&os_timer_task_2ms,
	&os_timer_task_16ms,
	&os_timer_task_32ms,
	&os_timer_task_240ms,
};

void os_timer_init()
{
	HAL_system_init();
}

void os_timer_run()
{
	while (1)
	{
		switch (os_state)
		{
		case os_init_e:
		{
			/* call system init */
			systick_timer_init();
			os_state = os_normal_e;
			break;
		}
		case os_normal_e:
		{
			os_state = os_timer_handle_tasks();
			break;
		}
		case os_idle_e:
		{
			os_timer_delay();
			break;
		}
		case os_error_e:
		{
			os_state = os_timer_handle_error();
			break;
		}
		default:
		{
			/* code never touch here */
			break;
		}
		}
	}
}

void os_timer_set_state(os_state_ten new_state)
{
	os_state = new_state;
}

os_state_ten os_timer_handle_tasks()
{
	unsigned char task_type = 0;
	while ((0 != task_indicator) && (task_type < task_max_e))
	{
		if (IS_BIT_SET(task_type, task_indicator))
		{
			os_timer_array_tasks[task_type]();
			CLEAR_BIT(task_type, task_indicator);
		}
		++task_type;
	}
	return os_normal_e;
}

os_state_ten os_timer_handle_error()
{
	os_state_ten ret = os_normal_e;
	sys_sta_report_error(os_timer_e, error_code);
	switch (error_code)
	{
	default:
	{
		/* code never touch here */
		break;
	}
	}
	return ret;
}

void os_timer_delay()
{
	/* software delay */
	BYTE x = 255;
	while (x > 1) x--;
}

void SysTick_Handler()
{
	timer_tick++;
	if ((timer_tick & DEFINE_BASE_TASK_MODULO) == 0)
	{
		if (0 != IS_BIT_SET(task_2ms_e, task_indicator)) /* only check for base task, other task no need to check */
		{
			error_code = err_runtime_task2ms_issue;
			os_timer_set_state(os_error_e);
			return;
		}
		SET_BIT(task_2ms_e, task_indicator);
	}


	if ((timer_tick & DEFINE_X8_TASK_MODULO) == 0)
	{
		if (0 != IS_BIT_SET(task_16ms_e, task_indicator)) /* only check for base task, other task no need to check */
		{
			error_code = err_runtime_task8ms_issue;
			os_timer_set_state(os_error_e);
			return;
		}
		SET_BIT(task_16ms_e, task_indicator);
	}

	if ((timer_tick & DEFINE_X32_TASK_MODULO) == 0)
	{
		if (0 != IS_BIT_SET(task_64ms_e, task_indicator)) /* only check for base task, other task no need to check */
		{
			error_code = err_runtime_task64ms_issue;
			os_timer_set_state(os_error_e);
			return;
		}
		SET_BIT(task_64ms_e, task_indicator);
	}

	if ((timer_tick & DEFINE_X128_TASK_MODULO) == 0)
	{
		if (0 != IS_BIT_SET(task_240ms_e, task_indicator)) /* only check for base task, other task no need to check */
		{
			error_code = err_runtime_task128ms_issue;
			os_timer_set_state(os_error_e);
			return;
		}
		SET_BIT(task_240ms_e, task_indicator);
	}
}

static void os_timer_task_2ms()
{
	/* API run as BG 2ms */
}

static void os_timer_task_16ms()
{
	/* API run as BG 16ms */
}
static void os_timer_task_32ms()
{
	/* API run as BG 332ms */
}
static void os_timer_task_240ms()
{
	/* API run as BG 240ms */
	warning_indicator_run();
}