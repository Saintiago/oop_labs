// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Please, specify file and string to find.";
		return 1;
	}

	string fileName = argv[1];
	string search = argv[2];
	string lineOfText;
	int lineCount = 0;
	bool somethingFound = false;

	ifstream fin(fileName);

	if (!fin.is_open())
	{
		cout << "Cannot open file " << fileName << endl;
		return 1;
	}

	while (getline(fin, lineOfText))
	{
		lineCount++;
		if (lineOfText.find(search) != string::npos)
		{
			somethingFound = true;
			cout << search << " found at " << lineCount << endl;
		}
	}

	if (!somethingFound)
	{
		cout << "Text not found" << endl;
		return 1;
	}

	return 0;
}