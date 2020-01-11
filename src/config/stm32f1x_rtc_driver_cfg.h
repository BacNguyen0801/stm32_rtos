#pragma once
#include "base_types.h"

typedef struct {
	DWORD SECIE : 1; /* Second interrupt enable */
	DWORD ALRIE : 1; /* Alarm interrupt enable */
	DWORD OWIE : 1; /* Overflow interrupt enable */
} RTC_CRH_REG;

typedef struct {
	DWORD SECF: 1; /* Second flag */
	DWORD ALRF: 1; /* Alarm flag */
	DWORD OWF: 1; /* Overflow flag */
	DWORD RSF: 1; /* Registers synchronized flag */
	DWORD CNF: 1; /* Configuration flag */
	DWORD RTOFF: 1; /* RTC operation OFF */
} RTC_CRL_REG;


typedef struct {
	DWORD PRL : 4; /* RTC prescaler reload value high */
} RTC_PRLH_REG;

typedef struct {
	DWORD PRL:16; /* RTC prescaler reload value low */
} RTC_PRLL_REG;

typedef struct {
	DWORD RTC_DIV: 4; /* RTC clock divider high */
} RTC_DIVH_REG;

typedef struct {
	DWORD RTC_DIV:16 ; /* RTC clock divider low */
} RTC_DIVL_REG;

typedef struct {
	DWORD RTC_CNT:16 ; /* RTC counter high */
} RTC_CNTH_REG;

typedef struct {
	DWORD RTC_CNT:16 ; /* RTC counter low */
} RTC_CNTL_REG;

typedef struct {
	DWORD RTC_ALR:16; /* RTC alarm high */
} RTC_ALRH_REG;

typedef struct {
	DWORD RTC_ALR:16; /* RTC alarm low */
} RTC_ALRL_REG;

typedef struct {
	RTC_CRH_REG 	CRH_REG; 			/* RTC_CRH */
	RTC_CRL_REG 	CRL_REG; 			/* RTC_CRL */
	RTC_PRLH_REG 	PRLH_REG; 			/* RTC_PRLH */ 
	RTC_PRLL_REG 	PRLL_REG;			/* RTC_PRLL */
	RTC_DIVH_REG 	DIVH_REG; 			/* RTC_DIVH */
	RTC_DIVL_REG 	DIVL_REG; 			/* RTC_DIVL */
	RTC_CNTH_REG 	CNTH_REG;			/* RTC_CNTH */
	RTC_CNTL_REG 	CNTL_REG;			/* RTC_CNTL */
	RTC_ALRH_REG 	ALRH_REG;			/* RTC_ALRH */
	RTC_ALRL_REG 	ALRL_REG; 			/* RTC_ALRL */
} RTC_REG_MAP;