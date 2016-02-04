#include "stdafx.h"
#include "Compound.h"


CCompound::CCompound()
	: CBody("Compound")
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

double CCompound::GetDensity()const
{
	double totalMass = 0;
	for (auto body : m_bodies)
	{
		totalMass += body->GetMass();
	}
	return (totalMass / GetVolume());
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

bool CCompound::AddBody(BodyPtr body)
{
	if (body->IsLocked())
	{
		return false;
	}
	body->SetLocked();
	m_bodies.push_back(body);
	return true;
}