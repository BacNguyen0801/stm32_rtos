#include "stm32f1x_flash_driver.h"

/* LATENCY: Latency
These bits represent the ratio of the SYSCLK (system clock) period to the Flash access
time.
000 Zero wait state, if 0 < SYSCLK≤ 24 MHz
001 One wait state, if 24 MHz < SYSCLK ≤ 48 MHz
010 Two wait states, if 48 MHz < SYSCLK ≤72 MHz */
#define LATENCY_NOWAIT 0x00
#define LATENCY_ONE_WAIT 0x01
#define LATENCY_TWO_WAIT 0x02

/* EOPIE: End of operation interrupt enable
This bit enables the interrupt generation when the EOP bit in the FLASH_SR register goes
to 1.
0: Interrupt generation disabled
1: Interrupt generation enabled */
#define EOPIE_DISABLE_INTERRUPT 0x00
#define EOPIE_ENABLE_INTERRUPT 0x01

/* ERRIE: Error interrupt enable
This bit enables the interrupt generation on an FPEC error (when PGERR / WRPRTERR are
set in the FLASH_SR register).
0: Interrupt generation disabled
1: Interrupt generation enabled */
#define ERRIE_DISABLE_INTERRUPT 0x00
#define ERRIE_ENABLE_INTERRUPT 0x01

/* EOP: End of operation
Set by hardware when a Flash operation (programming / erase) is completed. Reset by
writing a 1 */
#define EOP_RO_DONE 0x01

/* WRPRTERR: Write protection error
Set by hardware when programming a write-protected address of the Flash memory.
Reset by writing 1. */
#define WRPRTERR_RO_WRITE_PROTECTION 0x01

/* PGERR: Programming error
Set by hardware when an address to be programmed contains a value different from
'0xFFFF' before programming.
Reset by writing 1.
Note: The STRT bit in the FLASH_CR register should be reset before starting a programming
operation. */
#define PGERR_RO_WRITE_ERR 0x01

/* BSY: Busy
This indicates that a Flash operation is in progress. This is set on the beginning of a Flash
operation and reset when the operation finishes or when an error occurs. */
#define BSY_FLASH_BUSY 0x01

/* LOCK: Lock
Write to 1 only. When it is set, it indicates that the FPEC and FLASH_CR are locked. This bit
is reset by hardware after detecting the unlock sequence.
In the event of unsuccessful unlock operation, this bit remains set until the next reset. */
#define LOCK_RO_STATUS 0x01

/* STRT: Start
This bit triggers an ERASE operation when set. This bit is set only by software and reset
when the BSY bit is reset */
#define STRT_TRIGGER_ERASE 0x01

/* PG: Programming */
#define PG_TRIGGER_PROGRAM 0x01


#define SEQUENCE_KEY_1 0x45670123
#define SEQUENCE_KEY_2 0xCDEF89AB

#define FLASH_BAS_ADDRESS (FLASH_REG_MAP *) 0x40022000
static volatile FLASH_REG_MAP* const stm32f1x_flash_reg = FLASH_BAS_ADDRESS;
WORD* dbg_Testdata[2];
void stm32f1x_flash_driver_init()
{
    if(stm32f1x_flash_reg->CR.LOCK == LOCK_RO_STATUS)
    {
        stm32f1x_flash_reg->KEYR.FKEYR = SEQUENCE_KEY_1;
        stm32f1x_flash_reg->KEYR.FKEYR = SEQUENCE_KEY_2;
    }

    while(stm32f1x_flash_reg->CR.LOCK == LOCK_RO_STATUS); /* wait until lock is removed */

    stm32f1x_flash_reg->CR.EOPIE = EOPIE_ENABLE_INTERRUPT;
    stm32f1x_flash_reg->CR.ERRIE = ERRIE_ENABLE_INTERRUPT;

    // if (E_NOT_OK == stm32f1x_flash_driver_program(0x0801FC00, 0xAA55))
    // {
    //     while(1);
    // }
    // else
    // {
    //     dbg_Testdata[0] = (WORD*)0x0801FC00;
    //     dbg_Testdata[1] = (WORD*)0x0801FC02;
    // }
    
}

void stm32f1x_flash_driver_changeLatency()
{
    stm32f1x_flash_reg->ACR.LATENCY = LATENCY_TWO_WAIT;
}

ErrorCode stm32f1x_flash_driver_program(DWORD FlashAddr, WORD Value)
{
    ErrorCode err = E_NOT_OK;
    WORD* pointer; 
    if((FlashAddr & 0x01) != 0x01)        /* Align with half-word address */
    {
        pointer = (WORD*)FlashAddr;
        if(stm32f1x_flash_reg->SR.BSY != BSY_FLASH_BUSY)
        {
            stm32f1x_flash_reg->AR.FAR = FlashAddr; /* update address which be programed */
            stm32f1x_flash_reg->CR.PG = PG_TRIGGER_PROGRAM;
            *pointer = Value; /* Update data */

            while(stm32f1x_flash_reg->SR.BSY == BSY_FLASH_BUSY); /* wait for operation completed */
            if(stm32f1x_flash_reg->SR.EOP == EOP_RO_DONE)
            {
                err = E_OK;
            }
        }
    }
    return err;
}
