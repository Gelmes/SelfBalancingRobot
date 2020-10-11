
#ifndef _Mock_Motor_h
#define _Mock_Motor_h

#include <stdint.h>
#include "Motor.h"

class MockMotor : public Motor
{
  public:
    MockMotor(uint8_t motorStepPin, uint8_t motorDirectionPin);
    
    void setDirection(Motor_Direction_t direction);
    void setStepFrequency(uint32_t stepFrequency, uint32_t limit = 0);

    uint32_t getTotalSteps();
    uint32_t getAggregateSteps();

    void resetSteps();
    void stop();

    bool isStopped();
    bool isMoving();

  private:

    void updateAggregateSteps();

    uint8_t _pin;
    uint8_t _dirPin;
    uint32_t _prevSteps;
    uint32_t _aggregateSteps;
    uint32_t _stepFrequency;
    uint32_t _steps;
    Motor_Direction_t _direction;
};

#endif
