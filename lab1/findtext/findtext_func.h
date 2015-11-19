#pragma once

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <exception>
#include <vector>
#include <boost/algorithm/string/join.hpp>

using namespace std;

vector<int> SearchString(ifstream & fin, const string search);
