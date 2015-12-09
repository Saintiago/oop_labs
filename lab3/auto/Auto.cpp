#include "stdafx.h"
#include "Auto.h"

unsigned int CAuto::GetSpeed()
{
	return 1;
}

CAuto::Gears CAuto::GetGear()
{
	return Gears::Fifth;
}

bool CAuto::IsEngineOn()
{
	return true;
}