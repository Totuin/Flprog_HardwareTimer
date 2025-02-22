#include "flprogESP32SystemHardwareTimer.h"

#ifdef RT_HW_CORE_ESP32

uint32_t getFlprogSystemTimerTickPeriod()
{
    return flprogSystemTickPeriod;
}

void flprogSystemTimerOnTimer()
{
    if (flprogSystemTimerHandler == 0)
    {
        return;
    }
    flprogSystemTimerHandler();
}

void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func)
{
    flprogSystemTimerHandler = func;
    FLProgSystemHardwareTimer = timerBegin(0, 80, true);
    timerAttachInterrupt(FLProgSystemHardwareTimer, &flprogSystemTimerOnTimer, true);
    timerAlarmWrite(FLProgSystemHardwareTimer, flprogSystemTickPeriod, true);
    timerAlarmEnable(FLProgSystemHardwareTimer);
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    if (flprogSystemTickPeriod == period)
    {
        return;
    }
    flprogSystemTickPeriod = period;
    if (flprogSystemTickPeriod < 10)
    {
        flprogSystemTickPeriod = 10;
    }
    if (FLProgSystemHardwareTimer != 0)
    {
        timerAlarmWrite(FLProgSystemHardwareTimer, flprogSystemTickPeriod, true);
    }
}

#endif