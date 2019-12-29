#include "warning_indicator.h"
#include "HAL_gpio_control.h"

#define WI_INIT_THRESHOLD 50u /* 50 * 128 ms = 6400ms = 6.4s */
#define WI_OFF_THRESHOLD 50u /* 50 * 128 ms = 6400ms = 6.4s */


typedef enum {
    wi_stt_init,
    wi_stt_off,
    wi_stt_idle,
} wi_state;

static wi_state wi_stt_MainState = wi_stt_init;
static DWORD wi_stt_Counter = 0;

void warning_indicator_run()
{
    switch(wi_stt_MainState)
    {
        case wi_stt_init:
            if(wi_stt_Counter > WI_INIT_THRESHOLD)
            {
                wi_stt_MainState = wi_stt_off;
                wi_stt_Counter = 0;
            }
            else if (wi_stt_Counter == 0)
            {
                /* code */
                HAL_gpio_WITurnOn();
            }
            wi_stt_Counter++;
            break;
        case wi_stt_off:
            if(wi_stt_Counter > WI_OFF_THRESHOLD)
            {
                wi_stt_MainState = wi_stt_idle;
                wi_stt_Counter = 0;
            }
            else if (wi_stt_Counter == 0)
            {
                /* code */
                HAL_gpio_WITurnOff();
            }
            wi_stt_Counter++;
            break;
        case wi_stt_idle:
            /* Do nothing */
            break;
    }
}