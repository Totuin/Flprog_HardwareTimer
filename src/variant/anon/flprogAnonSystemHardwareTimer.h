#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"


#ifdef RT_HW_CORE_STM32
#define FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON
#endif 

#ifdef RT_HW_CORE_RP2040
#define FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON
#endif 

#ifdef RT_HW_CORE_ESP8266
#define FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON
#endif 

#ifdef RT_HW_CORE_ESP32
#define FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON
#endif 


#ifdef RT_HW_CORE_AVR
#define FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON
#endif 

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT_FOR_ANON


typedef void (*FLProgSystemHardwareTimerTickEvent)();
void initFlprogSystemTimer(FLProgSystemHardwareTimerTickEvent func);
void setFlprogSystemTimerTickPeriod(uint32_t period);
uint32_t getFlprogSystemTimerTickPeriod();

#endif 