#pragma once
#include "SolidBody.h"
class CParallelepiped :
	public CSolidBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	~CParallelepiped();

	double GetVolume() const override;
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;

protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	double m_width, m_height, m_depth;
};

