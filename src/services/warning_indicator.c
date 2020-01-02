#include "warning_indicator.h"
#include "HAL_gpio_control.h"

#define WI_INIT_THRESHOLD 200u /* 200 * 240 ms = 4800ms = 24s */
#define WI_OFF_THRESHOLD 50u /* 50 * 240 ms = 6400ms = 6.4s */


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
            wi_stt_Counter++;
            if(wi_stt_Counter > WI_INIT_THRESHOLD)
            {
                wi_stt_MainState = wi_stt_off;
                wi_stt_Counter = 0;
            }
            else
            {
                /* code */
                HAL_gpio_WITurnOn();
            }
            break;
        case wi_stt_off:
            wi_stt_Counter++;
            if(wi_stt_Counter > WI_OFF_THRESHOLD)
            {
                wi_stt_MainState = wi_stt_idle;
                wi_stt_Counter = 0;
            }
            else
            {
                /* code */
                HAL_gpio_WITurnOff();
            }
            break;
        case wi_stt_idle:
            /* Do nothing */
            break;
    }
}