#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    WATCHDOG_NONE = 0x00,
    WATCHDOG_ROLL = 0x01,
    WATCHDOG_PITCH = 0x02,
} watchdogs_e;

typedef struct watchdogsConfig_d {
    uint8_t enabled_watchdogs;
    uint8_t maxRoll;
    uint8_t maxPitch;
} watchdogsConfig_t;

PG_DECLARE(watchdogsConfig_t, watchdogsConfig);

void watchdogsHandleAttitude(float roll, float pitch, float yaw);