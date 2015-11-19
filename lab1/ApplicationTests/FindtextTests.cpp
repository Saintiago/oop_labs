#include "stdafx.h"
#include "../findtext/findtext_func.h"

BOOST_AUTO_TEST_SUITE(FindTextTests)

BOOST_AUTO_TEST_CASE(SearchStringTest)
{
	ifstream readme("..\\Debug\\readme.txt");
	BOOST_CHECK_EQUAL(SearchString(readme, "SQL"), 34);
	ifstream empty("..\\Debug\\empty.txt");
	BOOST_CHECK_EQUAL(SearchString(empty, ""), 0);
	ifstream text("..\\Debug\\text.txt");
	BOOST_CHECK_EQUAL(SearchString(text, "third"), 3);
}
BOOST_AUTO_TEST_SUITE_END()