#include "stdafx.h"
#include "../findtext/findtext_func.h"

BOOST_AUTO_TEST_SUITE(FindTextTests)

BOOST_AUTO_TEST_CASE(SearchStringTest)
{
	BOOST_CHECK_EQUAL(SearchString("C:\\PS\\my_oop\\oop_labs\\lab1\\Debug\\readme.txt", "SQL"), 34);
	BOOST_CHECK_EQUAL(SearchString("C:\\PS\\my_oop\\oop_labs\\lab1\\Debug\\empty.txt", ""), 0);
	BOOST_CHECK_EQUAL(SearchString("C:\\PS\\my_oop\\oop_labs\\lab1\\Debug\\text.txt", "third"), 3);
}
BOOST_AUTO_TEST_SUITE_END()