#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>

class complex
{
private:
    double m_reality;
    double m_imaginary;

public:
    complex()
    {
        m_reality = 0.0;
        m_imaginary = 0.0;
    }
    complex(double a, double b)
    {
        m_reality = a;
        m_imaginary = b;
    }
    ~complex(){};

    complex operator~() const;
    complex operator+(const complex &c) const;
    complex operator-(const complex &c) const;
    complex operator-() const;
    complex operator*(const complex &c) const;
    complex operator*(double n) const;
    friend complex operator*(double n, const complex &c);

    friend std::istream &operator>>(std::istream &os, complex &c);
    friend std::ostream &operator<<(std::ostream &os, const complex &c);
};

#endif