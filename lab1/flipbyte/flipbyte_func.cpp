#include "stdafx.h"
#include "flipbyte_func.h"

unsigned char GetNumber(char* str)
{
	istringstream ss(str);
	int number;
	if (!(ss >> number))
	{
		throw Error::NotNumber;
	}
	if (number < 0 || number > 255)
	{
		throw Error::NotByte;
	}
	return number;
}

unsigned char Flip(unsigned char number)
{
	number = (number & 0xF0) >> 4 | (number & 0x0F) << 4;
	number = (number & 0xCC) >> 2 | (number & 0x33) << 2;
	number = (number & 0xAA) >> 1 | (number & 0x55) << 1;
	return number;
}