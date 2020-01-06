#include "stm32f1x_timer_driver.h"

#define TIME1_BASE_ADDRESS (ADV_TIM_REG_MAP*)0x40012C00
#define TIME8_BASE_ADDRESS (ADV_TIM_REG_MAP*)0x40013400 

static volatile ADV_TIM_REG_MAP* const stm32f1x_reg_tim1 = TIME1_BASE_ADDRESS;
static volatile ADV_TIM_REG_MAP* const stm32f1x_reg_tim8 = TIME8_BASE_ADDRESS;

void stm32f1x_timer_driver_init()
{
	
}