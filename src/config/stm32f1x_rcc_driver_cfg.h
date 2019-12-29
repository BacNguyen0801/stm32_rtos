#pragma once
#include "base_types.h"

typedef struct {
	DWORD HSION: 1; /* Internal high-speed clock enable */
	DWORD HSIRDY: 1; /* Internal high-speed clock ready flag */
	DWORD Reserved_2: 1; /* Reserved, must be kept at reset value.  */
	DWORD HSITRIM:5; /* Internal high-speed clock trimming */
	DWORD HSICAL: 8; /* Internal high-speed clock calibration */
	DWORD HSEON: 1; /* HSE clock enable */
	DWORD HSERDY: 1; /* External high-speed clock ready flag */
	DWORD HSEBYP: 1; /* External high-speed clock bypass */
	DWORD CSSON: 1; /* Clock security system enable */
	DWORD Reserved_1: 4; /* Reserved, must be kept at reset value.  */
	DWORD PLLON: 1; /* PLL enable */
	DWORD PLLRDY: 1; /* PLL clock ready flag */
	DWORD Reserved: 6; /* Reserved, must be kept at reset value. */
} RCC_CR_REG;

typedef struct {
	DWORD SW: 2; /* System clock switch */
	DWORD SWS: 2; /* System clock switch status */
	DWORD HPRE: 4; /* AHB prescaler */
	DWORD PPRE1: 3; /* APB low-speed prescaler (APB1) */
	DWORD PPRE2: 3; /* APB high-speed prescaler (APB2) */
	DWORD ADCPRE: 2; /* ADC prescaler */
	DWORD PLLSRC: 1; /* PLL entry clock source */
	DWORD PLLXTPRE: 1; /* HSE divider for PLL entry */
	DWORD PLLMUL: 4; /* PLL multiplication factor */
	DWORD USBPRE: 1; /* USB prescaler */
	DWORD MCO: 3; /* Microcontroller clock output */
	DWORD Reserved: 5; /* Reserved, must be kept at reset value. */
} RCC_CFGR_REG;

typedef struct 
{
	DWORD LSIRDYF: 1; /* LSI ready interrupt flag */
	DWORD LSERDYF: 1; /* LSE ready interrupt flag */
	DWORD HSIRDYF: 1; /* HSI ready interrupt flag */
	DWORD HSERDYF: 1; /* HSE ready interrupt flag */
	DWORD PLLRDYF: 1; /* PLL ready interrupt flag */
	DWORD Reserved_3: 2; /* must be kept at reset value. */
	DWORD CSSF: 1; /* Clock security system interrupt flag */
	DWORD LSIRDYIE: 1; /* LSI ready interrupt enable */
	DWORD LSERDYIE: 1; /* LSE ready interrupt enable */
	DWORD HSIRDYIE: 1; /* HSI ready interrupt enable */
	DWORD HSERDYIE: 1; /* HSE ready interrupt enable */
	DWORD PLLRDYIE: 1; /* PLL ready interrupt enable */
	DWORD Reserved_2: 3; /* Reserved, must be kept at reset value. */
	DWORD LSIRDYC: 1; /* LSI ready interrupt clear */
	DWORD HSIRDYC: 1; /* LSERDYC: LSE ready interrupt clear */
	DWORD HSERDYC: 1; /* HSE ready interrupt clear */
	DWORD PLLRDYC: 1; /* PLL ready interrupt clear */
	DWORD Reserved_1: 2; /* Reserved, must be kept at reset value. */
	DWORD CSSC: 1; /* Clock security system interrupt clear */
	DWORD Reserved: 8; /* Reserved, must be kept at reset value. */
} RCC_CIR_REG;

typedef struct {
	DWORD AFIORST: 1; /*  Alternate function IO reset */
	DWORD Reserved_2: 1; /*  must be kept at reset value. */
	DWORD IOPARST: 1; /*  IO port A reset */
	DWORD IOPBRST: 1; /*  IO port B reset */
	DWORD IOPCRST: 1; /*  IO port C reset */
	DWORD IOPDRST: 1; /*  IO port D reset */
	DWORD IOPERST: 1; /*  IO port E reset */
	DWORD IOPFRST: 1; /*  IO port F reset */
	DWORD IOPGRST: 1; /*  IO port G reset */
	DWORD ADC1RST: 1; /*  ADC 1 interface reset */
	DWORD ADC2RST: 1; /*  ADC 2 interface reset */
	DWORD TIM1RST: 1; /*  TIM1 timer reset */
	DWORD SPI1RST: 1; /*  SPI1 reset */
	DWORD TIM8RST: 1; /*  TIM8 timer reset */
	DWORD USART1RST: 1; /*  USART1 reset */
	DWORD ADC3RST: 1; /*  ADC3 interface reset */
	DWORD Reserved_1: 3; /*  always read as 0. */
	DWORD TIM9RST: 1; /*  TIM9 timer reset */
	DWORD TIM10RST: 1; /*  TIM10 timer reset */
	DWORD TIM11RST: 1; /*  TIM11 timer reset */
} RCC_APB2RSTR_REG;

