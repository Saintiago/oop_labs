// dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

void workWithDictionary(CDictionary & dictionary, string & userInput, bool & newWordsAdded);
void initDictionary(CDictionary & dictionary, string & dictionaryFile, bool & newWordsAdded);
void saveDictionary(CDictionary & dictionary, string & dictionaryFile);

int main(int argc, char* argv[])
{
	try
	{
		bool newWordsAdded = true;
		CDictionary dictionary;
		string dictionaryFile = "input.txt";
		if (argc == 2)
		{
			dictionaryFile = argv[1];
			initDictionary(dictionary, dictionaryFile, newWordsAdded);
		}

		cout << "Enter word for translation." << endl;
		
		string userInput;
		do
		{
			getline(cin, userInput);
			if (userInput == "...")
			{
				continue;
			}
			workWithDictionary(dictionary, userInput, newWordsAdded);
		} 
		while (userInput != "...");

		if (newWordsAdded)
		{
			saveDictionary(dictionary, dictionaryFile);
		}
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}

void workWithDictionary(CDictionary & dictionary, string & userInput, bool & newWordsAdded)
{
	if (dictionary.IsWordPresent(userInput))
	{
		cout << dictionary.Translate(userInput) << endl;
	}
	else
	{
		string translation;
		cout << "New word! Enter translation:" << endl;
		getline(cin, translation);
		if (translation.length() > 0)
		{
			dictionary.AddWord(userInput, translation);
			cout << "\"" << userInput << "\"" << " saved as \"" << translation << "\"." << endl;
			newWordsAdded = true;
		}
		else
		{
			cout << "Ignoring " << "\"" << userInput << "\"." << endl;
		}
	}
}

void initDictionary(CDictionary & dictionary, string & dictionaryFile, bool & newWordsAdded)
{
	ifstream fin(dictionaryFile);
	if (fin.is_open())
	{
		cout << "Getting dictionary from " << dictionaryFile << "..." << endl;
		dictionary.LoadDictionary(fin);
		fin.close();
		newWordsAdded = false;
		cout << "Dictionary loaded. ";
	}
}

void saveDictionary(CDictionary & dictionary, string & dictionaryFile)
{
	string userInput;
	cout << "Save dictionary?" << endl;
	cin >> userInput;

	if (userInput == "y")
	{
		ofstream fout(dictionaryFile);
		if (!fout.is_open())
		{
			throw exception("Cannot open file.");
		}
		dictionary.SaveDictionary(fout);
	}
}