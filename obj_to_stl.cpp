#include "OBJReader.h"
#include <iostream>
#include "Triangulation.h"

int main()
{
    OBJReader reader;
    Triangulation tri;
    std::string oFilePath = "D://narayanWorkspace//obj_stl//obj_to_stl//cube_obj.txt";
    reader.read(oFilePath, tri);
}
