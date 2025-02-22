#include "flprogAnonSystemHardwareTimer.h"

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON

void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func)
{
    (void)func;
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    (void)period;
}

uint32_t getFlprogSystemTimerTickPeriod()
{
    return 10;
}

#endif