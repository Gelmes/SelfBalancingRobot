#include "CppUTest/TestHarness.h"
#include <stdio.h>
extern "C"
{
    #include "MockMotor.h"
}

TEST_GROUP(MockMotor)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(MockMotor, BasicTest)
{
    MockMotor motor(5, 5);
    uint32_t result = motor.getTotalSteps();
    CHECK_EQUAL(0, result);
}

TEST(MockMotor, SteppingFunction)
{
    MockMotor motor(5, 5);
    motor.step(10);
    CHECK_EQUAL(10, motor.getTotalSteps());
    CHECK_EQUAL(10, motor.getAggregateSteps());
    CHECK_EQUAL(false, motor.isStopped());
    CHECK_EQUAL(true, motor.isMoving());
}

TEST(MockMotor, MotorDirection)
{
    MockMotor motor(5, 5);
    motor.step(10);
    motor.setDirection(MOTOR_BACKWARD);
    motor.step(10);
    CHECK_EQUAL(20, motor.getTotalSteps());
    CHECK_EQUAL(0, motor.getAggregateSteps());
    CHECK_EQUAL(false, motor.isStopped());
    CHECK_EQUAL(true, motor.isMoving());
}

TEST(MockMotor, setFrequency)
{
    MockMotor motor(5, 5);
    motor.setStepFrequency(120);
    CHECK_EQUAL(120, motor._stepFrequency);
    motor.setStepFrequency(420);
    CHECK_EQUAL(420, motor._stepFrequency);
}

TEST(MockMotor, resetSteps)
{
    MockMotor motor(5, 5);
    motor.step(10);
    CHECK_EQUAL(10, motor.getAggregateSteps());
    motor.step(10);
    CHECK_EQUAL(20, motor.getAggregateSteps());
    motor.resetSteps();
    CHECK_EQUAL(0, motor.getAggregateSteps());
    motor.stop();
}


