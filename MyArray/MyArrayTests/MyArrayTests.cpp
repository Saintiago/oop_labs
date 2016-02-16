#include "stdafx.h"
#include "../MyArray/MyArray.h"

struct CMyArray_
{
	CMyArray<double> myDoubleArray;
	CMyArray_()
	{
	}
};

// Массив
BOOST_FIXTURE_TEST_SUITE(MyArray, CMyArray_)

	// может быть сконструирован
	BOOST_AUTO_TEST_CASE(can_be_constructed)
	{
		size_t initialSize = 1;
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), initialSize);
	}

	// имеет возможность добавления элемента в конец массива
	BOOST_AUTO_TEST_CASE(can_append_new_item_to_itself)
	{
		myDoubleArray.AppendItem(5.5);
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 2);
	}

	// имеет возможность индексированного чтения
	BOOST_AUTO_TEST_CASE(can_read_element_by_index)
	{
		myDoubleArray.AppendItem(-4.3);
		BOOST_CHECK_EQUAL(myDoubleArray[0], 0.0);
		BOOST_CHECK_EQUAL(myDoubleArray[1], -4.3);
		BOOST_CHECK_THROW(myDoubleArray[2], std::out_of_range);
	}

	// имеет возможность индексированной записи
	BOOST_AUTO_TEST_CASE(can_write_element_by_index)
	{
		myDoubleArray[0] = 20;
		BOOST_CHECK_EQUAL(myDoubleArray[0], 20);
		BOOST_CHECK_THROW(myDoubleArray[4] = 100, std::out_of_range);
	}

	// можно увеличить
	BOOST_AUTO_TEST_CASE(can_be_enlarged)
	{
		myDoubleArray[0] = 0.3;
		myDoubleArray.AppendItem(1.3);
		myDoubleArray.AppendItem(2.3);
		myDoubleArray.Resize(10);
		BOOST_CHECK_EQUAL(myDoubleArray[0], 0.3);
		BOOST_CHECK_EQUAL(myDoubleArray[1], 1.3);
		BOOST_CHECK_EQUAL(myDoubleArray[2], 2.3);
		BOOST_CHECK_EQUAL(myDoubleArray[9], double());
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 10);
		BOOST_CHECK_THROW(myDoubleArray[10], std::out_of_range);
	}

	// можно уменьшить
	BOOST_AUTO_TEST_CASE(can_be_shrunk)
	{
		myDoubleArray[0] = 0.3;
		myDoubleArray.AppendItem(1.3);
		myDoubleArray.AppendItem(2.3);
		myDoubleArray.Resize(1);
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 1);
		BOOST_CHECK_EQUAL(myDoubleArray[0], 0.3);
		BOOST_CHECK_THROW(myDoubleArray[1], std::out_of_range);
		BOOST_CHECK_THROW(myDoubleArray[2], std::out_of_range);
	}

	// можно очистить
	BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		myDoubleArray.Clear();
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 0);
	}

	// @TODO можно присвоить другому массиву
	BOOST_AUTO_TEST_CASE(can_be_assigned_to_other_array)
	{
		myDoubleArray[0] = 0.3;
		myDoubleArray.AppendItem(1.3);
		myDoubleArray.AppendItem(2.3);
		CMyArray<double> otherArray;
		otherArray = myDoubleArray;
		BOOST_CHECK_EQUAL(otherArray[0], 0.3);
		BOOST_CHECK_EQUAL(otherArray[1], 1.3);
		BOOST_CHECK_EQUAL(otherArray[2], 2.3);
		BOOST_CHECK_THROW(otherArray[3], std::out_of_range);
	}

BOOST_AUTO_TEST_SUITE_END()

