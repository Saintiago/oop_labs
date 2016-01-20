#include "stdafx.h"
#include "Body.h"

const std::map<std::string, CBody::Type> CBody::StringType =
{
	{ "compound", CBody::Type::Compound }, 
	{ "cone", CBody::Type::Cone },
	{ "cylinder", CBody::Type::Cylinder },
	{ "parallelepiped", CBody::Type::Parallelepiped },
	{ "sphere", CBody::Type::Sphere },
};

CBody::CBody(const std::string & type)
	: m_type(type)
{
}

CBody::~CBody()
{
}

std::string CBody::GetType()const
{
	return m_type;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << GetType() << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}
