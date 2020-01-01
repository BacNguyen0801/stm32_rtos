#include "sys_init.h"
#include "HAL_gpio_control.h"

#ifdef __USING_STM32F1x_MC__
#include "stm32f1x_rcc_driver.h"
#include "stm32f1x_rtc_driver.h"
#include "stm32f1x_timer_driver.h"
#include "stm32f1x_gpio_driver.h"
#include "stm32f1x_usart_driver.h"
#endif

// Quick and dirty delay
static void delay (unsigned int time) {
    for (unsigned int i = 0; i < time; i++)
        for (volatile unsigned int j = 0; j < 2000; j++);
}

void HAL_system_init()
{
	stm32f1x_rcc_driver_init();   /* initilize for system clock */
	// stm32f1x_rtc_driver_init();   /* initialize for realtime clock */
	// stm32f1x_timer_driver_init(); /* initialize for generic timer */
	stm32f1x_gpio_driver_init();  /* initialize for gpio driver */
	// stm32f1x_afio_driver_init();  /* initialize for afio driver */

	// while(1)
	// {
	// 	 // Reset the state of pin 13 to output low
    //     HAL_gpio_WITurnOn();

    //     delay(500);

    //     // Set the state of pin 13 to output high
    //     HAL_gpio_WITurnOff();

    //     delay(500);
	// }
}