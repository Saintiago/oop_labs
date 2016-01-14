#include "stdafx.h"

#include "../vector/VectorFunc.h"

// Вектор
BOOST_AUTO_TEST_SUITE(Vector)
	// может считывать числа из стандартного потока ввода
	BOOST_AUTO_TEST_CASE(can_read_number_from_standart_input_stream)
	{
		std::string vectorStr("1.3 2.8 5.0");
		std::vector<double> expectedVector = { 1.3, 2.8, 5.0 };
		std::vector<double> result = ReadVector(vectorStr);
		BOOST_CHECK_EQUAL_COLLECTIONS(result.begin(), result.end(),
			expectedVector.begin(), expectedVector.end());
	}
	// может прибавить к каждому элементу вектора среднее арифметическое его положительных элементов
	BOOST_AUTO_TEST_CASE(can_add_positive_average_to_all_items)
	{
		std::vector<double> inputVector = { 1.2, 2.8, -5 };
		std::vector<double> expectedVector = { 3.2, 4.8, -3 };
		ProcessVector(inputVector);
		BOOST_CHECK_EQUAL_COLLECTIONS(inputVector.begin(), inputVector.end(),
			expectedVector.begin(), expectedVector.end());
	}
	// может вывести список элементов в строку
	BOOST_AUTO_TEST_CASE(can_convert_its_items_to_string)
	{
		std::vector<double> inputVector = { 1.2, 2.8, -5 };
		BOOST_CHECK_EQUAL(GetVectorItems(inputVector), "1.2 2.8 -5 ");
	}

BOOST_AUTO_TEST_SUITE_END()