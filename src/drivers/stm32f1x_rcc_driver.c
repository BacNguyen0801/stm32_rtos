#include "stm32f1x_rcc_driver.h"
/* PLL3RDY: PLL3 clock ready flag
Set by hardware to indicate that the PLL3 is locked.
0: PLL3 unlocked
1: PLL3 locked */
#define PLL3RDY_UNLOCKED 0x00
#define PLL3RDY_LOCKED 0x01

/* PLL3ON: PLL3 enable
Set and cleared by software to enable PLL3.
Cleared by hardware when entering Stop or Standby mode.
0: PLL3 OFF
1: PLL3 ON */
#define PLL3ON_OFF 0x00
#define PLL3ON_ON 0x01

/* PLL2RDY: PLL2 clock ready flag
Set by hardware to indicate that the PLL2 is locked.
0: PLL2 unlocked
1: PLL2 locked */
#define PLL2RDY_UNLOCKED 0x00
#define PLL2RDY_LOCKED 0x01

/* PLL2ON: PLL2 enable
Set and cleared by software to enable PLL2.
Cleared by hardware when entering Stop or Standby mode.
0: PLL2 OFF
1: PLL2 ON */
#define PLL2ON_OFF 0x00
#define PLL2ON_ON 0x01

/* PLLRDY: PLL clock ready flag
Set by hardware to indicate that the PLL is locked.
0: PLL unlocked
1: PLL locked */
#define PLLRDY_UNLOCKED 0x00
#define PLLRDY_LOCKED 0x01

/* PLLON: PLL enable
Set and cleared by software to enable PLL2.
Cleared by hardware when entering Stop or Standby mode.
0: PLL OFF
1: PLL ON */
#define PLLON_OFF 0x00
#define PLLON_ON 0x01

/* CSSON: Clock security system enable
Set and cleared by software to enable the clock security system. When CSSON is set, the
clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by
hardware if a HSE clock failure is detected.
0: Clock detector OFF
1: Clock detector ON (Clock detector ON if the HSE oscillator is ready, OFF if not) */
#define CSSON_CLOCK_DETECTOR_OFF 0x00
#define CSSON_CLOCK_DETECTOR_ON 0x01

/* HSEBYP: External high-speed clock bypass
Set and cleared by software to bypass the oscillator with an external clock. The external
clock must be enabled with the HSEON bit set, to be used by the device. The HSEBYP bit
can be written only if the HSE oscillator is disabled.
0: external 3-25 MHz oscillator not bypassed
1: external 3-25 MHz oscillator bypassed with external clock */
#define HSEBYP_EXTERNAL_OSC_NOT_BYPASSED 0x00
#define HSEBYP_EXTERNAL_OSC_BYPASSED 0x01

/* HSERDY: External high-speed clock ready flag
Set by hardware to indicate that the HSE oscillator is stable. This bit needs 6 cycles of the
HSE oscillator clock to fall down after HSEON reset.
0: HSE oscillator not ready
1: HSE oscillator ready */
#define HSERDY_HSE_NOT_READY 0x00
#define HSERDY_HSE_READY 0x01

/* HSEON: HSE clock enable
Set and cleared by software.
Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
0: HSE oscillator OFF
1: HSE oscillator ON */
#define HSEON_OSC_OFF 0x00
#define HSEON_OSC_ON 0x01

/* HSICAL[7:0]: Internal high-speed clock calibration
These bits are initialized automatically at startup. */
#define HSICAL_DEFAULT_VALUE 0x00

/* HSITRIM[4:0]: Internal high-speed clock trimming
These bits provide an additional user-programmable trimming value that is added to the
HSICAL[7:0] bits. It can be programmed to adjust to variations in voltage and temperature
that influence the frequency of the internal HSI RC.
The default value is 16, which, when added to the HSICAL value, should trim the HSI to 8
MHz ± 1%. The trimming step (Fhsitrim) is around 40 kHz between two consecutive HSICAL
step */
#define HSITRIM_DEFAULT_VALUE 0x00

/* HSIRDY: Internal high-speed clock ready flag
Set by hardware to indicate that internal 8 MHz RC oscillator is stable. After the HSION bit
is cleared, HSIRDY goes low after 6 internal 8 MHz RC oscillator clock cycles.
0: Internal 8 MHz RC oscillator not ready
1: Internal 8 MHz RC oscillator ready */
#define HSIRDY_8MHz_OSC_NOT_READY 0x00
#define HSIRDY_8MHz_OSC_READY 0x01

/* HSION: Internal high-speed clock enable
Set and cleared by software.
Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
mode or in case of failure of the external 3-25 MHz oscillator used directly or indirectly as
system clock. This bit can not be cleared if the internal 8 MHz RC is used directly or
indirectly as system clock or is selected to become the system clock.
0: Internal 8 MHz RC oscillator OFF
1: Internal 8 MHz RC oscillator ON */
#define HSION_8Mhz_INTERNAL_OFF 0x00
#define HSION_8Mhz_INTERNAL_ON 0x01

/* MCO: Microcontroller clock output
Set and cleared by software.
0xx: No clock
100: System clock (SYSCLK) selected
101: HSI clock selected
110: HSE clock selected
111: PLL clock divided by 2 selected */
#define MCO_NO_CLOCK_OUTPUT 0x00
#define MCO_SYSCLK_CLOCK_OUTPUT 0x04
#define MCO_HSI_CLOCK_OUTPUT 0x05
#define MCO_HSE_CLOCK_OUTPUT 0x06
#define MCO_PLL_DIV2_CLOCK_OUTPUT 0x07

/* USBPRE: USB prescaler
Set and cleared by software to generate 48 MHz USB clock. This bit must be valid before
enabling the USB clock in the RCC_APB1ENR register. This bit can’t be reset if the USB
clock is enabled.
0: PLL clock is divided by 1.5
1: PLL clock is not divided */
#define USBPRE_PLL_DIV 0x00
#define USBPRE_PLL_NOT_DIV 0x01

