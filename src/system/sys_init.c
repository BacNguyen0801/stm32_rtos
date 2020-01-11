#include "sys_init.h"
#include "HAL_gpio_control.h"

#ifdef __USING_STM32F1x_MC__
#include "stm32f1x_rcc_driver.h"
#include "stm32f1x_rtc_driver.h"
#include "stm32f1x_timer_driver.h"
#include "stm32f1x_gpio_driver.h"
#include "stm32f1x_usart_driver.h"
#endif

void HAL_system_init()
{
	stm32f1x_rcc_driver_init();   /* initilize for system clock */
	stm32f1x_rtc_driver_init();   /* initialize for realtime clock */
	stm32f1x_gpio_driver_init();  /* initialize for gpio driver */
}