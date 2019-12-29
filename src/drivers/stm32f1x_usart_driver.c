
#include "base_types.h"
#include "stm32f1x_usart_driver.h"

/* CTS flag
This bit is set by hardware when the CTS input toggles, if the CTSE bit is set. It is cleared by
software (by writing it to 0). An interrupt is generated if CTSIE=1 in the USART_CR3
register.
0: No change occurred on the CTS status line
1: A change occurred on the CTS status line */
#define CTS_NO_CHANGE_OCCURRED 0x00
#define CTS_A_CHANGE_OCCURRED 0x01
/* LIN break detection flag
This bit is set by hardware when the LIN break is detected. It is cleared by software (by
writing it to 0). An interrupt is generated if LBDIE = 1 in the USART_CR2 register.
0: LIN Break not detected
1: LIN break detected */
#define LIN_BREAK_NOT_DETECTED 0x00
#define LIN_BREAK_DETECTED 0x01
/* Transmit data register empty
This bit is set by hardware when the content of the TDR register has been transferred into
the shift register. An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register. It
is cleared by a write to the USART_DR register.
0: Data is not transferred to the shift register
1: Data is transferred to the shift register) */
#define DATA_IS_NOT_TRANSFERRED 0x00
#define DATA_IS_TRANSFERRED 0x01
/* Transmission complete
This bit is set by hardware if the transmission of a frame containing data is complete and if
TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a
software sequence (a read from the USART_SR register followed by a write to the
USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing
sequence is recommended only for multibuffer communication.
0: Transmission is not complete
1: Transmission is complete */
#define DATA_TRANSMISSION_IS_NOT_COMPLETE 0x00
#define DATA_TRANSMISSION_IS_COMPLTETE 0x01
/* Read data register not empty
This bit is set by hardware when the content of the RDR shift register has been transferred to
the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
writing a zero to it. This clearing sequence is recommended only for multibuffer
communication.
0: Data is not received
1: Received data is ready to be read */
#define DATA_IS_NOT_RECEIVED 0x00
#define DATA_IS_READY_TOBE_READ 0x01
/* IDLE line detected
This bit is set by hardware when an Idle Line is detected. An interrupt is generated if the
IDLEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the
USART_SR register followed by a read to the USART_DR register).
0: No Idle Line is detected
1: Idle Line is detected */
#define IDLE_LINE_IS_NOT_DETECTED 0x00
#define IDLE_LINE_IS_DETECTED 0x01
/* Overrun error
This bit is set by hardware when the word currently being received in the shift register is
ready to be transferred into the RDR register while RXNE=1. An interrupt is generated if
RXNEIE=1 in the USART_CR1 register. It is cleared by a software sequence (an read to the
USART_SR register followed by a read to the USART_DR register).
0: No Overrun error
1: Overrun error is detected */
#define OVERRUN_IS_NOT_DETECTED 0x00
#define OVERRUN_IS_DETECTED 0x01
/* Noise error flag
This bit is set by hardware when noise is detected on a received frame. It is cleared by a
software sequence (an read to the USART_SR register followed by a read to the
USART_DR register).
0: No noise is detected
1: Noise is detected */
#define NOISE_ERROR_IS_NOT_DETECTED 0x00
#define NOISE_ERROR_IS_DETECTED 0x01
/* Framing error
This bit is set by hardware when a de-synchronization, excessive noise or a break character
is detected. It is cleared by a software sequence (an read to the USART_SR register
followed by a read to the USART_DR register).
0: No Framing error is detected
1: Framing error or break character is detected */
#define FRAME_ERROR_IS_NOT_DETECTED 0x00
#define FRAME_ERROR_IS_DETECTED 0x01
/* Parity error
This bit is set by hardware when a parity error occurs in receiver mode. It is cleared by a
software sequence (a read to the status register followed by a read to the USART_DR data
register). The software must wait for the RXNE flag to be set before clearing the PE bit.
An interrupt is generated if PEIE = 1 in the USART_CR1 register.
0: No parity error
1: Parity error */
#define PARITY_ERROR_IS_NOT_DETECTED 0x00
#define PARITY_ERROR_IS_DETECTED 0x01

