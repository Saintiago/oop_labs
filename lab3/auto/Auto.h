#pragma once

class CAuto
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

	unsigned int GetSpeed();
	Gears GetGear();
	bool IsEngineOn();

private:

};

