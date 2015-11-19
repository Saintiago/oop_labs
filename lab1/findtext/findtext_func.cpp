#include "stdafx.h"
#include "findtext_func.h"

int SearchString(ifstream & fin, const string search)
{
	string lineOfText;
	int lineCount = 0;
	int found = 0;
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