/* USART enable
When this bit is cleared the USART prescalers and outputs are stopped and the end of the
current
byte transfer in order to reduce power consumption. This bit is set and cleared by software.
0: USART prescaler and outputs disabled
1: USART enabled */
#define DISABLE_USART 0x00
#define ENABLE_USART 0x01
/* Word length
This bit determines the word length. It is set or cleared by software.
0: 1 Start bit, 8 Data bits, n Stop bit
1: 1 Start bit, 9 Data bits, n Stop bit */
#define WORD_LENGTH_8BIT_DATA 0x00
#define WORD_LENGTH_9BIT_DATA 0x01
/* Wakeup method
This bit determines the USART wakeup method, it is set or cleared by software.
0: Idle Line
1: Address Mark */
#define WAKE_UP_BY_IDLE_LINE 0x00
#define WAKE_UP_BY_ADDRESS_MASK 0x01
/* Parity control enable
This bit selects the hardware parity control (generation and detection). When the parity
control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
if M=0) and parity is checked on the received data. This bit is set and cleared by software.
Once it is set, PCE is active after the current byte (in reception and in transmission).
0: Parity control disabled
1: Parity control enabled */
#define PARITY_CONTROL_DISABLE 0x00
#define PARITY_CONTROL_ENABLE 0x01
/* Parity selection
This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
bit set). It is set and cleared by software. The parity will be selected after the current byte.
0: Even parity
1: Odd parity */
#define PAPITY_SELECTION_EVEN 0x00
#define PAPITY_SELECTION_ODD 0x01
/* PE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever PE=1 in the USART_SR register */
#define PE_INTERRUPT_DISABLE 0x00
#define PE_INTERRUPT_ENABLE 0x01
/* TXE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TXE=1 in the USART_SR register */
#define TXE_INTERRUPT_DISABLE 0x00
#define TXE_INTERRUPT_ENABLE 0x01
/* Transmission complete interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever TC=1 in the USART_SR register */
#define TRANSMISSION_INTERRUPT_DISABLE 0x00
#define TRANSMISSION_INTERRUPT_ENABLE 0x01
/* XNE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR register */
#define XNE_INTERRUPT_DISABLE 0x00
#define XNE_INTERRUPT_ENABLE 0x01
/* IDLE interrupt enable
This bit is set and cleared by software.
0: Interrupt is inhibited
1: A USART interrupt is generated whenever IDLE=1 in the USART_SR register */
#define IDLE_INTERRUPT_DISABLE 0x00
#define IDLE_INTERRUPT_ENABLE 0x01
/* Transmitter enable
This bit enables the transmitter. It is set and cleared by software.
0: Transmitter is disabled
1: Transmitter is enabled */
#define TRANSMITTER_DISABLE 0x00
#define TRANSMITTER_ENABLE 0x01
/* This bit enables the receiver. It is set and cleared by software.
0: Receiver is disabled
1: Receiver is enabled and begins searching for a start bit */
#define RECEIVER_DISABLE 0x00
#define RECEIVER_ENABLE 0x01
/* Receiver wakeup
This bit determines if the USART is in mute mode or not. It is set and cleared by software and
can be cleared by hardware when a wakeup sequence is recognized.
0: Receiver in active mode
1: Receiver in mute mode */
#define RECEIVER_IS_ACTIVE 0x00
#define RECEIVER_IS_MUTE 0x01
/* Send break
This bit set is used to send break characters. It can be set and cleared by software. It should
be set by software, and will be reset by hardware during the stop bit of break.
0: No break character is transmitted
1: Break character will be transmitted */
#define BREAK_CHAR_IS_NOT_TRANSMITTED 0x00
#define BREAK_CHAR_IS_TRANSMITTED 0x01

