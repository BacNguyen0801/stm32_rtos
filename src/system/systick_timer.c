#include "systick_timer.h"

/* Bit 2 CLKSOURCE: Clock source selection
Selects the clock source.
0: AHB/8
1: Processor clock (AHB) */
#define CLKSOURCE_ABH_DIV_8 0x00
#define CLKSOURCE_ABH_DIV_1 0x01

/* Bit 1 TICKINT: SysTick exception request enable
0: Counting down to zero does not assert the SysTick exception request
1: Counting down to zero to asserts the SysTick exception request */
#define TICKINT_DISABLE_IRQ 0x00
#define TICKINT_ENABLE_IRQ 0x01

/* ENABLE: Counter enable
Enables the counter. When ENABLE is set to 1, the counter loads the RELOAD value from the
LOAD register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and
optionally asserts the SysTick depending on the value of TICKINT. It then loads the RELOAD
value again, and begins counting.
0: Counter disabled
1: Counter enabled */
#define COUNTER_DISABLE 0x00
#define COUNTER_ENABLE 0x01

/* RELOAD[23:0]: RELOAD value
The LOAD register specifies the start value to load into the VAL register when the counter is
enabled and when it reaches 0.
Calculating the RELOAD value
The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF. A start value of
0 is possible, but has no effect because the SysTick exception request and COUNTFLAG are
activated when counting from 1 to 0. */
#define RELOAD_VALUE 0x1000

#define SYS_TICK_REG_BASE_ADDRESS (STK_REG_MAP*)0xE000E010
static volatile STK_REG_MAP* systick_reg = SYS_TICK_REG_BASE_ADDRESS;
void systick_timer_init()
{
	systick_reg->LOAD_REG.RELOAD    = RELOAD_VALUE;

    systick_reg->CTRL_REG.ENABLE    = COUNTER_ENABLE;
    systick_reg->CTRL_REG.TICKINT   = TICKINT_ENABLE_IRQ;
    systick_reg->CTRL_REG.CLKSOURCE = CLKSOURCE_ABH_DIV_1;
}