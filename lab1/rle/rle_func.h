#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

enum class Error
{
	WrongRequest
};

struct Rle
{
	unsigned int count;
	char symbol;
};

string Pack(string input);