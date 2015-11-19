#include "stdafx.h"
#include "../findtext/findtext_func.h"

BOOST_AUTO_TEST_SUITE(FindTextTests)

BOOST_AUTO_TEST_CASE(SearchStringTest)
{
	ifstream readme("..\\Debug\\readme.txt");
	vector<int> readmeExpect = { 2, 4, 6, 22 };
	vector<int> readmeActual = SearchString(readme, "Server2Go");
	BOOST_CHECK_EQUAL_COLLECTIONS(readmeActual.begin(), readmeActual.end(), readmeExpect.begin(), readmeExpect.end());

	ifstream empty("..\\Debug\\empty.txt");
	vector<int> emptyExpect = {};
	vector<int> emptyActual = SearchString(empty, "");
	BOOST_CHECK_EQUAL_COLLECTIONS(emptyActual.begin(), emptyActual.end(), emptyExpect.begin(), emptyExpect.end());

	ifstream text("..\\Debug\\text.txt");
	vector<int> textExpect = { 3 };
	vector<int> textActual = SearchString(text, "third");
	BOOST_CHECK_EQUAL_COLLECTIONS(textActual.begin(), textActual.end(), textExpect.begin(), textExpect.end());
}

BOOST_AUTO_TEST_SUITE_END()