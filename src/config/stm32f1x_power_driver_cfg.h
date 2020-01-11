#pragma once
#include "base_types.h"

typedef struct {
    DWORD LPD: 1; /* Low-power deepsleep. */
    DWORD PDD: 1; /* Power down deepsleep. */
    DWORD CWU: 1; /* Clear wakeup flag */
    DWORD CSB: 1; /* Clear standby flag */
    DWORD PVD: 1; /* Power voltage detector enable. */
    DWORD PLS: 3; /* PVD level selection. */
    DWORD DBP: 1; /* Disable backup domain write protection */
} PWR_CR_REG;

typedef struct {
    DWORD WUF:1; /* Wakeup flag */
    DWORD SBF:1; /* Standby flag */
    DWORD PVDO:1; /* PVD output */
    DWORD Reserved:4; /* must be kept at reset value. */
    DWORD EWUP:1; /* Enable WKUP pin */
} PWR_CSR_REG;

typedef struct {
    PWR_CR_REG CR; /* Power control/status register */
    PWR_CSR_REG CSR; /* Power control/status register */
} PWR_REG_MAP;