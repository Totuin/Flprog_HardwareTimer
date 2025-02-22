#include "flprogSystemHardwareTimer.h"
#ifdef RT_HW_PLC_CODE
#define CONTROL_PIN RT_HW_Base.getPinDOT(0)
#endif

#ifndef CONTROL_PIN
#ifdef RT_HW_CORE_STM32
#define CONTROL_PIN PB9
#endif
#endif

#ifndef CONTROL_PIN
#ifdef RT_HW_CORE_RP2040
#define CONTROL_PIN 7
#endif
#endif

#ifndef CONTROL_PIN
#ifdef RT_HW_CORE_ESP8266
#define CONTROL_PIN 5  //D1
#endif
#endif

#ifndef CONTROL_PIN
#ifdef RT_HW_CORE_ESP32
#define CONTROL_PIN 2 
#endif
#endif

#ifndef CONTROL_PIN
#define CONTROL_PIN 13
#endif

FlprogDiscreteOutputPin controlPin(CONTROL_PIN);
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