#pragma once
#include "base_types.h"

typedef struct
{
	DWORD CEN : 1;  /* Counter enable */
	DWORD UDIS : 1; /* Update disable */
	DWORD URS : 1;  /* Update request source */
	DWORD OPM : 1;  /* One pulse mode */
	DWORD DIR : 1;  /* Direction */
	DWORD CMS : 2;  /* Center-aligned mode selection */
	DWORD ARPE : 1; /* Auto-reload preload enable */
	DWORD CKD : 2;  /* Clock division */
} ADV_TIM_CR1_REG;

typedef struct
{
	DWORD CCPC : 1;	/* Capture/compare preloaded control */
	DWORD Reserve : 1; /* Reserved, must be kept at reset value */
	DWORD CCUS : 1;	/* Capture/compare control update selection */
	DWORD CCDS : 1;	/* Capture/compare DMA selection */
	DWORD MMS : 3;	 /* Master mode selection */
	DWORD TI1S : 1;	/* TI1 selection */
	DWORD OIS1 : 1;	/* Output Idle state 1 (OC1 output) */
	DWORD OIS1N : 1;   /* Output Idle state 1 (OC1N output) */
	DWORD OIS2 : 1;	/* Output Idle state 2 (OC2 output) */
	DWORD OIS2N : 1;   /* Output Idle state 2 (OC2N output) */
	DWORD OIS3 : 1;	/* Output Idle state 3 (OC3 output) */
	DWORD OIS3N : 1;   /* Output Idle state 3 (OC3N output) */
	DWORD OIS4 : 1;	/* Output Idle state 3 (OC3 output) */
} ADV_TIM_CR2_REG;

typedef struct
{
	DWORD SMS : 3;		/* Slave mode selection */
	DWORD Reserved : 1; /* Reserved */
	DWORD TS : 3;		/* Trigger selection */
	DWORD MSM : 1;		/* Master/slave mode */
	DWORD ETF : 4;		/* External trigger filter */
	DWORD ETPS : 2;		/* External trigger prescaler */
	DWORD ECE : 1;		/* External clock enable */
	DWORD ETP : 1;		/* External trigger polarity */
} ADV_TIM_SMCR_REG;

typedef struct
{
	DWORD UIE : 1;   /* Update interrupt enable */
	DWORD CC1IE : 1; /* Capture/Compare 1 interrupt enable */
	DWORD CC2IE : 1; /* Capture/Compare 2 interrupt enable */
	DWORD CC3IE : 1; /* Capture/Compare 3 interrupt enable */
	DWORD CC4IE : 1; /* Capture/Compare 4 interrupt enable */
	DWORD COMIE : 1; /* COM interrupt enable */
	DWORD TIE : 1;   /* Trigger interrupt enable */
	DWORD BIE : 1;   /* Break interrupt enable */
	DWORD UDE : 1;   /* Update DMA request enable */
	DWORD CC1DE : 1; /* Capture / Compare 1 DMA request enable */
	DWORD CC2DE : 1; /* Capture/Compare 2 DMA request enable */
	DWORD CC3DE : 1; /* Capture/Compare 3 DMA request enable */
	DWORD CC4DE : 1; /* Capture/Compare 4 DMA request enable */
	DWORD COMDE : 1; /* COM DMA request enable */
	DWORD TDE : 1;   /* Trigger DMA request enable */
} ADV_TIM_DIER_REG;

typedef struct
{
	DWORD UIF : 1;		/* Update interrupt flag */
	DWORD CC1IF : 1;	/* Capture/Compare 1 interrupt flag */
	DWORD CC2IF : 1;	/* Capture/Compare 2 interrupt flag */
	DWORD CC3IF : 1;	/* Capture/Compare 3 interrupt flag */
	DWORD CC4IF : 1;	/* Capture/Compare 4 interrupt flag */
	DWORD COMIF : 1;	/* COM interrupt flag */
	DWORD TIF : 1;		/* Trigger interrupt flag */
	DWORD BIF : 1;		/* Break interrupt flag */
	DWORD Reserved : 1; /* must be kept at reset value. */
	DWORD CC1OF : 1;	/*Capture / Compare 1 overcapture flag */
	DWORD CC2OF : 1;	/*Capture / Compare 2 overcapture flag */
	DWORD CC3OF : 1;	/*Capture / Compare 3 overcapture flag */
	DWORD CC4OF : 1;	/*Capture / Compare 4 overcapture flag */
} ADV_TIM_SR_REG;

