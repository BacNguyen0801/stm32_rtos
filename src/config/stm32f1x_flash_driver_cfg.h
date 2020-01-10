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
    FLASH_ACR_REG ACR; /* FLASH_ACR_REG */
} FLASH_REG_MAP;