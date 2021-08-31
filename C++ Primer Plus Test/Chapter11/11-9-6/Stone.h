#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14
    }; // pounds per stone
    enum Mode
    {
        INT,
        FLOAT
    };
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
    Mode mode;

public:
    Stonewt(double lbs);          // construct from double pounds
    Stonewt(int stn, double lbs); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void setINT() { mode = INT; }
    void setFLOAT() { mode = FLOAT; }
    Stonewt operator+(const Stonewt &s) const;
    Stonewt operator-(const Stonewt &s) const;
    Stonewt operator*(double n) const;
    bool operator>(const Stonewt &s) const;
    bool operator>=(const Stonewt &s) const;
    bool operator<(const Stonewt &s) const;
    bool operator<=(const Stonewt &s) const;
    bool operator==(const Stonewt &s) const;
    bool operator!=(const Stonewt &s) const;
    operator int() const;
    operator double() const;
    friend Stonewt operator*(double n, const Stonewt &s);
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &s);
};
#endif
