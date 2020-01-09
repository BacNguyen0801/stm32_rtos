#include "stm32f1x_gpio_driver.h"

/* CNFy[1:0]: Port x configuration bits (y= 8 .. 15)
These bits are written by software to configure the corresponding I/O port.
Refer to Table 20: Port bit configuration table.
In input mode (MODE[1:0]=00):
00: Analog mode
01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved
In output mode (MODE[1:0] > 00):
00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain */
#define GPIO_INPUT_ANALOG_MODE 0x00
#define GPIO_INPUT_FLOATING_MODE 0x01
#define GPIO_INPUT_PULL_UP_DOWN 0x02
#define GPIO_INPUT_RESERVED 0x03
#define GPIO_OUTPUT_PUSH_PULL 0x00
#define GPIO_OUTPUT_OPEN_DRAIN 0x01
#define GPIO_OUTPUT_ALTERNATE_PUSH_PULL 0x02
#define GPIO_OUTPUT_ALTERNATE_OPEN_DRAIN 0x03
/* MODEy[1:0] Port x mode bits (y= 0 .. 15)
These bits are written by software to configure the corresponding I/O port.
Refer to Table 20: Port bit configuration table.
00: Input mode (reset state)
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.*/
#define GPIO_INPUT_RESET_STATE 0x00
#define GPIO_OUTPUT_FREQUENCY_10MHz 0x01
#define GPIO_OUTPUT_FREQUENCY_2MHz 0x02
#define GPIO_OUTPUT_FREQUENCY_50MHz 0x03

/* SWJ_CFG[2:0]: Serial wire JTAG configuration
These bits are write-only (when read, the value is undefined). They are used to configure the
SWJ and trace alternate function I/Os. The SWJ (Serial Wire JTAG) supports JTAG or SWD
access to the Cortex® debug port. The default state after reset is SWJ ON without trace.
This allows JTAG or SW mode to be enabled by sending a specific sequence on the JTMS /
JTCK pin.
000: Full SWJ (JTAG-DP + SW-DP): Reset State
001: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
010: JTAG-DP Disabled and SW-DP Enabled
100: JTAG-DP Disabled and SW-DP Disabled */
#define ALT_SWJ_CFG_FULL 0x00
#define ALT_SWJ_CFG_FULL_WO_NJTRST 0x01
#define ALT_SWJ_CFG_DIS_JTAG_EN_SWDP 0x02
#define ALT_SWJ_CFG_DIS_JTAG_DIS_SWDP 0x03
/* ADC2_ETRGREG_REMAP: ADC 2 external trigger regular conversion remapping
Set and cleared by software. This bit controls the trigger input connected to ADC2 external
trigger regular conversion. When this bit is reset, the ADC2 external trigger regular
conversion is connected to EXTI11. When this bit is set, the ADC2 external event regular
conversion is connected to TIM8_TRGO. */
#define ALT_ADC2_CONVERSION_MAPPING_TO_EXTI11 0x00
#define ALT_ADC2_CONVERSION_MAPPING_TO_TIM8_TRGO 0x01
/* ADC2_ETRGINJ_REMAP: ADC 2 external trigger injected conversion remapping
Set and cleared by software. This bit controls the trigger input connected to ADC2 external
trigger injected conversion. When this bit is reset, the ADC2 external trigger injected
conversion is connected to EXTI15. When this bit is set, the ADC2 external event injected
conversion is connected to TIM8_Channel4. */
#define ALT_ADC2_TRIGGER_MAPPING_TO_EXTI15 0x00
#define ALT_ADC2_TRIGGER_MAPPING_TO_TIM8_CHANNEL4 0x01
/* ADC1_ETRGREG_REMAP: ADC 1 external trigger regular conversion remapping
Set and cleared by software. This bit controls the trigger input connected to ADC1
External trigger regular conversion. When reset the ADC1 External trigger regular
conversion is connected to EXTI11. When set the ADC1 External Event regular conversion
is connected to TIM8 TRGO. */
#define ALT_ADC1_CONVERSION_MAPPING_TO_EXTI11 0x00
#define ALT_ADC1_CONVERSION_MAPPING_TO_TIM8_TRGO 0x01
/* ADC1_ETRGINJ_REMAP: ADC 1 External trigger injected conversion remapping
Set and cleared by software. This bit controls the trigger input connected to ADC1
External trigger injected conversion. When reset the ADC1 External trigger injected
conversion is connected to EXTI15. When set the ADC1 External Event injected conversion
is connected to TIM8 Channel4. */
#define ALT_ADC1_TRIGGER_MAPPING_TO_EXTI15 0x00
#define ALT_ADC1_TRIGGER_MAPPING_TO_TIM8_CHANNEL4 0x01
/* TIM5CH4_IREMAP: TIM5 channel4 internal remap
Set and cleared by software. This bit controls the TIM5_CH4 internal mapping. When reset
the timer TIM5_CH4 is connected to PA3. When set the LSI internal clock is connected to
TIM5_CH4 input for calibration purpose. */
#define ALT_TIMER5_NO_REMAP 0x00
#define ALT_TIMER5_MAPPING_TO_INTERNAL 0x01

