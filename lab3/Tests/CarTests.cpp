#include "stdafx.h"
#include "../auto/Car.h"

/*
���������
���������� ��������
*/

using Direction = CCar::Direction;
using Gear = CCar::Gear;

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
		BOOST_CHECK(car.GetGear() == Gear::Neutral);
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

		template <typename Fn>
		void ExpectActionFailure(Fn && action)
		{
			CCar clone(car);
			BOOST_CHECK_THROW(action(), std::exception);
			BOOST_REQUIRE_EQUAL(clone.IsEngineOn(), car.IsEngineOn());
			if (clone.IsEngineOn())
			{
				BOOST_CHECK(clone.GetDirection() == car.GetDirection());
				BOOST_CHECK(clone.GetGear() == car.GetGear());
				BOOST_CHECK(clone.GetSpeed() == car.GetSpeed());
			}
		}

		template <typename Fn>
		void ExpectActionSucceeds(Fn && action, bool expectEngineIsOn, CCar::Gear expectedGear, int expectedSpeed)
		{
			// �������, ��� �������� ���������� �������
			BOOST_REQUIRE_NO_THROW(action());
			BOOST_REQUIRE_EQUAL(car.IsEngineOn(), expectEngineIsOn);
			if (expectEngineIsOn)
			{
				BOOST_CHECK(car.GetGear() == expectedGear);
				BOOST_CHECK_EQUAL(car.GetSpeed(), expectedSpeed);
				auto expectedDirection =
					(expectedSpeed > 0) ? Direction::Forward :
					(expectedSpeed < 0) ? Direction::Backwards : 
					Direction::StandingStill;
				BOOST_CHECK(car.GetDirection() == expectedDirection);
			}
		}
	};

	// ����� ������ ���������
	BOOST_FIXTURE_TEST_SUITE(when_engine_started, when_engine_started_)
		
		// �� ����� ����������� �������� �� ���������
		BOOST_AUTO_TEST_CASE(cant_accelerate_in_neutral_gear)
		{
			ExpectActionFailure([=] { car.SetSpeed(10); });
		}

		// ����� �������� ������������ ��������
		BOOST_AUTO_TEST_CASE(can_shift_gear)
		{
			ExpectActionSucceeds([=] {
				car.SetGear(Gear::First); 
			}, true, Gear::First, 0);
		}

		// ����� ������� �������� ������ � �������� �� ���������� ���������
		BOOST_AUTO_TEST_CASE(can_shift_gear_only_when_in_corresponding_speed_range)
		{
			BOOST_CHECK(!car.SetGear(Gear::Second)); // TODO: ���������, ��� �������� �� ���������
			BOOST_CHECK(car.SetGear(Gear::First));
			car.SetSpeed(19);
			BOOST_CHECK(!car.SetGear(Gear::Second));
			car.SetSpeed(20);
			BOOST_CHECK(car.SetGear(Gear::Second));
			car.SetSpeed(50);
			BOOST_CHECK(car.SetGear(Gear::Second));
			BOOST_CHECK(car.GetGear() == Gear::Second);

			car.SetSpeed(30);
			BOOST_CHECK(!car.SetGear(Gear::Fifth));
			car.SetSpeed(49);
			BOOST_CHECK(!car.SetGear(Gear::Fifth));
			car.SetSpeed(50);
			BOOST_CHECK(car.SetGear(Gear::Fifth));
			car.SetSpeed(150);
			BOOST_CHECK(car.SetGear(Gear::Fifth));
			BOOST_CHECK(car.GetGear() == Gear::Fifth);
		}

		// ����� ������ �������� ������ � �������� ��������
		BOOST_AUTO_TEST_CASE(can_accelerate_only_in_gear_range)
		{
			car.SetGear(Gear::First);
			BOOST_CHECK_NO_THROW(car.SetSpeed(0));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
			BOOST_CHECK_NO_THROW(car.SetSpeed(15));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 15);
			BOOST_CHECK_NO_THROW(car.SetSpeed(30));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 30);
			BOOST_CHECK_THROW(car.SetSpeed(31), std::exception);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 30);

			car.SetGear(Gear::Third);
			BOOST_CHECK_NO_THROW(car.SetSpeed(50));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 50);

			car.SetGear(Gear::Fifth);
			BOOST_CHECK_THROW(car.SetSpeed(49), std::exception);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 50);
			BOOST_CHECK_NO_THROW(car.SetSpeed(150));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 150);
			BOOST_CHECK_THROW(car.SetSpeed(151), std::exception);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 150);
		}

		// ����������� �������� � ������� ���� �� ������ � �������� ������ ��� ������� ��������
		BOOST_AUTO_TEST_CASE(shifts_gear_from_rear_to_first_and_vice_versa_only_while_standing_still )
		{
			car.SetGear(Gear::Rear);
			car.SetSpeed(-20);
			BOOST_CHECK(!car.SetGear(Gear::First));
			BOOST_CHECK(car.GetGear() == Gear::Rear);
			car.SetSpeed(0);
			BOOST_CHECK(car.SetGear(Gear::First));
			BOOST_CHECK(car.GetGear() == Gear::First);

			car.SetGear(Gear::First);
			car.SetSpeed(20);
			BOOST_CHECK(!car.SetGear(Gear::Rear));
			BOOST_CHECK(car.GetGear() == Gear::First);
			car.SetSpeed(0);
			BOOST_CHECK(car.SetGear(Gear::Rear));
			BOOST_CHECK(car.GetGear() == Gear::Rear);
		}

		// �������������� �� ��������� � ������� ���� ����� ������������ 
		// �� ������ ������ ��� ������� ��������
		BOOST_AUTO_TEST_CASE(can_shift_to_first_from_neutral_after_rear_only_while_standing_still)
		{
			car.SetGear(Gear::Rear);
			car.SetSpeed(-10);
			car.SetGear(Gear::Neutral);
			BOOST_CHECK(!car.SetGear(Gear::First));
			BOOST_CHECK(car.GetGear() == Gear::Neutral);
			
			car.SetSpeed(0);
			BOOST_CHECK(car.SetGear(Gear::First));
			BOOST_CHECK(car.GetGear() == Gear::First);
		}

		// �������������� �� ��������� � ������ �������� ����� ������������ 
		// �� ������ ������ ��� ������� ��������
		BOOST_AUTO_TEST_CASE(can_shift_to_neutral_from_first_after_rear_only_while_standing_still)
		{
			car.SetGear(Gear::First);
			car.SetSpeed(10);
			car.SetGear(Gear::Neutral);
			BOOST_CHECK(!car.SetGear(Gear::Rear));
			BOOST_CHECK(car.GetGear() == Gear::Neutral);

			car.SetSpeed(0);
			BOOST_CHECK(car.SetGear(Gear::Rear));
			BOOST_CHECK(car.GetGear() == Gear::Rear);
		}

		// ����� ���������� ��������� ������ ��� ������� �������� �� ����������� ��������
		BOOST_AUTO_TEST_CASE(can_stop_engine_only_in_neutral_while_standing_still)
		{
			car.SetGear(Gear::First);
			car.SetSpeed(10);
			BOOST_CHECK(!car.StopEngine());
			BOOST_CHECK(car.IsEngineOn());
			car.SetSpeed(0);
			BOOST_CHECK(!car.StopEngine());
			BOOST_CHECK(car.IsEngineOn());
			car.SetGear(Gear::Neutral);
			BOOST_CHECK(car.StopEngine());
			BOOST_CHECK(!car.IsEngineOn());
		}

	BOOST_AUTO_TEST_SUITE_END()

	// ��� ����������� ��������� ����� ����������� �������� ������ �� �����������
	BOOST_AUTO_TEST_CASE(can_stop_engine_only_in_neutral_while_standing_still)
	{
		BOOST_CHECK(!car.SetGear(Gear::First));
		BOOST_CHECK(car.GetGear() == Gear::Neutral);
		BOOST_CHECK(car.SetGear(Gear::Neutral));
		BOOST_CHECK(car.GetGear() == Gear::Neutral);
	}

BOOST_AUTO_TEST_SUITE_END()