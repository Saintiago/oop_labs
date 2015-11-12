/*
«авести енум дл€ кодов ошибок
ѕроверить в тестах зеркалирование каждого из разр€дов
*/

#include "stdafx.h"
#include "flipbyte_func.h"

int main(int argc, char* argv[])
{
	try
	{
		if (argc < 2)
		{
			throw Error::NoArguments;
		}
		int num = getNumber(argv[1]);
		cout << static_cast <int> (flip(num)) << endl;
	}
	catch (Error e)
	{
		char* message = "Unknown error";
		switch (e)
		{
			case Error::NotNumber: 
				message = "Not a number";
				break;
			case Error::NotByte:
				message = "Number must be 0..255";
				break;
			case Error::NoArguments:
				message = "Please, specify byte to flip.";
				break;
		}
		cout << message << endl;
		return 1;
	}
	
    return 0;
}

