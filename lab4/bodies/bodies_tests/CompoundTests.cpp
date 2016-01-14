#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Compound.h"
#include "../Cylinder.h"
#include "../Sphere.h"
#include <math.h>


struct Compound_
{
	const double expectedVolume = 20420.352248333656;
	const double expectedDensity = 56.923076923;
	CCompound compound;

	Compound_()
		: compound()
	{
		compound.AddBody(std::make_shared<CCylinder>(50, 20, 5)); // volume = 6283, mass = 314150
		compound.AddBody(std::make_shared<CSphere>(60, 15)); // volume = 14136.75, mass = 848205
	}
};
// ��������� ����
BOOST_FIXTURE_TEST_SUITE(Compound, Compound_)
// �������� �������� �����
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&compound));
}
// ����� �������� � ���� ����� ����
BOOST_AUTO_TEST_CASE(can_include_other_bodies)
{
	BOOST_CHECK_EQUAL(compound.GetBodiesListStr(), "Cylinder Sphere ");
	compound.AddBody(std::make_shared<CCylinder>(10, 10, 10));
	BOOST_CHECK_EQUAL(compound.GetBodiesListStr(), "Cylinder Sphere Cylinder ");
	compound.AddBody(std::make_shared<CSphere>(10, 10));
	BOOST_CHECK_EQUAL(compound.GetBodiesListStr(), "Cylinder Sphere Cylinder Sphere ");
}
// ����� ���������
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_CLOSE_FRACTION(compound.GetDensity(), expectedDensity, 1e-7);
}
// ����� �����
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(compound).GetVolume(), expectedVolume, 1e-7);
}
// ����� �����
BOOST_AUTO_TEST_CASE(has_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(compound.GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// ����� ��������� �������������
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Compound:
	density = 56.92307692
	volume = 20420.35225
	mass = 1162389.282
)";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(compound).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()