/* LIN mode enable */
#define LIN_ENABLE_VALUE 0x01
#define LIN_DISABLE_VALUE 0x00
/* STOP bits */
#define STOP_BIT_ONE_BIT 0x00
#define STOP_BIT_HALF_BIT 0x01
#define STOP_BIT_TWO_BIT 0x02
#define STOP_BIT_ONE_HALF_BIT 0x03
/* Clock enable */
#define CLOCK_ENABLE_VALUE 0x01
#define CLOCK_DISABLE_VALUE 0x00
/* Clock polarity */
#define CLOCK_STEADY_LOW_VALUE 0x00
#define CLOCK_STEADY_HIGH_VALUE 0x01
/* Clock phase */
#define CLOCK_FIRST_TRANSITION_CAPTURE 0x00
#define CLOCK_SECOND_TRANSITION_CAPTURE 0x01
/* Last bit clock pulse */
#define CLOCK_PUSLE_NOT_OUTPUT 0x00
#define CLOCK_PUSLE_OUTPUT 0x00
/* LIN break detection interrupt enable */
#define ENABLE_LIN_INTERRUPT 0x01
#define DISABLE_LIN_INTERRUPT 0x00
/* lin break detection length
This bit is for selection between 11 bit or 10 bit break detection.
0: 10 bit break detection
1: 11 bit break detection */
#define LIN_BREAK_DETECTION_10 0x00
#define LIN_BREAK_DETECTION_11 0x01
/*  Address of the USART node
This bit-field gives the address of the USART node.
This is used in multiprocessor communication during mute mode, for wake up with address
mark detection */
#define USART_ADDRESS_VALUE 0x00000000

/* CTS interrupt enable
0: Interrupt is inhibited
1: An interrupt is generated whenever CTS=1 in the USART_SR register */
#define CTS_INTERRUPT_DISABLE 0x00
#define CTS_INTERRUPT_ENABLE 0x01
/* CTS enable
0: CTS hardware flow control disabled
1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
the CTS input is deasserted while a data is being transmitted, then the transmission is
completed before stopping. If a data is written into the data register while CTS is deasserted,
the transmission is postponed until CTS is asserted. */
#define CTS_HW_FLOW_IS_DISABLED 0x00
#define CTS_HW_FLOW_IS_ENABLED 0x01
/* RTS enable
0: RTS hardware flow control disabled
1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
The transmission of data is expected to cease after the current character has been
transmitted. The RTS output is asserted (tied to 0) when a data can be received. */
#define RTS_HW_FLOW_IS_DISABLED 0x00
#define RTS_HW_FLOW_IS_ENABLED 0x01
/* DMA enable transmitter
This bit is set/reset by software
1: DMA mode is enabled for transmission
0: DMA mode is disabled for transmission */
#define DMA_MODE_USED 0x00
#define DMA_MODE_NOT_USED 0x01
/* DMA enable receiver
This bit is set/reset by software
1: DMA mode is enabled for reception
0: DMA mode is disabled for reception */
#define DMA_MODE_ENABLE_FOR_RECEPTION 0x00
#define DMA_MODE_DISABLE_FOR_RECEPTION 0x01
/* Smartcard mode enable
This bit is used for enabling Smartcard mode.
0: Smartcard Mode disabled
1: Smartcard Mode enabled */
#define SMART_CARD_MODE_ENABLE_VALUE 0x01
#define SMART_CARD_MODE_DISABLE_VALUE 0x00
/* NACK: Smartcard NACK enable
0: NACK transmission in case of parity error is disabled
1: NACK transmission during parity error is enabled */
#define NACK_TRANSMITTED_DISABLE 0x00
#define NACK_TRANSMITTED_ENABLE 0x01
/* HDSEL: Half-duplex selection
Selection of Single-wire Half-duplex mode
0: Half duplex mode is not selected
1: Half duplex mode is selected */
#define HALP_DUPLEX_SELECTION 0x01
#define HALP_DUPLEX_DESELECTION 0x00
/* IRLP: IrDA low-power
This bit is used for selecting between normal and low-power IrDA modes
0: Normal mode
1: Low-power mode */
#define IrDA_NORMAL_MODE 0x00
#define IrDA_LOW_POWER_MODE 0x01
/* IREN: IrDA mode enable
This bit is set and cleared by software.
0: IrDA disabled
1: IrDA enabled */
#define IrDA_DISABLE 0x00
#define IrDA_ENABLE 0x01
/* EIE: Error interrupt enable
Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing
error, overrun error or noise error (FE=1 or ORE=1 or NE=1 in the USART_SR register) in
case of Multi Buffer Communication (DMAR=1 in the USART_CR3 register).
0: Interrupt is inhibited
1: An interrupt is generated whenever DMAR=1 in the USART_CR3 register and FE=1 or
ORE=1 or NE=1 in the USART_SR register. */
#define ERROR_INTERRUPT_DISABLE 0x00
#define ERROR_INTERRUPT_ENABLE 0x01

