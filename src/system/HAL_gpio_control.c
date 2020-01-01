#include "HAL_gpio_control.h"
#include "stm32f1x_gpio_driver.h"

#define WARNING_INDICATOR_PORT_DEF  GPIOx_PORT_C
#define WARNING_INDICATOR_PIN_DEF   GPIOx_PIN_13

void HAL_gpio_WITurnOn()
{
    /* Set low output to turn on the led */
    stm32f1x_gpio_TurnOff(WARNING_INDICATOR_PORT_DEF, WARNING_INDICATOR_PIN_DEF);
}
void HAL_gpio_WITurnOff()
{
    /* Set high output to turn off the led */
    stm32f1x_gpio_TurnOn(WARNING_INDICATOR_PORT_DEF, WARNING_INDICATOR_PIN_DEF);
}