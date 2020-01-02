#include "systick_timer.h"

#define SYS_TICK_REG_BASE_ADDRESS (STK_REG_MAP*)0xE000E010
static volatile STK_REG_MAP* systick_reg = SYS_TICK_REG_BASE_ADDRESS;
void systick_timer_init()
{
	systick_reg->LOAD_REG.RELOAD    = 255;

    systick_reg->CTRL_REG.ENABLE    = 0x01;
    systick_reg->CTRL_REG.TICKINT   = 0x01;
    systick_reg->CTRL_REG.CLKSOURCE = 0x00;
}