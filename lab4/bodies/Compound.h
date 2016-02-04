#pragma once
#include "Body.h"
class CCompound :
	public CBody
{
public:
	CCompound();
	~CCompound();

	double GetVolume() const override;
	double GetDensity() const override;
	std::string GetBodiesListStr() const;

	bool AddBody(BodyPtr body);

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	BodyPtrVector m_bodies;

};

