#pragma once

#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(std::string_view, double, double, double, double);
    Rectangle(std::string_view, Point, double, double);
    Rectangle(double, double, double, double);
    Rectangle(Point, double, double);

    inline double length() const { return m_length; }
    inline double width() const { return m_width; }

    inline void length(double length) { m_length = length; }
    inline void width(double width) { m_width = width; }

    double area() override;
    double perimeter() override;

private:
    double m_length;
    double m_width;
};
