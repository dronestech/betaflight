#include "platform.h"
#ifdef USE_WATCHDOGS
#include "common/maths.h"
#include "pg/pg.h"
#include "pg/pg_ids.h"
#include "fc/fc_core.h"
#include "io/serial.h"
#include "io/debugserial.h"
#include "watchdogs/watchdogs.h"

PG_REGISTER_WITH_RESET_TEMPLATE(watchdogsConfig_t, watchdogsConfig, PG_WATCHDOGS_CONFIG, 0);
PG_RESET_TEMPLATE(watchdogsConfig_t, watchdogsConfig,
    .enabled_watchdogs = 0,
    .maxRoll = 10,
    .maxPitch = 10
);

void watchdogsHandleAttitude(float roll, float pitch, float yaw)
{
    UNUSED(yaw);
    roll = ABS(roll);
    pitch = ABS(pitch);
    if (((watchdogsConfig()->enabled_watchdogs & WATCHDOG_ROLL) && roll >= watchdogsConfig()->maxRoll) ||
            ((watchdogsConfig()->enabled_watchdogs & WATCHDOG_PITCH) && pitch >= watchdogsConfig()->maxPitch))
    {
        disarm();
    }
}

#endif //USE_WATCHDOGS