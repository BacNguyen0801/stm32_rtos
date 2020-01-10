#pragma once
#include "base_types.h"

typedef struct {
    DWORD INRQ:1; /* Initialization request */
    DWORD SLEEP:1; /* Sleep mode request */
    DWORD TXFP:1; /* Transmit FIFO priority */
    DWORD RFLM:1; /* Receive FIFO locked mode */
    DWORD NART:1; /* No automatic retransmission */
    DWORD AWUM:1; /* Automatic wakeup mode */
    DWORD ABOM:1; /* Automatic bus-off management */
    DWORD TTCM:1; /* Time triggered communication mode */
    DWORD Reserved:7; /* must be kept at reset value */
    DWORD RESET:1; /* bxCAN software master reset */
    DWORD DBF:1; /* Debug freeze */
} CAN_MCR_REG; /* CAN master control register */

typedef struct {
    DWORD INAK:1; /* Initialization acknowledge */
    DWORD SLAK:1; /* Sleep acknowledge */
    DWORD ERRI:1; /* Error interrupt */
    DWORD WKUI:1; /* Wakeup interrupt */
    DWORD SLAKI:1; /* Sleep acknowledge interrupt */
    DWORD Reserved:3; /* must be kept at reset value. */
    DWORD TXM:1; /* Transmit mode */
    DWORD RXM:1; /* Receive mode */
    DWORD SAMP:1; /* Last sample point */
    DWORD RX:1; /* CAN Rx signal */
} CAN_MSR_REG; /* CAN master status register */

typedef struct {
    DWORD RQCP0:1; /* Request completed mailbox0 */
    DWORD TXOK0:1; /* Transmission OK of mailbox0 */
    DWORD ALST0:1; /* Arbitration lost for mailbox0 */
    DWORD TERR0:1; /* Transmission error of mailbox0 */
    DWORD Reserved:3; /* must be kept at reset value */
    DWORD ABRQ0:1; /* Abort request for mailbox0 */
    DWORD RQCP1:1; /* Request completed mailbox1 */
    DWORD TXOK1:1; /* Transmission OK of mailbox1 */
    DWORD ALST1:1; /* Arbitration lost for mailbox1 */
    DWORD TERR1:1; /* Transmission error of mailbox1 */
    DWORD Reserved1:3; /* must be kept at reset value */
    DWORD BRQ1:1; /* Abort request for mailbox 1 */
    DWORD RQCP2:1; /* Request completed mailbox2 */
    DWORD TXOK2:1; /* Transmission OK of mailbox 2 */
    DWORD ALST2:1; /* Arbitration lost for mailbox 2 */
    DWORD TERR2:1; /* Transmission error of mailbox 2 */
    DWORD Reserved:3; /* must be kept at reset value. */
    DWORD ABRQ2:1; /* Abort request for mailbox 2 */
    DWORD CODE:2; /* Mailbox code */
    DWORD TME2:1; /* Transmit mailbox 2 empty */
    DWORD TME2:1; /* Transmit mailbox 2 empty */
    DWORD TME2:1; /* Transmit mailbox 2 empty */
    DWORD LOW0:1; /* Lowest priority flag for mailbox 0 */
    DWORD LOW1:1; /* Lowest priority flag for mailbox 1 */
    DWORD LOW2:1; /* Lowest priority flag for mailbox 2 */
} CAN_TSR_REG; /* CAN transmit status register */