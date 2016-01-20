#pragma once
#include "SolidBody.h"
class CCylinder :
	public CSolidBody
{
public:
	CCylinder(double density, double radius, double height);
	~CCylinder();

	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	double m_radius, m_height;
};

