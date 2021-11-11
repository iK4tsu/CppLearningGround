#pragma once

class Point
{
public:
    Point(double, double);

    inline double x() const { return m_x; }
    inline double y() const { return m_y; }

    inline void x(double x) { m_x = x; }
    inline void y(double y) { m_y = y; }

private:
    double m_x;
    double m_y;
};
