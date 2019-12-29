#pragma once
#include "base_types.h"

typedef struct {
	BYTE SECIE : 1; /* Second interrupt enable */
	BYTE ALRIE : 1; /* Alarm interrupt enable */
	BYTE OWIE : 1; /* Overflow interrupt enable */
} RTC_CRH_REG;

typedef struct {
	BYTE SECF: 1; /* Second flag */
	BYTE ALRF: 1; /* Alarm flag */
	BYTE OWF: 1; /* Overflow flag */
	BYTE RSF: 1; /* Registers synchronized flag */
	BYTE CNF: 1; /* Configuration flag */
	BYTE RTOFF: 1; /* RTC operation OFF */
} RTC_CRL_REG;


typedef struct {
	BYTE PRL : 4; /* RTC prescaler reload value high */
} RTC_PRLH_REG;

typedef struct {
	BYTE PRL[2]; /* RTC prescaler reload value low */
} RTC_PRLL_REG;

typedef struct {
	BYTE RTC_DIV: 4; /* RTC clock divider high */
} RTC_DIVH_REG;

typedef struct {
	BYTE RTC_DIV[2] ; /* RTC clock divider low */
} RTC_DIVL_REG;

typedef struct {
	BYTE RTC_CNT[2] ; /* RTC counter high */
} RTC_CNTH_REG;

typedef struct {
	BYTE RTC_CNT[2] ; /* RTC counter low */
} RTC_CNTL_REG;

typedef struct {
	BYTE RTC_ALR[2]; /* RTC alarm high */
} RTC_ALRH_REG;

typedef struct {
	BYTE RTC_ALR[2]; /* RTC alarm low */
} RTC_ALRL_REG;

typedef struct {
	RTC_CRH_REG 	CRH_REG; 			/* RTC_CRH */
	BYTE 			Reserved[2]; 		/* Unused */
	RTC_CRL_REG 	CRL_REG; 			/* RTC_CRL */
	BYTE 			Reserved_1[2]; 		/* Unused */
	RTC_PRLH_REG 	PRLH_REG; 			/* RTC_PRLH */ 
	BYTE 			Reserved_2[2]; 		/* Unused */
	RTC_PRLL_REG 	PRLL_REG;			/* RTC_PRLL */
	BYTE 			Reserved_3[2]; 		/* Unused */
	RTC_DIVH_REG 	DIVH_REG; 			/* RTC_DIVH */
	BYTE 			Reserved_4[2]; 		/* Unused */
	RTC_DIVL_REG 	DIVL_REG; 			/* RTC_DIVL */
	BYTE 			Reserved_5[2]; 		/* Unused */
	RTC_CNTH_REG 	CNTH_REG;			/* RTC_CNTH */
	BYTE 			Reserved_6[2]; 		/* Unused */
	RTC_CNTL_REG 	CNTL_REG;			/* RTC_CNTL */
	BYTE 			Reserved_7[2]; 		/* Unused */
	RTC_ALRH_REG 	ALRH_REG;			/* RTC_ALRH */
	BYTE 			Reserved_8[2]; 		/* Unused */
	RTC_ALRL_REG 	ALRL_REG; 			/* RTC_ALRL */
	BYTE 			Reserved_9[2]; 		/* Unused */
} RTC_REG_MAP;