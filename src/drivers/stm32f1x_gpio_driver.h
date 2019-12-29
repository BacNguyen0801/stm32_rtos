#pragma once
#include "stm32f1x_gpio_driver_cfg.h"

/* Define GPIO Pin */
#define GPIOx_PIN_0 0x00000001
#define GPIOx_PIN_1 0x00000002
#define GPIOx_PIN_2 0x00000004
#define GPIOx_PIN_3 0x00000008
#define GPIOx_PIN_4 0x00000010
#define GPIOx_PIN_5 0x00000020
#define GPIOx_PIN_6 0x00000040
#define GPIOx_PIN_7 0x00000080
#define GPIOx_PIN_8 0x00000100
#define GPIOx_PIN_9 0x00000200
#define GPIOx_PIN_10 0x00000400
#define GPIOx_PIN_11 0x00000800
#define GPIOx_PIN_12 0x00001000
#define GPIOx_PIN_13 0x00002000
#define GPIOx_PIN_14 0x00004000
#define GPIOx_PIN_15 0x00008000
#define GPIOx_PIN_ALL 0x0000FFFF

/* Define GPIO PORT */
#define GPIOx_PORT_A 0x00
#define GPIOx_PORT_B 0x01
#define GPIOx_PORT_C 0x02
#define GPIOx_PORT_D 0x03
#define GPIOx_PORT_E 0x04
#define GPIOx_PORT_F 0x05
#define GPIOx_PORT_G 0x06
#define GPIOx_PORT_NUM_MAX 0x07


void stm32f1x_gpio_driver_init();
void stm32f1x_afio_driver_init();
BYTE stm32f1x_gpio_getValue(BYTE Port, DWORD Pin);
void stm32f1x_gpio_clearValue(BYTE Port, DWORD Pin);
void stm32f1x_gpio_setValue(BYTE Port, DWORD Pin);
DWORD stm32f1x_gpio_getPort(BYTE Port);
void stm32f1x_gpio_clearPort(BYTE Port);
void stm32f1x_gpio_setPort(BYTE Port, DWORD Data);
void stm32f1x_gpio_switchOn(BYTE Port);