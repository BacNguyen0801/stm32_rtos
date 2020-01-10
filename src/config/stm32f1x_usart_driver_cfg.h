#pragma once
#include "base_types.h"

typedef struct
{
	DWORD PE : 1;   /*  Parity error */
	DWORD FE : 1;   /*  Framing error */
	DWORD NE : 1;   /*  Noise error flag */
	DWORD ORE : 1;  /*  Overrun error */
	DWORD IDLE : 1; /*  IDLE line detected */
	DWORD RXNE : 1; /*  Read data register not empty */
	DWORD TC : 1;   /*  Transmission complete */
	DWORD TXE : 1;  /*  Transmit data register empty */
	DWORD LBD : 1;  /*  LIN break detection flag */
	DWORD CTS : 1;  /*  CTS flag */
} USART_SR_REG;

typedef struct
{
	DWORD DR; /* Data value */
} USART_DR_REG;

typedef struct
{
	DWORD DIV_Fraction : 4;   /* fraction of USARTDIV */
	DWORD DIV_Mantissa : 12; /* mantissa of USARTDIV */
} USART_BRR_REG;

typedef struct
{
	DWORD SBK : 1;	/* Send break */
	DWORD RWU : 1;	/* Receiver wakeup */
	DWORD RE : 1;	 /* Receiver enable */
	DWORD TE : 1;	 /* Transmitter enable */
	DWORD IDLEIE : 1; /* IDLE interrupt enable */
	DWORD RXNEIE : 1; /* RXNE interrupt enable */
	DWORD TCIE : 1;   /* Transmission complete interrupt enable */
	DWORD TXEIE : 1;  /* TXE interrupt enable */
	DWORD PEIE : 1;   /* PE interrupt enable */
	DWORD PS : 1;	 /* Parity selection */
	DWORD PCE : 1;	/* Parity control enable */
	DWORD WAKE : 1;   /* Wakeup method */
	DWORD M : 1;		 /* Word length */
	DWORD UE : 1;	 /* USART enable */
} USART_CR1_REG;

typedef struct
{
	DWORD ADD : 4;		 /* Address of the USART node */
	DWORD Reserved : 1;   /* forced by hardware to 0. */
	DWORD LBDL : 1;		 /* lin break detection length */
	DWORD LBDIE : 1;		 /* LIN break detection interrupt enable */
	DWORD Reserved_1 : 1; /* forced by hardware to 0. */
	DWORD LBCL : 1;		 /* Last bit clock pulse */
	DWORD CPHA : 1;		 /* Clock phase */
	DWORD CPOL : 1;		 /* Clock polarity */
	DWORD CLKEN : 1;		 /* Clock enable */
	DWORD STOP : 1;		 /* STOP bits */
	DWORD LINEN : 1;		 /* LIN mode enable */
} USART_CR2_REG;

typedef struct
{
	DWORD EIE : 1;   /*  Error interrupt enable */
	DWORD IREN : 1;  /*  IrDA mode enable */
	DWORD IRLP : 1;  /*  IrDA low-power */
	DWORD HDSEL : 1; /*  Half-duplex selection */
	DWORD NACK : 1;  /*  Smartcard NACK enable */
	DWORD SCEN : 1;  /*  Smartcard mode enable */
	DWORD DMAR : 1;  /*  DMA enable receiver */
	DWORD DMAT : 1;  /*  DMA enable transmitter */
	DWORD RTSE : 1;  /*  RTS enable */
	DWORD CTSE : 1;  /*  CTS enable */
	DWORD CTSIE : 1; /*  CTS interrupt enable */
} USART_CR3_REG;

typedef struct
{
	DWORD GT;  /* Guard time value */
	DWORD PSC; /* Prescaler value */
} USART_GTPR_REG;

typedef struct
{
	USART_SR_REG SR_REG;	 /* USART_SR */
	USART_DR_REG DR_REG;	 /* USART_DR */
	USART_BRR_REG BRR_REG;   /* USART_BRR */
	USART_CR1_REG CR1_REG;   /* USART_CR1 */
	USART_CR2_REG CR2_REG;   /* USART_CR2 */
	USART_CR3_REG CR3_REG;   /* USART_CR3 */
	USART_GTPR_REG GTPR_REG; /* USART_GTPR */
} USART_REG_MAP;