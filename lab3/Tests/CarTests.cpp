#include "stdafx.h"
#include "../auto/Car.h"

/*
Телевизор
изначально выключен
*/

struct CarFixture
{
	CCar car;
};
// Автомобиль
BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	// изначально стоит на месте на нейтральной передаче с выключенным двигателем
	BOOST_AUTO_TEST_CASE(is_not_moving_in_neutral_gear_with_stopped_engine_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		BOOST_CHECK_EQUAL(car.GetGear(), CCar::Gears::Neutral);
		BOOST_CHECK(!car.IsEngineOn());
	}

	// может завести двигатель
	BOOST_AUTO_TEST_CASE(can_start_engine)
	{
		BOOST_CHECK(car.StartEngine());
		BOOST_CHECK(car.IsEngineOn());
	}

	struct when_engine_started_ : CarFixture
	{
		when_engine_started_()
		{
			car.StartEngine();
		}
	};
	// после старта двигателя
	BOOST_FIXTURE_TEST_SUITE(when_engine_started, when_engine_started_)
		
		// может изменить скорость
		BOOST_AUTO_TEST_CASE(can_change_speed)
		{
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()