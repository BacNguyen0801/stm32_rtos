#pragma once
#include "base_types.h"
#include "stm32f1x_usart_driver_cfg.h"

void stm32f1x_usart_driver_init();
ErrorCode stm32f1x_usart_driver_write(BYTE data);
