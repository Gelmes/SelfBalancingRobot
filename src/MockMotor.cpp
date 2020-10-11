#include "MockMotor.h"

MockMotor::MockMotor(uint8_t motorStepPin, uint8_t motorDirectionPin){
    _pin = motorStepPin;
    _dirPin = motorDirectionPin;
    _steps = 0;

    _prevSteps = 0;
    _aggregateSteps = 0;
    _stepFrequency = 100;
    _stepLimit = 0;
    _prevStepSize = 0;
    _direction = MOTOR_FORWARD;
}

void MockMotor::setDirection(Motor_Direction_t direction){
    updateAggregateSteps();
    _direction = direction;
}

void MockMotor::setStepFrequency(uint32_t stepFrequency, uint32_t limit){
    _stepLimit = limit;
    _stepFrequency = stepFrequency;
}

uint32_t MockMotor::getTotalSteps(){
    updateAggregateSteps();
    return _steps;
}

double MockMotor::getAggregateSteps(){
    updateAggregateSteps();
    return _aggregateSteps;
}

void MockMotor::resetSteps(){
    _aggregateSteps = 0;
}

void MockMotor::stop(){
    return;
}

bool MockMotor::isStopped(){
    return _prevSteps == _steps;
}

bool MockMotor::isMoving(){
    return _prevSteps != _steps;
}

bool MockMotor::step(uint32_t steps){
    _prevSteps = _steps;
    _steps += steps;
    _prevStepSize = steps;
    return true;
}

void MockMotor::updateAggregateSteps(){
    switch (_direction){
        case MOTOR_FORWARD:
            _aggregateSteps += _prevStepSize;
            break;
        case MOTOR_BACKWARD:
            _aggregateSteps -= _prevStepSize;
            break;
        default: break;
    }
    _prevStepSize = 0;

}
