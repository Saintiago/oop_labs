#include "stdafx.h"
#include "../auto/Car.h"

/*
“елевизор
изначально выключен
*/

struct AutoFixture
{
	CCar car;
};
// јвтомобиль
BOOST_FIXTURE_TEST_SUITE(Car, AutoFixture)

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

BOOST_AUTO_TEST_SUITE_END()