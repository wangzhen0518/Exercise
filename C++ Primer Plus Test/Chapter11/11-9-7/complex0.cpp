#include <iostream>
#include "complex0.h"

complex complex::operator~() const
{
    return complex(m_reality, -m_imaginary);
}
complex complex::operator+(const complex &c) const
{
    return complex(m_reality + c.m_reality, m_imaginary + c.m_imaginary);
}
complex complex::operator-(const complex &c) const
{
    return complex(m_reality - c.m_reality, m_imaginary - c.m_imaginary);
}
complex complex::operator-() const
{
    return complex(-m_reality, -m_imaginary);
}
complex complex::operator*(const complex &c) const
{
    return complex(m_reality * c.m_reality - m_imaginary * c.m_imaginary,
                   m_reality * c.m_imaginary + m_imaginary * c.m_reality);
}
complex complex::operator*(double n) const
{
    return complex(n * m_reality, n * m_imaginary);
}
complex operator*(double n, const complex &c)
{
    return complex(n * c.m_reality, n * c.m_imaginary);
}

std::istream &operator>>(std::istream &os, complex &c)
{
    using std::cout;
    cout << "real: ";
    if (!(os >> c.m_reality))
        return os;
    cout << "imaginary: ";
    os >> c.m_imaginary;
    return os;
}
std::ostream &operator<<(std::ostream &os, const complex &c)
{
    os << "(" << c.m_reality << ", " << c.m_imaginary << "i)";
    return os;
}
