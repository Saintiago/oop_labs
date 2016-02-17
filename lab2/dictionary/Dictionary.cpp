#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

CDictionary::CDictionary()
{
}


CDictionary::~CDictionary()
{
}

void CDictionary::FillDictionary(std::istream & is)
{
	string ruWord, enWord;
	while (!is.eof())
	{
		getline(is, enWord);
		getline(is, ruWord);
		AddWord(enWord, ruWord);
	}
}

size_t CDictionary::GetWordsCount()
{
	return enRu.size();
}

void CDictionary::AddWord(std::string enWord, std::string ruWord)
{
	enRu.insert({ enWord, ruWord });
}

void CDictionary::saveDictionary(std::ostream & out)
{
	bool first = true;
	for (auto & word : enRu)
	{
		if (!first)
		{
			out << endl;
		}
		out << word.first << endl << word.second;
		first = false;
	}
}

void CDictionary::loadDictionary(istream & is)
{
	FillDictionary(is);
}

string CDictionary::translate(string source)
{
	return enRu[source];
}

bool CDictionary::IsWordPresent(std::string word)
{
	return (enRu.find(word) != enRu.end());
}