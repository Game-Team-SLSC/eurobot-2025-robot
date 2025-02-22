#include <Arduino.h>
#include <Remote.h>
#include <Logger.h>
#include <Movers.h>
#include <Display.h>
#include <ScoreDisplay.h>
#include <Actuators.h>
#include <RemoteData.h>
#include <GlobalState.h>

//Display& display = Display::getInstance();
Movers& movers = Movers::getInstance();
Remote& remote = Remote::getInstance();
ScoreDisplay& scoreDisplay = ScoreDisplay::getInstance();
Actuators& actuators = Actuators::getInstance();

RemoteData remoteData;

bool remoteErrorShown = false;

void setup() {
  initLogger();
  //display.setup();

  info("Powered up");

  movers.setup();
  info("Movers setup");

  remote.setup();
  info("Remote setup");

  scoreDisplay.setup();
  info("Score display setup");

  actuators.setup();
  info("Actuators setup");

  actuators.setPosition(PositionName::FOLDED);

  info("Setup complete");
}

void updateLibs() {
  movers.update();
  scoreDisplay.update();
}

bool checkConnection() {
  if (millis() - remote.lastTransmission < RADIO_TIMEOUT) {
    remoteErrorShown = false;
    GlobalState::getInstance().remoteConnected.set(true);
    return false;
  }

  GlobalState::getInstance().remoteConnected.set(false);

  if (remoteErrorShown) return true;

  if (remote.lastTransmission == 0) {
    info("Connecting to remote...");
  } else {
    warn("Remote connection lost. Reconnecting...");
  }

  return true;
}

void loop() {
  checkConnection();
  if (remote.hasData()) {
    remote.fetch(remoteData);
    GlobalState::getInstance().updateFromController(remoteData);
  }
  updateLibs();

  delay(LOOP_DELAY);
}