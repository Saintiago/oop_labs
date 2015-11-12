#include "stdafx.h"
#include "matrix33.h"

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			throw Error::NoInputFile;
		}

		matrix33 inputMatrix = ReadMatrix(argv[1]);
		matrix33 inversedMatrix = InverseMatrix(inputMatrix);

		cout << "Source matrix: " << endl;
		ShowMatrix(inputMatrix);

		cout << "Inversed matrix: " << endl;
		ShowMatrix(inversedMatrix);
	}
	catch (Error err)
	{
		char* message;
		switch (err)
		{
		case Error::ZeroDet:
			message = "Determinat is zero. Inversed matrix doesn't exist.";
			break;
		case Error::NoInputFile:
			message = "Please specify matrix file.";
			break;
		default:
			message = "Unknown error.";
			break;
		}
		cout << message << endl;
		return 1;
	}
	return 0;
}