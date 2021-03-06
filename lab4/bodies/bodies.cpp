// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BodyConstructor.h"

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		std::cout << "Available commands:" << std::endl;
		std::cout << "  create <compound, cone, cylinder, parallelepiped, sphere> <params>:" << std::endl;
		std::cout << "    <params>:" << std::endl;
		std::cout << "      compound: <body_params_list>, i.e. compound sphere 10 6 parallelepiped 64 3 5 8" << std::endl;
		std::cout << "      cone: <density> <base_radius> <height>" << std::endl;
		std::cout << "      cylinder: <density> <base_radius> <height>" << std::endl;
		std::cout << "      parallelepiped: <density> <width> <height> <depth>" << std::endl;
		std::cout << "      sphere: <density> <radius>" << std::endl;
		std::cout << "  list - lists currently added bodies," << std::endl;
		std::cout << "  heaviest - shows info about body with max mass," << std::endl;
		std::cout << "  lightest - shows info about body with min weight in water," << std::endl;
		std::cout << "  exit - shuts down application." << std::endl;

		std::string command = "";
		CBodyConstructor constructor;
		bool waitForCommand = true;

		while (!std::cin.eof() && waitForCommand)
		{
			std::cout << std::endl << "Enter command: " << std::endl;
			waitForCommand = constructor.ProcessCommand(std::cin);
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}