#include <iostream>
using std::cout;
#include "Stone.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn + (int)lbs / Lbs_per_stn;
    pds_left = lbs - (int)lbs / Lbs_per_stn;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() // destructor
{
}

Stonewt Stonewt::operator+(const Stonewt &s) const
{
    return Stonewt(pounds + s.pounds);
}
Stonewt Stonewt::operator-(const Stonewt &s) const
{
    return Stonewt(pounds - s.pounds);
}
Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n);
}
Stonewt operator*(double n, const Stonewt &s)
{
    return Stonewt(s.pounds * n);
}
bool Stonewt::operator>(const Stonewt &s) const
{
    if (pounds > s.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator>=(const Stonewt &s) const
{
    if (pounds >= s.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator<(const Stonewt &s) const
{
    if (pounds < s.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator<=(const Stonewt &s) const
{
    if (pounds <= s.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator==(const Stonewt &s) const
{
    if (pounds == s.pounds)
        return true;
    else
        return false;
}
bool Stonewt::operator!=(const Stonewt &s) const
{
    if (pounds != s.pounds)
        return true;
    else
        return false;
}
// conversion functions
Stonewt::operator int() const
{

    return int(pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

std::ostream &operator<<(std::ostream &os, const Stonewt &s)
{
    if (s.mode == Stonewt::INT)
        os << s.stone << " stone, " << s.pds_left << " pounds\n";
    else if (s.mode == Stonewt::FLOAT)
        os << s.pounds << " pounds\n";
    return os;
}
