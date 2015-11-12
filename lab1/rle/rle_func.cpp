#include "stdafx.h"
#include "rle_func.h"

/*string Pack(ifstream in, ofstream out)
{
	char curSym = 0;
	unsigned int charCount = 0;
	stringstream result;
	for (unsigned int i = 0; i < input.length(); i++)
	{
		char sym = input[i];

		if (i == 0)
		{
			curSym = sym;
		}

		if (sym == curSym)
		{
			charCount++;
		}
		else
		{
			result << (int)charCount << curSym;
			curSym = sym;
			charCount = 1;
		}

		if (i == input.length() - 1)
		{
			result << charCount << curSym;
		}
	}
	return result.str();
}*/