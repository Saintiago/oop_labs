/*
Завести енум для кодов ошибок
Проверить в тестах зеркалирование каждого из разрядов
Исправитть именование функций
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
		int num = GetNumber(argv[1]);
		cout << static_cast <int> (Flip(num)) << endl;
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

