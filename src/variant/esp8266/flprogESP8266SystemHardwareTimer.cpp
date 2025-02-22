#include "flprogESP8266SystemHardwareTimer.h"

#ifdef RT_HW_CORE_ESP8266

uint32_t getFlprogSystemTimerTickPeriod()
{
    return flprogSystemTickPeriod;
}

void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func)
{
    flprogSystemTimerHandler = func;
    privateSetPeriod(flprogSystemTickPeriod);
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    uint32_t _period = period;
    if (_period < 10)
    {
        _period = 10;
    }
    uint32_t oldFreq = flprogSystemTimerTimClockFreq;
    flprogSystemTimerTimClockFreq = FLPROG_SYSTEM_TIMER_TIM_DIV1_CLOCK;
    if (privateSetPeriod(_period))
    {
        flprogSystemTickPeriod = _period;
        return;
    }
    flprogSystemTimerTimClockFreq = oldFreq;
}

bool privateSetPeriod(uint32_t period)
{
    if (flprogSystemTimerHandler == 0)
    {
        return false;
    }
    float freq = (float)(1000000.0f / period);
    if (freq < ((float)(flprogSystemTimerTimClockFreq / 8388607)))
    {
        return false;
    }
    uint32_t _timerCount = (uint32_t)(flprogSystemTimerTimClockFreq / freq);
    if (_timerCount > 8388607)
    {
        if (flprogSystemTimerTimClockFreq == FLPROG_SYSTEM_TIMER_TIM_DIV1_CLOCK)
        {
            flprogSystemTimerTimClockFreq = FLPROG_SYSTEM_TIMER_TIM_DIV16_CLOCK;
            return privateSetPeriod(period);
        }
        if (flprogSystemTimerTimClockFreq == FLPROG_SYSTEM_TIMER_TIM_DIV16_CLOCK)
        {
            flprogSystemTimerTimClockFreq = FLPROG_SYSTEM_TIMER_TIM_DIV256_CLOCK;
            return privateSetPeriod(period);
        }
        return false;
    }
    timer1_attachInterrupt(flprogSystemTimerHandler);
    timer1_write(_timerCount);
    if (flprogSystemTimerTimClockFreq == FLPROG_SYSTEM_TIMER_TIM_DIV1_CLOCK)
    {
        timer1_enable(TIM_DIV1, TIM_EDGE, TIM_LOOP);
        return true;
    }
    if (flprogSystemTimerTimClockFreq == FLPROG_SYSTEM_TIMER_TIM_DIV16_CLOCK)
    {
        timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
        return true;
    }
    timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
    return true;
}

#endif
