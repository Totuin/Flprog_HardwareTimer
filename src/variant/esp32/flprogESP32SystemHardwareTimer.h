#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_ESP32

#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

typedef void (*FLProgSystemHardwareTimerTickEvent)();
static FLProgSystemHardwareTimerTickEvent VARIABLE_IS_NOT_USED flprogSystemTimerHandler = 0;
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTickPeriod = 10;
static hw_timer_t VARIABLE_IS_NOT_USED *FLProgSystemHardwareTimer = 0;
void IRAM_ATTR flprogSystemTimerOnTimer();

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
void privateSetPeriod();

#endif
