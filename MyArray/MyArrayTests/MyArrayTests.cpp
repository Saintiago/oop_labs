#include "stdafx.h"
#include "../MyArray/MyArray.h"

struct CMyArray_
{
	CMyArray<double> myDoubleArray;
	CMyArray_()
	{
		myDoubleArray.AppendItem(1.8);
		myDoubleArray.AppendItem(2.7);
		myDoubleArray.AppendItem(3.5);
		myDoubleArray.AppendItem(-4.3);
	}
};

// Массив
BOOST_FIXTURE_TEST_SUITE(MyArray, CMyArray_)

	// имеет возможность добавления элемента в конец массива
	BOOST_AUTO_TEST_CASE(can_append_new_item_to_itself)
	{
		myDoubleArray.AppendItem(5.5);
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 5);
	}

	// имеет возможность индексированного чтения
	BOOST_AUTO_TEST_CASE(can_read_element_by_index)
	{
		BOOST_CHECK_EQUAL(myDoubleArray[0], 1.8);
		BOOST_CHECK_EQUAL(myDoubleArray[3], -4.3);
		BOOST_CHECK_THROW(myDoubleArray[4], std::out_of_range);
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
		myDoubleArray.Resize(10);
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 10);
		BOOST_CHECK_EQUAL(myDoubleArray[9], double());
		BOOST_CHECK_THROW(myDoubleArray[10], std::out_of_range);
	}

	// можно уменьшить
	BOOST_AUTO_TEST_CASE(can_be_shrunk)
	{
		myDoubleArray.Resize(1);
		BOOST_CHECK_EQUAL(myDoubleArray.Size(), 1);
		BOOST_CHECK_EQUAL(myDoubleArray[0], 1.8);
		BOOST_CHECK_THROW(myDoubleArray[1], std::out_of_range);
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
		CMyArray<double> otherArray;
		otherArray = myDoubleArray;
		BOOST_CHECK_EQUAL(otherArray[0], 1.8);
		BOOST_CHECK_EQUAL(otherArray[3], -4.3);
		BOOST_CHECK_THROW(otherArray[4], std::out_of_range);
	}

BOOST_AUTO_TEST_SUITE_END()

