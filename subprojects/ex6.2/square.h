#pragma once

#include "figure.h"

class Square : public Figure
{
public:
    Square(std::string_view, double, double, double);
    Square(std::string_view, Point, double);
    Square(double, double, double);
    Square(Point, double);

    inline double side() const { return m_side; }

    inline void side(double side) { m_side = side; }

    double area() override;
    double perimeter() override;

private:
    double m_side;
};
