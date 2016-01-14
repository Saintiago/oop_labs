#include "stdafx.h"
#include "Compound.h"


CCompound::CCompound()
	: CBody("Compound", 0.0)
{
}

CCompound::~CCompound()
{
}

double CCompound::GetVolume()const
{
	double volume = 0;
	for (auto body : m_bodies)
	{
		volume += body->GetVolume();
	}
	return volume;
}

void CCompound::AppendProperties(std::ostream & strm) const
{
}

std::string CCompound::GetBodiesListStr() const
{
	std::string bodiesList = "";
	for (auto body : m_bodies)
	{
		bodiesList += body->GetType() + " ";
	}
	return bodiesList;
}

void CCompound::AddBody(BodyPtr body)
{
	m_bodies.push_back(body);
	CorrectDensity();
	
}

void CCompound::CorrectDensity()
{
	double totalMass = 0;
	for (auto body : m_bodies)
	{
		totalMass += body->GetMass();
	}
	SetDensity(totalMass / GetVolume());
}