#include <Arduino.h>
#include <RobotSettings.h>
#include <Display.h>

#ifndef __LOGGER_H__
#define __LOGGER_H__

void initLogger();
void info(String msg);
void warn(String msg);
void error(String msg);

#endif