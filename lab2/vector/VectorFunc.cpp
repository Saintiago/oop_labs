#include "stdafx.h"
#include "VectorFunc.h"

std::vector<double> ReadVector(std::string vectorStr)
{
	std::stringstream ss(vectorStr);
	double number;
		std::vector<double> result;
	while (!ss.eof())
	{
		ss >> number;
		result.push_back(number);
	}
	
	return result;
}

void ProcessVector(std::vector<double> & numbers)
{
	auto positiveAverage = GetPositiveAverage(numbers);
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), 
		[positiveAverage](double & number) { return number += positiveAverage; });
}

std::string GetVectorItems(const std::vector<double> & numbers)
{
	std::ostringstream oss;
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(oss, " "));
	return oss.str();
}

double GetPositiveAverage(std::vector<double> numbers)
{
	double positiveTotal = 0;
	auto positiveCount = std::count_if(numbers.begin(), numbers.end(), [](double number) { return number > 0; });
	std::for_each(numbers.begin(), numbers.end(), [&positiveTotal](double number)
	{
		if (number > 0)
		{
			positiveTotal += number;
		}
	});
	return (positiveTotal / positiveCount);
}