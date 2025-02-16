#include <Movers.h>
#include <Arduino.h>
#include <Sabertooth.h>
#include <SoftwareSerial.h>

SoftwareSerial sbrSerial(NOT_A_PIN, 10);

const float X_FACTOR_RATIO = X_MOVE_FACTOR/255;
const float Y_FACTOR_RATIO = Y_MOVE_FACTOR/255;
const float YAW_FACTOR_RATIO = YAW_FACTOR/255;

Movers::Movers() : saberFront(128, sbrSerial), saberBack(129, sbrSerial) {
    speedRatio = 1;
}

Movers& Movers::getInstance() {
    static Movers instance;
    return instance;
}

void Movers::setup() {
    sbrSerial.begin(9600);

    Sabertooth::autobaud(sbrSerial);
    saberFront.setTimeout(MOVERS_TIMEOUT);
    saberBack.setTimeout(MOVERS_TIMEOUT);
    saberFront.setRamping(MOVERS_RAMPING);
    saberBack.setRamping(MOVERS_RAMPING);
    saberFront.setDeadband(0);
    saberBack.setDeadband(0);
    
    // find right values
    // saberFront.setMaxVoltage(71);
    // saberBack.setMaxVoltage(71);
}

void Movers::drive(byte x, byte y, byte z) {
    if (x > 255 or x < 0) return;
    if (y > 255 or y < 0) return;
    if (z > 255 or z < 0) return;

    x = x * X_FACTOR_RATIO * speedRatio;
    y = y * Y_FACTOR_RATIO * speedRatio;
    z = z * YAW_FACTOR_RATIO * speedRatio;

    saberFront.motor(1, - x + y - z);   // FR
    saberFront.motor(2, - x - y - z);     // FL
    saberBack.motor(1, + x + y - z);      // BR
    saberBack.motor(2, + x - y + z);    // BL
}

void Movers::setSpeed(byte value) {
    speedRatio = value / 255;
}