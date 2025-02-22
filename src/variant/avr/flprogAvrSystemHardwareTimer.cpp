#include "flprogAvrSystemHardwareTimer.h"

#ifdef RT_HW_CORE_AVR

void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func)
{
    flprogSystemTimerHandler = func;
    noInterrupts();
    initFlprogSystemTimerParametrs();
}

void initFlprogSystemTimerParametrs()
{
    TCCR1A = 0x00;
    TCCR1B = 0x00;
    if (flprogSystemPrescaler == 1)
    {
        TCCR1B |= (1 << CS10);
    }
    if (flprogSystemPrescaler == 8)
    {
        TCCR1B |= (1 << CS11);
    }
    if (flprogSystemPrescaler == 64)
    {
        TCCR1B |= (1 << CS10) | (1 << CS11);
    }
    if (flprogSystemPrescaler == 256)
    {
        TCCR1B |= (1 << CS12);
    }
    if (flprogSystemPrescaler == 1024)
    {
        TCCR1B |= (1 << CS10) | (1 << CS12);
    }
    TIMSK1 |= (1 << TOIE1);
    TCNT1 = flprogSystemTimerPresetValue;
    interrupts();
}

void setFlprogSystemTimerTickPeriod(uint32_t period)
{
    if (flprogSystemTickPeriod == period)
    {
        return;
    }
    uint32_t temp = period;
    if (temp < 10)
    {
        temp = 10;
    }
    noInterrupts();
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

    uint32_t offset = (uint32_t)((16 * period) / flprogSystemPrescaler);
    if (offset > 65535)
    {
        if (flprogSystemPrescaler == 1)
        {
            flprogSystemPrescaler = 8;
            return privateSetFlprogSystemTimerTickPeriod(period);
        }
        if (flprogSystemPrescaler == 8)
        {
            flprogSystemPrescaler = 64;
            return privateSetFlprogSystemTimerTickPeriod(period);
        }
        if (flprogSystemPrescaler == 64)
        {
            flprogSystemPrescaler = 256;
            return privateSetFlprogSystemTimerTickPeriod(period);
        }
        if (flprogSystemPrescaler == 256)
        {
            flprogSystemPrescaler = 1024;
            return privateSetFlprogSystemTimerTickPeriod(period);
        }
        return false;
    }
    flprogSystemTimerPresetValue = 65535 - offset;
    flprogSystemTickPeriod = period;
    return true;
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = flprogSystemTimerPresetValue;
    if (flprogSystemTimerHandler != 0)
    {
        flprogSystemTimerHandler();
    }
}

uint32_t getFlprogSystemTimerTickPeriod()
{
    return flprogSystemTickPeriod;
}

#endif