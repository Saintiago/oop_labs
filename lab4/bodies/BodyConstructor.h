#pragma once
#include "Body.h"
#include "Compound.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"

class CBodyConstructor
{
public:
	enum class Command
	{
		Create, 
		ShowBodies,
		ShowHeaviest, 
		ShowWaterLightest, 
		Exit
	};

	static const std::map<CBodyConstructor::Command, std::string> m_commands;

	CBodyConstructor();
	~CBodyConstructor();

	static const int waterDensity = 1000;
	static const double g;

	BodyPtr MakeBody(std::stringstream & ss, bool addToList = true);
	std::string GetHighestMassBodyInfo() const;
	std::string GetLightestInWaterBodyInfo() const;
	void ProcessCommand(std::string rawCommand);
	std::string GetBodiesListStr() const;

private:
	BodyPtr MakeCompound(std::vector<std::string> & args);
	BodyPtr MakeCone(std::vector<double> & args);
	BodyPtr MakeCylinder(std::vector<double> & args);
	BodyPtr MakeParallelepiped(std::vector<double> & args);
	BodyPtr MakeSphere(std::vector<double> & args);
	double GetWeightInWater(BodyPtr body) const;

	BodyPtrVector m_bodies;
};

