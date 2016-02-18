#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

CDictionary::CDictionary()
{
}


CDictionary::~CDictionary()
{
}

size_t CDictionary::GetWordsCount() const
{
	return m_enRu.size();
}

void CDictionary::AddWord(const std::string & enWord, const std::string & ruWord)
{
	m_enRu.insert({ ToLower(enWord), ruWord });
}

void CDictionary::SaveDictionary(std::ostream & out) const
{
	bool first = true;
	for (auto & word : m_enRu)
	{
		if (!first)
		{
			out << endl;
		}
		out << word.first << endl << word.second;
		first = false;
	}
}

void CDictionary::LoadDictionary(istream & is)
{
	string ruWord, enWord;
	while (!is.eof() && !is.fail())
	{
		getline(is, enWord);
		getline(is, ruWord);
		AddWord(enWord, ruWord);
	}
}

string CDictionary::Translate(const string & source) const
{
	return m_enRu.at(ToLower(source));
}

bool CDictionary::IsWordPresent(const string & word) const
{
	return (m_enRu.find(ToLower(word)) != m_enRu.end());
}

string CDictionary::ToLower(const string & str) const
{
	string tmpStr = str;
	transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), ::tolower);;
	return tmpStr;
}