#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_AVR

#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__ ((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

typedef void (*FLProgSystemHardwareTimerTickEvent)();
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTickPeriod;

static FLProgSystemHardwareTimerTickEvent VARIABLE_IS_NOT_USED flprogSystemTimerHandler = 0;

static uint32_t VARIABLE_IS_NOT_USED flprogSystemTimerPresetValue = 65375;
static uint16_t  VARIABLE_IS_NOT_USED flprogSystemPrescaler = 1;

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private

void initFlprogSystemTimerParametrs();
bool privateSetFlprogSystemTimerTickPeriod(uint32_t period);

#endif
