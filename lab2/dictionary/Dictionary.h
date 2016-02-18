#pragma once

class CDictionary
{
public:
	CDictionary();
	~CDictionary();

	size_t GetWordsCount() const;
	void AddWord(const std::string & enWord, const std::string & ruWord);
	void LoadDictionary(std::istream & is);
	void SaveDictionary(std::ostream & out) const;
	std::string Translate(const std::string & source) const;
	bool IsWordPresent(const std::string & word) const;

private:
	std::map<std::string, std::string> m_enRu = {};

	std::string ToLower(const std::string & str) const;
};

