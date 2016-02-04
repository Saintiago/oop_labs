#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../BodyConstructor.h"
#include "../Sphere.h"
#include "../Parallelepiped.h"
#include <math.h>

struct BodyConstructor_
{
	CBodyConstructor constructor;
	BodyConstructor_()
		: constructor()
	{
		std::stringstream ss;
		ss << "sphere 10 6" << std::endl;
		BodyPtr sphere = constructor.MakeBody(ss);
		ss << "parallelepiped 64 3 5 8" << std::endl;
		BodyPtr parallelepiped = constructor.MakeBody(ss);
		constructor.AddBodyToList(sphere);
		constructor.AddBodyToList(parallelepiped);
	}
};

//  онструкор тел
BOOST_FIXTURE_TEST_SUITE(Body_constructor, BodyConstructor_)
	// может создать сферу по параметрам во вход€щем потоке
	BOOST_AUTO_TEST_CASE(can_make_sphere_by_input_stream_params)
	{
		std::stringstream ss("sphere 10 6");
		std::iostream & is(ss);
		BodyPtr sphere = constructor.MakeBody(ss);
		const auto expectedString = R"(Sphere:
	density = 10
	volume = 904.7786842
	mass = 9047.786842
	radius = 6
)";
		BOOST_CHECK_EQUAL(static_cast<const std::shared_ptr<CBody> &>(sphere)->ToString(), expectedString);
	}
	// может создать составное тело по параметрам во вход€щем потоке
	BOOST_AUTO_TEST_CASE(can_make_compound_by_input_stream_params)
	{
		std::stringstream ss;
		ss << "compound" << std::endl << "sphere 10 6" << std::endl << "yes" << std::endl << "parallelepiped 64 3 5 8" << std::endl << "no";
		BodyPtr compound = constructor.MakeBody(ss);
		const auto expectedString = R"(Compound:
	density = 16.32331654
	volume = 1024.778684
	mass = 16727.78684

Sphere:
	density = 10
	volume = 904.7786842
	mass = 9047.786842
	radius = 6

Parallelepiped:
	density = 64
	volume = 120
	mass = 7680
	width = 3
	height = 5
	depth = 8

----------)";
		BOOST_CHECK_EQUAL(static_cast<const std::shared_ptr<CBody> &>(compound)->ToString(), expectedString);
	}
	// может вывести информацию о теле с наибольшей массой
	BOOST_AUTO_TEST_CASE(can_show_info_about_body_with_highest_mass)
	{
		const auto expectedString = R"(Sphere:
	density = 10
	volume = 904.7786842
	mass = 9047.786842
	radius = 6
)";
		BOOST_CHECK_EQUAL(constructor.GetHighestMassBodyInfo(), expectedString);
	}
	// может вывести информацию о теле с наименьшим весом в воде
	BOOST_AUTO_TEST_CASE(can_show_info_about_body_that_is_lightest_in_water)
	{
		const auto expectedString = R"(Sphere:
	density = 10
	volume = 904.7786842
	mass = 9047.786842
	radius = 6
)";
		BOOST_CHECK_EQUAL(constructor.GetLightestInWaterBodyInfo(), expectedString);
	}
	// не позвол€ет одному телу входить одновременно в состав двух compound'ов
	BOOST_AUTO_TEST_CASE(forbids_single_body_being_incorporated_in_two_compounds)
	{
		std::stringstream ss;

		ss << "sphere 10 6" << std::endl;
		BodyPtr sphere = constructor.MakeBody(ss);

		ss << "compound" << std::endl << "sphere 1 1" << std::endl << "no" << std::endl;
		BodyPtr compound1 = constructor.MakeBody(ss);

		ss << "compound" << std::endl << "sphere 1 1" << std::endl << "no" << std::endl;
		BodyPtr compound2 = constructor.MakeBody(ss);

		BOOST_CHECK(dynamic_cast<CCompound*>(compound1.get())->AddBody(sphere));
		BOOST_CHECK(!dynamic_cast<CCompound*>(compound1.get())->AddBody(sphere));
		BOOST_CHECK(!dynamic_cast<CCompound*>(compound2.get())->AddBody(sphere));
	}

BOOST_AUTO_TEST_SUITE_END()