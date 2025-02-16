#ifndef __ROBOT_SETTINGS_H__
#define __ROBOT_SETTINGS_H__

// WARNING : A TOO LOW VALUE MAY BLOCK PROGRAM TRANSFER (AVRDUDE: stk500_getsync() attempt 10 of 10: not in sync: resp=0x00)
// values between 50 and 200 are recommended. Increasing the value will diminish the responsiveness of the robot.

#define LOOP_DELAY 50

// SERIAL OUTPUT

#define ERROR_STATE true;
#define WARN_STATE true;
#define INFO_STATE true;

// RF24

#define RF_CE 48
#define RF_CS 49
#define RF_MISO 50
#define RF_MOSI 51
#define RF_SCK 52
#define RF_IRQ 2

// STEPPERS

#define GRB_STEP 34
#define GRB_DIR 36
#define GRB_SERIAL Serial2

#define SC_STEP 38
#define SC_DIR 40
#define SC_SERIAL Serial3

// SCORE

#define BLINK_INTERVAL 500
#define DEFAULT_SCORE 70
#define SCORE_DP_DIO 26
#define SCORE_DP_CLK 27

// MOVERS

#define MOVERS_RAMPING 45
#define MOVERS_TIMEOUT 1000

#define YAW_FACTOR 100
#define X_MOVE_FACTOR 255
#define Y_MOVE_FACTOR 255

#define SBR 10

// SERVOS

enum Servos {
    GRB_LEFT,
    GRB_RIGHT,
    GRB_MAGNET_LEFT,
    GRB_MAGNET_RIGHT,
    GRB_ARM_LEFT,
    GRB_ARM_RIGHT,
    SC_LEFT,
    SC_RIGHT,
    BANNER
};

#define GRB_OPEN_ANGLE 0
#define GRB_CLOSE_ANGLE 180

#define GRB_MAGNET_ATTACH_ANGLE 0
#define GRB_MAGNET_RELEASE_ANGLE 180

#define GRB_ARM_DEP_ANGLE 0
#define GRB_ARM_RET_ANGLE 0

#define SC_DEP_ANGLE 0
#define SC_RET_ANGLE 0

#define BANNER_DEP_ANGLE 0
#define BANNER_RET_ANGLE 0

// BUTTONS CONFIG

enum Buttons {
    // auto
    GAME_START_AUTO,
    STACK_2_AUTO,
    STACK_3_AUTO,

    // manual
    APPROACH,
    TRANSPORT,
    RELEASE,
    LATERAL_W_PUMP,
    CATCH,

    STAGE_1,
    STAGE_2,
};

// MISC

#define STATUS_LED 13

#define PUMP_RLY 32

#endif