typedef struct 
{
	DWORD TIM2RST: 1; /* TIM2 timer reset */
	DWORD TIM3RST: 1; /* TIM3 timer reset */
	DWORD TIM4RST: 1; /* TIM4 timer reset */
	DWORD TIM5RST: 1; /* TIM5 timer reset */
	DWORD TIM6RST: 1; /* TIM6 timer reset */
	DWORD TIM7RST: 1; /* TIM7 timer reset */
	DWORD TIM12RST: 1; /* TIM12 timer reset */
	DWORD TIM13RST: 1; /* TIM13 timer reset */
	DWORD TIM14RST: 1; /* TIM14 timer reset */
	DWORD Reserved: 2; /* must be kept at reset value. */
	DWORD WWDGRST: 1; /* Window watchdog reset */
	DWORD Reserved_1: 2; /* must be kept at reset value. */
	DWORD SPI2RST: 1; /* SPI2 reset */
	DWORD SPI3RST: 1; /* SPI3 reset */
	DWORD Reserved_2: 1; /* must be kept at reset value. */
	DWORD USART2RST: 1; /* USART2 reset */
	DWORD USART3RST: 1; /* USART3 reset */
	DWORD UART4RST: 1; /* USART4 reset */
	DWORD UART5RST: 1; /* USART5 reset */
	DWORD I2C1RST: 1; /* I2C1 reset */
	DWORD I2C2RST: 1; /* I2C2 reset */
	DWORD USBRST: 1; /* USB reset */
	DWORD Reserved_3: 1; /* always read as 0. */
	DWORD CANRST: 1; /* CAN reset */
	DWORD Reserved_4: 1; /* must be kept at reset value. */
	DWORD BKPRST: 1; /* Backup interface reset */
	DWORD PWRRST: 1; /* Power interface reset */
	DWORD DACRST: 1; /* DAC interface reset */
} RCC_APB1RSTR_REG;

typedef struct {
	DWORD DMA1EN: 1; /* DMA1 clock enable */
	DWORD DMA2EN: 1; /* DMA2 clock enable */
	DWORD SRAMEN: 1; /* SRAM interface clock enable */
	DWORD Reserved_1: 1; /* must be kept at reset value. */
	DWORD FLITFEN: 1; /* FLITF clock enable */
	DWORD Reserved_2: 1; /* must be kept at reset value. */
	DWORD CRCEN: 1; /* CRC clock enable */
	DWORD Reserved_3: 1; /* always read as 0. */
	DWORD FSMCEN: 1; /* FSMC clock enable */
	DWORD Reserved_4: 1; /* always read as 0. */
	DWORD SDIOEN: 1; /* SDIO clock enable */
} RCC_AHBENR_REG;

typedef struct {
	DWORD AFIOEN: 1; /* Alternate function IO clock enable */
	DWORD Reserved: 1; /* must be kept at reset value. */
	DWORD IOPAEN: 1; /* IO port A clock enable */
	DWORD IOPBEN: 1; /* IO port B clock enable */
	DWORD IOPCEN: 1; /* IO port C clock enable */
	DWORD IOPDEN: 1; /* IO port D clock enable */
	DWORD IOPEEN: 1; /* IO port E clock enable */
	DWORD IOPFEN: 1; /* IO port F clock enable */
	DWORD IOPGEN: 1; /* IO port G clock enable */
	DWORD ADC1EN: 1; /* ADC 1 interface clock enable */
	DWORD ADC2EN: 1; /* ADC 2 interface clock enable */
	DWORD TIM1EN: 1; /* TIM1 timer clock enable */
	DWORD SPI1EN: 1; /* SPI1 clock enable */
	DWORD TIM8EN: 1; /* TIM8 Timer clock enable */
	DWORD USART1EN: 1; /* USART1 clock enable */
	DWORD ADC3EN: 1; /* ADC3 interface clock enable */
	DWORD Reserved_1: 3; /* always read as 0. */
	DWORD TIM9EN: 1; /* TIM9 timer clock enable */
	DWORD TIM10EN: 1; /* TIM10 timer clock enable */
	DWORD TIM11EN: 1; /* TIM11 timer clock enable */
} RCC_APB2ENR_REG;

