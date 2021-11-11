#pragma once

#include <string>

#include "point.h"

class Figure
{
protected:
    Figure(std::string_view, Point);
    Figure(Point);
    virtual ~Figure() = default;

    virtual double area() = 0;
    virtual double perimeter() = 0;

    std::string_view m_color;
    Point m_center;
};
