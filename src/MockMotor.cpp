#include "MockMotor.h"

MockMotor::MockMotor(uint8_t motorStepPin, uint8_t motorDirectionPin){
    _pin = motorStepPin;
    _dirPin = motorDirectionPin;
}

void MockMotor::setDirection(Motor_Direction_t direction){
    updateAggregateSteps();
    _direction = direction;
}

void MockMotor::setStepFrequency(uint32_t stepFrequency, uint32_t limit){
    _steps = limit;
    switch (_direction){
        case MOTOR_FORWARD:
            _stepFrequency = stepFrequency;
            break;
        case MOTOR_BACKWARD:
            _stepFrequency = -1 * stepFrequency;
            break;
        default: break;
    }
}

uint32_t MockMotor::getTotalSteps(){
    return _steps;
}

uint32_t MockMotor::getAggregateSteps(){
    return _aggregateSteps;
}

void MockMotor::resetSteps(){
    _aggregateSteps = 0;
}

void MockMotor::stop(){
    return;
}

bool MockMotor::isStopped(){
    return false;
}

bool MockMotor::isMoving(){
    return true;
}

void MockMotor::updateAggregateSteps(){

}
