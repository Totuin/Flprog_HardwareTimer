#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_ESP32

typedef void (*FLProgSystemHardwareTimerTickEvent)();
static FLProgSystemHardwareTimerTickEvent flprogSystemTimerHandler = 0;
static uint32_t flprogSystemTickPeriod = 10;
static hw_timer_t *FLProgSystemHardwareTimer = 0;
void IRAM_ATTR flprogSystemTimerOnTimer();

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
void privateSetPeriod();

#endif
