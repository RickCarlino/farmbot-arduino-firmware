

/*
 * F84Handler.cpp
 *
 *  Created on: 2014/07/21
 *      Author: MattLech
 */

#include "F84Handler.h"

static F84Handler *instance;

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

  if (LOGGING)
  {
    Serial.print("R99 Report server version\r\n");
  }

  Serial.print("R84 ");
  Serial.println("IF YOU GOT THIS FAR, CAL SETx SETy OR SETz");
  CurrentState::getInstance()->printQAndNewLine();

  return 0;
}
