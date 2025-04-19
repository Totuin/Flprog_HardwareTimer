#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_RP2040

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/irq.h"

#ifdef __GNUC__
#define VARIABLE_IS_NOT_USED __attribute__((unused))
#else
#define VARIABLE_IS_NOT_USED
#endif

typedef bool (*pico_timer_callback)(struct repeating_timer *t);
typedef void (*FLProgSystemHardwareTimerTickEvent)();
static struct repeating_timer VARIABLE_IS_NOT_USED FLProgSystemHardwareTimer;

static FLProgSystemHardwareTimerTickEvent VARIABLE_IS_NOT_USED flprogSystemTimerHandler = 0;
static uint32_t VARIABLE_IS_NOT_USED flprogSystemTickPeriod = 10;

// public
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

// private
void privateSetPeriod();

#endif