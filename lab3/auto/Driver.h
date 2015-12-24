#include "stdafx.h"
#include "Car.h"

#pragma once
class CDriver
{
public:

	enum Command
	{
		InfoCommand, EngineOnCommand, EngineOffCommand, SetGearCommand, SetSpeedCommand, Exit
	};

	CDriver();
	~CDriver();
	
	void ProcessCommand(std::string command);

private:
	void Info();
	void EngineOn();
	void EngineOff();
	void SetGear(int gear);
	void SetSpeed(int speed);

	void ShowEngineState();
	void ShowDirectionState();
	void ShowGearState();
	void ShowSpeedState();

	bool IsGearCorrect(int gear);

	std::map <Command, std::string> m_commands;
	std::map <CCar::Gear, std::string> m_gear_string;
	std::map <CCar::Direction, std::string> m_direction_string;
	CCar car;

};

