#include "OBJReader.h"
#include <iostream>
#include "Triangulation.h"

int main()
{
    OBJReader reader;
    Triangulation tri;
    std::string oFilePath = "cube.obj";
    reader.read(oFilePath, tri);
}
