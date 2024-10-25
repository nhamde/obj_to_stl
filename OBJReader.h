#pragma once
#include <string>
#include"Triangulation.h"
using namespace std;
class OBJReader
{
public:
	void read(const string& fileName, Triangulation& tri);
};

