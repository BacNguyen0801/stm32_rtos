#pragma once
#include "base_types.h"

typedef struct {
	BYTE DR_REG[4]; /* Data register bits */
} CRC_DR_REG;

typedef struct {
	BYTE IDR_REG; /* General-purpose 8-bit data register bits */
} CRC_IDR_REG;

typedef struct {
	BYTE RESET : 1; /* RESET bit */
} CRC_CR_REG;

typedef struct {
	CRC_DR_REG		DR_REG;			/* CRC_DR */
	CRC_IDR_REG		IDR_REG;		/* CRC_IDR */
	BYTE			Reserved[3];	/* Reserved, must be kept at reset value. */
	CRC_CR_REG		CR_REG;			/* CRC_CR */
	BYTE			Reserved_1[3];	/* Reserved, must be kept at reset value. */
} CRC_REG_MAP;