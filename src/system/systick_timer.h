#pragma once
#include "base_types.h"

typedef struct {
	DWORD ENABLE: 1; /* Counter enable */
	DWORD TICKINT: 1; /* SysTick exception request enable */
	DWORD CLKSOURCE: 1; /* Clock source selection */
	DWORD Reserved:13; /* must be kept cleared. */
	DWORD COUNTFLAG: 1; /* Returns 1 if timer counted to 0 since last time this was read. */
} STK_CTRL_REG;

typedef struct {
	DWORD RELOAD; /* RELOAD value */
} STK_LOAD_REG;

typedef struct {
	DWORD CURRENT; /* Current counter value */
} STK_VAL_REG;

typedef struct {
	STK_CTRL_REG CTRL_REG; /* STK_CTRL_REG */
	STK_LOAD_REG LOAD_REG; /* STK_LOAD_REG */
	STK_VAL_REG VAL_REG; /* STK_VAL_REG */
} STK_REG_MAP;

void systick_timer_init();
