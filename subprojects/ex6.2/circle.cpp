#include <math.h>

#include "circle.h"

Circle::Circle(std::string_view color, double x, double y, double radius)
    : Figure(color, Point(x, y))
    , m_radius(radius)
{}

Circle::Circle(std::string_view color, Point center, double radius)
    : Figure(color, center)
    , m_radius(radius)
{}

Circle::Circle(double x, double y, double radius)
    : Figure("none", Point(x, y))
    , m_radius(radius)
{}

Circle::Circle(Point center, double radius)
    : Figure(center)
    , m_radius(radius)
{}

double Circle::area()
{
    return M_PI * m_radius * m_radius;
}

double Circle::perimeter()
{
    return 2 * M_PI * m_radius;
}

bool Circle::intersects(const Circle& other)
{
    using namespace std;
    const double dist = pow(m_center.x() - other.m_center.x(), 2) + pow(m_center.y() - other.m_center.y(), 2);

    return pow(m_radius - other.m_radius, 2) <= dist && pow(m_radius + other.m_radius, 2) >= dist;
}