typedef struct {
	DWORD TIM2EN:1; /* TIM2 timer clock enable */
	DWORD TIM3EN:1; /* TIM3 timer clock enable */
	DWORD TIM4EN:1; /* TIM4 timer clock enable */
	DWORD TIM5EN:1; /* TIM5 timer clock enable */
	DWORD TIM6EN:1; /* TIM6 timer clock enable */
	DWORD TIM7EN:1; /* TIM7 timer clock enable */
	DWORD TIM12EN:1; /* TIM12 timer clock enable */
	DWORD TIM13EN:1; /* TIM13 timer clock enable */
	DWORD TIM14EN:1; /* TIM14 timer clock enable */
	DWORD Reserved:2; /* must be kept at reset value. */
	DWORD WWDGEN:1; /* Window watchdog clock enable */
	DWORD Reserved_1:2; /* must be kept at reset value. */
	DWORD SPI2EN:1; /* SPI2 clock enable */
	DWORD SPI3EN:1; /* SPI 3 clock enable */
	DWORD Reserved_3:1; /* always read as 0. */
	DWORD USART2EN:1; /* USART2 clock enable */
	DWORD USART3EN:1; /* USART3 clock enable */
	DWORD UART4EN:1; /* USART4 clock enable */
	DWORD UART5EN:1; /* USART5 clock enable */
	DWORD I2C1EN:1; /* I2C1 clock enable */
	DWORD I2C2EN:1; /* I2C2 clock enable */
	DWORD USBEN:1; /* USB clock enable */
	DWORD Reserved_4:1; /* always read as 0. */
	DWORD CANEN:1; /* CAN clock enable */
	DWORD Reserved_5:1; /* must be kept at reset value. */
	DWORD BKPEN:1; /* Backup interface clock enable */
	DWORD PWREN:1; /* Power interface clock enable */
	DWORD DACEN:1; /* DAC interface clock enable */
} RCC_APB1ENR_REG;

typedef struct 
{
	DWORD LSEON: 1; /* External low-speed oscillator enable */
	DWORD LSERDY: 1; /* External low-speed oscillator ready */
	DWORD LSEBYP: 1; /* External low-speed oscillator bypass */
	DWORD Reserved: 5; /* must be kept at reset value. */
	DWORD RTCSEL: 1; /* RTC clock source selection */
	DWORD Reserved_1: 5; /* must be kept at reset value. */
	DWORD RTCEN: 1; /* RTC clock enable */
	DWORD BDRST: 1; /* Backup domain software reset */
} RCC_BDCR_REG;

typedef struct {
	DWORD LSION: 1; /* Internal low-speed oscillator enable */
	DWORD LSIRDY: 1; /* Internal low-speed oscillator ready */
	DWORD Reserved: 6; /* must be kept at reset value. */
	DWORD Reserved_1: 8; /* must be kept at reset value. */
	DWORD Reserved_2: 8; /* must be kept at reset value. */
	DWORD RMVF: 1; /* Remove reset flag */
	DWORD Reserved_3: 1; /* must be kept at reset value. */
	DWORD PINRSTF: 1; /* PIN reset flag */
	DWORD PORRSTF: 1; /* POR/PDR reset flag */
	DWORD SFTRSTF: 1; /* Software reset flag */
	DWORD IWDGRSTF: 1; /* Independent watchdog reset flag */
	DWORD WWDGRSTF: 1; /* Window watchdog reset flag */
	DWORD LPWRRSTF: 1; /* Low-power reset flag */
} RCC_CSR_REG;

typedef struct {
	DWORD Reserved_0; /*  must be kept at reset value. */
	DWORD Reserved_1: 3; /*  must be kept at reset value. */
	DWORD OTGFSRST; /* USB OTG FS reset */
	DWORD Reserved_2: 1; /*  must be kept at reset value. */
	DWORD ETHMACRST; /* Ethernet MAC reset */
} RCC_AHBRSTR_REG;

typedef struct {
	DWORD PREDIV1: 4; /* PREDIV1 division factor */
	DWORD PREDIV2: 4; /* PREDIV2 division factor */
	DWORD PLL2MUL: 4; /* PLL2 Multiplication Factor */
	DWORD PLL3MUL: 4; /* PLL3 Multiplication Factor */
	DWORD PREDIV1SRC:1; /* PREDIV1 entry clock source */
	DWORD I2S2SRC:1; /* I2S2 clock source */
	DWORD I2S3SRC:1; /* I2S3 clock source */
} RCC_CFGR2_REG;

typedef struct
{
	RCC_CR_REG 			CR_REG; /* RCC_CR */
	RCC_CFGR_REG 		CFGR_REG; /* RCC_CFGR */
	RCC_CIR_REG 		CIR_REG; /* RCC_CIR */
	RCC_APB2RSTR_REG 	APB2RSTR_REG; /* RCC_APB2RSTR */
	RCC_APB1RSTR_REG 	APB1RSTR_REG; /* RCC_APB1RSTR */
	RCC_AHBENR_REG 		AHBENR_REG; /* RCC_AHBENR */
	RCC_APB2ENR_REG 	APB2ENR_REG; /* RCC_APB2ENR */
	RCC_APB1ENR_REG 	APB1ENR_REG; /* RCC_APB1ENR */
	RCC_BDCR_REG 		BDCR_REG; /* RCC_BDCR */
	RCC_CSR_REG 		CSR_REG; /* RCC_CSR */
	RCC_AHBRSTR_REG		AHBRSTR_REG; /* RCC_AHBRSTR_REG */
	RCC_CFGR2_REG		CFGR2_REG; /* RCC_CFGR2_REG */
}  RCC_REG_MAP;






