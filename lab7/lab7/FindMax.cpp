#include "stdafx.h"
#include <vector>
#include <cassert>
#include <iostream>

template<typename T, typename Less = less<T>>
bool FindMaxEx(std::vector<T> & arr, T & maxValue, Less const & less = less<T>())
{
	if (arr.size() == 0)
	{
		return false;
	}

	T * newMax = &arr.at(0);
	for (auto & item : arr)
	{
		if (less(*newMax, item))
		{
			newMax = &item;
		}
	}
	maxValue = *newMax;
	return true;
}

bool enableLogging = false;

struct Logger
{
	Logger() {}
	Logger(const Logger&)
	{
		std::cout << "Copy construction" << std::endl;
	}
	Logger& operator=(const Logger&)
	{
		if (enableLogging)
		{
			std::cout << "Copy assignment" << std::endl;
		}
		return *this;
	}
};

int main()
{
	{
		std::vector<int> v = { 1, 2, 3 };
		int maxValue;
		assert(FindMaxEx(v, maxValue));
		assert(maxValue == 3);
	}

	std::vector<Logger> arr(5);
	Logger maxLogger;
	enableLogging = true;
	FindMaxEx(arr, maxLogger, [](const Logger & l, const Logger& r) {
		return &l < &r;
	});
	return 0;
}