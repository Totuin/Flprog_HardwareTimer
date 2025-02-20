#include "flprogSystemHardwareTimer.h"

FlprogDiscreteOutputPin controlPin((RT_HW_Base.getPinDOT(0)));

void setup()
{
    initFlprogSystemTimer(systemTimerHandler);
    setFlprogSystemTimerTickPeriod(15);
}

void loop()
{
}

void systemTimerHandler()
{
    controlPin.digitalWrite(!controlPin.digitalRead());
}
