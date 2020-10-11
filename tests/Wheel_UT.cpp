#include "CppUTest/TestHarness.h"

extern "C"
{
	/*
	 * Add your c-only include files here
	 */
    #include "Wheel.h"
    #include "MockMotor.h"
}

TEST_GROUP(MyCode)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(MyCode, setVelocityInMetersPerSecond)
{
    MockMotor motor(5, 5);
    Wheel wheel(&motor);
    wheel.setVelocityInMetersPerSecond(10);
    double result = wheel.getDistanceInMeters();
    CHECK_EQUAL(0, result);
    motor.step(10);
    result = wheel.getDistanceInMeters();
    CHECK_EQUAL(0.01, result);
}

TEST(MyCode, resetDistance)
{
    MockMotor motor(5, 5);
    Wheel wheel(&motor);
    wheel.setVelocityInMetersPerSecond(10);
    motor.step(10);
    double result = wheel.getDistanceInMeters();
    CHECK_EQUAL(0.01, result);
    wheel.resetDistance();
    result = wheel.getDistanceInMeters();
    CHECK_EQUAL(0.0, result);
    wheel.stop();
}

TEST(MyCode, setStepsInOneMeter)
{
    MockMotor motor(5, 5);
    Wheel wheel(&motor);
    wheel.setVelocityInMetersPerSecond(10);
    wheel.setStepsInOneMeter(10);
    motor.step(10);
    double result = wheel.getDistanceInMeters();
    CHECK_EQUAL(1, result);
}

