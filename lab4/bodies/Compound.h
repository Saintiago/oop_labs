#pragma once
#include "Body.h"
class CCompound :
	public CBody
{
public:
	CCompound();
	~CCompound();

	double GetVolume() const override;
	std::string GetBodiesListStr() const;

	void AddBody(BodyPtr body);

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	void CorrectDensity();

	BodyPtrVector m_bodies;

};

