#pragma once
#include "base_types.h"

typedef struct 
{
	BYTE PE: 1; /*  Parity error */
	BYTE FE: 1; /*  Framing error */
	BYTE NE: 1; /*  Noise error flag */
	BYTE ORE: 1; /*  Overrun error */
	BYTE IDLE: 1; /*  IDLE line detected */
	BYTE RXNE: 1; /*  Read data register not empty */
	BYTE TC: 1; /*  Transmission complete */
	BYTE TXE: 1; /*  Transmit data register empty */
	BYTE LBD: 1; /*  LIN break detection flag */
	BYTE CTS: 1; /*  CTS flag */
} USART_SR_REG;

typedef struct 
{
	BYTE DR; /* Data value */
} USART_DR_REG;

typedef struct 
{
	BYTE DIV_Fraction : 4; /* fraction of USARTDIV */
	DWORD DIV_Mantissa: 12; /* mantissa of USARTDIV */
} USART_BRR_REG;

typedef struct 
{
	BYTE SBK: 1; /* Send break */
	BYTE RWU: 1; /* Receiver wakeup */
	BYTE RE: 1; /* Receiver enable */
	BYTE TE: 1; /* Transmitter enable */
	BYTE IDLEIE: 1; /* IDLE interrupt enable */
	BYTE RXNEIE: 1; /* RXNE interrupt enable */
	BYTE TCIE: 1; /* Transmission complete interrupt enable */
	BYTE TXEIE: 1; /* TXE interrupt enable */
	BYTE PEIE: 1; /* PE interrupt enable */
	BYTE PS: 1; /* Parity selection */
	BYTE PCE: 1; /* Parity control enable */
	BYTE WAKE: 1; /* Wakeup method */
	BYTE M: 1; /* Word length */
	BYTE UE: 1; /* USART enable */
} USART_CR1_REG;

typedef struct 
{
	BYTE ADD: 4; /* Address of the USART node */
	BYTE Reserved: 1; /* forced by hardware to 0. */
	BYTE LBDL: 1; /* lin break detection length */
	BYTE LBDIE: 1; /* LIN break detection interrupt enable */
	BYTE Reserved_1: 1; /* forced by hardware to 0. */
	BYTE LBCL: 1; /* Last bit clock pulse */
	BYTE CPHA: 1; /* Clock phase */
	BYTE CPOL: 1; /* Clock polarity */
	BYTE CLKEN: 1; /* Clock enable */
	BYTE STOP: 1; /* STOP bits */
	BYTE LINEN: 1; /* LIN mode enable */
} USART_CR2_REG;

typedef struct
{
	BYTE EIE: 1; /*  Error interrupt enable */
	BYTE IREN: 1; /*  IrDA mode enable */
	BYTE IRLP: 1; /*  IrDA low-power */
	BYTE HDSEL: 1; /*  Half-duplex selection */
	BYTE NACK: 1; /*  Smartcard NACK enable */
	BYTE SCEN: 1; /*  Smartcard mode enable */
	BYTE DMAR: 1; /*  DMA enable receiver */
	BYTE DMAT: 1; /*  DMA enable transmitter */
	BYTE RTSE: 1; /*  RTS enable */
	BYTE CTSE: 1; /*  CTS enable */
	BYTE CTSIE: 1; /*  CTS interrupt enable */
} USART_CR3_REG;


typedef struct 
{
	BYTE GT; /* Guard time value */
	BYTE PSC; /* Prescaler value */
} USART_GTPR_REG;

typedef struct
{
	USART_SR_REG SR_REG; 	/* USART_SR */
	BYTE 	Reserved_0[2]; /* Reserved */
	USART_DR_REG DR_REG; 	/* USART_DR */
	BYTE 	Reserved_1[2]; /* Reserved */
	USART_BRR_REG BRR_REG; /* USART_BRR */
	BYTE 	Reserved_2[2]; /* Reserved */
	USART_CR1_REG 	CR1_REG; /* USART_CR1 */
	BYTE 	Reserved_3[2]; /* Reserved */
	USART_CR2_REG 	CR2_REG; /* USART_CR2 */
	BYTE 	Reserved_4[2]; /* Reserved */
	USART_CR3_REG 	CR3_REG; /* USART_CR3 */
	BYTE 	Reserved_5[2]; /* Reserved */
	USART_GTPR_REG GTPR_REG; /* USART_GTPR */
} USART_REG_MAP;