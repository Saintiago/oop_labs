#pragma once
#include "Body.h"
class CCone :
	public CBody
{
public:
	CCone(double density, double radius, double height);
	~CCone();

	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	double m_radius, m_height;
};

