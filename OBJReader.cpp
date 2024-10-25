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
    string str1;
    string str2;
    string str3;
    vector<int> pointIndices;
    vector<Point> oPoints;
    

    ifstream infile(fileName);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }
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
            while (ss >> word) {
                if (word == "f")
                {
                    ss >> str1 >> str2 >> str3;
                    int x = stoi(str1.substr(0, 1)) - 1;
                    int y = stoi(str2.substr(0, 1)) - 1;
                    int z = stoi(str3.substr(0, 1)) - 1;
                    cout << x << y << z;
                    triangulation.triangles.push_back(Triangle(oPoints[x], oPoints[y], oPoints[z]));
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