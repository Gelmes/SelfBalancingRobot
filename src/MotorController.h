#ifndef _Motor_Controller_h
#define _Motor_Controller_h


class MotorController
{
    public:
     MotorController(
            double * input, 
            double * output, 
            double * setpoint,
            double kp,
            double ki,
            double kd
    );

    void setAcceleration(double acceleration);
    void setVelocity(double velocity);
    void setTargetDistance(double distance);

    void move(double targetDistance);
    
    void resetDistance();
    
    double getDistance();

    private:
        double * _input;
        double * _output;
        double * _setPoint;
        double kp;
        double ki;
        double kd;

        double acceleration;
        double targetDistance;
        double distance;

        PID _pid{
            _input,
            _output,
            _setPoint,
            kp,
            ki,
            kd,
            DIRECT
        };
};


#endif