/* PLLMUL: PLL multiplication factor
These bits are written by software to define the PLL multiplication factor. These bits can be
written only when PLL is disabled.
Caution: The PLL output frequency must not exceed 72 MHz.
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16 */
#define PLLMUL_MUL_2 0x00
#define PLLMUL_MUL_3 0x01
#define PLLMUL_MUL_4 0x02
#define PLLMUL_MUL_5 0x03
#define PLLMUL_MUL_6 0x04
#define PLLMUL_MUL_7 0x05
#define PLLMUL_MUL_8 0x06
#define PLLMUL_MUL_9 0x07
#define PLLMUL_MUL_10 0x08
#define PLLMUL_MUL_11 0x09
#define PLLMUL_MUL_12 0x0A
#define PLLMUL_MUL_13 0x0B
#define PLLMUL_MUL_14 0x0C
#define PLLMUL_MUL_15 0x0D
#define PLLMUL_MUL_16 0x0E

/* PLLXTPRE: HSE divider for PLL entry
Set and cleared by software to divide HSE before PLL entry. This bit can be written only
when PLL is disabled.
0: HSE clock not divided
1: HSE clock divided by 2 */
#define PLLXTPRE_NOT_DIV 0x00
#define PLLXTPRE_DIV_2 0x01

/* PLLSRC: PLL entry clock source
Set and cleared by software to select PLL clock source. This bit can be written only when PLL is
disabled.
0: HSI oscillator clock / 2 selected as PLL input clock
1: Clock from PREDIV1 selected as PLL input clock */
#define PLLSRC_HSI_CLOCK_DIV_2 0x00
#define PLLSRC_HSE_CLOCK 0x01

/* ADCPRE[1:0]: ADC prescaler
Set and cleared by software to select the frequency of the clock to the ADCs.
00: PCLK2 divided by 2
01: PCLK2 divided by 4
10: PCLK2 divided by 6
11: PCLK2 divided by 8 */
#define ADCPRE_PCLK_DIV_2 0x00
#define ADCPRE_PCLK_DIV_4 0x01
#define ADCPRE_PCLK_DIV_6 0x02
#define ADCPRE_PCLK_DIV_8 0x03

/* PPRE2[2:0]: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16 */
#define PPRE2_HCLK_NOT_DIV 0x00
#define PPRE2_HCLK_DIV_2 0x04
#define PPRE2_HCLK_DIV_4 0x05
#define PPRE2_HCLK_DIV_8 0x06
#define PPRE2_HCLK_DIV_16 0x07

/* PPRE1[2:0]: APB Low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16 */
#define PPRE1_HCLK_NOT_DIV 0x00
#define PPRE1_HCLK_DIV_2 0x04
#define PPRE1_HCLK_DIV_4 0x05
#define PPRE1_HCLK_DIV_8 0x06
#define PPRE1_HCLK_DIV_16 0x07

/* HPRE[3:0]: AHB prescaler
Set and cleared by software to control AHB clock division factor.
0xxx: SYSCLK not divided
1000: SYSCLK divided by 2
1001: SYSCLK divided by 4
1010: SYSCLK divided by 8
1011: SYSCLK divided by 16
1100: SYSCLK divided by 64
1101: SYSCLK divided by 128
1110: SYSCLK divided by 256
1111: SYSCLK divided by 512 */
#define HPRE_SYSCLK_NOT_DIV 0x00
#define HPRE_SYSCLK_DIV_2 0x08
#define HPRE_SYSCLK_DIV_4 0x09
#define HPRE_SYSCLK_DIV_8 0x0A
#define HPRE_SYSCLK_DIV_16 0x0B
#define HPRE_SYSCLK_DIV_64 0x0C
#define HPRE_SYSCLK_DIV_128 0x0D
#define HPRE_SYSCLK_DIV_256 0x0E
#define HPRE_SYSCLK_DIV_512 0x0F

/* SWS[1:0]: System clock switch status
Set and cleared by hardware to indicate which clock source is used as system clock.
00: HSI oscillator used as system clock
01: HSE oscillator used as system clock
10: PLL used as system clock
11: Not applicable */
#define SWS_HSI_STS_SELECTED 0x00
#define SWS_HSE_STS_SELECTED 0x01
#define SWS_PLL_STS_SELECTED 0x02

/* SW[1:0]: System clock Switch
Set and cleared by software to select SYSCLK source.
Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
enabled).
00: HSI selected as system clock
01: HSE selected as system clock
10: PLL selected as system clock
11: Not allowed */
#define SW_HSI_SELECTED 0x00
#define SW_HSE_SELECTED 0x01
#define SW_PLL_SELECTED 0x02

/* CSSC: Clock security system interrupt clear
This bit is set by software to clear the CSSF flag.
0: No effect
1: Clear CSSF flag */
#define CSSC_NO_EFFECT 0x00
#define CSSC_CLEAR_FLAG 0x01

/* PLL3RDYC: PLL3 Ready Interrupt Clear
This bit is set by software to clear the PLL3RDYF flag.
0: No effect
1: Clear PLL3RDYF flag */
#define PLL3RDYC_NO_EFFECT 0x00
#define PLL3RDYC_CLEAR_FLAG 0x01

/* PLL2RDYC: PLL2 Ready Interrupt Clear
This bit is set by software to clear the PLL2RDYF flag.
0: No effect
1: Clear PLL2RDYF flag */
#define PLL2RDYC_NO_EFFECT 0x00
#define PLL2RDYC_CLEAR_FLAG 0x01

/* PLLRDYC: PLL Ready Interrupt Clear
This bit is set by software to clear the PLLRDYF flag.
0: No effect
1: Clear PLLRDYF flag */
#define PLLRDYC_NO_EFFECT 0x00
#define PLLRDYC_CLEAR_FLAG 0x01

