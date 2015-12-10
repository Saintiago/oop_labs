#include "stdafx.h"
#include "Car.h"

unsigned int CCar::GetSpeed() const
{
	return m_speed;
}

CCar::Gear CCar::GetGear() const
{
	return m_gear;
}

bool CCar::IsEngineOn() const
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

	if (m_speed == 0)
	{
		m_direction = Direction::StandingStill;
	}

	return true;
}

bool CCar::SetGear(Gear gear)
{
	if (!CanShiftGearTo(gear))
	{
		return false;
	}
	m_gear = gear;

	if (m_gear < Gear::Neutral)
	{
		m_direction = Direction::Backwards;
	}
	else if (m_gear > Gear::Neutral)
	{
		m_direction = Direction::Forward;
	}

	return true;
}

bool CCar::CanShiftGearTo(Gear gear)
{
	if (gear == m_gear || gear == Gear::Neutral)
	{
		return true;
	}

	return (!(gear < Gear::Neutral && m_direction == Direction::Forward)
		&& !(gear > Gear::Neutral && m_direction == Direction::Backwards)
		&& m_speed >= gearSpeedRange[gear].min
		&& m_speed <= gearSpeedRange[gear].max);
}