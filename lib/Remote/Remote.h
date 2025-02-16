#ifndef __REMOTE_H__
#define __REMOTE_H__

#include <Arduino.h>
#include <RF24.h>
#include <RemoteData.h>

class Remote {
    public:
        static Remote& getInstance();

        void setup();
        bool hasData();
        void fetch(RemoteData& buffer);

        unsigned long lastTransmission;

        // Make singleton
        Remote(const Remote&) = delete;
        Remote& operator=(const Remote&) = delete;

    private:
        Remote();
        RF24 radio;
        bool dataAvailable;

        void handleInterrupt();
};

#endif