/* HSERDYC: HSE ready interrupt clear
This bit is set by software to clear the HSERDYF flag.
0: No effect
1: Clear HSERDYF flag */
#define HSERDYC_NO_EFFECT 0x00
#define HSERDYC_CLEAR_FLAG 0x01

/* HSIRDYC: HSI ready interrupt clear
This bit is set by software to clear the HSIRDYF flag.
0: No effect
1: Clear HSIRDYF flag */
#define HSIRDYC_NO_EFFECT 0x00
#define HSIRDYC_CLEAR_FLAG 0x01

/* LSERDYC: LSE ready interrupt clear
This bit is set by software to clear the LSERDYF flag.
0: No effect
1: Clear LSERDYF flag */
#define LSERDYC_NO_EFFECT 0x00
#define LSERDYC_CLEAR_FLAG 0x01

/* LSIRDYC: LSI ready interrupt clear
This bit is set by software to clear the LSIRDYF flag.
0: No effect
1: Clear LSIRDYF flag */
#define LSIRDYC_NO_EFFECT 0x00
#define LSIRDYC_CLEAR_FLAG 0x01

/* PLL3RDYIE: PLL3 Ready Interrupt Enable
Set and cleared by software to enable/disable interrupt caused by PLL3 lock.
0: PLL3 lock interrupt disabled
1: PLL3 lock interrupt enabled */
#define PLL3RDYIE_LOCK_IRQ_DISABLE 0x00
#define PLL3RDYIE_LOCK_IRQ_ENABLE 0x01

/* PLL2RDYIE: PLL2 Ready Interrupt Enable
Set and cleared by software to enable/disable interrupt caused by PLL2 lock.
0: PLL2 lock interrupt disabled
1: PLL2 lock interrupt enabled */
#define PLL2RDYIE_LOCK_IRQ_DISABLE 0x00
#define PLL2RDYIE_LOCK_IRQ_ENABLE 0x01

/* PLLRDYIE: PLL ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by PLL lock.
0: PLL lock interrupt disabled
1: PLL lock interrupt enabled */
#define PLLRDYIE_LOCK_IRQ_DISABLE 0x00
#define PLLRDYIE_LOCK_IRQ_ENABLE 0x01

/* HSERDYIE: HSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the external 3-25 MHz
oscillator stabilization.
0: HSE ready interrupt disabled
1: HSE ready interrup */
#define HSERDYIE_IRQ_DISABLE 0x00
#define HSERDYIE_IRQ_ENABLE 0x01

/* HSIRDYIE: HSI ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the internal 8 MHz RC
oscillator stabilization.
0: HSI ready interrupt disabled
1: HSI ready interrupt enabled */
#define HSIRDYIE_IRQ_DISABLE 0x00
#define HSIRDYIE_IRQ_ENABLE 0x01

/* LSERDYIE: LSE ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by the external 32 kHz
oscillator stabilization.
0: LSE ready interrupt disabled
1: LSE ready interrupt enabled */
#define LSERDYIE_IRQ_DISABLE 0x00
#define LSERDYIE_IRQ_ENABLE 0x01

/* LSIRDYIE: LSI ready interrupt enable
Set and cleared by software to enable/disable interrupt caused by internal RC 40 kHz
oscillator stabilization.
0: LSI ready interrupt disabled
1: LSI ready interrupt enabled */
#define LSIRDYIE_IRQ_DISABLE 0x00
#define LSIRDYIE_IRQ_ENABLE 0x01

/* CSSF: Clock security system interrupt flag
Set by hardware when a failure is detected in the external 3-25 MHz oscillator. It is cleared
by software setting the CSSC bit.
0: No clock security interrupt caused by HSE clock failure
1: Clock security interrupt caused by HSE clock failure */
#define LSIRDYIE_IRQ_DISABLE 0x00
#define LSIRDYIE_IRQ_ENABLE 0x01

/* PLL3RDYF: PLL3 Ready Interrupt flag
Set by hardware when the PLL3 locks and PLL3RDYIE is set. It is cleared by software
setting the PLL3RDYC bit.
0: No clock ready interrupt caused by PLL3 lock
1: Clock ready interrupt caused by PLL3 lock */
#define PLL3RDYF_CLOCK_NO_READY 0x00
#define PLL3RDYF_CLOCK_READY 0x01

/* PLL2RDYF: PLL2 Ready Interrupt flag
Set by hardware when the PLL2 locks and PLL2RDYDIE is set. It is cleared by software
setting the PLL2RDYC bit.
0: No clock ready interrupt caused by PLL2 lock
1: Clock ready interrupt caused by PLL2 lock */
#define PLL2RDYF_CLOCK_NO_READY 0x00
#define PLL2RDYF_CLOCK_READY 0x01

/* PLLRDYF: PLL ready interrupt flag
Set by hardware when the PLL locks and PLLRDYDIE is set. It is cleared by software
setting the PLLRDYC bit.
0: No clock ready interrupt caused by PLL lock
1: Clock ready interrupt caused by PLL lock */
#define PLLRDYF_CLOCK_NO_READY 0x00
#define PLLRDYF_CLOCK_READY 0x01

/* HSERDYF: HSE ready interrupt flag
Set by hardware when External High Speed clock becomes stable and HSERDYIE is set. It
is cleared by software setting the HSERDYC bit.
0: No clock ready interrupt caused by the external 3-25 MHz oscillator
1: Clock ready interrupt caused by the external 3-25 MHz oscillator */
#define HSERDYF_CLOCK_NO_READY 0x00
#define HSERDYF_CLOCK_READY 0x01

/* HSIRDYF: HSI ready interrupt flag
Set by hardware when the Internal High Speed clock becomes stable and HSIRDYIE is set.
It is cleared by software setting the HSIRDYC bit.
0: No clock ready interrupt caused by the internal 8 MHz RC oscillator
1: Clock ready interrupt caused by the internal 8 MHz RC oscillator */
#define HSIRDYF_CLOCK_NO_READY 0x00
#define HSIRDYF_CLOCK_READY 0x01

