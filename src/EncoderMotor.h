
#ifndef _Encoder_Motor_h
#define _Encoder_Motor_h

#include <stdint.h>
#include "Motor.h"
#include "Tone.h"

class EncoderMotor : public Motor
{
  public:
    EncoderMotor(uint8_t motorStepPin, uint8_t motorDirectionPin);
    
    void setDirection(Motor_Direction_t direction);
    void setStepFrequency(uint32_t stepFrequency, uint32_t limit = 0);

    uint32_t getTotalSteps();
    double getAggregateSteps();

    void resetSteps();
    void stop();

    bool isStopped();
    bool isMoving();

  private:

    void updateAggregateSteps();

    Tone _motor;
    uint8_t _pin;
    uint8_t _dirPin;
    uint32_t _prevSteps;
    double _aggregateSteps;
    Motor_Direction_t _direction;
};

#endif
