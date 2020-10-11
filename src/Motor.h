
#ifndef _Motor_h
#define _Motor_h

#include <stdint.h>

typedef enum eMotor_Direction{
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} Motor_Direction_t;

class Motor
{
  public:
    Motor(){};
    virtual ~Motor(){};
    
    virtual void setDirection(Motor_Direction_t direction) = 0;
    virtual void setStepFrequency(uint32_t stepFrequency, uint32_t limit = 0) = 0;
    virtual uint32_t getTotalSteps() = 0;
    virtual uint32_t getAggregateSteps() = 0;
    virtual void resetSteps() = 0;
    virtual void stop() = 0;
    virtual bool isStopped()= 0;
    virtual bool isMoving() = 0;

  private:

    uint32_t _aggregateSteps;
    Motor_Direction_t _direction;
};

#endif
