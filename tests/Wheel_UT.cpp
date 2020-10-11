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

TEST(MyCode, test1)
{
    MockMotor motor(5, 5);
    Wheel wheel(&motor);
}

