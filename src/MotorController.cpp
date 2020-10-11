
#if defined(WIRING)
 #include <Wiring.h>
#elif ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <PID_v1.h>
#include "MotorController.h"

MotorController::MotorController(
            double * input, 
            double * output, 
            double * setpoint,
            double kp,
            double ki,
            double kd
            ){
    _setPoint = 0;
    _pid.SetMode(AUTOMATIC);
}

// void setup()
// {
//   //initialize the variables we're linked to
//   Input = analogRead(PIN_INPUT);
//   Setpoint = 100;

//   //turn the PID on
//   myPID.SetMode(AUTOMATIC);
// }

// void loop()
// {
//   Input = analogRead(PIN_INPUT);
//   myPID.Compute();
//   analogWrite(PIN_OUTPUT, Output);
// }