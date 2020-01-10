#include "warning_indicator.h"
#include "HAL_gpio_control.h"

#define WI_INIT_THRESHOLD 20u /* 20 * 128 ms = 2560 ms */
#define WI_OFF_THRESHOLD 20u  /* 20 * 128 ms = 2560ms = 2.56s */

typedef enum
{
    wi_stt_init,
    wi_stt_off,
    wi_stt_idle,
} wi_state;

static wi_state wi_stt_MainState = wi_stt_init;
static DWORD wi_stt_Counter = 0;

void warning_indicator_run()
{
    switch (wi_stt_MainState)
    {
    case wi_stt_init:
        wi_stt_Counter++;
        if (wi_stt_Counter > WI_INIT_THRESHOLD)
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
        if (wi_stt_Counter > WI_OFF_THRESHOLD)
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