#pragma once

class CBody;
typedef std::shared_ptr<CBody> BodyPtr;
typedef std::vector<BodyPtr> BodyPtrVector;

class CBody
{
public:

	enum class Type
	{
		Sphere,
		Cone,
		Cylinder,
		Parallelepiped,
		Compound
	};

	static const std::map<std::string, Type> StringType;

	CBody(const std::string & type, double density);
	
	double GetDensity() const;
	void SetDensity(double density);
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string GetType() const;
	std::string ToString() const;

	virtual ~CBody();
protected:
	virtual void AppendProperties(std::ostream & strm) const = 0;
private:
	double m_density;
	std::string m_type;
};
