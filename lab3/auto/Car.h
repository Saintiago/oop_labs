#pragma once
#include <map>

class CCar
{
public:

	enum class Gear
	{
		Rear = -1,
		Neutral = 0,
		First = 1,
		Second = 2,
		Third = 3,
		Fourth = 4,
		Fifth = 5
	};

	enum class Direction
	{
		Backwards = -1,
		StandingStill = 0,
		Forward = 1
	};

	struct SpeedRange
	{
		int min, max;
	};

	static const int maxSpeed;
	static const std::map <Gear, SpeedRange> gearSpeedRange;

	int GetSpeed() const;
	Gear GetGear() const;
	Direction GetDirection() const;
	bool IsEngineOn() const;
	bool StartEngine();
	bool StopEngine();
	void SetSpeed(int speed);
	bool SetGear(Gear gear);

private:

	bool m_isEngineOn = false;
	int m_speed = 0;
	Gear m_gear = Gear::Neutral;
	bool CanShiftGearTo(Gear gear);
};

