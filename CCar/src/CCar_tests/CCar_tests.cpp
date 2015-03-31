#include "stdafx.h"
#include "../lab3.1_CCar/Car.h"

struct MyCarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, MyCarFixture)

BOOST_AUTO_TEST_CASE(TurnedOffByDefault)
{
	BOOST_CHECK(!car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnOn)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(CanBeTurnOff)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK(!car.IsTurnedOn());
}

BOOST_AUTO_TEST_CASE(NeutralGearByDefault)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
}

BOOST_AUTO_TEST_CASE(TurnOnEngineTwiceProduceFalse)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
}

BOOST_AUTO_TEST_CASE(TurnOffEngineTwiceProduceFalse)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.TurnOffEngine());
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
}

BOOST_AUTO_TEST_CASE(SetRearwardGear)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK_EQUAL(car.GetGear(), -1);	
}

BOOST_AUTO_TEST_CASE(CanRideBack)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(10));
}

BOOST_AUTO_TEST_CASE(CanRideBackStopAndTurnOff)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(-1));
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CanRideForward)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(10));
}

BOOST_AUTO_TEST_CASE(CanRideForwardStopAndTurnOff)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(car.SetGear(1));
	BOOST_CHECK(car.SetSpeed(10));
	BOOST_CHECK(car.SetGear(0));
	BOOST_CHECK(car.SetSpeed(0));
	BOOST_CHECK(car.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CantSetGearOutOfRange)
{
	BOOST_CHECK(car.TurnOnEngine());
	BOOST_CHECK(!car.SetGear(6));
}

BOOST_AUTO_TEST_CASE(GearRangeCheckWorks)
{
	car.TurnOnEngine();
	BOOST_CHECK(car.SetGear(-2) == false);
	BOOST_CHECK(car.SetGear(-1) != false);
	BOOST_CHECK(car.SetGear(1) != false);
	BOOST_CHECK(car.SetGear(6) == false);
}

BOOST_AUTO_TEST_CASE(CanSwitchOntoNeutralWhenOff)
{
	BOOST_CHECK(car.SetGear(0) == true);
	BOOST_CHECK_EQUAL(car.GetGear(), 0);

	BOOST_CHECK(car.SetGear(-1) != true);
	BOOST_CHECK_EQUAL(car.GetGear(), 0);

	BOOST_CHECK(car.SetGear(1) != true);
	BOOST_CHECK_EQUAL(car.GetGear(), 0);

	BOOST_CHECK(car.SetGear(5) != true);
	BOOST_CHECK_EQUAL(car.GetGear(), 0);
}
BOOST_AUTO_TEST_CASE(NeutralGearSlowdownOnly)
{
	car.TurnOnEngine();
	car.SetGear(1);
	car.SetSpeed(30);
	BOOST_CHECK(car.SetGear(0) == true);
	BOOST_CHECK(car.SetSpeed(31) == false);
	BOOST_CHECK(car.SetSpeed(30) != false);
	BOOST_CHECK(car.SetSpeed(29) == true);
}
BOOST_AUTO_TEST_CASE(NoForwardGearWhileMovingBackward)
{
	car.TurnOnEngine();
	car.SetGear(-1);
	car.SetSpeed(1);
	BOOST_CHECK(car.SetGear(0) == true);
	BOOST_CHECK(car.SetGear(1) == false);
}

BOOST_AUTO_TEST_SUITE_END()