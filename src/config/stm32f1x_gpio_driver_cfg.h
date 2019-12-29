#pragma once
#include "base_types.h"

typedef struct 
{
	DWORD MODE0: 2; /* Port 0 mode bits */
	DWORD CNF0: 2; /* Port 0 configuration bits */
	DWORD MODE1: 2; /* Port 1 mode bits */
	DWORD CNF1: 2; /* Port 1 configuration bits */
	DWORD MODE2: 2; /* Port 2 mode bits */
	DWORD CNF2: 2; /* Port 2 configuration bits */
	DWORD MODE3: 2; /* Port 3 mode bits */
	DWORD CNF3: 2; /* Port 3 configuration bits */
	DWORD MODE4: 2; /* Port 4 mode bits */
	DWORD CNF4: 2; /* Port 4 configuration bits */
	DWORD MODE5: 2; /* Port 5 mode bits */
	DWORD CNF5: 2; /* Port 5 configuration bits */
	DWORD MODE6: 2; /* Port 6 mode bits */
	DWORD CNF6: 2; /* Port 6 configuration bits */
	DWORD MODE7: 2; /* Port 7 mode bits */
	DWORD CNF7: 2; /* Port 7 configuration bits */
} GPIOx_CRL_REG;


typedef struct {
	DWORD MODE8: 2; /* Port 8 mode bits */
	DWORD CNF8: 2; /* Port 8 configuration bits */
	DWORD MODE9: 2; /* Port 9 mode bits */
	DWORD CNF9: 2; /* Port 9 configuration bits */
	DWORD MODE10: 2; /* Port 10 mode bits */
	DWORD CNF10: 2; /* Port 10 configuration bits */
	DWORD MODE11: 2; /* Port 11 mode bits */
	DWORD CNF11: 2; /* Port 11 configuration bits */
	DWORD MODE12: 2; /* Port 12 mode bits */
	DWORD CNF12: 2; /* Port 12 configuration bits */
	DWORD MODE13: 2; /* Port 13 mode bits */
	DWORD CNF13: 2; /* Port 13 configuration bits */
	DWORD MODE14: 2; /* Port 14 mode bits */
	DWORD CNF14: 2; /* Port 14 configuration bits */
	DWORD MODE15: 2; /* Port 15 mode bits */
	DWORD CNF15: 2; /* Port 15 configuration bits */
} GPIOx_CRH_REG;

typedef struct {
	DWORD IDR; /* Port input data */
} GPIOx_IDR_REG;

typedef struct {
	DWORD ODR; /* Port output data */
} GPIOx_ODR_REG;

typedef struct {
	DWORD BSRR; /* Port x Set bit y (y= 0 .. 15): Lower nibble + Port x Reset bit y (y= 0 .. 15): Higher nibble */
} GPIOx_BSRR_REG;

typedef struct {
	DWORD BRR; /* Port x Reset bit y (y= 0 .. 15) */
} GPIOx_BRR_REG;

typedef struct 
{
	DWORD LCK[2]; /* Port x Lock bit y (y= 0 .. 15) */
	DWORD LCKK:1; /* Lock key */
} GPIOx_LCKR_REG;

typedef struct 
{
	DWORD PIN: 4; /* Pin selection */
	DWORD PORT: 3; /* Port selection */
	DWORD EVOE: 1; /* Event output enable */
} AFIO_EVCR_REG;

typedef struct 
{
	DWORD SPI1_REMAP: 1; /* SPI1 remapping */
	DWORD I2C1_REMAP: 1; /* I2C1 remapping */
	DWORD USART1_REMAP: 1; /* USART1 remapping */
	DWORD USART2_REMAP: 1; /* USART2 remapping */
	DWORD USART3_REMAP: 2; /* USART3 remapping */
	DWORD TIM1_REMAP: 2; /* TIM1 remapping */
	DWORD TIM2_REMAP: 2; /* TIM2 remapping */
	DWORD TIM3_REMAP: 2; /* TIM3 remapping */
	DWORD TIM4_REMAP: 1; /* TIM4 remapping */
	DWORD CAN_REMAP: 2; /* CAN alternate function remapping */
	DWORD PD01_REMAP: 1; /* Port D0/Port D1 mapping on OSC_IN/OSC_OUT */
	DWORD TIM5CH4_IREMAP: 1; /* TIM5 channel4 internal remap */
	DWORD ADC1_ETRGINJ_REMAP: 1; /* ADC 1 External trigger injected conversion remapping */
	DWORD ADC1_ETRGREG_REMAP: 1; /* ADC 1 external trigger regular conversion remapping */
	DWORD ADC2_ETRGINJ_REMAP: 1; /* ADC 2 external trigger injected conversion remapping */
	DWORD ADC2_ETRGREG_REMAP: 1; /* ADC 2 external trigger regular conversion remapping */
	DWORD Reserved: 3; /* */
	DWORD SWJ_CFG: 3; /* Serial wire JTAG configuration */
} AFIO_MAPR_REG;

