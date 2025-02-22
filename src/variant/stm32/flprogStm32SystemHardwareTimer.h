#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_STM32

#include <HardwareTimer.h>

static callback_function_t flprogSystemTimerHandler = 0;
static uint32_t flprogSystemTickPeriod = 10;
static uint32_t flprogSystemTimerPresetValue = 10;
static uint32_t flprogSystemTimerOneMicrosPrescaler;
static uint16_t flprogSystemPrescaler = 1;

static HardwareTimer FLProgSystemHardwareTimer(TIM2);

// public
void initFlprogSystemTimer(callback_function_t func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
void initFlprogSystemTimerParametrs();
bool privateSetFlprogSystemTimerTickPeriod(uint32_t period);

#endif