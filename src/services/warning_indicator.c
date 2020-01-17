#include "warning_indicator.h"
#include "HAL_gpio_control.h"
#include "HAL_timer_service.h"

#define WI_INIT_THRESHOLD 400u /* 500 * 0.01s = 5s */
#define WI_OFF_THRESHOLD 200u  /* 200 * 0.01ms = 2s */
#define WI_FREQ_NORMAL 50u /* Freq Hz = 0.5s */

typedef enum
{
    wi_stt_preinit,
    wi_stt_init_on,
    wi_stt_init_off,
    wi_stt_normal,
    wi_stt_idle,
} wi_state;

static BYTE wi_IsOffState = TRUE;
static wi_state wi_stt_MainState = wi_stt_preinit;
static DWORD wi_stt_startTimerTick = 0;
static DWORD wi_freq_value = WI_FREQ_NORMAL;

void warning_indicator_run()
{
    switch (wi_stt_MainState)
    {
    case wi_stt_preinit:
        wi_stt_startTimerTick = HAL_tim_getTickCnt();
        HAL_gpio_turnWLOn();
        wi_stt_MainState = wi_stt_init_on;
        break;
    case wi_stt_init_on:
        if ((HAL_tim_getTickCnt() - wi_stt_startTimerTick) >= WI_INIT_THRESHOLD)
        {
            wi_stt_startTimerTick = HAL_tim_getTickCnt();
            HAL_gpio_turnWLOff();
            wi_stt_MainState = wi_stt_init_off;
        }
        break;
    case wi_stt_init_off:
        if ((HAL_tim_getTickCnt() - wi_stt_startTimerTick) >= WI_OFF_THRESHOLD)
        {
            wi_stt_MainState = wi_stt_normal;
            wi_freq_value = WI_FREQ_NORMAL;
            wi_stt_startTimerTick = HAL_tim_getTickCnt();
        }
        break;
    case wi_stt_normal:
        if((HAL_tim_getTickCnt() - wi_stt_startTimerTick) >= wi_freq_value)
        {
            if(wi_IsOffState == TRUE)
            {
                HAL_gpio_turnWLOn();
                wi_stt_startTimerTick = HAL_tim_getTickCnt();
                wi_IsOffState = FALSE;
            }
            else
            {
                /* code */
                HAL_gpio_turnWLOff();
                wi_stt_startTimerTick = HAL_tim_getTickCnt();
                wi_IsOffState = TRUE;
            }
            
        }
    case wi_stt_idle:
        /* Do nothing */
        break;
    }
}