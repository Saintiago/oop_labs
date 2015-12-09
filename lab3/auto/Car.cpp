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
	if (!CanShiftGearTo(gear))
	{
		return false;
	}
	m_gear = gear;
	return true;
}

bool CCar::CanShiftGearTo(Gear gear)
{
	if (gear == m_gear || gear == Gear::Neutral)
	{
		m_gear = gear;
		return true;
	}

	return (!(m_gear == Gear::Rear && m_speed > 0)
		&& m_speed >= gearSpeedRange[gear].min
		&& m_speed <= gearSpeedRange[gear].max);
}