#include "stdafx.h"
#include "Car.h"

int const CCar::maxSpeed = 150;
std::map <CCar::Gear, CCar::SpeedRange> const CCar::gearSpeedRange =
{
	{ CCar::Gear::Rear,{ -20, 0 } },
	{ CCar::Gear::Neutral,{ 0, CCar::maxSpeed } },
	{ CCar::Gear::First,{ 0, 30 } },
	{ CCar::Gear::Second,{ 20, 50 } },
	{ CCar::Gear::Third,{ 30, 60 } },
	{ CCar::Gear::Fourth,{ 40, 90 } },
	{ CCar::Gear::Fifth,{ 50, CCar::maxSpeed } }
};

int CCar::GetSpeed() const
{
	return m_speed;
}

CCar::Gear CCar::GetGear() const
{
	return m_gear;
}

CCar::Direction CCar::GetDirection() const
{
	if (m_speed > 0)
	{
		return Direction::Forward;
	}
	else if (m_speed < 0)
	{
		return Direction::Backwards;
	}
	else
	{
		return Direction::StandingStill;
	}
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
	if (m_isEngineOn && GetDirection() == Direction::StandingStill && m_gear == Gear::Neutral)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;
}

void CCar::SetSpeed(int speed)
{
	if (GetGear() == Gear::Neutral && abs(speed) > abs(m_speed))
	{
		throw std::exception("You must shift gear to accelerate.");
	}

	if (speed < gearSpeedRange.at(m_gear).min || speed > gearSpeedRange.at(m_gear).max)
	{
		throw std::exception("Careful! You'll break transmission like that.");
	}

	m_speed = speed;
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
	if (!m_isEngineOn && gear != Gear::Neutral)
	{
		return false;
	}

	if (gear == m_gear || gear == Gear::Neutral)
	{
		return true;
	}

	return (!(gear < Gear::Neutral && GetDirection() == Direction::Forward)
		&& !(gear > Gear::Neutral && GetDirection() == Direction::Backwards)
		&& m_speed >= gearSpeedRange.at(gear).min
		&& m_speed <= gearSpeedRange.at(gear).max);
}