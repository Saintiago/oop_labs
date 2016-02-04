#pragma once
#include "Body.h"
class CSolidBody :
	public CBody
{
public:
	CSolidBody(const std::string & type, double density);
	virtual ~CSolidBody();

	double GetDensity() const override;

private:
	double m_density;
};

