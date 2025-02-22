#include <Logger.h>
#include <Arduino.h>
#include <RobotSettings.h>
#include <Display.h>

const String LOG_TAG = "[INFO] : ";
const String WARN_TAG = "[WARN] : ";
const String ERROR_TAG = "[ERROR] : ";

void initLogger() {
    Serial.begin(9600);
}

void info(String msg) {
    Serial.println(LOG_TAG + msg);
}

void warn(String msg) {
    Serial.println(WARN_TAG + msg);
}

void error(String msg) {
    Serial.println(ERROR_TAG + msg);
}