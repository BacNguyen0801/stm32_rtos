#pragma once
#include "base_types.h"

typedef struct {
	BYTE CEN : 1; /* Counter enable */
	BYTE UDIS : 1; /* Update disable */
	BYTE URS : 1; /* Update request source */
	BYTE OPM : 1; /* One pulse mode */
	BYTE DIR : 1; /* Direction */
	BYTE CMS : 2; /* Center-aligned mode selection */
	BYTE ARPE : 1; /* Auto-reload preload enable */
	BYTE CKD : 2; /* Clock division */
	BYTE Reserve : 5; /* Reserved, must be kept at reset value */
} TIMx_CR1_REG;

typedef struct {
	BYTE CCPC : 1; /* Capture/compare preloaded control */
	BYTE Reserve : 1; /* Reserved, must be kept at reset value */
	BYTE CCUS : 1; /* Capture/compare control update selection */
	BYTE CCDS : 1; /* Capture/compare DMA selection */
	BYTE MMS : 3; /* Master mode selection */
	BYTE TI1S : 1; /* TI1 selection */
	BYTE OIS1 : 1; /* Output Idle state 1 (OC1 output) */
	BYTE OIS1N : 1; /* Output Idle state 1 (OC1N output) */
	BYTE OIS2 : 1; /* Output Idle state 2 (OC2 output) */
	BYTE OIS2N : 1; /* Output Idle state 2 (OC2N output) */
	BYTE OIS3 : 1; /* Output Idle state 3 (OC3 output) */
	BYTE OIS3N : 1; /* Output Idle state 3 (OC3N output) */
	BYTE OIS4 : 1; /* Output Idle state 3 (OC3 output) */
	BYTE Reserve1 : 1; /* Reserved, must be kept at reset value */
} TIMx_CR2_REG;

typedef struct {
	BYTE SMS : 3; /* Slave mode selection */
	BYTE Reserved : 1; /* Reserved */
	BYTE TS : 3; /* Trigger selection */
	BYTE MSM : 1; /* Master/slave mode */
	BYTE ETF : 4; /* External trigger filter */
	BYTE ETPS : 2; /* External trigger prescaler */
	BYTE ECE : 1; /* External clock enable */
	BYTE ETP : 1; /* External trigger polarity */
} TIMx_SMCR_REG;

typedef struct {
	BYTE UIE : 1; /* Update interrupt enable */
	BYTE CC1IE : 1; /* Capture/Compare 1 interrupt enable */
	BYTE CC2IE : 1; /* Capture/Compare 2 interrupt enable */
	BYTE CC3IE : 1; /* Capture/Compare 3 interrupt enable */
	BYTE CC4IE : 1; /* Capture/Compare 4 interrupt enable */
	BYTE COMIE : 1; /* COM interrupt enable */
	BYTE TIE : 1; /* Trigger interrupt enable */
	BYTE BIE : 1; /* Break interrupt enable */
	BYTE UDE : 1; /* Update DMA request enable */
	BYTE CC1DE : 1; /* Capture / Compare 1 DMA request enable */
	BYTE CC2DE : 1; /* Capture/Compare 2 DMA request enable */
	BYTE CC3DE : 1; /* Capture/Compare 3 DMA request enable */
	BYTE CC4DE : 1; /* Capture/Compare 4 DMA request enable */
	BYTE COMDE : 1; /* COM DMA request enable */
	BYTE TDE : 1; /* Trigger DMA request enable */
	BYTE Reserved : 1; /* Reserved */
} TIMx_DIER_REG;

typedef struct {
	BYTE UIF : 1; /* Update interrupt flag */
	BYTE CC1IF : 1; /* Capture/Compare 1 interrupt flag */
	BYTE CC2IF : 1; /* Capture/Compare 2 interrupt flag */
	BYTE CC3IF : 1; /* Capture/Compare 3 interrupt flag */
	BYTE CC4IF : 1; /* Capture/Compare 4 interrupt flag */
	BYTE COMIF : 1; /* COM interrupt flag */
	BYTE TIF : 1; /* Trigger interrupt flag */
	BYTE BIF : 1; /* Break interrupt flag */
	BYTE Reserved : 1;/* must be kept at reset value. */
	BYTE CC1OF : 1;/*Capture / Compare 1 overcapture flag */
	BYTE CC2OF : 1;/*Capture / Compare 2 overcapture flag */
	BYTE CC3OF : 1;/*Capture / Compare 3 overcapture flag */
	BYTE CC4OF : 1;/*Capture / Compare 4 overcapture flag */
	BYTE Reserved_1 : 3;/* must be kept at reset value. */
} TIMx_SR_REG;

