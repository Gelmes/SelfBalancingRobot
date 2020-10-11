#if defined(WIRING)
 #include <Wiring.h>
#elif ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include "EncoderMotor.h"

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

EncoderMotor::EncoderMotor(uint8_t motorStepPin, uint8_t motorDirectionPin) :
    Motor(){
    _pin = motorStepPin;
    _dirPin = motorDirectionPin;
    _prevSteps = 0;
    _aggregateSteps = 0;
    _direction = MOTOR_FORWARD;
    _motor.begin(_pin);
}

void EncoderMotor::setDirection(Motor_Direction_t direction){
    updateAggregateSteps();
    _direction = direction;
}

void EncoderMotor::setStepFrequency(uint32_t stepFrequency, uint32_t limit){
    uint32_t time = limit * 1000 / stepFrequency;
    switch (_direction){
        case MOTOR_FORWARD:
            digitalWrite(_dirPin, HIGH);
            _motor.play(stepFrequency, time);
            break;
        case MOTOR_BACKWARD:
            digitalWrite(_dirPin, LOW);
            _motor.play(stepFrequency, time);
            break;
        default: break;
    }
}

uint32_t EncoderMotor::getTotalSteps(){
    return _motor.getEpochTicks();
}

double EncoderMotor::getAggregateSteps(){
    updateAggregateSteps();
    return _aggregateSteps;
}

void EncoderMotor::resetSteps(){
    _aggregateSteps = 0;
}

void EncoderMotor::stop(){
    _motor.stop();
}

bool EncoderMotor::isStopped(){
    return !_motor.isPlaying();
}

bool EncoderMotor::isMoving(){
    return _motor.isPlaying();
}

void EncoderMotor::updateAggregateSteps(){

    uint32_t totalSteps = getTotalSteps();
    uint32_t steps = totalSteps - _prevSteps;
    _prevSteps = totalSteps;

    switch (_direction){
        case MOTOR_FORWARD:
            _aggregateSteps += steps;
            break;
        case MOTOR_BACKWARD:
            _aggregateSteps -= steps;
            break;
        default: break;
    }
}
