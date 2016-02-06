#include "stdafx.h"
#include "../lab7/FindMaxFunc.cpp"

struct FindMax_
{
	std::vector<int> vectorOfInt = { 1, 2, 4, 90, 3, 0, -110 };
	std::vector<double> vectorOfDouble = { 0.13, -2.1, 98.99, -90, 3.14, 0.0, -110.87 };
	std::vector<std::string> vectorOfString = { "B", "C", "A" };
	std::vector<const char *> vectorOfCharString = { "ABC", "CBA", "BCA" };
	std::vector<const char *> emptyVectorOfCharString = {};
	std::vector<int> emptyVector = {};
	int maxIntValue;
	double maxDoubleValue;
	std::string maxStringValue;
	const char* maxCharStringValue;

	FindMax_()
	{
	}
};
// Функция FindMax
BOOST_FIXTURE_TEST_SUITE(FindMaxFunction, FindMax_)

	// возвращает true если найден максимум и false ели массив пустой
	BOOST_AUTO_TEST_CASE(returns_true_if_max_found_and_false_if_array_is_empty)
	{
		BOOST_CHECK(FindMax(vectorOfInt, maxIntValue));
		BOOST_CHECK(!FindMax(emptyVector, maxIntValue));
	}

	// сохраняет максимальное значение в переданную переменную
	BOOST_AUTO_TEST_CASE(save_max_value_in_given_variable)
	{
		FindMax(vectorOfInt, maxIntValue);
		BOOST_CHECK_EQUAL(maxIntValue, 90);
		FindMax(vectorOfDouble, maxDoubleValue);
		BOOST_CHECK_EQUAL(maxDoubleValue, 98.99);
		FindMax(vectorOfString, maxStringValue);
		BOOST_CHECK_EQUAL(maxStringValue, "C");
	}

	// не портит переменную если массив пустой
	BOOST_AUTO_TEST_CASE(dont_spoil_variable_if_array_is_empty)
	{
		maxIntValue = 10;
		FindMax(emptyVector, maxIntValue);
		BOOST_CHECK_EQUAL(maxIntValue, 10);
	}

	// находит максимум в массиве строк const char*
	BOOST_AUTO_TEST_CASE(finds_maximum_in_const_char_string_array)
	{
		BOOST_CHECK(FindMax(vectorOfCharString, maxCharStringValue));
		BOOST_CHECK(!FindMax(emptyVectorOfCharString, maxCharStringValue));
		BOOST_CHECK(maxCharStringValue == "CBA");
	}

BOOST_AUTO_TEST_SUITE_END()