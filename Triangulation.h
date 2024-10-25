#pragma once
#include"Triangle.h"
#include <vector>
using namespace std;
class Triangulation
{
public:
	vector<Triangle> triangles;
	vector<double> uniqueValues;

	Triangulation();
	~Triangulation();
};

