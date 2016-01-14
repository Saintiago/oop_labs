// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "VectorFunc.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Enter numbers divided by space:" << endl;
	string vectorStr;
	getline(cin, vectorStr);
	vector<double> numbers = ReadVector(vectorStr);
	ProcessVector(numbers);
	cout << GetVectorItems(numbers);
	
	return 0;
}