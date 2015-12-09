#pragma once
#include <map>

class CCar
{
public:

	enum Gear
	{
		Rear = -1,
		Neutral = 0,
		First = 1,
		Second = 2,
		Third = 3,
		Fourth = 4,
		Fifth = 5
	};

	struct SpeedRange
	{
		unsigned int min, max;
	};

	unsigned int GetSpeed();
	Gear GetGear();
	bool IsEngineOn();
	bool StartEngine();
	bool SetSpeed(unsigned int speed);
	bool SetGear(Gear gear);

private:

	bool m_isEngineOn = false;
	unsigned int m_speed = 0;
	Gear m_gear = Gear::Neutral;
	const unsigned int m_maxSpeed = 150;
	std::map <Gear, SpeedRange> gearSpeedRange =
	{
		{ Rear,{ 0, 20 } },
		{ Neutral,{ 0, m_maxSpeed } },
		{ First,{ 0, 30 } },
		{ Second,{ 20, 50 } },
		{ Third,{ 30, 60 } },
		{ Fourth,{ 40, 90 } },
		{ Fifth,{ 50, m_maxSpeed } }
	};

	bool IsGearInRange(Gear gear);

};

