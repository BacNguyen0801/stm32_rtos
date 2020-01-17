#pragma once
#include "base_types.h"

typedef struct
{
    DWORD LATENCY : 3; /* Latency */
    DWORD HLFCYA : 1;  /* Flash half cycle access enable */
    DWORD PRFTBE : 1;  /* Prefetch buffer enable */
    DWORD PRFTBS : 1;  /* Prefetch buffer status */
} FLASH_ACR_REG;

typedef struct
{
    DWORD FKEYR; /* FPEC key */
} FLASH_KEYR_REG;

typedef struct
{
    DWORD OPTKEYR; /* Option byte key */
} FLASH_OPTKEYR_REG;

typedef struct
{
    DWORD BSY : 1;       /* Busy */
    DWORD Reserved : 1;  /* must be kept cleared */
    DWORD PGERR : 1;     /* Programming error */
    DWORD Reserved1 : 1; /* must be kept cleared. */
    DWORD WRPRTERR : 1;  /* Write protection error */
    DWORD EOP : 1;       /* End of operation */
} FLASH_SR_REG;

typedef struct
{
    DWORD PG : 1;        /* Programming */
    DWORD PER : 1;       /* Page erase */
    DWORD MER : 1;       /* Mass erase */
    DWORD Reserved : 1;  /* must be kept cleared. */
    DWORD OPTPG : 1;     /* Option byte programming */
    DWORD OPTER : 1;     /* Option byte erase */
    DWORD STRT : 1;      /* Start */
    DWORD LOCK : 1;      /* Lock */
    DWORD Reserved1 : 1; /* must be kept cleared */
    DWORD OPTWRE : 1;    /* Option bytes write enable */
    DWORD ERRIE : 1;     /* Error interrupt enable */
    DWORD EOPIE : 1;     /* End of operation interrupt enable */
} FLASH_CR_REG;

typedef struct
{
    DWORD FAR; /* Flash Address */
} FLASH_AR_REG;

typedef struct
{
    DWORD OPTERR : 1; /* Option byte error */
    DWORD RDPRT : 1;  /* Read protection */
    DWORD WDG_SW : 1;
    DWORD nRST_STOP : 1;
    DWORD nRST_STDBY : 1;
    DWORD Notused : 5;
    DWORD Data0 : 8;
    DWORD Data1 : 8;
} FLASH_OBR_REG;

typedef struct
{
    DWORD WRP; /* Write protect */
} FLASH_WRPR_REG;

typedef struct
{
    FLASH_ACR_REG ACR;         /* FLASH_ACR_REG */
    FLASH_KEYR_REG KEYR;       /* FLASH_KEYR_REG */
    FLASH_OPTKEYR_REG OPTKEYR; /* FLASH_OPTKEYR */
    FLASH_SR_REG SR;           /* FLASH_SR */
    FLASH_CR_REG CR;           /* FLASH_CR */
    FLASH_AR_REG AR;           /*  FLASH_AR */
    DWORD NotUsed;
    FLASH_OBR_REG OBR;   /*  FLASH_OBR */
    FLASH_WRPR_REG WRPR; /* FLASH_WRPR */
} FLASH_REG_MAP;