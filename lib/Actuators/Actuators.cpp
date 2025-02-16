#include <Actuators.h>
#include <RobotSettings.h>
#include <Arduino.h>
#include <RobotState.h>
#include <Movement.h>
#include <Position.h>

// CONSTRUCTORS

// Actuators
Actuators::Actuators() : pwm(0x40) {
    positions = {};
    Movement movements[] = {};

    pumpEnabled = false;

    movements[MAGNET_ATTACH] = Movement(+[](bool state) {
        return Actuators::getInstance().setMagnets(state);
    });

    movements[ARM_DEPLOY] = Movement(+[](bool state) {
        return Actuators::getInstance().setArms(state);
    });

    movements[GRABBER_CATCH] = Movement(+[](bool state) {
        return Actuators::getInstance().setGrabbers(state);
    });

    movements[SUCTION_DEPLOY] = Movement(+[](bool state) {
        return Actuators::getInstance().setSuction(state);
    });

    movements[PUMP_ENABLE] = Movement(+[](bool state) {
        return Actuators::getInstance().setPumps(state);
    });

    movements[GRABBER_BLOCK_UP] = Movement(+[](bool state) {
        // TODO
    });

    movements[SUCTION_BLOCK_UP] = Movement(+[](bool state) {
        // TODO
    });

    positions[PositionName::FOLDED] = Position((MovementSet[]){
        {movements[ARM_DEPLOY], false},
        {movements[MAGNET_ATTACH], true},
        {movements[GRABBER_CATCH], false},
        {movements[SUCTION_DEPLOY], false},
        
        {movements[GRABBER_BLOCK_UP], false},
        {movements[SUCTION_BLOCK_UP], false},
        
        {movements[PUMP_ENABLE], false}
    });

    positions[PositionName::APPROACH] = Position((MovementSet[]){
        {movements[ARM_DEPLOY], true},
        {movements[MAGNET_ATTACH], false},
        {movements[GRABBER_CATCH], false},
        {movements[SUCTION_DEPLOY], false},
        
        {movements[GRABBER_BLOCK_UP], false},
        {movements[SUCTION_BLOCK_UP], false},
        
        {movements[PUMP_ENABLE], false}
    });

    positions[PositionName::TRANSPORT] = Position((MovementSet[]){
        {movements[ARM_DEPLOY], true},
        {movements[MAGNET_ATTACH], true},
        {movements[GRABBER_CATCH], true},
        {movements[SUCTION_DEPLOY], true},
        
        {movements[GRABBER_BLOCK_UP], false},
        {movements[SUCTION_BLOCK_UP], false},
        
        {movements[PUMP_ENABLE], false}
    });

    positions[PositionName::RELEASE] = Position((MovementSet[]){
        {movements[ARM_DEPLOY], true},
        {movements[MAGNET_ATTACH], false},
        {movements[GRABBER_CATCH], false},
        {movements[SUCTION_DEPLOY], false},
        
        //{movements[GRABBER_BLOCK_UP], false},
        //{movements[SUCTION_BLOCK_UP], false},
        
        {movements[PUMP_ENABLE], false}
    });

    positions[PositionName::LATERAL] = Position((MovementSet[]){
        {movements[ARM_DEPLOY], false},
        {movements[MAGNET_ATTACH], true},
        {movements[GRABBER_CATCH], true},
        {movements[SUCTION_DEPLOY], true},

        //{movements[GRABBER_BLOCK_UP], false},
        //{movements[SUCTION_BLOCK_UP], false},
        
        {movements[PUMP_ENABLE], true}
    });
    
    positions[PositionName::CATCH] = Position((MovementSet[]){
        //{movements[ARM_DEPLOY], true},
        //{movements[MAGNET_ATTACH], true},
        {movements[GRABBER_CATCH], true},
        //{movements[SUCTION_DEPLOY], true},

        //{movements[GRABBER_BLOCK_UP], false},
        //{movements[SUCTION_BLOCK_UP], false},

        //{movements[PUMP_ENABLE], false}
    });
    
    positions[PositionName::S1] = Position((MovementSet[]){
        //{movements[ARM_DEPLOY], false},
        //{movements[MAGNET_ATTACH], true},
        //{movements[GRABBER_CATCH], true},
        //{movements[SUCTION_DEPLOY], true},

        {movements[GRABBER_BLOCK_UP], false},
        {movements[SUCTION_BLOCK_UP], false},
        
        //{movements[PUMP_ENABLE], true}
    });

    positions[PositionName::S2] = Position((MovementSet[]){
        //{movements[ARM_DEPLOY], false},
        //{movements[MAGNET_ATTACH], true},
        //{movements[GRABBER_CATCH], true},
        //{movements[SUCTION_DEPLOY], true},

        {movements[GRABBER_BLOCK_UP], true},
        {movements[SUCTION_BLOCK_UP], true},
        
        //{movements[PUMP_ENABLE], true}
    });
}

Actuators& Actuators::getInstance() {
    static Actuators instance;
    return instance;
}
// UTILITY

short Actuators::getUSFromAngle(byte angle, boolean ccw = false) {
    return map(min(angle, 180), 0, 180, 1000, 2000) - (ccw ? 1000 : 0);
}


// PRIVATE

void Actuators::setup() {
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);

    

    pinMode(PUMP_RLY, OUTPUT);
}

void Actuators::setMagnets(bool attaching) {
    pwm.writeMicroseconds(
        Servos::GRB_MAGNET_LEFT,
        getUSFromAngle(attaching? GRB_MAGNET_ATTACH_ANGLE : GRB_MAGNET_RELEASE_ANGLE)
    );
    pwm.writeMicroseconds(
        Servos::GRB_MAGNET_RIGHT,
        getUSFromAngle(attaching? GRB_MAGNET_ATTACH_ANGLE : GRB_MAGNET_RELEASE_ANGLE, true)
    );
}

void Actuators::setArms(bool deployed) {
    pwm.writeMicroseconds(
        Servos::GRB_ARM_LEFT,
        getUSFromAngle(deployed? GRB_ARM_DEP_ANGLE : GRB_ARM_DEP_ANGLE)
    );
    pwm.writeMicroseconds(
        Servos::GRB_ARM_RIGHT,
        getUSFromAngle(deployed? GRB_ARM_DEP_ANGLE : GRB_ARM_DEP_ANGLE, true)
    );
}

void Actuators::setGrabbers(bool catching) {
    pwm.writeMicroseconds(
        Servos::GRB_LEFT,
        getUSFromAngle(catching? GRB_CLOSE_ANGLE : GRB_OPEN_ANGLE)
    );
    pwm.writeMicroseconds(
        Servos::GRB_RIGHT,
        getUSFromAngle(catching? GRB_CLOSE_ANGLE : GRB_OPEN_ANGLE, true)
    );
}

void Actuators::setSuction(bool deployed) {
    pwm.writeMicroseconds(
        Servos::SC_LEFT,
        getUSFromAngle(deployed? SC_DEP_ANGLE : SC_RET_ANGLE)
    );
    pwm.writeMicroseconds(
        Servos::SC_RIGHT,
        getUSFromAngle(deployed? SC_DEP_ANGLE : SC_RET_ANGLE, true)
    );
}

void Actuators::setPumps(bool enabled) {
    digitalWrite(PUMP_RLY, enabled? HIGH : LOW);
}

// PUBLIC
