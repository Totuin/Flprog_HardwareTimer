#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#ifdef RT_HW_CORE_AVR
#include "variant/avr/flprogAvrSystemHardwareTimer.h"
#define FLPROG_SYSTEM_TIMER_CORE_SELECT
#endif

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT
#ifdef RT_HW_CORE_STM32
#include "variant/stm32/flprogStm32SystemHardwareTimer.h"
#define FLPROG_SYSTEM_TIMER_CORE_SELECT
#endif
#endif

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT
#ifdef RT_HW_CORE_RP2040
#include "variant/rp2040/flprogRP2040SystemHardwareTimer.h"
#define FLPROG_SYSTEM_TIMER_CORE_SELECT
#endif
#endif

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT
#ifdef RT_HW_CORE_ESP8266
#include "variant/esp8266/flprogESP8266SystemHardwareTimer.h"
#define FLPROG_SYSTEM_TIMER_CORE_SELECT
#endif
#endif

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT
#ifdef RT_HW_CORE_ESP32
#include "variant/esp32/flprogESP32SystemHardwareTimer.h"
#define FLPROG_SYSTEM_TIMER_CORE_SELECT
#endif
#endif

#ifndef FLPROG_SYSTEM_TIMER_CORE_SELECT
#include "variant/anon/flprogAnonSystemHardwareTimer.h"
#endif