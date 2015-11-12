#pragma once
#include <iostream>
#include <sstream>

using namespace std;

unsigned char getNumber(char*);
unsigned char flip(unsigned char number);

enum class Error
{
	NoArguments,
	NotNumber,
	NotByte
};