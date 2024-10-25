#pragma once
#include <string>
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"

class STLWriter
{
public:
    void write(const std::string& filename, const Triangulation& triangulation);

private:
    std::string formulateText(Triangulation triangulation, Point point);
};

