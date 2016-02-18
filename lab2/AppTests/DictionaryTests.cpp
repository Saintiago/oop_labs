#include "stdafx.h"
#include "../dictionary/Dictionary.h"

using namespace std;

struct Dictionary_
{
	stringstream ss;
	CDictionary dictionary;

	Dictionary_()
	{
		ss << "cat" << endl << "кошка" << endl << "dog" << endl << "собака";
		dictionary.LoadDictionary(ss);
	}
};

// Словарь
BOOST_FIXTURE_TEST_SUITE(Dictionary, Dictionary_)
	
	// Может быть сконструирован
	BOOST_AUTO_TEST_CASE(can_be_constructed)
	{
		BOOST_CHECK_NO_THROW(CDictionary dict);
	}

	// Может получить словарь из входящего потока
	BOOST_AUTO_TEST_CASE(can_get_dictionary_from_input_stream)
	{
		CDictionary dict;
		stringstream ss2;
		ss2 << "cat" << endl << "кошка" << endl << "dog" << endl << "собака";
		dict.LoadDictionary(ss2);
		BOOST_CHECK_EQUAL(dict.GetWordsCount(), 2);
	}

	// Может сохранить словарь в выходящий поток
	BOOST_AUTO_TEST_CASE(can_save_dictionary_in_output_stream)
	{
		string expectedString = "cat\nкошка\ndog\nсобака";
		stringstream output;
		dictionary.SaveDictionary(output);
		BOOST_CHECK_EQUAL(output.str(), expectedString);
	}

	// Может перевести слово
	BOOST_AUTO_TEST_CASE(can_translate_word)
	{
		string inputWord = "cat";
		string expectedOutput = "кошка";
		BOOST_CHECK_EQUAL(dictionary.Translate(inputWord), expectedOutput);
	}

	// Может проверить существует ли слово в словаре
	BOOST_AUTO_TEST_CASE(can_check_if_word_present_in_dictionary)
	{
		BOOST_CHECK(dictionary.IsWordPresent("dog"));
		BOOST_CHECK(!dictionary.IsWordPresent("fish"));
	}

	// Может перевести слово независимо от регистра
	BOOST_AUTO_TEST_CASE(can_translate_word_case_independent)
	{
		string inputWord = "CAt";
		string expectedOutput = "кошка";
		BOOST_CHECK_EQUAL(dictionary.Translate(inputWord), expectedOutput);
	}

BOOST_AUTO_TEST_SUITE_END()