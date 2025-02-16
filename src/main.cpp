#include <Arduino.h>
#include <Remote.h>
#include <Logger.h>
#include <Movers.h>
#include <Display.h>
#include <ScoreDisplay.h>
#include <RemoteData.h>

Display& display = Display::getInstance();
Movers& movers = Movers::getInstance();
Remote& remote = Remote::getInstance();
ScoreDisplay& scoreDisplay = ScoreDisplay::getInstance();

RemoteData remoteData;

bool remoteErrorShown = false;

void setup() {
  Serial.begin(9600);

  display.setup();
  info("Powered up");

  movers.setup();
  info("Movers setup");

  remote.setup();
  info("Remote setup");

  scoreDisplay.setup();
  info("Score display setup");

  info("Setup complete");
}

void updateLibs() {
  scoreDisplay.updateBlink();
}

void processControllerUpdate() {
  if (!remote.hasData()) { return; };

  remote.fetch(remoteData);

  scoreDisplay.setScore(remoteData.score);

  movers.drive(
    remoteData.joystickRight.x,
    (remoteData.joystickLeft.y + remoteData.joystickRight.y) / 2,
    remoteData.joystickRight.x
  );
}

bool checkConnection() {
  if (millis() - remote.lastTransmission < 1000) {
    scoreDisplay.blinking = false;
    return false;
  }

  scoreDisplay.blinking = true;

  if (remoteErrorShown) return true;

  if (remote.lastTransmission == 0) {
    info("Connecting to remote...");
  } else {
    warn("Remote connection lost. Reconnecting...");
  }

  remoteErrorShown = true;

  return true;
}

void loop() {
  bool remoteConnected = checkConnection();
  if (remoteConnected) processControllerUpdate();
  updateLibs();

  delay(LOOP_DELAY);
}