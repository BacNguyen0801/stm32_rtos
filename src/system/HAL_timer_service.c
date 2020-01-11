#include "stm32f1x_rtc_driver.h"

DWORD HAL_tim_getTickCnt()
{
    return stm32f1x_rtc_driver_getTickCnt();
}