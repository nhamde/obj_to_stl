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
    double normalXYZ[3];
    string str1;
    string str2;
    string str3;
    //vector<int> pointIndices;
    vector<Point> vertices;
    vector<Point> normals;
    

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

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(xyz[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.uniqueValues.push_back(xyz[i]);
                            uniqueMap[xyz[i]] = triangulation.uniqueValues.size() - 1;
                            pt[i] = triangulation.uniqueValues.size() - 1;
                            
                        }
                        else
                        {
                            pt[i] = pair->second;
                            
                        }
                        
                    }
                    vertices.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "vn")
                {
                    ss >> normalXYZ[0] >> normalXYZ[1] >> normalXYZ[2];

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(normalXYZ[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.uniqueValues.push_back(normalXYZ[i]);
                            uniqueMap[normalXYZ[i]] = triangulation.uniqueValues.size() - 1;
                            pt[i] = triangulation.uniqueValues.size() - 1;

                        }
                        else
                        {
                            pt[i] = pair->second;

                        }

                    }
                    normals.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "f")
                {
                    ss >> str1 >> str2 >> str3;
                    int FirstPointIndex= stoi(str1.substr(0, 1)) - 1;
                    int SecondPointIndex = stoi(str2.substr(0, 1)) - 1;
                    int ThirdPointIndex = stoi(str3.substr(0, 1)) - 1;
                    int normalIndex = stoi(str3.substr(4, 1)) - 1;
                    cout << FirstPointIndex << SecondPointIndex << ThirdPointIndex << normalIndex << endl;
                    triangulation.triangles.push_back(Triangle(vertices[FirstPointIndex], vertices[SecondPointIndex], vertices[ThirdPointIndex], normals[normalIndex]));
                }
            }   
        }
        cout << triangulation.triangles.size();
    }
}