/* LSERDYF: LSE ready interrupt flag
Set by hardware when the External Low Speed clock becomes stable and LSERDYIE is set.
It is cleared by software setting the LSERDYC bit.
0: No clock ready interrupt caused by the external 32 kHz oscillator
1: Clock ready interrupt caused by the external 32 kHz oscillator */
#define LSERDYF_CLOCK_NO_READY 0x00
#define LSERDYF_CLOCK_READY 0x01

/*  LSIRDYF: LSI ready interrupt flag
Set by hardware when Internal Low Speed clock becomes stable and LSIRDYIE is set. It is
cleared by software setting the LSIRDYC bit.
0: No clock ready interrupt caused by the internal RC 40 kHz oscillator
1: Clock ready interrupt caused by the internal RC 40 kHz oscillator */
#define LSIRDYF_CLOCK_NO_READY 0x00
#define LSIRDYF_CLOCK_READY 0x01

/* TIM11RST: TIM11 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM11 timer */
#define TIM11RST_NO_RESET 0x00
#define TIM11RST_RESET 0x01

/* TIM10RST: TIM10 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM10 timer */
#define TIM10RST_NO_RESET 0x00
#define TIM10RST_RESET 0x01

/* TIM9RST: TIM9 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM9 timer */
#define TIM9RST_NO_RESET 0x00
#define TIM9RST_RESET 0x01

/* ADC3RST: ADC3 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC3 interface */
#define ADC3RST_NO_RESET 0x00
#define ADC3RST_RESET 0x01

/* USART1RST: USART1 reset
Set and cleared by software.
0: No effect
1: Reset USART1 */
#define USART1RST_NO_RESET 0x00
#define USART1RST_RESET 0x01

/* TIM8RST: TIM8 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM8 timer */
#define TIM8RST_NO_RESET 0x00
#define TIM8RST_RESET 0x01

/* SPI1RST: SPI1 reset
Set and cleared by software.
0: No effect
1: Reset SPI1 */
#define SPI1RST_NO_RESET 0x00
#define SPI1RST_RESET 0x01

/* TIM1RST: TIM1 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM1 timer */
#define TIM1RST_NO_RESET 0x00
#define TIM1RST_RESET 0x01

/* ADC2RST: ADC 2 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC 2 interface */
#define ADC2RST_NO_RESET 0x00
#define ADC2RST_RESET 0x01

/* ADC1RST: ADC 1 interface reset
Set and cleared by software.
0: No effect
1: Reset ADC 1 interface */
#define ADC1RST_NO_RESET 0x00
#define ADC1RST_RESET 0x01

/* IOPGRST: IO port G reset
Set and cleared by software.
0: No effect
1: Reset IO port G */
#define IOPGRST_NO_RESET 0x00
#define IOPGRST_RESET 0x01

/* IOPFRST: IO port F reset
Set and cleared by software.
0: No effect
1: Reset IO port F */
#define IOPFRST_NO_RESET 0x00
#define IOPFRST_RESET 0x01

/*  IOPERST: IO port E reset
Set and cleared by software.
0: No effect
1: Reset IO port E */
#define IOPERST_NO_RESET 0x00
#define IOPERST_RESET 0x01

/* IOPDRST: IO port D reset
Set and cleared by software.
0: No effect
1: Reset IO port D */
#define IOPDRST_NO_RESET 0x00
#define IOPDRST_RESET 0x01

/* IOPCRST: IO port C reset
Set and cleared by software.
0: No effect
1: Reset IO port C */
#define IOPCRST_NO_RESET 0x00
#define IOPCRST_RESET 0x01

/* IOPBRST: IO port B reset
Set and cleared by software.
0: No effect
1: Reset IO port B */
#define IOPBRST_NO_RESET 0x00
#define IOPBRST_RESET 0x01

/* IOPARST: IO port A reset
Set and cleared by software.
0: No effect
1: Reset IO port A */
#define IOPARST_NO_RESET 0x00
#define IOPARST_RESET 0x01

/* AFIORST: Alternate function IO reset
Set and cleared by software.
0: No effect
1: Reset Alternate Function */
#define AFIORST_NO_RESET 0x00
#define AFIORST_RESET 0x01

/* DACRST: DAC interface reset
Set and cleared by software.
0: No effect
1: Reset DAC interface */
#define DACRST_NO_RESET 0x00
#define DACRST_RESET 0x01

/* PWRRST: Power interface reset
Set and cleared by software.
0: No effect
1: Reset power interface */
#define PWRRST_NO_RESET 0x00
#define PWRRST_RESET 0x01

/* BKPRST: Backup interface reset
Set and cleared by software.
0: No effect
1: Reset backup interface */
#define BKPRST_NO_RESET 0x00
#define BKPRST_RESET 0x01

/* CANRST: CAN reset
Set and cleared by software.
0: No effect
1: Reset CAN */
#define CANRST_NO_RESET 0x00
#define CANRST_RESET 0x01

/* USBRST: USB reset
Set and cleared by software.
0: No effect
1: Reset USB */
#define USBRST_NO_RESET 0x00
#define USBRST_RESET 0x01

/* I2C2RST: I2C2 reset
Set and cleared by software.
0: No effect
1: Reset I2C2 */
#define I2C2RST_NO_RESET 0x00
#define I2C2RST_RESET 0x01

/* I2C1RST: I2C1 reset
Set and cleared by software.
0: No effect
1: Reset I2C1 */
#define I2C1RST_NO_RESET 0x00
#define I2C1RST_RESET 0x01

/* UART5RST: USART5 reset
Set and cleared by software.
0: No effect
1: Reset USART5 */
#define UART5RST_NO_RESET 0x00
#define UART5RST_RESET 0x01