typedef struct
{
	DWORD UG : 1;   /* Update generation */
	DWORD CC1G : 1; /* Capture / Compare 1 generation */
	DWORD CC2G : 1; /* Capture / Compare 2 generation */
	DWORD CC3G : 1; /* Capture / Compare 3 generation */
	DWORD CC4G : 1; /* Capture / Compare 4 generation */
	DWORD COMG : 1; /* Capture / Compare control update generation */
	DWORD TG : 1;   /* Trigger generation */
	DWORD BG : 1;   /* Break generation */
} ADV_TIM_EGR_REG;

typedef struct
{
	DWORD CC1S : 2;  /* Capture / Compare 1 selection*/
	DWORD OC1FE : 1; /* Output Compare 1 fast enable */
	DWORD OC1PE : 1; /* Output Compare 1 preload enable */
	DWORD OC1M : 3;  /* Output Compare 1 mode */
	DWORD OC1CE : 1; /* Output Compare 1 clear enable */
	DWORD CC2S : 2;  /* Capture / Compare 2 selection */
	DWORD OC2FE : 1; /* Output Compare 2 fast enable */
	DWORD OC2PE : 1; /* Output Compare 2 preload enable */
	DWORD OC2M : 3;  /* Output Compare 2 mode */
	DWORD OC2CE : 1; /* Output Compare 2 clear enable */
} ADV_TIM_CCMR1_OM_REG;

typedef struct
{
	DWORD CC1S : 2;   /* Capture/Compare 1 Selection */
	DWORD IC1PSC : 2; /* Input capture 1 prescaler */
	DWORD IC1F : 4;   /* Input capture 1 filter */
	DWORD CC2S : 2;   /* Capture/Compare 2 selection */
	DWORD IC2PSC : 2; /* Input capture 2 prescaler */
	DWORD IC2F : 4;   /* Input capture 2 filter */
} ADV_TIM_CCMR1_IM_REG;

typedef struct
{
	DWORD CC3S : 2;  /* Capture / Compare 3 selection */
	DWORD OC3FE : 1; /* Output compare 3 fast enable */
	DWORD OC3PE : 1; /* Output compare 3 preload enable */
	DWORD OC3M : 3;  /* Output compare 3 mode */
	DWORD OC3CE : 1; /* Output compare 3 clear enable */
	DWORD CC4S : 2;  /* Capture / Compare 4 selection */
	DWORD OC4FE : 1; /* Output compare 4 fast enable */
	DWORD OC4PE : 1; /* Output compare 4 preload enable */
	DWORD OC4M : 3;  /* Output compare 4 mode */
	DWORD OC4CE : 1; /* Output compare 4 clear enable */
} ADV_TIM_CCMR2_OM_REG;

typedef struct
{
	DWORD CC3S : 2;   /* Capture / compare 3 selection */
	DWORD IC3PSC : 2; /* Input capture 3 prescaler */
	DWORD IC3F : 4;   /* Input capture 3 filter */
	DWORD CC4S : 2;   /* Capture / Compare 4 selection */
	DWORD IC4PSC : 2; /* Input capture 4 prescaler */
	DWORD IC4F : 4;   /* Input capture 4 filter */
} ADV_TIM_CCMR2_IM_REG;

typedef struct
{
	DWORD CC1E : 1;  /* Capture / Compare 1 output enable */
	DWORD CC1P : 1;  /* Capture / Compare 1 output polarity */
	DWORD CC1NE : 1; /* Capture / Compare 1 complementary output enable */
	DWORD CC1NP : 1; /* Capture / Compare 1 complementary output polarity */
	DWORD CC2E : 1;  /* Capture / Compare 2 output enable */
	DWORD CC2P : 1;  /* Capture / Compare 2 output polarity */
	DWORD CC2NE : 1; /* Capture / Compare 2 complementary output enable */
	DWORD CC2NP : 1; /* Capture / Compare 2 complementary output polarity */
	DWORD CC3E : 1;  /* Capture / Compare 3 output enable */
	DWORD CC3P : 1;  /* Capture / Compare 3 output polarity */
	DWORD CC3NE : 1; /* Capture / Compare 3 complementary output enable */
	DWORD CC3NP : 1; /* Capture / Compare 3 complementary output polarity */
	DWORD CC4E : 1;  /* Capture / Compare 4 output enable */
	DWORD CC4P : 1;  /* Capture / Compare 4 output polarity */
} ADV_TIM_CCER_REG;

typedef struct
{
	DWORD CNT : 16; /* Counter value */
} ADV_TIM_CNT_REG;

