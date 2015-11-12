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
			throw Error::InvalidArguments;
		}

		int foundLine = SearchString(argv[1], argv[2]);

		if (foundLine == 0)
		{
			cout << "Text not found" << endl;
			return 1;
		}
		cout << "Text found at " << foundLine << endl;
	}
	catch (Error e)
	{
		char* message = "Unknown error";
		switch (e)
		{
		case Error::InvalidArguments:
			message = "Please, specify file and string to find.";
			break;
		case Error::CantOpenFile:
			message = "Cannot open file.";
			break;
		}
		cout << message << endl;
		return 1;
	}
	
	return 0;
}