/* UART5RST: USART4 reset
Set and cleared by software.
0: No effect
1: Reset USART4 */
#define UART4RST_NO_RESET 0x00
#define UART4RST_RESET 0x01

/* UART3RST: USART3 reset
Set and cleared by software.
0: No effect
1: Reset USART3 */
#define UART3RST_NO_RESET 0x00
#define UART3RST_RESET 0x01

/* UART2RST: USART2 reset
Set and cleared by software.
0: No effect
1: Reset USART2 */
#define UART2RST_NO_RESET 0x00
#define UART2RST_RESET 0x01

/*  SPI3RST: SPI3 reset
Set and cleared by software.
0: No effect
1: Reset SPI3 */
#define SPI3RST_NO_RESET 0x00
#define SPI3RST_RESET 0x01

/*  SPI2RST: SPI2 reset
Set and cleared by software.
0: No effect
1: Reset SPI2 */
#define SPI2RST_NO_RESET 0x00
#define SPI2RST_RESET 0x01

/* WWDGRST: Window watchdog reset
Set and cleared by software.
0: No effect
1: Reset window watchdog */
#define WWDGRST_NO_RESET 0x00
#define WWDGRST_RESET 0x01

/* TIM14RST: TIM14 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM14 */
#define TIM14RST_NO_RESET 0x00
#define TIM14RST_RESET 0x01

/* TIM13RST: TIM13 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM13 */
#define TIM13RST_NO_RESET 0x00
#define TIM13RST_RESET 0x01

/* TIM12RST: TIM12 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM12 */
#define TIM12RST_NO_RESET 0x00
#define TIM12RST_RESET 0x01

/* TIM7RST: TIM7 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM7 */
#define TIM7RST_NO_RESET 0x00
#define TIM7RST_RESET 0x01

/* TIM6RST: TIM6 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM6 */
#define TIM6RST_NO_RESET 0x00
#define TIM6RST_RESET 0x01

/* TIM5RST: TIM5 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM5 */
#define TIM5RST_NO_RESET 0x00
#define TIM5RST_RESET 0x01

/* TIM4RST: TIM4 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM4 */
#define TIM4RST_NO_RESET 0x00
#define TIM4RST_RESET 0x01

/* TIM3RST: TIM3 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM3 */
#define TIM3RST_NO_RESET 0x00
#define TIM3RST_RESET 0x01

/* TIM2RST: TIM2 timer reset
Set and cleared by software.
0: No effect
1: Reset TIM2 */
#define TIM2RST_NO_RESET 0x00
#define TIM2RST_RESET 0x01

/* SDIOEN: SDIO clock enable
Set and cleared by software.
0: SDIO clock disabled
1: SDIO clock enabled */
#define SDIOEN_CLOCK_DISABLE 0x00
#define SDIOEN_CLOCK_ENABLE 0x01

/* FSMCEN: FSMC clock enable
Set and cleared by software.
0: FSMC clock disabled
1: FSMC clock enabled */
#define FSMCEN_CLOCK_DISABLE 0x00
#define FSMCEN_CLOCK_ENABLE 0x01

/* CRCEN: CRC clock enable
Set and cleared by software.
0: CRC clock disabled
1: CRC clock enabled */
#define CRCEN_CLOCK_DISABLE 0x00
#define CRCEN_CLOCK_ENABLE 0x01

/* FLITFEN: FLITF clock enable
Set and cleared by software to disable/enable FLITF clock during Sleep mode.
0: FLITF clock disabled during Sleep mode
1: FLITF clock enabled during Sleep mode */
#define FLITFEN_CLOCK_DISABLE 0x00
#define FLITFEN_CLOCK_ENABLE 0x01

/* SRAMEN: SRAM interface clock enable
Set and cleared by software to disable/enable SRAM interface clock during Sleep mode.
0: SRAM interface clock disabled during Sleep mode.
1: SRAM interface clock enabled during Sleep mode */
#define SRAMEN_CLOCK_DISABLE 0x00
#define SRAMEN_CLOCK_ENABLE 0x01

/* DMA2EN: DMA2 clock enable
Set and cleared by software.
0: DMA2 clock disabled
1: DMA2 clock enabled */
#define DMA2EN_CLOCK_DISABLE 0x00
#define DMA2EN_CLOCK_ENABLE 0x01

/* DMA1EN: DMA1 clock enable
Set and cleared by software.
0: DMA1 clock disabled
1: DMA1 clock enabled */
#define DMA1EN_CLOCK_DISABLE 0x00
#define DMA1EN_CLOCK_ENABLE 0x01

/* Bit 21 TIM11EN: TIM11 timer clock enable
Set and cleared by software.
0: TIM11 timer clock disabled
1: TIM11 timer clock enabled */
#define TIM11EN_CLOCK_DISABLE 0x00
#define TIM11EN_CLOCK_ENABLE 0x01

/* Bit 20 TIM10EN: TIM10 timer clock enable
Set and cleared by software.
0: TIM10 timer clock disabled
1: TIM10 timer clock enabled */
#define TIM10EN_CLOCK_DISABLE 0x00
#define TIM10EN_CLOCK_ENABLE 0x01

/* Bit 19 TIM9EN: TIM9 timer clock enable
Set and cleared by software.
0: TIM9 timer clock disabled
1: TIM9 timer clock enabled */
#define TIM9EN_CLOCK_DISABLE 0x00
#define TIM9EN_CLOCK_ENABLE 0x01

/* Bit 15 ADC3EN: ADC3 interface clock enable
Set and cleared by software.
0: ADC3 interface clock disabled
1: ADC3 interface clock enabled */
#define ADC3EN_CLOCK_DISABLE 0x00
#define ADC3EN_CLOCK_ENABLE 0x01

/* Bit 14 USART1EN: USART1 clock enable
Set and cleared by software.
0: USART1 clock disabled
1: USART1 clock enabled */
#define USART1EN_CLOCK_DISABLE 0x00
#define USART1EN_CLOCK_ENABLE 0x01

