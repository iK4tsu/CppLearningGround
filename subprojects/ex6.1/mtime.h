#pragma once

#include <iostream>

class Time
{
public:
    Time();
    Time(int, int, int);
    Time(const Time&);

    Time operator+(const Time&);
    Time operator-(const Time&);
    friend std::ostream& operator<<(std::ostream&, const Time&);

    // getters
    inline int hours() const { return m_hours; }
    inline int minutes() const { return m_minutes; }
    inline int seconds() const { return m_seconds; }

    // setters
    inline void hours(int i) { m_hours = i; }
    inline void minutes(int i) { m_minutes = i; }
    inline void seconds(int i) { m_seconds = i; }

private:
    int m_hours;
    int m_minutes;
    int m_seconds;
};
