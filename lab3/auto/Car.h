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

	enum Direction
	{
		Backwards = -1,
		StandingStill = 0,
		Forward = 1
	};

	struct SpeedRange
	{
		unsigned int min, max;
	};

	unsigned int GetSpeed() const;
	Gear GetGear() const;
	bool IsEngineOn() const;
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
		{ Gear::Rear,{ 0, 20 } },
		{ Gear::Neutral,{ 0, m_maxSpeed } },
		{ Gear::First,{ 0, 30 } },
		{ Gear::Second,{ 20, 50 } },
		{ Gear::Third,{ 30, 60 } },
		{ Gear::Fourth,{ 40, 90 } },
		{ Gear::Fifth,{ 50, m_maxSpeed } }
	};
	Direction m_direction = Direction::StandingStill;

	bool CanShiftGearTo(Gear gear);
};

