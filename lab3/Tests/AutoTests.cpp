#include "stdafx.h"
#include "../auto/Auto.h"

/*
Телевизор
изначально выключен
*/

struct AutoFixture
{
	CAuto car;
};
// Автомобиль
BOOST_FIXTURE_TEST_SUITE(Auto, AutoFixture)
// изначально стоит на месте на нейтральной передаче с выключенным двигателем
BOOST_AUTO_TEST_CASE(is_not_moving_in_neutral_gear_with_stopped_engine_by_default)
{
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK_EQUAL(car.GetGear(), CAuto::Gears::Neutral);
	BOOST_CHECK(!car.IsEngineOn());
}

BOOST_AUTO_TEST_SUITE_END()