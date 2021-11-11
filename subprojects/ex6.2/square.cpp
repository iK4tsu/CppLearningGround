#include "square.h"

Square::Square(std::string_view color, double x, double y, double side)
    : Figure(color, Point(x, y))
    , m_side(side)
{}

Square::Square(std::string_view color, Point center, double side)
    : Figure(color, center)
    , m_side(side)
{}

Square::Square(double x, double y, double side)
    : Figure("none", Point(x, y))
    , m_side(side)
{}

Square::Square(Point center, double side)
    : Figure(center)
    , m_side(side)
{}

double Square::area()
{
    return m_side * m_side;
}

double Square::perimeter()
{
    return m_side * 4;
}