typedef struct {
	BYTE UG : 1; /* Update generation */
	BYTE CC1G : 1; /* Capture / Compare 1 generation */
	BYTE CC2G : 1; /* Capture / Compare 2 generation */
	BYTE CC3G : 1; /* Capture / Compare 3 generation */
	BYTE CC4G : 1; /* Capture / Compare 4 generation */
	BYTE COMG : 1; /* Capture / Compare control update generation */
	BYTE TG : 1; /* Trigger generation */
	BYTE BG : 1; /* Break generation */
	BYTE Reserved; /* Reserved, must be kept at reset value. */
} TIMx_EGR_REG;

typedef struct {
	BYTE CC1S : 2; /* Capture / Compare 1 selection*/
	BYTE OC1FE : 1; /* Output Compare 1 fast enable */
	BYTE OC1PE : 1; /* Output Compare 1 preload enable */
	BYTE OC1M : 3; /* Output Compare 1 mode */
	BYTE OC1CE : 1; /* Output Compare 1 clear enable */
	BYTE CC2S : 2; /* Capture / Compare 2 selection */
	BYTE OC2FE : 1; /* Output Compare 2 fast enable */
	BYTE OC2PE : 1; /* Output Compare 2 preload enable */
	BYTE OC2M : 3; /* Output Compare 2 mode */
	BYTE OC2CE : 1; /* Output Compare 2 clear enable */
} TIMx_CCMR1_OM_REG;

typedef struct {
	BYTE CC1S : 2; /* Capture/Compare 1 Selection */
	BYTE IC1PSC : 2; /* Input capture 1 prescaler */
	BYTE IC1F : 4; /* Input capture 1 filter */
	BYTE CC2S : 2; /* Capture/Compare 2 selection */
	BYTE IC2PSC : 2; /* Input capture 2 prescaler */
	BYTE IC2F : 4;	/* Input capture 2 filter */
} TIMx_CCMR1_IM_REG;

typedef struct {
	BYTE CC3S : 2;/* Capture / Compare 3 selection */
	BYTE OC3FE : 1;/* Output compare 3 fast enable */
	BYTE OC3PE : 1;/* Output compare 3 preload enable */
	BYTE OC3M : 3;/* Output compare 3 mode */
	BYTE OC3CE : 1;/* Output compare 3 clear enable */
	BYTE CC4S : 2;/* Capture / Compare 4 selection */
	BYTE OC4FE : 1;/* Output compare 4 fast enable */
	BYTE OC4PE : 1;/* Output compare 4 preload enable */
	BYTE OC4M : 3;/* Output compare 4 mode */
	BYTE OC4CE : 1;/* Output compare 4 clear enable */
} TIMx_CCMR2_OM_REG;

typedef struct {
	BYTE CC3S : 2;/* Capture / compare 3 selection */
	BYTE IC3PSC : 2;/* Input capture 3 prescaler */
	BYTE IC3F : 4;/* Input capture 3 filter */
	BYTE CC4S : 2;/* Capture / Compare 4 selection */
	BYTE IC4PSC : 2;/* Input capture 4 prescaler */
	BYTE IC4F : 4;/* Input capture 4 filter */
} TIMx_CCMR2_IM_REG;

typedef struct {
	BYTE CC1E : 1;/* Capture / Compare 1 output enable */
	BYTE CC1P : 1;/* Capture / Compare 1 output polarity */
	BYTE CC1NE : 1;/* Capture / Compare 1 complementary output enable */
	BYTE CC1NP : 1;/* Capture / Compare 1 complementary output polarity */
	BYTE CC2E : 1;/* Capture / Compare 2 output enable */
	BYTE CC2P : 1;/* Capture / Compare 2 output polarity */
	BYTE CC2NE : 1;/* Capture / Compare 2 complementary output enable */
	BYTE CC2NP : 1;/* Capture / Compare 2 complementary output polarity */
	BYTE CC3E : 1;/* Capture / Compare 3 output enable */
	BYTE CC3P : 1;/* Capture / Compare 3 output polarity */
	BYTE CC3NE : 1;/* Capture / Compare 3 complementary output enable */
	BYTE CC3NP : 1;/* Capture / Compare 3 complementary output polarity */
	BYTE CC4E : 1;/* Capture / Compare 4 output enable */
	BYTE CC4P : 1;/* Capture / Compare 4 output polarity */
	BYTE Reserved : 2;/* must be kept at reset value. */
} TIMx_CCER_REG;

typedef struct {
	BYTE CNT[2]; /* Counter value */
} TIMx_CNT_REG;

typedef struct {
	BYTE PSC[2]; /* Prescaler value */
} TIMx_PSC_REG;

typedef struct {
	BYTE ARR[2]; /* Auto-reload value */
} TIMx_ARR_REG;

typedef struct {
	BYTE REP; /* Repetition counter value */
} TIMx_RCR_REG;

typedef struct {
	BYTE CCR1[2]; /* Capture/Compare 1 value */
} TIMx_CCR1_REG;

