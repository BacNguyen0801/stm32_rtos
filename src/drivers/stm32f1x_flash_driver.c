#include "stm32f1x_flash_driver_cfg.h"

/* LATENCY: Latency
These bits represent the ratio of the SYSCLK (system clock) period to the Flash access
time.
000 Zero wait state, if 0 < SYSCLK≤ 24 MHz
001 One wait state, if 24 MHz < SYSCLK ≤ 48 MHz
010 Two wait states, if 48 MHz < SYSCLK ≤72 MHz */
#define LATENCY_NOWAIT 0x00
#define LATENCY_ONE_WAIT 0x01
#define LATENCY_TWO_WAIT 0x02

#define FLASH_BAS_ADDRESS (FLASH_REG_MAP *) 0x40022000
static volatile FLASH_REG_MAP* const stm32f1x_flash_reg = FLASH_BAS_ADDRESS;

void stm32f1x_flash_driver_changeLatency()
{
    stm32f1x_flash_reg->ACR.LATENCY = LATENCY_TWO_WAIT;
}