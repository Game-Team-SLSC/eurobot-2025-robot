#include <Remote.h>

#include <Arduino.h>
#include <Logger.h>
#include <RF24.h>
#include <RobotSettings.h>
#include <printf.h>

const byte ADDRESS[6] = "912CR";

Remote& Remote::getInstance() {
    static Remote instance;
    return instance;
}

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

bool Remote::hasData() {
    return dataAvailable;
}

void Remote::fetch(RemoteData &buffer) {
    dataAvailable = false;
    
    radio.read(&buffer, sizeof(buffer));
}

void Remote::handleInterrupt() {
    lastTransmission = millis();
    dataAvailable = true;
}