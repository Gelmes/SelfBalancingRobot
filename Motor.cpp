#if defined(WIRING)
 #include <Wiring.h>
#elif ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include "Motor.h"

#if defined(__AVR_ATmega8__)
#define TCCR2A TCCR2
#define TCCR2B TCCR2
#define COM2A1 COM21
#define COM2A0 COM20
#define OCR2A OCR2
#define TIMSK2 TIMSK
#define OCIE2A OCIE2
#define TIMER2_COMPA_vect TIMER2_COMP_vect
#define TIMSK1 TIMSK
#endif

void Motor::begin(uint8_t motorStepPin, uint8_t motorDirectionPin){
    _pin = motorStepPin;
    _dirPin = motorDirectionPin;
    _motor.begin(_pin);
}

void Motor::move(uint32_t tickFrequency, Motor_Direction_t direction){
    switch (direction){
        case MOTOR_FORWARD:
            digitalWrite(_dirPin, HIGH);
            _motor.play(tickFrequency);
            break;
        case MOTOR_BACKWARD:
            digitalWrite(_dirPin, LOW);
            _motor.play(tickFrequency);
            break;
    }
    _prevTicks = _motor.getEpochTicks();
}

void Motor::stop(){
    _motor.stop();
}

uint32_t Motor::getTotalTicks(){
    return _motor.getEpochTicks();
}

uint32_t Motor::getTicksSinceLastMove(){
    return _motor.getEpochTicks() -  _prevTicks;
}


bool Motor::isStopped(){
    return !_motor.isPlaying();
}

bool Motor::isMoving(){
    return _motor.isPlaying();
}