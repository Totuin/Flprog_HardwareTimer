#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_AVR

typedef void (*FLProgSystemHardwareTimerTickEvent)();
static uint32_t flprogSystemTickPeriod = 10;
static FLProgSystemHardwareTimerTickEvent flprogSystemTimerHandler = 0;

static uint32_t flprogSystemTimerPresetValue = 65375;
static uint16_t flprogSystemPrescaler = 1;

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private

void initFlprogSystemTimerParametrs();
bool privateSetFlprogSystemTimerTickPeriod(uint32_t period);

#endif
