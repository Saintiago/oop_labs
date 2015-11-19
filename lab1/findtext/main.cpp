// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "findtext_func.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			throw exception("Usage: search.exe <file-name> <search-string>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}
		int foundLine = SearchString(fin, argv[2]);

		if (foundLine == 0)
		{
			cout << "Text not found" << endl;
			return 1;
		}
		cout << "Text found at " << foundLine << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}
	
	return 0;
}