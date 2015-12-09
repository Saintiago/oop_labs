#include "stdafx.h"
#include "Car.h"

unsigned int CCar::GetSpeed()
{
	return m_speed;
}

CCar::Gear CCar::GetGear()
{
	return m_gear;
}

bool CCar::IsEngineOn()
{
	return m_isEngineOn;
}

bool CCar::StartEngine()
{
	m_isEngineOn = true;
	return true;
}

bool CCar::SetSpeed(unsigned int speed)
{
	if (GetGear() == Gear::Neutral && speed > m_speed)
	{
		return false;
	}
	m_speed = speed;
	return true;
}

bool CCar::SetGear(Gear gear)
{
	m_gear = gear;
	return true;
}