/* Bit 13 TIM8EN: TIM8 Timer clock enable
Set and cleared by software.
0: TIM8 timer clock disabled
1: TIM8 timer clock enabled */
#define TIM8EN_CLOCK_DISABLE 0x00
#define TIM8EN_CLOCK_ENABLE 0x01

/* Bit 12 SPI1EN: SPI1 clock enable
Set and cleared by software.
0: SPI1 clock disabled
1: SPI1 clock enabled */
#define SPI1EN_CLOCK_DISABLE 0x00
#define SPI1EN_CLOCK_ENABLE 0x01

/* Bit 11 TIM1EN: TIM1 timer clock enable
Set and cleared by software.
0: TIM1 timer clock disabled
1: TIM1 timer clock enabled */
#define TIM1EN_CLOCK_DISABLE 0x00
#define TIM1EN_CLOCK_ENABLE 0x01

/* Bit 10 ADC2EN: ADC 2 interface clock enable
Set and cleared by software.
0: ADC 2 interface clock disabled
1: ADC 2 interface clock enabled */
#define ADC2EN_CLOCK_DISABLE 0x00
#define ADC2EN_CLOCK_ENABLE 0x01

/* Bit 9 ADC1EN: ADC 1 interface clock enable
Set and cleared by software.
0: ADC 1 interface disabled
1: ADC 1 interface clock enabled */
#define ADC1EN_CLOCK_DISABLE 0x00
#define ADC1EN_CLOCK_ENABLE 0x01

/* Bit 8 IOPGEN: IO port G clock enable
Set and cleared by software.
0: IO port G clock disabled
1: IO port G clock enabled */
#define IOPGEN_CLOCK_DISABLE 0x00
#define IOPGEN_CLOCK_ENABLE 0x01

/* Bit 7 IOPFEN: IO port F clock enable
Set and cleared by software.
0: IO port F clock disabled
1: IO port F clock enabled */
#define IOPFEN_CLOCK_DISABLE 0x00
#define IOPFEN_CLOCK_ENABLE 0x01

/* Bit 6 IOPEEN: IO port E clock enable
Set and cleared by software.
0: IO port E clock disabled
1: IO port E clock enabled */
#define IOPEEN_CLOCK_DISABLE 0x00
#define IOPEEN_CLOCK_ENABLE 0x01

/* Bit 5 IOPDEN: IO port D clock enable
Set and cleared by software.
0: IO port D clock disabled
1: IO port D clock enabled */
#define IOPDEN_CLOCK_DISABLE 0x00
#define IOPDEN_CLOCK_ENABLE 0x01

/* Bit 4 IOPCEN: IO port C clock enable
Set and cleared by software.
0: IO port C clock disabled
1: IO port C clock enabled */
#define IOPCEN_CLOCK_DISABLE 0x00
#define IOPCEN_CLOCK_ENABLE 0x01

/* Bit 3 IOPBEN: IO port B clock enable
Set and cleared by software.
0: IO port B clock disabled
1: IO port B clock enabled */
#define IOPBEN_CLOCK_DISABLE 0x00
#define IOPBEN_CLOCK_ENABLE 0x01

/* Bit 2 IOPAEN: IO port A clock enable
Set and cleared by software.
0: IO port A clock disabled
1: IO port A clock enabled */
#define IOPAEN_CLOCK_DISABLE 0x00
#define IOPAEN_CLOCK_ENABLE 0x01

/* AFIOEN: Alternate function IO clock enable
Set and cleared by software.
0: Alternate Function IO clock disabled
1: Alternate Function IO clock enabled */
#define AFIOEN_CLOCK_DISABLE 0x00
#define AFIOEN_CLOCK_ENABLE 0x01

/* Bit 29 DACEN: DAC interface clock enable
Set and cleared by software.
0: DAC interface clock disabled
1: DAC interface clock enable */
#define DACEN_CLOCK_DISABLE 0x00
#define DACEN_CLOCK_ENABLE 0x01

/* Bit 28 PWREN: Power interface clock enable
Set and cleared by software.
0: Power interface clock disabled
1: Power interface clock enable */
#define PWREN_CLOCK_DISABLE 0x00
#define PWREN_CLOCK_ENABLE 0x01

/* Bit 27 BKPEN: Backup interface clock enable
Set and cleared by software.
0: Backup interface clock disabled
1: Backup interface clock enabled */
#define BKPEN_CLOCK_DISABLE 0x00
#define BKPEN_CLOCK_ENABLE 0x01

/* CANEN: CAN clock enable
Set and cleared by software.
0: CAN clock disabled
1: CAN clock enabled */
#define CANEN_CLOCK_DISABLE 0x00
#define CANEN_CLOCK_ENABLE 0x01

/* USBEN: USB clock enable
Set and cleared by software.
0: USB clock disabled
1: USB clock enabled */
#define USBEN_CLOCK_DISABLE 0x00
#define USBEN_CLOCK_ENABLE 0x01

/* Bit 22 I2C2EN: I2C2 clock enable
Set and cleared by software.
0: I2C2 clock disabled
1: I2C2 clock enabled */
#define I2C2EN_CLOCK_DISABLE 0x00
#define I2C2EN_CLOCK_ENABLE 0x01

/* Bit 21 I2C1EN: I2C1 clock enable
Set and cleared by software.
0: I2C1 clock disabled
1: I2C1 clock enabled */
#define I2C1EN_CLOCK_DISABLE 0x00
#define I2C1EN_CLOCK_ENABLE 0x01

/* Bit 20 UART5EN: USART5 clock enable
Set and cleared by software.
0: USART5 clock disabled
1: USART5 clock enabled */
#define UART5EN_CLOCK_DISABLE 0x00
#define UART5EN_CLOCK_ENABLE 0x01

