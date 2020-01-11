#include "stm32f1x_power_driver.h"

/* DBP: Disable backup domain write protection.
In reset state, the RTC and backup registers are protected against parasitic write access.
This bit must be set to enable write access to these registers.
0: Access to RTC and Backup registers disabled
1: Access to RTC and Backup registers enabled */
#define DBP_DISABLE_ACCESS 0x00
#define DBP_ENABLE_ACCESS 0x01

#define POWER_BASE_ADDRESS (PWR_REG_MAP *)0x40007000
static volatile PWR_REG_MAP *const stm32f1x_pwr_reg = POWER_BASE_ADDRESS;
void stm32f1x_power_driver_enableWrite()
{
    stm32f1x_pwr_reg->CR.DBP = DBP_ENABLE_ACCESS;
    while(stm32f1x_pwr_reg->CR.DBP != DBP_ENABLE_ACCESS); /* wait until enable this bit */
}