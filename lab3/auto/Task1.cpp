// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Driver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		std::string command = "";

		CDriver driver;

		while (command != "exit")
		{
			std::cout << std::endl << "Here we go. What do you want to do with your car?" << std::endl;
			std::getline(std::cin, command);
			driver.ProcessCommand(command);
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}