/* GT[7:0]: Guard time value
This bit-field gives the Guard time value in terms of number of baud clocks.
This is used in Smartcard mode. The Transmission Complete flag is set after this guard time
value. */
#define GAURD_TIME_VALUE_DEFAULT 0x00
/* PSC[7:0]: Prescaler value */
#define PRECASLER_VALUE_DAFAULT 0x01

/* DIV_Mantissa[11:0]: mantissa of USARTDIV */
#define DIV_MANTISSA_VALUE 0x0000
/* DIV_Fraction[3:0]: fraction of USARTDIV */
#define DIV_FRACTION_VALUE 0x00

volatile USART_REG_MAP usart_reg;

void stm32f1x_usart_driver_init()
{
	/* Init USART_CR1 */
	usart_reg.CR1_REG.UE = ENABLE_USART;		   /* Enable USART */
	usart_reg.CR1_REG.M = WORD_LENGTH_8BIT_DATA;   /* Use 8bit data */
	usart_reg.CR1_REG.WAKE = WAKE_UP_BY_IDLE_LINE; /* Wake up by idle line */
	usart_reg.CR1_REG.PCE = PARITY_CONTROL_ENABLE; /* Enable Parity control */
	usart_reg.CR1_REG.PS = PAPITY_SELECTION_EVEN;  /* Use Even parity */
	usart_reg.CR1_REG.PEIE = PE_INTERRUPT_DISABLE; /* Disable interrupt Parity error */

	/* Init CR2_REG */
	usart_reg.CR2_REG.LINEN = LIN_DISABLE_VALUE;			 /* Disable LIN */
	usart_reg.CR2_REG.STOP = LIN_DISABLE_VALUE;				 /* Disable LIN */
	usart_reg.CR2_REG.CLKEN = CLOCK_DISABLE_VALUE;			 /* Using asynchonous mode */
	usart_reg.CR2_REG.CPOL = CLOCK_STEADY_LOW_VALUE;		 /* Default 0 */
	usart_reg.CR2_REG.CPHA = CLOCK_FIRST_TRANSITION_CAPTURE; /* Default 0 */

	/* Init CR3_REG */
	usart_reg.CR3_REG.SCEN = SMART_CARD_MODE_DISABLE_VALUE; /* Disable Smart card mode */
	usart_reg.CR3_REG.IREN = IrDA_DISABLE;					/* IrDA mode disable */
	usart_reg.CR3_REG.HDSEL = HALP_DUPLEX_SELECTION;		/* Half-duplex selection */

	/* Baurdrate configuration */
	usart_reg.BRR_REG.DIV_Mantissa = DIV_MANTISSA_VALUE;
	usart_reg.BRR_REG.DIV_Fraction = DIV_FRACTION_VALUE;
}

void stm32f1x_usart_driver_write(BYTE data)
{
}