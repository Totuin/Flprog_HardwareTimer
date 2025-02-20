#include "flprogStm32SystemHardwareTimer.h"

#ifdef RT_HW_CORE_STM32
void initFlprogSystemTimer(callback_function_t func)
{
    flprogSystemTimerHandler = func;
    flprogSystemTimerOneMicrosPrescaler = FLProgSystemHardwareTimer.getTimerClkFreq() / 1000000;
    FLProgSystemHardwareTimer.pause();
    initFlprogSystemTimerParametrs();
}

void initFlprogSystemTimerParametrs()
{
    if (flprogSystemTimerHandler == 0)
    {
        return;
    }
    uint32_t prescaler = (flprogSystemTimerOneMicrosPrescaler * flprogSystemPrescaler);
    FLProgSystemHardwareTimer.setPrescaleFactor(prescaler);
    FLProgSystemHardwareTimer.setOverflow(flprogSystemTimerPresetValue);
    FLProgSystemHardwareTimer.attachInterrupt(flprogSystemTimerHandler);
    FLProgSystemHardwareTimer.setPreloadEnable(false);
    FLProgSystemHardwareTimer.resume();
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    uint32_t temp = period;
    if (temp < 10)
    {
        temp = 10;
    }
    uint16_t oldPrescaler = flprogSystemPrescaler;
    flprogSystemPrescaler = 1;
    if (privateSetFlprogSystemTimerTickPeriod(temp))
    {
        initFlprogSystemTimerParametrs();
        return;
    }
    flprogSystemPrescaler = oldPrescaler;
}

bool privateSetFlprogSystemTimerTickPeriod(uint32_t period)
{
    uint32_t prescaler = (flprogSystemTimerOneMicrosPrescaler * flprogSystemPrescaler);
    if (prescaler > 65535)
    {
        return false;
    }
    uint32_t offset = (uint32_t)(period / flprogSystemPrescaler);
    if (offset > 65535)
    {
        flprogSystemPrescaler = flprogSystemPrescaler + 10;
        return privateSetFlprogSystemTimerTickPeriod(period);
    }
    flprogSystemTickPeriod = period;
    flprogSystemTimerPresetValue = offset;
    return true;
}
#endif