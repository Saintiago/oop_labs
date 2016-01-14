#include "stdafx.h"
#include "Parallelepiped.h"


CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	: CBody("Parallelepiped", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}


CParallelepiped::~CParallelepiped()
{
}

double CParallelepiped::GetWidth()const
{
	return m_width;
}

double CParallelepiped::GetHeight()const
{
	return m_height;
}

double CParallelepiped::GetDepth()const
{
	return m_depth;
}

double CParallelepiped::GetVolume()const
{
	return (GetWidth() * GetHeight() * GetDepth());
}

void CParallelepiped::AppendProperties(std::ostream & strm) const
{
	strm << "\twidth = " << GetWidth() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
	strm << "\tdepth = " << GetDepth() << std::endl;
}