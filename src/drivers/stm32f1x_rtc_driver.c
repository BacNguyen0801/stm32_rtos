#include "stm32f1x_rtc_driver.h"

/* OWIE: Overflow interrupt enable
0: Overflow interrupt is masked.
1: Overflow interrupt is enabled. */
#define OWIE_IS_MASKED 0x00
#define OWIE_IS_ENABLED 0x01

/* ALRIE: Alarm interrupt enable
0: Alarm interrupt is masked.
1: Alarm interrupt is enabled. */
#define ALRIE_IS_MASKED 0x00
#define ALRIE_IS_ENABLED 0x01

/* SECIE: Second interrupt enable
0: Second interrupt is masked.
1: Second interrupt is enabled. */
#define SECIE_IS_MASKED 0x00
#define SECIE_IS_ENABLE 0x01

/* RTOFF: RTC operation OFF
With this bit the RTC reports the status of the last write operation performed on its registers,
indicating if it has been completed or not. If its value is ‘0’ then it is not possible to write to any
of the RTC registers. This bit is read only.
0: Last write operation on RTC registers is still ongoing.
1: Last write operation on RTC registers terminated. */
#define RTOFF_SETTING_ON_GOING 0x00
#define RTOFF_SETTING_COMPLETELY 0x01

/* CNF: Configuration flag
This bit must be set by software to enter in configuration mode so as to allow new values to
be written in the RTC_CNT, RTC_ALR or RTC_PRL registers. The write operation is only
executed when the CNF bit is reset by software after has been set.
0: Exit configuration mode (start update of RTC registers).
1: Enter configuration mode */
#define CNF_EXIT_CONF_MODE 0x00
#define CNF_ENTER_CONF_MODE 0x01

/* RSF: Registers synchronized flag
This bit is set by hardware at each time the RTC_CNT and RTC_DIV registers are updated
and cleared by software. Before any read operation after an APB1 reset or an APB1 clock
stop, this bit must be cleared by software, and the user application must wait until it is set to
be sure that the RTC_CNT, RTC_ALR or RTC_PRL registers are synchronized.
0: Registers not yet synchronized.
1: Registers synchronized. */
#define RSF_NOT_YET_SYNC 0x00
#define RSF_SYNCHRONIZED 0x01

/* OWF: Overflow flag
This bit is set by hardware when the 32-bit programmable counter overflows. An interrupt is
generated if OWIE=1 in the RTC_CRH register. It can be cleared only by software. Writing ‘1’
has no effect.
0: Overflow not detected
1: 32-bit programmable counter overflow occurred */
#define OWF_OVERFLOW_NOT_DETECTED 0x00
#define OWF_OVERFLOW_DETECTED 0x01

/* ALRF: Alarm flag
This bit is set by hardware when the 32-bit programmable counter reaches the threshold set
in the RTC_ALR register. An interrupt is generated if ALRIE=1 in the RTC_CRH register. It
can be cleared only by software. Writing ‘1’ has no effect.
0: Alarm not detected
1: Alarm detected */
#define ALRF_ALARM_NOT_DETECTED 0x00
#define ALRF_ALARM_DETECTED 0x01

/* SECF: Second flag
This bit is set by hardware when the 32-bit programmable prescaler overflows, thus
incrementing the RTC counter. Hence this flag provides a periodic signal with a period
corresponding to the resolution programmed for the RTC counter (usually one second). An
interrupt is generated if SECIE=1 in the RTC_CRH register. It can be cleared only by
software. Writing ‘1’ has no effect.
0: Second flag condition not met.
1: Second flag condition met. */
#define SECF_FLAG_NOT_DETECTED 0x00
#define SECF_FLAG_DETECTED 0x01

/* RTC prescaler reload value high */
#define RTC_PREH_RELOAD_VALUE 0x00
/* RTC prescaler reload value low */
#define RTC_PREL_RELOAD_VALUE 624u /* signal period of 10ms  */

#define RCC_BASE_ADDRESS (RTC_REG_MAP *)0x40002800
static volatile RTC_REG_MAP *const stm32f1x_rtc_reg = RCC_BASE_ADDRESS;

static volatile DWORD stm32f1x_rtc_tickCnt = 0;

void stm32f1x_rtc_driver_init()
{
    /*  1. Poll RTOFF, wait until its value goes to ‘1’
        2. Set the CNF bit to enter configuration mode
        3. Write to one or more RTC registers
        4. Clear the CNF bit to exit configuration mode
        5. Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation */
    while (stm32f1x_rtc_reg->CRL_REG.RTOFF == RTOFF_SETTING_ON_GOING);
    stm32f1x_rtc_reg->CRL_REG.CNF = CNF_ENTER_CONF_MODE;

    stm32f1x_rtc_reg->PRLH_REG.PRL = RTC_PREH_RELOAD_VALUE;
    stm32f1x_rtc_reg->PRLL_REG.PRL = RTC_PREL_RELOAD_VALUE;

    stm32f1x_rtc_reg->CNTL_REG.RTC_CNT = 0;
    stm32f1x_rtc_reg->CNTH_REG.RTC_CNT = 0;
    stm32f1x_rtc_reg->CRL_REG.CNF = CNF_EXIT_CONF_MODE;
    while (stm32f1x_rtc_reg->CRL_REG.RTOFF == RTOFF_SETTING_ON_GOING);
}

DWORD stm32f1x_rtc_driver_getTickCnt()
{
    /* 62.5k / 625 => 1lsb = 0.01s */ 
    stm32f1x_rtc_tickCnt = (stm32f1x_rtc_reg->CNTL_REG.RTC_CNT | (stm32f1x_rtc_reg->CNTH_REG.RTC_CNT << 16));
    return stm32f1x_rtc_tickCnt; 
}

