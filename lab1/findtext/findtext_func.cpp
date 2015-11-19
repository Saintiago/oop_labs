#include "stdafx.h"
#include "findtext_func.h"

vector<int> SearchString(ifstream & fin, const string search)
{
	string lineOfText;
	int lineCount = 0;
	vector<int> found;
	while (getline(fin, lineOfText))
	{
		lineCount++;
		if (lineOfText.find(search) != string::npos)
		{
			found.push_back(lineCount);
		}
	}

	return found;
}