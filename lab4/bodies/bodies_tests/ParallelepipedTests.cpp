#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Parallelepiped.h"
#include <math.h>


struct Parallelepiped_
{
	const double expectedWidth   = 3;
	const double expectedHeight = 5;
	const double expectedDepth   = 8;
	const double expectedDensity = 64;
	const double expectedVolume = 120;
	const CParallelepiped box;
	Parallelepiped_()
		: box(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
	{}
};
// ��������������
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
// �������� �������� �����
BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CBody*>(&box));
}

// ����� ������
BOOST_AUTO_TEST_CASE(has_a_width)
{
	BOOST_CHECK_EQUAL(box.GetWidth(), expectedWidth);
}
// ����� ������
BOOST_AUTO_TEST_CASE(has_a_height)
{
	BOOST_CHECK_EQUAL(box.GetHeight(), expectedHeight);
}
// ����� �������
BOOST_AUTO_TEST_CASE(has_a_depth)
{
	BOOST_CHECK_EQUAL(box.GetDepth(), expectedDepth);
}

// ����� ���������
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(box).GetDensity(), expectedDensity);
}
// ����� �����
BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(box).GetVolume(), expectedVolume, 1e-7);
}
// ����� �����
BOOST_AUTO_TEST_CASE(has_a_mass)
{
	BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(box).GetMass(), expectedVolume * expectedDensity, 1e-7);
}
// ����� ��������� �������������
BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	const auto expectedString = R"(Parallelepiped:
	density = 64
	volume = 120
	mass = 7680
	width = 3
	height = 5
	depth = 8
)";
	BOOST_CHECK_EQUAL(static_cast<const CBody &>(box).ToString(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()