/*
 * F84Handler.cpp
 *
 *  Created on: 2017/04/13
 *      Author: Rick Carlino
 */

#include "F84Handler.h"

static F84Handler *instance;
const long DO_RESET = 1;

F84Handler *F84Handler::getInstance()
{
  if (!instance)
  {
    instance = new F84Handler();
  };
  return instance;
};

F84Handler::F84Handler()
{
}

int F84Handler::execute(Command *command)
{

  if (ParameterList::getInstance()->getValue(command->getX()) == DO_RESET)
  {
    // I ended up here via "F84 X0"
    Serial.println("R84 Will zero X");
    CurrentState::getInstance()->setX(0);
  }
  else
  {
    // I ended up here via "F84 X0"
    Serial.println("R84 Will *NOT* zero X");
  }
  CurrentState::getInstance()->printQAndNewLine();
  return 0;
}
