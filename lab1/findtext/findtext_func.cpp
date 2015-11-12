#include "stdafx.h"
#include "findtext_func.h"

int SearchString(string fileName, string search)
{
	string lineOfText;
	int lineCount = 0;
	int found = 0;

	ifstream fin(fileName);

	if (!fin.is_open())
	{
		throw Error::CantOpenFile;
	}

	while (getline(fin, lineOfText))
	{
		lineCount++;
		if (lineOfText.find(search) != string::npos)
		{
			found = lineCount;
		}
	}

	return found;
}