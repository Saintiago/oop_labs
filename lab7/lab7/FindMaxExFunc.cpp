#include "stdafx.h"

using namespace std;

struct Athlete
{
	std::string name;
	unsigned height;
	unsigned weight;
};

bool operator == (Athlete const & athleteL, Athlete const & athleteR)
{
	return (athleteL.name == athleteR.name)
		&& (athleteL.height == athleteR.height)
		&& (athleteL.weight == athleteR.weight);
}

template<typename T, typename Less>
bool FindMaxEx(std::vector<T> & arr, T & maxValue, Less const & less = less<T>)
{
	if (arr.size() == 0)
	{
		return false;
	}

	T & newMax (arr.at(0));
	for (auto & item : arr)
	{
		if (less(newMax, item))
		{
			newMax = item;
		}
	}
	maxValue = newMax;
	return true;
}


