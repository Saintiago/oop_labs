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

BodyPtr CBodyConstructor::MakeBody(std::istream & is)
{
	std::string command;
	std::getline(is, command);
	std::stringstream ss(command);

	std::string body;
	std::vector<std::string> args;
	ss >> body;
	while (!ss.eof())
	{
		std::string parsedArg;
		ss >> parsedArg;
		args.push_back(parsedArg);
	}

	BodyPtr createdBody = nullptr;
	
	if (CBody::StringType.at(body) == CBody::Type::Compound)
	{
		createdBody = MakeCompound(is);
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

	return createdBody;
}

void CBodyConstructor::AddBodyToList(BodyPtr body)
{
	if (!body->IsLocked())
	{
		body->SetLocked();
		m_bodies.push_back(body);
	}
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

bool CBodyConstructor::ProcessCommand(std::istream & is)
{
	std::string command;
	is >> command;
	std::transform(command.begin(), command.end(), command.begin(), ::tolower);
	if (command == m_commands.at(Command::Create))
	{
		ProcessCreateCommand(is);
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
		return false;
	}
	else
	{
		std::cout << "Command not implemented." << std::endl;
	}

	return true;
}

void CBodyConstructor::ProcessCreateCommand(std::istream & is)
{
	BodyPtr body = MakeBody(is);
	AddBodyToList(body);
}

std::string CBodyConstructor::GetBodiesListStr() const
{
	std::string bodiesList = "";
	for (auto body : m_bodies)
	{
		bodiesList += body->ToString() + "\n ";
	}
	return bodiesList;
}

BodyPtr CBodyConstructor::MakeCompound(std::istream & is)
{
	BodyPtr compound = std::make_shared<CCompound>();
	std::string answer = "yes";
	while (answer == "yes")
	{
		std::dynamic_pointer_cast<CCompound> (compound)->AddBody(MakeBody(is));
		std::cout << "Add another body to compound?" << std::endl;
		std::getline(is, answer);
	}
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