/* Bit 19 UART4EN: USART4 clock enable
Set and cleared by software.
0: USART4 clock disabled
1: USART4 clock enabled */
#define UART4EN_CLOCK_DISABLE 0x00
#define UART4EN_CLOCK_ENABLE 0x01

/* Bit 18 USART3EN: USART3 clock enable
Set and cleared by software.
0: USART3 clock disabled
1: USART3 clock enabled */
#define UART3EN_CLOCK_DISABLE 0x00
#define UART3EN_CLOCK_ENABLE 0x01

/* Bit 17 USART2EN: USART2 clock enable
Set and cleared by software.
0: USART2 clock disabled
1: USART2 clock enabled */
#define UART2EN_CLOCK_DISABLE 0x00
#define UART2EN_CLOCK_ENABLE 0x01

/* Bit 15 SPI3EN: SPI 3 clock enable
Set and cleared by software.
0: SPI 3 clock disabled
1: SPI 3 clock enabled */
#define SPI3EN_CLOCK_DISABLE 0x00
#define SPI3EN_CLOCK_ENABLE 0x01

/* Bit 14 SPI2EN: SPI2 clock enable
Set and cleared by software.
0: SPI2 clock disabled
1: SPI2 clock enabled */
#define SPI2EN_CLOCK_DISABLE 0x00
#define SPI2EN_CLOCK_ENABLE 0x01

/* WWDGEN: Window watchdog clock enable
Set and cleared by software.
0: Window watchdog clock disabled
1: Window watchdog clock enabled */
#define WWDGEN_CLOCK_DISABLE 0x00
#define WWDGEN_CLOCK_ENABLE 0x01

/* TIM14EN: TIM14 timer clock enable
Set and cleared by software.
0: TIM14 clock disabled
1: TIM14 clock enabled */
#define TIM14EN_CLOCK_DISABLE 0x00
#define TIM14EN_CLOCK_ENABLE 0x01

/* Bit 7 TIM13EN: TIM13 timer clock enable
Set and cleared by software.
0: TIM13 clock disabled
1: TIM13 clock enabled */
#define TIM13EN_CLOCK_DISABLE 0x00
#define TIM13EN_CLOCK_ENABLE 0x01

/* Bit 6 TIM12EN: TIM12 timer clock enable
Set and cleared by software.
0: TIM12 clock disabled
1: TIM12 clock enabled */
#define TIM12EN_CLOCK_DISABLE 0x00
#define TIM12EN_CLOCK_ENABLE 0x01

/* Bit 5 TIM7EN: TIM7 timer clock enable
Set and cleared by software.
0: TIM7 clock disabled
1: TIM7 clock enabled */
#define TIM7EN_CLOCK_DISABLE 0x00
#define TIM7EN_CLOCK_ENABLE 0x01

/* Bit 4 TIM6EN: TIM6 timer clock enable
Set and cleared by software.
0: TIM6 clock disabled
1: TIM6 clock enabled */
#define TIM6EN_CLOCK_DISABLE 0x00
#define TIM6EN_CLOCK_ENABLE 0x01

/* Bit 3 TIM5EN: TIM5 timer clock enable
Set and cleared by software.
0: TIM5 clock disabled
1: TIM5 clock enabled */
#define TIM5EN_CLOCK_DISABLE 0x00
#define TIM5EN_CLOCK_ENABLE 0x01

/* Bit 2 TIM4EN: TIM4 timer clock enable
Set and cleared by software.
0: TIM4 clock disabled
1: TIM4 clock enabled */
#define TIM4EN_CLOCK_DISABLE 0x00
#define TIM4EN_CLOCK_ENABLE 0x01

/* Bit 1 TIM3EN: TIM3 timer clock enable
Set and cleared by software.
0: TIM3 clock disabled
1: TIM3 clock enabled */
#define TIM3EN_CLOCK_DISABLE 0x00
#define TIM3EN_CLOCK_ENABLE 0x01

/* Bit 0 TIM2EN: TIM2 timer clock enable
Set and cleared by software.
0: TIM2 clock disabled
1: TIM2 clock enabled */
#define TIM2EN_CLOCK_DISABLE 0x00
#define TIM2EN_CLOCK_ENABLE 0x01

/* Bit 16 BDRST: Backup domain software reset
Set and cleared by software.
0: Reset not activated
1: Resets the entire Backup domain */
#define BDRST_RESET_NOT_ACTIVE 0x00
#define BDRST_RESET_ENTIRE_BK_DOMAIN 0x01

/* Bit 15 RTCEN: RTC clock enable
Set and cleared by software.
0: RTC clock disabled
1: RTC clock enabled */
#define RTCEN_CLOCK_DISABLE 0x00
#define RTCEN_CLOCK_ENABLE 0x01

/* RTCSEL: RTC clock source selection
Set by software to select the clock source for the RTC. Once the RTC clock source has been
selected, it cannot be changed anymore unless the Backup domain is reset. The BDRST bit
can be used to reset them.
00: No clock
01: LSE oscillator clock used as RTC clock
10: LSI oscillator clock used as RTC clock
11: HSE oscillator clock divided by 128 used as RTC clock */
#define RTCSEL_NO_CLOCK 0x00
#define RTCSEL_LSE_SELECTED 0x01
#define RTCSEL_LSI_SELECTED 0x02
#define RTCSEL_HSE_SELECTED 0x03

/* Bit 2 LSEBYP: External low-speed oscillator bypass
Set and cleared by software to bypass oscillator in debug mode. This bit can be written only
when the external 32 kHz oscillator is disabled.
0: LSE oscillator not bypassed
1: LSE oscillator bypassed */
#define LSEBYP_LSE_NOT_BYPASSED 0x00
#define LSEBYP_LSE_BYPASSED 0x01

/* Bit 1 LSERDY: External low-speed oscillator ready
Set and cleared by hardware to indicate when the external 32 kHz oscillator is stable. After
the LSEON bit is cleared, LSERDY goes low after 6 external low-speed oscillator clock
cycles.
0: External 32 kHz oscillator not ready
1: External 32 kHz oscillator ready */
#define LSERDY_32KHZ_NOT_READY 0x00
#define LSERDY_32KHZ_READY 0x01

