#pragma once

std::vector<double> ReadVector(std::string vectorStr);
void ProcessVector(std::vector<double> & numbers);
std::string ConvertVectorToString(const std::vector<double> & numbers);

double GetPositiveAverage(std::vector<double> numbers);
