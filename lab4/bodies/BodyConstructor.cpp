#include "stdafx.h"
#include "BodyConstructor.h"

const std::map<CBodyConstructor::Command, std::string> CBodyConstructor::m_commands =
{
	{ Command::Create, "create" },
	{ Command::ShowBodies, "list" },
	{ Command::ShowHeaviest, "heaviest" },
	{ Command::ShowWaterLightest, "lightest" },
	{ Command::Exit, "exit" }
};

CBodyConstructor::CBodyConstructor()
{
}

CBodyConstructor::~CBodyConstructor()
{
}

const double CBodyConstructor::g = 9.8;

BodyPtr CBodyConstructor::MakeBody(std::stringstream & ss, bool addToList)
{
	if (ss.eof())
	{
		throw std::exception("Incorrect input");
	}

	std::string body;
	std::vector<std::string> args;
	ss >> body;
	while (!ss.eof())
	{
		std::string parsedArg;
		ss >> parsedArg;
		args.push_back(parsedArg);
	}

	BodyPtr createdBody;
	
	if (CBody::StringType.at(body) == CBody::Type::Compound)
	{
		createdBody = MakeCompound(args);
	}
	else
	{
		std::vector<double> numberArgs;
		for (auto & arg : args)
		{
			numberArgs.push_back(std::stod(arg));
		}

		if (CBody::StringType.at(body) == CBody::Type::Cone)
		{
			createdBody = MakeCone(numberArgs);
		}
		else if (CBody::StringType.at(body) == CBody::Type::Cylinder)
		{
			createdBody = MakeCylinder(numberArgs);
		}
		else if (CBody::StringType.at(body) == CBody::Type::Parallelepiped)
		{
			createdBody = MakeParallelepiped(numberArgs);
		}
		else if (CBody::StringType.at(body) == CBody::Type::Sphere)
		{
			createdBody = MakeSphere(numberArgs);
		}
		else
		{
			throw std::exception("Unknown body");
		}
	}

	if (addToList)
	{
		m_bodies.push_back(createdBody);
	}
	
	return createdBody;
}

std::string CBodyConstructor::GetHighestMassBodyInfo() const
{
	if (m_bodies.size() == 0)
	{
		throw std::exception("There is no bodies yet.");
	}

	BodyPtr heaviest = m_bodies.at(0);

	for (auto body : m_bodies)
	{
		if (body->GetMass() > heaviest->GetMass())
		{
			heaviest = body;
		}
	}

	return heaviest->ToString();
}

std::string CBodyConstructor::GetLightestInWaterBodyInfo() const
{
	if (m_bodies.size() == 0)
	{
		throw std::exception("There is no bodies yet.");
	}

	BodyPtr lightest = m_bodies.at(0);
	double oldWeightInWater = GetWeightInWater(m_bodies.at(0));

	for (auto body : m_bodies)
	{
		double weightInWater = GetWeightInWater(body);
		if (oldWeightInWater > weightInWater)
		{
			lightest = body;
		}
		oldWeightInWater = weightInWater;
	}

	return lightest->ToString();
}

double CBodyConstructor::GetWeightInWater(BodyPtr body) const
{
	return (body->GetMass() * CBodyConstructor::g) - (CBodyConstructor::waterDensity * body->GetVolume() * CBodyConstructor::g);
}

void CBodyConstructor::ProcessCommand(std::string rawCommand)
{
	std::transform(rawCommand.begin(), rawCommand.end(), rawCommand.begin(), ::tolower);
	std::stringstream ss;
	std::string command = "";
	int parsedArg = 0;
	ss << rawCommand;
	ss >> command;
	if (command == m_commands.at(Command::Create))
	{
		MakeBody(ss);
	}
	else if (command == m_commands.at(Command::ShowBodies))
	{
		std::cout << GetBodiesListStr() << std::endl;
	}
	else if (command == m_commands.at(Command::ShowHeaviest))
	{
		std::cout << GetHighestMassBodyInfo() << std::endl;
	}
	else if (command == m_commands.at(Command::ShowWaterLightest))
	{
		std::cout << GetLightestInWaterBodyInfo() << std::endl;
	}
	else if (command == m_commands.at(Command::Exit))
	{
		std::cout << "Bye!" << std::endl;
	}
	else
	{
		std::cout << "Command not implemented." << std::endl;
	}
}

std::string CBodyConstructor::GetBodiesListStr() const
{
	std::string bodiesList = "";
	for (auto body : m_bodies)
	{
		bodiesList += body->GetType() + " ";
	}
	return bodiesList;
}

BodyPtr CBodyConstructor::MakeCompound(std::vector<std::string> & args) 
{
	BodyPtr compound = std::make_shared<CCompound>();
	std::stringstream ss;
	ss.clear();
	unsigned count = 0;
	for (auto arg : args)
	{
		count++;
		if ((ss.rdbuf()->in_avail() > 0) && (CBody::StringType.find(arg) != CBody::StringType.end()))
		{
			ss.get();
			std::dynamic_pointer_cast<CCompound> (compound)->AddBody(MakeBody(ss, false));
			ss.clear();
		}
		ss << " " << arg;
	}
	std::dynamic_pointer_cast<CCompound> (compound)->AddBody(MakeBody(ss, false));
	return compound;
}

BodyPtr CBodyConstructor::MakeCone(std::vector<double>& args) 
{
	BodyPtr cone = std::make_shared<CCone>(args.at(0), args.at(1), args.at(2));
	return cone;
}

BodyPtr CBodyConstructor::MakeCylinder(std::vector<double>& args) 
{
	BodyPtr cylinder = std::make_shared<CCylinder>(args.at(0), args.at(1), args.at(2));
	return cylinder;
}

BodyPtr CBodyConstructor::MakeParallelepiped(std::vector<double>& args) 
{
	BodyPtr parallelepiped = std::make_shared<CParallelepiped>(args.at(0), args.at(1), args.at(2), args.at(3));
	return parallelepiped;
}

BodyPtr CBodyConstructor::MakeSphere(std::vector<double>& args)
{
	BodyPtr sphere = std::make_shared<CSphere>(args.at(0), args.at(1));
	return sphere;
}