/* Bit 0 LSEON: External low-speed oscillator enable
Set and cleared by software.
0: External 32 kHz oscillator OFF
1: External 32 kHz oscillator ON */
#define LSEON_32KHZ_OFF 0x00
#define LSEON_32KHZ_ON 0x01

/* LPWRRSTF: Low-power reset flag
Set by hardware when a Low-power management reset occurs.
Cleared by writing to the RMVF bit.
0: No Low-power management reset occurred
1: Low-power management reset occurred */
#define LPWRRSTF_RESET_NO_OCCURRED 0x00
#define LPWRRSTF_RESET_OCCURRED 0x01

/* WWDGRSTF: Window watchdog reset flag
Set by hardware when a window watchdog reset occurs.
Cleared by writing to the RMVF bit.
0: No window watchdog reset occurred
1: Window watchdog reset occurred */
#define WWDGRSTF_RESET_NO_OCCURRED 0x00
#define WWDGRSTF_RESET_OCCURRED 0x01

/* IWDGRSTF: Independent watchdog reset flag
Set by hardware when an independent watchdog reset from VDD domain occurs.
Cleared by writing to the RMVF bit.
0: No watchdog reset occurred
1: Watchdog reset occurred */
#define IWDGRSTF_RESET_NO_OCCURRED 0x00
#define IWDGRSTF_RESET_OCCURRED 0x01

/* SFTRSTF: Software reset flag
Set by hardware when a software reset occurs.
Cleared by writing to the RMVF bit.
0: No software reset occurred
1: Software reset occurred */
#define SFTRSTF_RESET_NO_OCCURRED 0x00
#define SFTRSTF_RESET_OCCURRED 0x01

/* PORRSTF: POR/PDR reset flag
Set by hardware when a POR/PDR reset occurs.
Cleared by writing to the RMVF bit.
0: No POR/PDR reset occurred
1: POR/PDR reset occurred */
#define PORRSTF_RESET_NO_OCCURRED 0x00
#define PORRSTF_RESET_OCCURRED 0x01

/* PINRSTF: PIN reset flag
Set by hardware when a reset from the NRST pin occurs.
Cleared by writing to the RMVF bit.
0: No reset from NRST pin occurred
1: Reset from NRST pin occurred */
#define PINRSTF_RESET_NO_OCCURRED 0x00
#define PINRSTF_RESET_OCCURRED 0x01

/* RMVF: Remove reset flag
Set by software to clear the reset flags.
0: No effect
1: Clear the reset flags */
#define RMVF_NO_EFFECT 0x00
#define RMVF_CLEAR_RESET 0x01

/* LSIRDY: Internal low-speed oscillator ready
Set and cleared by hardware to indicate when the internal RC 40 kHz oscillator is stable.
After the LSION bit is cleared, LSIRDY goes low after 3 internal RC 40 kHz oscillator clock
cycles.
0: Internal RC 40 kHz oscillator not ready
1: Internal RC 40 kHz oscillator ready */
#define LSIRDY_40KHZ_NOT_READY 0x00
#define LSIRDY_40KHZ_READY 0x01

/* LSION: Internal low-speed oscillator enable
Set and cleared by software.
0: Internal RC 40 kHz oscillator OFF
1: Internal RC 40 kHz oscillator ON */
#define LSION_40KHZ_OFF 0x00
#define LSION_40KHZ_ON 0x01

#define RCC_BASE_ADDRESS (RCC_REG_MAP *)0x40021000
static volatile RCC_REG_MAP *const stm32f1x_rcc_reg = RCC_BASE_ADDRESS;

void stm32f1x_rcc_driver_init()
{
    stm32f1x_rcc_reg->CR_REG.HSION = HSION_8Mhz_INTERNAL_ON;

    stm32f1x_rcc_reg->CFGR_REG.PLLSRC = PLLSRC_HSE_CLOCK;
    stm32f1x_rcc_reg->CFGR_REG.PLLXTPRE = PLLXTPRE_NOT_DIV;
    stm32f1x_rcc_reg->CFGR_REG.PLLMUL = PLLMUL_MUL_2;

    stm32f1x_rcc_reg->CR_REG.HSEON = HSEON_OSC_ON;
    stm32f1x_rcc_reg->CR_REG.PLLON = PLLON_ON;

    stm32f1x_rcc_reg->CFGR_REG.SW = SW_PLL_SELECTED;
    stm32f1x_rcc_reg->CFGR_REG.HPRE = HPRE_SYSCLK_NOT_DIV;
    stm32f1x_rcc_reg->CFGR_REG.PPRE1 = PPRE1_HCLK_DIV_2;
    stm32f1x_rcc_reg->CFGR_REG.PPRE2 = PPRE2_HCLK_NOT_DIV;
    stm32f1x_rcc_reg->CFGR_REG.ADCPRE = ADCPRE_PCLK_DIV_2;

    stm32f1x_rcc_reg->CIR_REG.LSIRDYC = LSIRDYC_CLEAR_FLAG;
    stm32f1x_rcc_reg->CIR_REG.HSIRDYC = HSIRDYC_CLEAR_FLAG;
    stm32f1x_rcc_reg->CIR_REG.HSERDYC = HSERDYC_CLEAR_FLAG;
    stm32f1x_rcc_reg->CIR_REG.PLLRDYC = PLLRDYC_CLEAR_FLAG;
    stm32f1x_rcc_reg->CIR_REG.CSSC = CSSC_CLEAR_FLAG;

    stm32f1x_rcc_reg->APB2ENR_REG.IOPCEN = IOPCEN_CLOCK_ENABLE;
    stm32f1x_rcc_reg->APB1ENR_REG.TIM6EN = TIM6EN_CLOCK_ENABLE;
}