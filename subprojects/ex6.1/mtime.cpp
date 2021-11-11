#include "mtime.h"

#include <iomanip>

Time::Time()
    : m_hours(0)
    , m_minutes(0)
    , m_seconds(0)
{}

Time::Time(int hours, int minutes, int seconds)
    : m_hours(hours)
    , m_minutes(minutes)
    , m_seconds(seconds)
{}

Time::Time(const Time& other)
    : m_hours(other.m_hours)
    , m_minutes(other.m_minutes)
    , m_seconds(other.m_seconds)
{}

Time Time::operator+(const Time& other)
{
    const int s = m_seconds + other.m_seconds;
    const int m = m_minutes + other.m_minutes + s / 60;
    const int h = m_hours + other.m_hours + m / 60;

    return Time(
        h % 24,
        m % 60,
        s % 60
    );
}

Time Time::operator-(const Time& other)
{
    const int s = m_seconds - other.m_seconds + 60;
    const int m = m_minutes - other.m_minutes + 60 + (s - 120) / 60;
    const int h = m_hours   - other.m_hours   + 24 + (m - 120) / 60;

    return Time(
        h % 24,
        m % 60,
        s % 60
    );
}

std::ostream& operator<<(std::ostream& ostream, const Time& self)
{
    using namespace std;
    ostream
        << setfill('0')
        << setw(2) << self.m_hours   << ':'
        << setw(2) << self.m_minutes << ':'
        << setw(2) << self.m_seconds << 'h';
    return ostream;
}
