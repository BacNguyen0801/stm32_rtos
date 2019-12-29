#pragma once

typedef unsigned char	BYTE;
typedef unsigned int	DWORD;
typedef unsigned int	ERROR_CODE;

#define SET_BIT(x, data)	data |= (1 << x)
#define CLEAR_BIT(x, data)	data &= ~(1 << x)
#define IS_BIT_SET(x, data)	(data & (1 << x))
#define NULL				(0)