typedef struct
{
	DWORD PSC : 16; /* Prescaler value */
} ADV_TIM_PSC_REG;

typedef struct
{
	DWORD ARR : 16; /* Auto-reload value */
} ADV_TIM_ARR_REG;

typedef struct
{
	DWORD REP; /* Repetition counter value */
} ADV_TIM_RCR_REG;

typedef struct
{
	DWORD CCR1 : 16; /* Capture/Compare 1 value */
} ADV_TIM_CCR1_REG;

typedef struct
{
	DWORD CCR2 : 16; /* Capture/Compare 2 value */
} ADV_TIM_CCR2_REG;

typedef struct
{
	DWORD CCR3 : 16; /* Capture/Compare 3 value */
} ADV_TIM_CCR3_REG;

typedef struct
{
	DWORD CCR4 : 16; /* Capture/Compare 4 value */
} ADV_TIM_CCR4_REG;

typedef struct
{
	DWORD DTG : 8;  /* Dead - time generator setup */
	DWORD LOCK : 2; /* Lock configuration */
	DWORD OSSI : 1; /* Off - state selection for Idle mode */
	DWORD OSSR : 1; /* Off - state selection for Run mode */
	DWORD BKE : 1;  /* Break enable */
	DWORD BKP : 1;  /* Break polarity */
	DWORD AOE : 1;  /* Automatic output enable */
	DWORD MOE : 1;  /* Main output enable */
} ADV_TIM_BDTR_REG;

typedef struct
{
	DWORD DBA : 5;		/*  DMA base address */
	DWORD Reserved : 3; /* must be kept at reset value. */
	DWORD DBL : 5;		/* DMA burst length */
} ADV_TIM_DCR_REG;

typedef struct
{
	DWORD DMAB[4]; /* DMA register for burst accesses */
} ADV_TIM_DMAR_REG;

typedef union {
	ADV_TIM_CCMR1_OM_REG CCMR1_OM_REG; /* CCMR1_OM_REG output */
	ADV_TIM_CCMR1_IM_REG CCMR1_IM_REG; /* CCMR1_IM_REG input */
} ADV_TIM_CCMR1_REG;

typedef union {
	ADV_TIM_CCMR2_OM_REG CCMR2_OM_REG; /* CCMR2_OM_REG output */
	ADV_TIM_CCMR2_IM_REG CCMR2_IM_REG; /* CCMR2_IM_REG input */
} ADV_TIM_CCMR2_REG;

typedef struct
{
	ADV_TIM_CR1_REG CR1_REG;	 /* TIMx_CR1 */
	ADV_TIM_CR2_REG CR2_REG;	 /* TIMx_CR2 */
	ADV_TIM_SMCR_REG SMCR_REG;   /* TIMx_SMCR */
	ADV_TIM_DIER_REG DIER_REG;   /* TIMx_DIER */
	ADV_TIM_SR_REG SR_REG;		 /* TIMx_SR */
	ADV_TIM_EGR_REG EGR_REG;	 /* TIMx_EGR */
	ADV_TIM_CCMR1_REG CCMR1_REG; /* TIMx_CCMR1 */
	ADV_TIM_CCMR2_REG CCMR2_REG; /* TIMx_CCMR2 */
	ADV_TIM_CCER_REG CCER_REG;   /* TIMx_CCER */
	ADV_TIM_CNT_REG CNT_REG;	 /* TIMx_CNT */
	ADV_TIM_PSC_REG PSC_REG;	 /* TIMx_PSC */
	ADV_TIM_ARR_REG ARR_REG;	 /* TIMx_ARR */
	ADV_TIM_RCR_REG RCR_REG;	 /* TIMx_RCR */
	ADV_TIM_CCR1_REG CCR1_REG;   /* TIMx_CCR1 */
	ADV_TIM_CCR2_REG CCR2_REG;   /* TIMx_CCR2 */
	ADV_TIM_CCR3_REG CCR3_REG;   /* TIMx_CCR3 */
	ADV_TIM_CCR4_REG CCR4_REG;   /* TIMx_CCR4 */
	ADV_TIM_BDTR_REG BDTR_REG;   /* TIMx_BDTR */
	ADV_TIM_DCR_REG DCR_REG;	 /* TIMx_DCR */
	ADV_TIM_DMAR_REG DMAR_REG;   /* TIMx_DMAR */
} ADV_TIM_REG_MAP;


typedef struct
{

} BASIC_TIM_REG_MAP;
