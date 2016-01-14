#include "stdafx.h"
#include "Driver.h"

CDriver::CDriver()
{
	m_commands = 
	{
		{ Command::InfoCommand, "info" },
		{ Command::EngineOnCommand, "engineon" },
		{ Command::EngineOffCommand, "engineoff" },
		{ Command::SetGearCommand, "setgear" },
		{ Command::SetSpeedCommand, "setspeed" },
		{ Command::Exit, "exit" }
	};
	m_direction_string =
	{
		{ CCar::Direction::Backwards, "moving backwards" },
		{ CCar::Direction::Forward, "moving forward" },
		{ CCar::Direction::StandingStill, "standing still" }
	};
	m_gear_string =
	{
		{ CCar::Gear::Rear, "rear" },
		{ CCar::Gear::Neutral, "neutral" },
		{ CCar::Gear::First, "first" },
		{ CCar::Gear::Second, "second" },
		{ CCar::Gear::Third, "third" },
		{ CCar::Gear::Fourth, "fourth" },
		{ CCar::Gear::Fifth, "fifth" }
	};
}


CDriver::~CDriver()
{
}


void CDriver::Info()
{
	ShowEngineState();
	ShowDirectionState();
	ShowGearState();
	ShowSpeedState();
}

void CDriver::ShowEngineState()
{
	std::cout << "Engine is ";
	if (car.IsEngineOn())
	{
		std::cout << "started";
	}
	else
	{
		std::cout << "stopped";
	}
	std::cout << "." << std::endl;
}
void CDriver::ShowDirectionState()
{
	std::cout << "Car is " << m_direction_string[car.GetDirection()] << "." << std::endl;
}
void CDriver::ShowGearState()
{
	std::cout << "Car is in " << m_gear_string[car.GetGear()] << " gear." << std::endl;
}
void CDriver::ShowSpeedState()
{
	std::cout << "Car is moving " << car.GetSpeed() << " mph." << std::endl;
}

void CDriver::EngineOn()
{
	if (car.StartEngine())
	{
		std::cout << "Wrrroooom-wrooom!" << std::endl;
	}
	else
	{
		std::cout << "Already started." << std::endl;
	}
}

void CDriver::EngineOff()
{
	if (car.StopEngine())
	{
		std::cout << "Enjoy the silence!" << std::endl;
	}
	else
	{
		std::cout << "Can't stop now." << std::endl;
	}
}


void CDriver::SetGear(int gear)
{
	if (!IsGearCorrect(gear))
	{
		std::cout << "You'll break gear lever like that." << std::endl;
	}
	else if (car.SetGear(static_cast<CCar::Gear>(gear)))
	{
		std::cout << "Done!" << std::endl;
	}
	else
	{
		std::cout << "Can't do that." << std::endl;
	}
}

bool CDriver::IsGearCorrect(int gear)
{
	int minGear = static_cast<int> (CCar::Gear::Rear);
	int maxGear = static_cast<int> (CCar::Gear::Fifth);
	return (gear >= minGear && gear <= maxGear);
}

void CDriver::SetSpeed(int speed)
{
	try
	{
		car.SetSpeed(speed);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}


void CDriver::ProcessCommand(std::string rawCommand)
{
	std::transform(rawCommand.begin(), rawCommand.end(), rawCommand.begin(), ::tolower);
	std::stringstream ss;
	std::string command = "";
	int parsedArg = 0;
	ss << rawCommand;
	ss >> command >> parsedArg;
	if (command == m_commands[Command::InfoCommand])
	{
		Info();
	}
	else if (command == m_commands[Command::EngineOnCommand])
	{
		EngineOn();
	}
	else if (command == m_commands[Command::EngineOffCommand])
	{
		EngineOff();
	}
	else if (command == m_commands[Command::SetGearCommand])
	{
		SetGear(parsedArg);
	}
	else if (command == m_commands[Command::SetSpeedCommand])
	{
		SetSpeed(parsedArg);
	}
	else if (command == m_commands[Command::Exit])
	{
		std::cout << "Bye!" << std::endl;
	}
	else
	{
		std::cout << "Command not implemented." << std::endl;
	}
}
