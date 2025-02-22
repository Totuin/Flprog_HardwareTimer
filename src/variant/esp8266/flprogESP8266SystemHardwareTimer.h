#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_ESP8266

#define FLPROG_SYSTEM_TIMER_TIM_DIV1_CLOCK (80000000UL) // 80000000 / 1   = 80.0  MHz
#define FLPROG_SYSTEM_TIMER_TIM_DIV16_CLOCK (5000000UL) // 80000000 / 16  = 5.0   MHz
#define FLPROG_SYSTEM_TIMER_TIM_DIV256_CLOCK (312500UL) // 80000000 / 256 = 312.5 KHz

typedef void (*FLProgSystemHardwareTimerTickEvent)();

static FLProgSystemHardwareTimerTickEvent flprogSystemTimerHandler = 0;
static uint32_t flprogSystemTickPeriod = 10;
static uint32_t flprogSystemTimerTimClockFreq = FLPROG_SYSTEM_TIMER_TIM_DIV1_CLOCK;

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
bool privateSetPeriod(uint32_t period);

#endif