/* PD01_REMAP: Port D0/Port D1 mapping on OSC_IN/OSC_OUT
This bit is set and cleared by software. It controls the mapping of PD0 and PD1 GPIO
functionality. When the HSE oscillator is not used (application running on internal 8 MHz RC)
PD0 and PD1 can be mapped on OSC_IN and OSC_OUT. This is available only on 36-, 48-
and 64-pin packages (PD0 and PD1 are available on 100-pin and 144-pin packages, no
need for remapping).
0: No remapping of PD0 and PD1
1: PD0 remapped on OSC_IN, PD1 remapped on OSC_OUT, */
#define ALT_PD0_PD1_NO_MAPPING 0x00
#define ALT_PD0_PD1_MAPPING_TO_OCS 0x01
/* CAN_REMAP[1:0]: CAN alternate function remapping
These bits are set and cleared by software. They control the mapping of alternate functions
CAN_RX and CAN_TX in devices with a single CAN interface.
00: CAN_RX mapped to PA11, CAN_TX mapped to PA12
01: Not used
10: CAN_RX mapped to PB8, CAN_TX mapped to PB9 (not available on 36-pin package)
11: CAN_RX mapped to PD0, CAN_TX mapped to PD1 */
#define ALT_CAN_RX_TO_PA11_CAN_TX_TO_PA12 0x00
#define ALT_CAN_RX_TO_NOT_USED_CAN_TX_TO_NOT_USED 0x01
#define ALT_CAN_RX_TO_PB8_CAN_TX_TO_PB9 0x02
#define ALT_CAN_RX_TO_PD0_CAN_TX_TO_PD1 0x03
/* TIM4_REMAP: TIM4 remapping
This bit is set and cleared by software. It controls the mapping of TIM4 channels 1 to 4 onto
the GPIO ports.
0: No remap (TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
1: Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15) */
#define ALT_TIMER4_REMAP_DISABLE 0x00
#define ALT_TIMER4_REMAP_ENABLE 0x01
/* TIM3_REMAP[1:0]: TIM3 remapping
These bits are set and cleared by software. They control the mapping of TIM3 channels 1 to
4 on the GPIO ports.
00: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
01: Not used
10: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1) 
11: Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9) */
#define ALT_TIMER3_REMAP_DISABLE 0x00
#define ALT_TIMER3_REMAP_NOT_USED 0x01
#define ALT_TIMER3_REMAP_PARTIAL 0x02
#define ALT_TIMER3_REMAP_FULL 0x03
/* TIM2_REMAP[1:0]: TIM2 remapping
These bits are set and cleared by software. They control the mapping of TIM2 channels 1 to
4 and external trigger (ETR) on the GPIO ports.
00: No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
01: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
10: Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
11: Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11) */
#define ALT_TIMER2_REMAP_DISABLE 0x00
#define ALT_TIMER2_REMAP_PARTIAL_1 0x01
#define ALT_TIMER2_REMAP_PARTIAL_2 0x02
#define ALT_TIMER2_REMAP_FULL 0x03
/* TIM1_REMAP[1:0]: TIM1 remapping
These bits are set and cleared by software. They control the mapping of TIM1 channels 1 to
4, 1N to 3N, external trigger (ETR) and Break input (BKIN) on the GPIO ports.
00: No remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12,
CH1N/PB13, CH2N/PB14, CH3N/PB15)
01: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6,
CH1N/PA7, CH2N/PB0, CH3N/PB1)
10: not used
11: Full remap (ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15,
CH1N/PE8, CH2N/PE10, CH3N/PE12) */
#define ALT_TIMER1_REMAP_DISABLE 0x00
#define ALT_TIMER1_REMAP_PARTIAL 0x01
#define ALT_TIMER1_REMAP_NOT_USED 0x02
#define ALT_TIMER1_REMAP_FULL 0x03
/* USART3_REMAP[1:0]: USART3 remapping
These bits are set and cleared by software. They control the mapping of USART3 CTS,
RTS,CK,TX and RX alternate functions on the GPIO ports.
00: No remap (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
01: Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
10: not used
11: Full remap (TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12) */
#define ALT_USART3_REMAP_DISABLE 0x00
#define ALT_USART3_REMAP_PARTIAL 0x01
#define ALT_USART3_REMAP_NOT_USED 0x02
#define ALT_USART3_REMAP_FULL 0x03
/* USART2_REMAP: USART2 remapping
This bit is set and cleared by software. It controls the mapping of USART2 CTS, RTS,CK,TX
and RX alternate functions on the GPIO ports.
0: No remap (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
1: Remap (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7) */
#define ALT_USART2_REMAP_DISABLE 0x00
#define ALT_USART2_REMAP_ENABLE 0x01
/* USART1_REMAP: USART1 remapping
This bit is set and cleared by software. It controls the mapping of USART1 TX and RX
alternate functions on the GPIO ports.
0: No remap (TX/PA9, RX/PA10)
1: Remap (TX/PB6, RX/PB7) */
#define ALT_USART1_REMAP_DISABLE 0x00
#define ALT_USART1_REMAP_ENABLE 0x01
/* I2C1_REMAP: I2C1 remapping
This bit is set and cleared by software. It controls the mapping of I2C1 SCL and SDA
alternate functions on the GPIO ports.
0: No remap (SCL/PB6, SDA/PB7)
1: Remap (SCL/PB8, SDA/PB9) */
#define ALT_I2C1_REMAP_DISABLE 0x00
#define ALT_I2C1_REMAP_ENABLE 0x01
/* SPI1_REMAP: SPI1 remapping
This bit is set and cleared by software. It controls the mapping of SPI1 NSS, SCK, MISO,
MOSI alternate functions on the GPIO ports.
0: No remap (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)
1: Remap (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5) */
#define ALT_SPI1_REMAP_DISABLE 0x00
#define ALT_SPI1_REMAP_ENABLE 0x01

/* EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
These bits are written by software to select the source input for EXTIx external interrupt.
Refer to Section 10.2.5: External interrupt/event line mapping
0000: PA[x] pin
0001: PB[x] pin
0010: PC[x] pin
0011: PD[x] pin
0100: PE[x] pin
0101: PF[x] pin
0110: PG[x] pin */
#define ALT_EXTI_PORTA_DEFINITION 0x00
#define ALT_EXTI_PORTB_DEFINITION 0x01
#define ALT_EXTI_PORTC_DEFINITION 0x02
#define ALT_EXTI_PORTD_DEFINITION 0x03
#define ALT_EXTI_PORTE_DEFINITION 0x04
#define ALT_EXTI_PORTF_DEFINITION 0x05
#define ALT_EXTI_PORTG_DEFINITION 0x06

#define GPIO_PORT_A_BASE_ADDRESS (GPIOx_REG_MAP *)0x40010800
#define GPIO_PORT_B_BASE_ADDRESS (GPIOx_REG_MAP *)0x40010C00
#define GPIO_PORT_C_BASE_ADDRESS (GPIOx_REG_MAP *)0x40011000
#define GPIO_PORT_D_BASE_ADDRESS (GPIOx_REG_MAP *)0x40011400
#define GPIO_PORT_E_BASE_ADDRESS (GPIOx_REG_MAP *)0x40011800
#define GPIO_PORT_F_BASE_ADDRESS (GPIOx_REG_MAP *)0x40011C00
#define GPIO_PORT_G_BASE_ADDRESS (GPIOx_REG_MAP *)0x40011400
#define AFIO_BASE_ADDRESS (AFIO_REG_MAP *)40010000

static volatile GPIOx_REG_MAP *const stm32f1x_gpio_a_reg = GPIO_PORT_A_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_b_reg = GPIO_PORT_B_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_c_reg = GPIO_PORT_C_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_d_reg = GPIO_PORT_D_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_e_reg = GPIO_PORT_E_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_f_reg = GPIO_PORT_F_BASE_ADDRESS;
static volatile GPIOx_REG_MAP *const stm32f1x_gpio_g_reg = GPIO_PORT_G_BASE_ADDRESS;
static volatile AFIO_REG_MAP *const stm32f1x_afio_reg = AFIO_BASE_ADDRESS;

static GPIOx_REG_MAP *const stm32f1x_gpio_reg_lst[GPIOx_PORT_NUM_MAX] = {
	stm32f1x_gpio_a_reg,
	stm32f1x_gpio_b_reg,
	stm32f1x_gpio_c_reg,
	stm32f1x_gpio_d_reg,
	stm32f1x_gpio_e_reg,
	stm32f1x_gpio_f_reg,
	stm32f1x_gpio_g_reg
};

