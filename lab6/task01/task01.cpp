// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
try
{
	cout << "Please, enter three numbers for triangle sides." << endl;
	double side1, side2, side3;
	cin >> side1 >> side2 >> side3;
	CTriangle triangle(side1, side2, side3);
	cout << "Given triangle perimeter is " << triangle.GetPerimeter() << endl;
	cout << "And his area is " << triangle.GetArea() << endl;
}
catch (exception const & e)
{
	cout << "Oops! We caught an exception!" << endl;
	cout << "And it says: \"" << e.what() << "\"" << endl;
}