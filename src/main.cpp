#include <Arduino.h>
#include <Remote.h>
#include <Logger.h>
#include <Movers.h>
#include <Display.h>
#include <ScoreDisplay.h>
#include <Actuators.h>
<<<<<<< Updated upstream
#include <RemoteData.h>
#include <GlobalState.h>

//Display& display = Display::getInstance();
Movers& movers = Movers::getInstance();
Remote& remote = Remote::getInstance();
ScoreDisplay& scoreDisplay = ScoreDisplay::getInstance();
Actuators& actuators = Actuators::getInstance();
=======
#include <Movers.h>
#include <Arduino.h>
>>>>>>> Stashed changes

RemoteData remoteData;

bool remoteErrorShown = false;

void setup() {
  initLogger();
  //display.setup();

<<<<<<< Updated upstream
  info("Powered up");
=======
    info("Radio setup...");
    //Remote::setup();
>>>>>>> Stashed changes

  movers.setup();
  info("Movers setup");

<<<<<<< Updated upstream
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
=======
    info("Movers setup...");
    Movers::setup();

    info("Actuators setup in 2 seconds. Put the robot in its initial position.");
    delay(2000);
    Actuators::setup();
 
    info("Robot ready !");
}

void postRun() {
    DynamicStateController::getInstance().resetStates();
}

bool acquire() {
    remoteData = {
         {0, 0, false}, // joystickLeft
         {0, 0, false}, // joystickRight
         {false, false, false, false, false, false, false, false, false, false}, // buttons
         255, // slider
         0, // score
         MIDDLE // sw
    };
    GlobalState::remoteConnected->set(true);

    return true;
    //return Remote::fetch(remoteData);
}
>>>>>>> Stashed changes

  GlobalState::getInstance().remoteConnected.set(false);

<<<<<<< Updated upstream
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
=======
void heartbeat() {
    Timing::update();
    Movers::update();
    ScoreDisplay::update();
    Actuators::update();
}

void loop() {
    delay(LOOP_DELAY);
    if (acquire()) {
        process();
    }
    heartbeat();
    postRun();
>>>>>>> Stashed changes
}