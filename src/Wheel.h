
#ifndef _Wheel_h
#define _Wheel_h


#include <stdint.h>
#include "Motor.h"

class Wheel
{
    public:
        Wheel(Motor * motor);
        
        void setVelocityInMetersPerSecond(double velocity);
        void setStepsInOneMeter(uint32_t steps);

        double getDistanceInMeters();
        
        void resetDistance(){ _motor->resetSteps(); }
        void stop(){ _motor->stop(); }

    private:
        Motor * _motor;
        uint32_t _stepsInOneMeter;
};

#endif