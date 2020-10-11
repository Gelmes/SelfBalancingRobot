
#ifndef _Robot_h
#define _Robot_h

#include <stdint.h>
#include "Sensor.h"

class Robot
{
  public:
    Robot();

  private:
    Sensor * sensor;
};

#endif