void stm32f1x_gpio_driver_init()
{
	stm32f1x_gpio_c_reg->CRL_REG.MODE0 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC0 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF0 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE1 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC1 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF1 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE2 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC2 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF2 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE3 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC3 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF3 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE4 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC4 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF4 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE5 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC5 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF5 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE6 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC6 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF6 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRL_REG.MODE7 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC7 */
	stm32f1x_gpio_c_reg->CRL_REG.CNF7 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE8 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC8 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF8 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE9 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC9 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF9 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE10 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC10 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF10 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE11 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC11 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF11 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE12 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC12 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF12 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE13 = GPIO_OUTPUT_FREQUENCY_2MHz;		/* Use frequency 2Mhz */
	stm32f1x_gpio_c_reg->CRH_REG.CNF13 = GPIO_OUTPUT_PUSH_PULL; 		/* Set output mode for PC13 */
	stm32f1x_gpio_c_reg->CRH_REG.MODE14 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC14 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF14 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
	stm32f1x_gpio_c_reg->CRH_REG.MODE15 = GPIO_INPUT_RESET_STATE;		/* Set input mode for PC15 */
	stm32f1x_gpio_c_reg->CRH_REG.CNF15 = GPIO_INPUT_FLOATING_MODE; /* Use frequency GPIO_INPUT_FLOATING_MODE */
}

void stm32f1x_afio_driver_init()
{
	/* configure for alternate function of GPIO */
	stm32f1x_afio_reg->EVCR_REG.EVOE = 0; /* Disable Event output */
	stm32f1x_afio_reg->AFIO_MAPR_REG.SPI1_REMAP = ALT_SPI1_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.I2C1_REMAP = ALT_I2C1_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.USART1_REMAP = ALT_USART1_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.USART2_REMAP = ALT_USART2_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.USART3_REMAP = ALT_USART3_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.TIM1_REMAP = ALT_TIMER1_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.TIM2_REMAP = ALT_TIMER2_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.TIM3_REMAP = ALT_TIMER3_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.TIM4_REMAP = ALT_TIMER4_REMAP_DISABLE;
	stm32f1x_afio_reg->AFIO_MAPR_REG.CAN_REMAP = ALT_CAN_RX_TO_PD0_CAN_TX_TO_PD1;
	stm32f1x_afio_reg->AFIO_MAPR_REG.PD01_REMAP = ALT_PD0_PD1_NO_MAPPING;
	stm32f1x_afio_reg->AFIO_MAPR_REG.TIM5CH4_IREMAP = ALT_TIMER5_NO_REMAP;
	stm32f1x_afio_reg->AFIO_MAPR_REG.ADC1_ETRGREG_REMAP = ALT_ADC1_CONVERSION_MAPPING_TO_EXTI11;
	stm32f1x_afio_reg->AFIO_MAPR_REG.ADC1_ETRGINJ_REMAP = ALT_ADC1_TRIGGER_MAPPING_TO_EXTI15;
	stm32f1x_afio_reg->AFIO_MAPR_REG.ADC2_ETRGREG_REMAP = ALT_ADC2_CONVERSION_MAPPING_TO_TIM8_TRGO;
	stm32f1x_afio_reg->AFIO_MAPR_REG.ADC2_ETRGINJ_REMAP = ALT_ADC2_TRIGGER_MAPPING_TO_TIM8_CHANNEL4;
	stm32f1x_afio_reg->AFIO_MAPR_REG.SWJ_CFG = ALT_SWJ_CFG_FULL;
}

void stm32f1x_gpio_TurnOn(BYTE Port, DWORD Pin)
{
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	p->BSRR_REG.BSRR |= Pin;
}

void stm32f1x_gpio_TurnOff(BYTE Port, DWORD Pin)
{
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	p->BSRR_REG.BSRR |= Pin << 16;
}

BYTE stm32f1x_gpio_GetValue(BYTE Port, DWORD Pin)
{
	BYTE ret = 0x00;
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	ret = ((p->IDR_REG.IDR & Pin) == ret) ? ret : 0x01;
	return ret;
}

DWORD stm32f1x_gpio_getPort(BYTE Port)
{
	DWORD ret;
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	ret = p->IDR_REG.IDR;
	return ret;
}
void stm32f1x_gpio_switchOffAll(BYTE Port)
{
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	p->BSRR_REG.BSRR = GPIOx_PIN_ALL << 16;
}

void stm32f1x_gpio_switchOnAll(BYTE Port)
{
	volatile GPIOx_REG_MAP *p = stm32f1x_gpio_reg_lst[Port];
	p->BSRR_REG.BSRR = GPIOx_PIN_ALL;
}