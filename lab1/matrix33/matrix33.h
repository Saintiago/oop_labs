#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

using namespace std;

const unsigned int MatrixWidth = 3;
const unsigned int MatrixHeight = 3;

typedef array<double, MatrixWidth> matrix3;
typedef array<matrix3, MatrixHeight> matrix33;

double Det(const matrix33 & matrix);
double FindMinorDet(const matrix33 & matrix, int i, int j);
int FindMultiplier(int i, int j);
matrix33 InverseMatrix(const matrix33 & matrix);
matrix33 ReadMatrix(char* fileName);
void ShowMatrix(const matrix33 & matrix);

enum class Error
{
	ZeroDet,
	NoInputFile
};