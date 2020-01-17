#pragma once
#include "stm32f1x_flash_driver_cfg.h"

void stm32f1x_flash_driver_changeLatency();
void stm32f1x_flash_driver_init();
ErrorCode stm32f1x_flash_driver_program(DWORD FlashAddr, WORD Value);