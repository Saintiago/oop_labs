#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class Error
{
	InvalidArguments,
	CantOpenFile
};

int SearchString(string file, string search);
