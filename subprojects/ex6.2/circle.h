#pragma once

#include "figure.h"

class Circle : public Figure
{
public:
    Circle(std::string_view, double, double, double);
    Circle(std::string_view, Point, double);
    Circle(double, double, double);
    Circle(Point, double);

    inline double radius() const { return m_radius; }

    inline void radius(double radius) { m_radius = radius; }

    double area() override;
    double perimeter() override;

    bool intersects(const Circle&);

private:
    double m_radius;
};
