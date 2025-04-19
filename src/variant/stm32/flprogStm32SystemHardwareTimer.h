#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_STM32

#include <HardwareTimer.h>

#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

static callback_function_t VARIABLE_IS_NOT_USED flprogSystemTimerHandler = 0;
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTickPeriod = 10;
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTimerPresetValue = 10;
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTimerOneMicrosPrescaler;
static uint16_t VARIABLE_IS_NOT_USED flprogSystemPrescaler = 1;

static HardwareTimer VARIABLE_IS_NOT_USED FLProgSystemHardwareTimer(TIM2);

// public
void initFlprogSystemTimer(callback_function_t func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
void initFlprogSystemTimerParametrs();
bool privateSetFlprogSystemTimerTickPeriod(uint32_t period);

#endif