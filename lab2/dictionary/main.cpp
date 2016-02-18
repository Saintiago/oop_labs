// dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

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
			ifstream fin(dictionaryFile);
			if (fin.is_open())
			{
				cout << "Getting dictionary from " << argv[1] << "..." << endl;
				dictionary.LoadDictionary(fin);
				fin.close();
				newWordsAdded = false;
				cout << "Dictionary loaded. ";
			}
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
		while (userInput != "...");

		if (newWordsAdded)
		{
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
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}