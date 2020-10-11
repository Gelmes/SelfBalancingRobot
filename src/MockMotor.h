
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
    double getAggregateSteps();

    void resetSteps();
    void stop();

    bool isStopped();
    bool isMoving();

    bool step(uint32_t steps);

  // private:

    void updateAggregateSteps();
    uint32_t _steps;
    uint8_t _pin;
    uint8_t _dirPin;

    uint32_t _prevSteps;
    double _aggregateSteps;
    uint32_t _stepFrequency;
    uint32_t _stepLimit;
    uint32_t _prevStepSize;
    Motor_Direction_t _direction;
};

#endif
