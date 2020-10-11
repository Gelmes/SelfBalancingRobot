
#ifndef _Motor_h
#define _Motor_h

#include <stdint.h>
#include "Tone.h"

typedef enum eMotor_Direction{
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} Motor_Direction_t;

class Motor
{
  public:
    void begin(uint8_t motorStepPin, uint8_t motorDirectionPin);
    void move(uint32_t tickFrequency, Motor_Direction_t direction);
    void stop();
    uint32_t getTotalTicks();
    uint32_t getTicksSinceLastMove();
    bool isStopped();
    bool isMoving();

  private:
    Tone _motor;
    uint8_t _pin;
    uint8_t _dirPin;
    uint32_t _prevTicks;
};

#endif
