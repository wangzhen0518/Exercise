#include "Time.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h + m / 60;
    minutes = m % 60;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time &t1, const Time &t2)
{
    return Time(t1.hours + t2.hours, t1.minutes + t2.minutes);
}

Time operator-(const Time &t1, const Time &t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t1.minutes + 60 * t1.hours;
    tot2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

Time operator*(const Time &t, double n)
{
    return Time(t.hours * n, t.minutes * n);
}
Time operator*(double n, const Time &t)
{
    return Time(t.hours * n, t.minutes * n);
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
