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
// Составное тело
BOOST_FIXTURE_TEST_SUITE(Compound, Compound_)
// является объемным телом
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&compound));
}
// может включать в себя други тела
BOOST_AUTO_TEST_CASE(can_include_other_bodies)
{
	auto expectedString1 = R"(
Cylinder:
	density = 50
	volume = 6283.185307
	mass = 314159.2654
	radius = 20
	height = 5

Sphere:
	density = 60
	volume = 14137.16694
	mass = 848230.0165
	radius = 15

)";
	auto expectedString2 = R"(
Cylinder:
	density = 50
	volume = 6283.185307
	mass = 314159.2654
	radius = 20
	height = 5

Sphere:
	density = 60
	volume = 14137.16694
	mass = 848230.0165
	radius = 15

Cylinder:
	density = 10
	volume = 3141.592654
	mass = 31415.92654
	radius = 10
	height = 10

)";
	BOOST_CHECK_EQUAL(compound.GetBodiesListStr(), expectedString1);
	compound.AddBody(std::make_shared<CCylinder>(10, 10, 10));
	BOOST_CHECK_EQUAL(compound.GetBodiesListStr(), expectedString2);
}
// имеет плотность
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_CLOSE_FRACTION(compound.GetDensity(), expectedDensity, 1e-7);
}
// имеет объем
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(compound).GetVolume(), expectedVolume, 1e-7);
}
// имеет массу
BOOST_AUTO_TEST_CASE(has_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(compound.GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// имеет строковое представление
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Compound:
	density = 56.92307692
	volume = 20420.35225
	mass = 1162389.282

Cylinder:
	density = 50
	volume = 6283.185307
	mass = 314159.2654
	radius = 20
	height = 5

Sphere:
	density = 60
	volume = 14137.16694
	mass = 848230.0165
	radius = 15

----------)";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(compound).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()