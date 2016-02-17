#pragma once

class CDictionary
{
public:
	CDictionary();
	~CDictionary();

	size_t GetWordsCount();
	void AddWord(std::string enWord, std::string ruWord);
	void loadDictionary(std::istream & is);
	void saveDictionary(std::ostream & out);
	std::string translate(std::string source);
	bool IsWordPresent(std::string word);

private:
	std::map<std::string, std::string> enRu = {};

	void FillDictionary(std::istream & is);
};

