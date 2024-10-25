#include "OBJReader.h"
#include "Triangulation.h"
#include "Point.h"
#include "Triangle.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

void OBJReader::read(const string& fileName, Triangulation& triangulation)
{
    map<double, int> uniqueMap;
    double xyz[3];
    string fnData[3];
    vector<int> pointIndices;
    vector<Point> oPoints;

    ifstream infile(fileName);
    if (infile.is_open())
    {
        string line;

        while (getline(infile, line))
        {
            stringstream ss(line);
            string word;
            while (ss >> word)
            {
                if (word == "v")
                {
                    ss >> xyz[0] >> xyz[1] >> xyz[2];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(xyz[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.uniqueValues.push_back(xyz[i]);
                            uniqueMap[xyz[i]] = triangulation.uniqueValues.size() - 1;
                            pointIndices.push_back(triangulation.uniqueValues.size() - 1);
                        }
                        else
                        {
                            pointIndices.push_back(pair->second);
                        }
                    }
                }
                else if (word == "f")
                {
                    ss >> fnData[0] >> fnData[1] >> fnData[2];

                    
                }
            }
        }
        for (int i = 0; i < pointIndices.size(); i += 3)
        {

            if (i + 2 < pointIndices.size())
            {
                int x = pointIndices[i];
                int y = pointIndices[i + 1];
                int z = pointIndices[i + 2];

                oPoints.push_back(Point(x, y, z)); 
            }
        }
    }
}