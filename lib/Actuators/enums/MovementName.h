#pragma once

enum MovementName {
    PUMP_ENABLE,
    PUMP_DISABLE,

    MAGNET_ATTACH,
    MAGNET_DETACH,

    ARM_DEPLOY,
    ARM_RETRACT,

    GRABBER_CATCH,
    GRABBER_RELEASE,

    SUCTION_DEPLOY,
    SUCTION_RETRACT,

    GRABBER_BLOCK_UP,
    GRABBER_BLOCK_DOWN,

    SUCTION_BLOCK_APPLY,
    SUCTION_BLOCK_UP,
    SUCTION_BLOCK_DOWN,

    BANNER_RELEASE,
    BANNER_CATCH,
    
    __MOV_COUNT
};