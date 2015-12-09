#include "stdafx.h"
#include "../auto/Auto.h"

/*
���������
���������� ��������
*/

struct AutoFixture
{
	CAuto car;
};
// ����������
BOOST_FIXTURE_TEST_SUITE(Auto, AutoFixture)
// ���������� ����� �� ����� �� ����������� �������� � ����������� ����������
BOOST_AUTO_TEST_CASE(is_not_moving_in_neutral_gear_with_stopped_engine_by_default)
{
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	BOOST_CHECK_EQUAL(car.GetGear(), CAuto::Gears::Neutral);
	BOOST_CHECK(!car.IsEngineOn());
}

BOOST_AUTO_TEST_SUITE_END()