typedef struct 
{
	DWORD EXTI0: 4; /* EXTI x configuration */
	DWORD EXTI1: 4; /* EXTI x configuration */
	DWORD EXTI2: 4; /* EXTI x configuration */
	DWORD EXTI3: 4; /* EXTI x configuration */
} AFIO_EXTICR1_REG;

typedef struct
{
	DWORD EXTI4: 4; /* EXTI x configuration (x= 4 to 7) */
	DWORD EXTI5: 4; /* EXTI x configuration (x= 4 to 7) */
	DWORD EXTI6: 4; /* EXTI x configuration (x= 4 to 7) */
	DWORD EXTI7: 4; /* EXTI x configuration (x= 4 to 7) */
} AFIO_EXTICR2_REG;

typedef struct
{
	DWORD EXTI8: 4;/* EXTI x configuration (x= 8 to 11) */
	DWORD EXTI9: 4;/* EXTI x configuration (x= 8 to 11) */
	DWORD EXTI10: 4; /* EXTI x configuration (x= 8 to 11) */
	DWORD EXTI11: 4; /* EXTI x configuration (x= 8 to 11) */
} AFIO_EXTICR3_REG;

typedef struct
{
	DWORD EXTI12: 4; /* EXTI x configuration (x= 12 to 15) */
	DWORD EXTI13: 4; /* EXTI x configuration (x= 12 to 15) */
	DWORD EXTI14: 4; /* EXTI x configuration (x= 12 to 15) */
	DWORD EXTI15: 4; /* EXTI x configuration (x= 12 to 15) */
} AFIO_EXTICR4_REG;

typedef struct
{	
	DWORD Reserved: 5; /* Reserved. */
	DWORD TIM9_REMAP: 1; /* TIM9 remapping */
	DWORD TIM10_REMAP: 1; /* TIM10 remapping */
	DWORD TIM11_REMAP: 1; /* TIM11 remapping */
	DWORD TIM13_REMAP: 1; /* TIM13 remapping */
	DWORD TIM14_REMAP: 1; /* TIM14 remapping */
	DWORD FSMC_NADV: 1; /* NADV connect/disconnect */
} AFIO_MAPR2_REG;

typedef struct 
{
	GPIOx_CRL_REG CRL_REG; /* GPIOx_CRL */
	GPIOx_CRH_REG CRH_REG; /* GPIOx_CRH */
	GPIOx_IDR_REG IDR_REG; /* GPIOx_IDR */
	GPIOx_ODR_REG ODR_REG; /* GPIOx_ODR */
	GPIOx_BSRR_REG BSRR_REG; /* GPIOx_BSRR */
	GPIOx_BRR_REG BRR_REG; /* GPIOx_BRR */
	GPIOx_LCKR_REG LCKR_REG; /* GPIOx_LCKR */
} GPIOx_REG_MAP;

typedef struct 
{
	AFIO_EVCR_REG EVCR_REG; /* AFIO_EVCR */
	AFIO_MAPR_REG AFIO_MAPR_REG; /* AFIO_MAPR */
	AFIO_EXTICR1_REG AFIO_EXTICR1_REG; /* AFIO_EXTICR1 */
	AFIO_EXTICR2_REG AFIO_EXTICR2_REG; /* AFIO_EXTICR2 */
	AFIO_EXTICR3_REG AFIO_EXTICR3_REG; /* AFIO_EXTICR3 */
	AFIO_EXTICR4_REG AFIO_EXTICR4_REG; /* AFIO_EXTICR4 */
	AFIO_MAPR2_REG AFIO_MAPR2_REG2; /* AFIO_MAPR 2 */
} AFIO_REG_MAP;

