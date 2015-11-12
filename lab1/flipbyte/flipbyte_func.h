#pragma once
#include <iostream>
#include <sstream>

using namespace std;

unsigned char GetNumber(char*);
unsigned char Flip(unsigned char number);

enum class Error
{
	NoArguments,
	NotNumber,
	NotByte
};