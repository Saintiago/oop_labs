#include "stdafx.h"
#include "Car.h"

unsigned int CCar::GetSpeed()
{
	return 0;
}

CCar::Gears CCar::GetGear()
{
	return Gears::Neutral;
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