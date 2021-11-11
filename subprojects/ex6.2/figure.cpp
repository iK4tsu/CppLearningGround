#include "figure.h"

Figure::Figure(std::string_view color, Point center)
    : m_color(color)
    , m_center(center)
{}

Figure::Figure(Point center)
    : m_color("none")
    , m_center(center)
{}
