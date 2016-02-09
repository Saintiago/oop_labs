#include "stdafx.h"
#include "../lab7/FindMaxExFunc.cpp"

struct FindMaxEx_
{
	std::function<bool(Athlete, Athlete)> lessWeight = [](Athlete athleteL, Athlete athleteR) {
		return (athleteL.weight < athleteR.weight);
	};

	std::function<bool(Athlete, Athlete)> lessHeight = [](Athlete athleteL, Athlete athleteR) {
		return (athleteL.height < athleteR.height);
	};

	Athlete Tiger { "Tiger Woods", 185, 85 };
	Athlete Anastasiya { "Anastasiya Sharapova", 188, 59 };
	Athlete Pete { "Pete Sampras", 185, 84 };
	Athlete Svetlana { "Svetlana Khorkina", 165, 47 };
	Athlete Fedor { "Fedor Emelyanenko", 182, 107 };

	std::vector<Athlete> Athletes = { Tiger, Anastasiya, Pete, Svetlana, Fedor };
	std::vector<Athlete> EmptyAthletes = {};
	Athlete maxAthlete;

	FindMaxEx_()
	{
	}
};
// Функция FindMaxEx
BOOST_FIXTURE_TEST_SUITE(FindMaxExFunction, FindMaxEx_)

	// возвращает true если найден максимум и false ели массив пустой
	BOOST_AUTO_TEST_CASE(returns_true_if_max_found_and_false_if_array_is_empty)
	{
		BOOST_CHECK(FindMaxEx(Athletes, maxAthlete, lessWeight));
		BOOST_CHECK(!FindMaxEx(EmptyAthletes, maxAthlete, lessWeight));
	}

	// сохраняет максимальное значение в переданную переменную
	BOOST_AUTO_TEST_CASE(save_max_value_in_given_variable)
	{
		FindMaxEx(Athletes, maxAthlete, lessWeight);
		BOOST_CHECK(maxAthlete == Fedor);
		FindMaxEx(Athletes, maxAthlete, lessHeight);
		BOOST_CHECK(maxAthlete == Anastasiya);
	}

	// не портит переменную если массив пустой
	BOOST_AUTO_TEST_CASE(dont_spoil_variable_if_array_is_empty)
	{
		maxAthlete = Svetlana;
		FindMaxEx(EmptyAthletes, maxAthlete, lessHeight);
		BOOST_CHECK(maxAthlete == Svetlana);
	}

BOOST_AUTO_TEST_SUITE_END()