#include <Remote.h>

<<<<<<< Updated upstream
#include <Arduino.h>
#include <Logger.h>
#include <RF24.h>
#include <RobotSettings.h>
#include <printf.h>

const byte ADDRESS[6] = "912CR";
=======
>>>>>>> Stashed changes

RF24 Remote::radio(RF_CE, RF_CS);
BaseTimer* Remote::timeoutTimer(nullptr);

Remote::Remote(): radio(RF_CE, RF_CS) {
    lastTransmission = 0;
    dataAvailable = false;
}

void Remote::setup() {
    radio.begin();
    printf_begin();

    pinMode(RF_IRQ, INPUT);

    radio.enableAckPayload();
    radio.maskIRQ(1, 1, 0);
    radio.setPALevel(RF24_PA_LOW);
    radio.setDataRate(RF24_250KBPS);
    radio.setChannel(110);
    radio.openReadingPipe(1, ADDRESS);
    radio.startListening();
    
    attachInterrupt(digitalPinToInterrupt(RF_IRQ), [](){Remote::getInstance().handleInterrupt();}, FALLING);

    #ifdef INFO_STATE
        radio.printDetails();
    #endif
}

<<<<<<< Updated upstream
bool Remote::hasData() {
    return dataAvailable;
}
=======
/*
@returns Weither the data was available
async
*/
bool Remote::fetch(RemoteData& dataBuffer) {
    if (!radio.available()) {
        if (timeoutTimer == nullptr) {
            timeoutTimer = Timing::in(RF_TIMEOUT, +[](void* selfPtr) {
                Remote* self = static_cast<Remote*>(selfPtr);
                self->timeoutTimer = nullptr;
                GlobalState::remoteConnected->set(false);
            GlobalState::remoteConnected->set(false);
        }, nullptr);
    }
>>>>>>> Stashed changes

void Remote::fetch(RemoteData &buffer) {
    dataAvailable = false;
    
    radio.read(&buffer, sizeof(buffer));
}

void Remote::handleInterrupt() {
    lastTransmission = millis();
    dataAvailable = true;
}