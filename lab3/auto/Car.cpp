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

CCar::Direction CCar::GetDirection() const
{
	return m_direction;
}

bool CCar::IsEngineOn() const
{
	return m_isEngineOn;
}

bool CCar::StartEngine()
{
	if (!m_isEngineOn)
	{
		m_isEngineOn = true;
		return true;
	}
	return false;
}

bool CCar::StopEngine()
{
	if (m_isEngineOn && m_direction == Direction::StandingStill && m_gear == Gear::Neutral)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(unsigned int speed)
{
	if (GetGear() == Gear::Neutral && speed > m_speed)
	{
		return false;
	}

	if (speed < gearSpeedRange[m_gear].min || speed > gearSpeedRange[m_gear].max)
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
	if (!m_isEngineOn && gear != Gear::Neutral)
	{
		return false;
	}

	if (gear == m_gear || gear == Gear::Neutral)
	{
		return true;
	}

	return (!(gear < Gear::Neutral && m_direction == Direction::Forward)
		&& !(gear > Gear::Neutral && m_direction == Direction::Backwards)
		&& m_speed >= gearSpeedRange[gear].min
		&& m_speed <= gearSpeedRange[gear].max);
}