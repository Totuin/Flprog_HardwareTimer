#include "flprogRP2040SystemHardwareTimer.h"

#ifdef RT_HW_CORE_RP2040

uint32_t getFlprogSystemTimerTickPeriod()
{
    return flprogSystemTickPeriod;
}

bool flprogSystemHardwarePrivateTimerTickEvent(struct repeating_timer *t)
{
    (void)t;
    if (flprogSystemTimerHandler != 0)
    {
        flprogSystemTimerHandler();
    }
    return true;
}

void privateSetPeriod()
{
    int64_t _timerCount = (int64_t)(((float)1000000.0f) / (1000000.0f / flprogSystemTickPeriod));
    cancel_repeating_timer(&FLProgSystemHardwareTimer);
    add_repeating_timer_us(-(_timerCount), flprogSystemHardwarePrivateTimerTickEvent, NULL, &FLProgSystemHardwareTimer);
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    uint32_t _period = period;
    if (_period < 10)
    {
        _period = 10;
    }
    flprogSystemTickPeriod = _period;
    privateSetPeriod();
}

void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func)
{
    flprogSystemTimerHandler = func;
    privateSetPeriod();
}

#endif