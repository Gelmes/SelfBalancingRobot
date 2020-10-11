#include "Wheel.h"

Wheel::Wheel(Motor * motor)
{
    _motor = motor;
}

void Wheel::setVelocityInMetersPerSecond(double velocity){
    _motor->setStepFrequency(velocity * _stepsInOneMeter);
}

void Wheel::setStepsInOneMeter(uint32_t steps){
    _stepsInOneMeter = steps;
}

double Wheel::getDistanceInMeters(){
    double steps = _motor->getAggregateSteps();
    double result = steps / _stepsInOneMeter;
    return result;
}