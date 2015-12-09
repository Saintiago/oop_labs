#pragma once

class CCar
{
public:

	enum Gears
	{
		Rear = -1,
		Neutral = 0,
		First = 1,
		Second = 2,
		Third = 3,
		Fourth = 4,
		Fifth = 5
	};

	static const unsigned int maxSpeed = 150;

	unsigned int GetSpeed();
	Gears GetGear();
	bool IsEngineOn();
	bool StartEngine();
	bool SetSpeed(unsigned int speed);

private:

	bool m_isEngineOn = false;
	unsigned int m_speed = 0;
};

