// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Triangle.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		string again;
		double side1, side2, side3;
		do
		{
			cout << "Please, enter three numbers for triangle sides." << endl;
			cin >> side1 >> side2 >> side3;
			CTriangle triangle(side1, side2, side3);
			cout << "Given triangle perimeter is " << triangle.GetPerimeter() << endl;
			cout << "And his area is " << triangle.GetArea() << endl;
			cout << "Want to try another triangle? (press 'y' to continue)" << endl;
			cin >> again;
		} 
		while (again == "y");

		return 0;
	}
	catch (exception const & e)
	{
		cout << "Oops! We caught an exception!" << endl;
		cout << "And it says: \"" << e.what() << "\"" << endl;
		return 1;
	}
}
