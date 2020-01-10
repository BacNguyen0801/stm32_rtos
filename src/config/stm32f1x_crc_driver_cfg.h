#pragma once
#include "base_types.h"

typedef struct {
	DWORD DR_REG; /* Data register bits */
} CRC_DR_REG;

typedef struct {
	DWORD IDR_REG:8; /* General-purpose 8-bit data register bits */
} CRC_IDR_REG;

typedef struct {
	DWORD RESET : 1; /* RESET bit */
} CRC_CR_REG;

typedef struct {
	CRC_DR_REG		DR_REG;			/* CRC_DR */
	CRC_IDR_REG		IDR_REG;		/* CRC_IDR */
	CRC_CR_REG		CR_REG;			/* CRC_CR */
} CRC_REG_MAP;