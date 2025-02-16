#include <Display.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

Display::Display() : lcd(0x27, SDA, SCL) {}

Display& Display::getInstance() {
    static Display instance;
    return instance;
}

void Display::setup() {
    lcd.begin();
    lcd.backlight();
    lcd.autoscroll();
}

void Display::print(String msg) {
    lcd.println(msg);
} 
