
#ifndef _Sensor_h
#define _Sensor_h

#include <stdint.h>

class Sensor
{
  public:
    Sensor(){};
    virtual ~Sensor(){};
    
    virtual void getValue() = 0;

  private:

};

#endif
