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
		vector<int> foundLines = SearchString(fin, argv[2]);

		if (foundLines.empty())
		{
			cout << "Text not found" << endl;
			return 1;
		}

		std::stringstream result;
		std::copy(foundLines.begin(), foundLines.end(), std::ostream_iterator<int>(result, ", "));
		cout << "Text found at " << result.str() << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}
	
	return 0;
}