typedef struct {
	BYTE CCR2[2]; /* Capture/Compare 2 value */
} TIMx_CCR2_REG;

typedef struct {
	BYTE CCR3[2]; /* Capture/Compare 3 value */
} TIMx_CCR3_REG;

typedef struct {
	BYTE CCR4[2]; /* Capture/Compare 4 value */
} TIMx_CCR4_REG;

typedef struct {
	BYTE DTG; /* Dead - time generator setup */
	BYTE LOCK : 2; /* Lock configuration */
	BYTE OSSI : 1; /* Off - state selection for Idle mode */
	BYTE OSSR : 1; /* Off - state selection for Run mode */
	BYTE BKE : 1; /* Break enable */
	BYTE BKP : 1; /* Break polarity */
	BYTE AOE : 1; /* Automatic output enable */
	BYTE MOE : 1; /* Main output enable */
} TIMx_BDTR_REG;

typedef struct {
	BYTE DBA : 5; /*  DMA base address */
	BYTE Reserved : 3; /* must be kept at reset value. */
	BYTE DBL : 5; /* DMA burst length */
	BYTE Reserved_1 : 3; /* must be kept at reset value. */
} TIMx_DCR_REG;

typedef struct {
	BYTE DMAB[4]; /* DMA register for burst accesses */
} TIMx_DMAR_REG;

typedef union {
	TIMx_CCMR1_OM_REG CCMR1_OM_REG; /* CCMR1_OM_REG output */
	TIMx_CCMR1_IM_REG CCMR1_IM_REG; /* CCMR1_IM_REG input */
} TIMx_CCMR1_REG;

typedef union {
	TIMx_CCMR2_OM_REG CCMR2_OM_REG; /* CCMR2_OM_REG output */
	TIMx_CCMR2_IM_REG CCMR2_IM_REG; /* CCMR2_IM_REG input */
} TIMx_CCMR2_REG;

typedef struct {
	TIMx_CR1_REG	CR1_REG;			/* TIMx_CR1 */
	BYTE			Reserved[2];		/* Padding */
	TIMx_CR2_REG	CR2_REG;			/* TIMx_CR2 */
	BYTE			Reserved_1[2];		/* Padding */
	TIMx_SMCR_REG	SMCR_REG;			/* TIMx_SMCR */
	BYTE			Reserved_2[2];		/* Padding */
	TIMx_DIER_REG	DIER_REG;			/* TIMx_DIER */
	BYTE			Reserved_3[2];		/* Padding */
	TIMx_SR_REG		SR_REG;				/* TIMx_SR */
	BYTE			Reserved_4[2];		/* Padding */
	TIMx_EGR_REG	EGR_REG;			/* TIMx_EGR */
	BYTE			Reserved_5[2];		/* Padding */
	TIMx_CCMR1_REG	CCMR1_REG;			/* TIMx_CCMR1 */
	BYTE			Reserved_6[2];		/* Padding */
	TIMx_CCMR2_REG	CCMR2_REG;			/* TIMx_CCMR2 */
	BYTE			Reserved_7[2];		/* Padding */
	TIMx_CCER_REG	CCER_REG;			/* TIMx_CCER */
	BYTE			Reserved_8[2];		/* Padding */
	TIMx_CNT_REG	CNT_REG;			/* TIMx_CNT */
	BYTE			Reserved_9[2];		/* Padding */
	TIMx_PSC_REG	PSC_REG;			/* TIMx_PSC */
	BYTE			Reserved_10[2];		/* Padding */
	TIMx_ARR_REG	ARR_REG;			/* TIMx_ARR */
	BYTE			Reserved_11[2];		/* Padding */
	TIMx_RCR_REG	RCR_REG;			/* TIMx_RCR */
	BYTE			Reserved_12[3];		/* Padding */
	TIMx_CCR1_REG	CCR1_REG;			/* TIMx_CCR1 */
	BYTE			Reserved_13[2];		/* Padding */
	TIMx_CCR2_REG	CCR2_REG;			/* TIMx_CCR2 */
	BYTE			Reserved_14[2];		/* Padding */
	TIMx_CCR3_REG	CCR3_REG;			/* TIMx_CCR3 */
	BYTE			Reserved_15[2];		/* Padding */
	TIMx_CCR4_REG	CCR4_REG;			/* TIMx_CCR4 */
	BYTE			Reserved_16[2];		/* Padding */
	TIMx_BDTR_REG	BDTR_REG;			/* TIMx_BDTR */
	BYTE			Reserved_17[2];		/* Padding */
	TIMx_DCR_REG	DCR_REG;			/* TIMx_DCR */
	BYTE			Reserved_18[2];		/* Padding */
	TIMx_DMAR_REG	DMAR_REG;			/* TIMx_DMAR */
} TIM1_REG_MAP;
