#include "stdafx.h"
#include "../auto/Car.h"

/*
���������
���������� ��������
*/

struct CarFixture
{
	CCar car;
};
// ����������
BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	// ���������� ����� �� ����� �� ����������� �������� � ����������� ����������
	BOOST_AUTO_TEST_CASE(is_not_moving_in_neutral_gear_with_stopped_engine_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		BOOST_CHECK_EQUAL(car.GetGear(), CCar::Gears::Neutral);
		BOOST_CHECK(!car.IsEngineOn());
	}

	// ����� ������� ���������
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
	// ����� ������ ���������
	BOOST_FIXTURE_TEST_SUITE(when_engine_started, when_engine_started_)
		
		// ����� �������� ��������
		BOOST_AUTO_TEST_CASE(can_change_speed)
		{
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()