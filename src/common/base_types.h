#pragma once

typedef unsigned char	BYTE;
typedef unsigned int	DWORD;
typedef unsigned short  WORD;
typedef unsigned int	ERROR_CODE;

typedef BYTE ErrorCode;
#define E_OK 0x00
#define E_NOT_OK 0x01
#define E_PEND 0x02
#define E_BUSY 0x03

#define TRUE  (1 == 1)
#define FALSE (1 != 1)

#define SET_BIT(x, data)	data |= (1 << x)
#define CLEAR_BIT(x, data)	data &= ~(1 << x)
#define IS_BIT_SET(x, data)	(data & (1 << x))
#define NULL				(0)

