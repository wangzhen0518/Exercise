#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>
class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(int h, int min = 0);
    ~Time(){};
    void AddMin(int min);
    void AddHr(int h);
    void Reset(int h = 0, int min = 0);
    friend Time operator+(const Time &t1, const Time &t2);
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(const Time &t, double n);
    friend Time operator*(double n, const Time &t);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};
#endif
