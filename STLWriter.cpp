#include "STLWriter.h"
#include<fstream>
#include<iomanip>

std::string STLWriter::formulateText(Triangulation triangulation, Point point)
{
    double x = triangulation.uniqueValues[point.X()];
    double y = triangulation.uniqueValues[point.Y()];
    double z = triangulation.uniqueValues[point.Z()];

    return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n";
}

void STLWriter::write(const std::string& filename, const Triangulation& triangulation)
{
    std::ofstream outfile(filename);

    if (outfile.is_open())
    {
        for (Triangle tri : triangulation.triangles)
        {
            outfile <<  std::fixed << std::setprecision(6)
                <<"  facet normal " << formulateText(triangulation, tri.N()) << "\n";
            outfile << "    outer loop\n";
            outfile << "      vertex " << formulateText(triangulation, tri.V1());
            outfile << "      vertex " << formulateText(triangulation, tri.V2());
            outfile << "      vertex " << formulateText(triangulation, tri.V3());
            outfile << "    endloop\n";
            outfile << "  endfacet\n";
        }
    }
}