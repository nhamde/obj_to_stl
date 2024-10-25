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
    vector<int> pointIndices;

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
        }
    }
    }
}