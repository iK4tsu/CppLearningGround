#include "rectangle.h"

Rectangle::Rectangle(std::string_view color, double x, double y, double length, double width)
    : Figure(color, Point(x, y))
    , m_length(length)
    , m_width(width)
{}

Rectangle::Rectangle(std::string_view color, Point center, double length, double width)
    : Figure(color, center)
    , m_length(length)
    , m_width(width)
{}

Rectangle::Rectangle(double x, double y, double length, double width)
    : Figure("none", Point(x, y))
    , m_length(length)
    , m_width(width)
{}

Rectangle::Rectangle(Point center, double length, double width)
    : Figure(center)
    , m_length(length)
    , m_width(width)
{}

double Rectangle::area()
{
    return m_length * m_width;
}

double Rectangle::perimeter()
{
    return m_length * 2 + m_width * 2;
}
