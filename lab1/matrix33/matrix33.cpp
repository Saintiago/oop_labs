#include "stdafx.h"
#include "matrix33.h"

// TODO: const char*
// нет проверки ошибок открытия файла
matrix33 ReadMatrix(char* fileName)
{
	matrix33 matrix;
	ifstream matrixFile(fileName);
	for (int y = 0; y < MatrixHeight; y++)
	{
		for (int x = 0; x < MatrixWidth; x++)
		{
			matrixFile >> matrix[x][y];
		}
	}
	return matrix;
}

void ShowMatrix(const matrix33 & matrix)
{
	for (int y = 0; y < MatrixHeight; y++)
	{
		for (int x = 0; x < MatrixWidth; x++)
		{
			cout << setprecision(3) << matrix[x][y] << " ";
		}
		cout << endl;
	}
}

double Det(const matrix33 & m)
{
	return m[0][0] * m[1][1] * m[2][2] - m[2][0] * m[1][1] * m[0][2] + 
		   m[1][0] * m[2][1] * m[0][2] + m[0][1] * m[1][2] * m[2][0] -
		   m[1][0] * m[0][1] * m[2][2] - m[2][1] * m[1][2] * m[0][0];
}

double FindMinorDet(const matrix33 & matrix, int i, int j)
{
	double minor[4];
	int minorIndex = 0;
	for (int y = 0; y < MatrixHeight; y++)
	{
		for (int x = 0; x < MatrixWidth; x++)
		{
			if (x != i && y != j)
			{
				minor[minorIndex] = matrix[x][y];
				minorIndex++;
			}
		}
	}
	return (minor[0] * minor[3]) - (minor[1] * minor[2]);
}

int FindMultiplier(int i, int j)
{
	int multiplier = -1;
	if ((i + j) % 2 == 0)
	{
		multiplier = 1;
	}
	return multiplier;
}

// TODO: Сравнивать с нулем с некоторой точностью
// DBL_EPSILON
// invert inverted inverted
matrix33 InverseMatrix(const matrix33 & matrix)
{
	double determinant = Det(matrix);
	if (determinant == 0)
	{
		throw Error::ZeroDet;
	}

	matrix33 inversed;
	for (int y = 0; y < MatrixHeight; y++)
	{
		for (int x = 0; x < MatrixWidth; x++)
		{
			inversed[y][x] = (FindMultiplier(x, y) * FindMinorDet(matrix, x, y)) / determinant;
		}
	}
	return inversed;
}



