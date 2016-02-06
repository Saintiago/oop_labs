#include "stdafx.h"

template<typename T>
bool FindMax(std::vector<T> const & arr, T & maxValue)
{
	if (arr.size() == 0)
	{
		return false;
	}
	maxValue = *(max_element(arr.begin(), arr.end()));
	return true;
}

template<>
inline bool FindMax<const char*>(std::vector<const char*>const & arr, const char* & maxCharStringValue)
{
	if (arr.size() == 0)
	{
		return false;
	}

	const char* newMax = arr.at(0);
	for (auto & item : arr)
	{
		if (*item > *newMax)
		{
			newMax = item;
		}
	}
	maxCharStringValue = newMax;
	return true;
}
