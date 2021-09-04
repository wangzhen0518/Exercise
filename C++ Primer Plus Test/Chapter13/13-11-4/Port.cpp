#include <iostream>
#include "Port.h"

Port &Port::operator=(const Port &p)
{
    if (this != &p)
    {
        delete[] brand;
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    return *this;
}
Port &Port::operator+=(int b)
{
    bottles += b;
    return *this;
}
Port &Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}
int Port::BottleCount() const
{
    return bottles;
}
void Port::Show() const
{
    using std::cout;
    using std::endl;
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}
std::ostream &operator<<(std::ostream &os, const Port &p)
{
    os << p.brand << ", "
       << p.style << ", "
       << p.bottles;
    return os;
}

void VintagePort::Show() const
{
    using std::cout;
    using std::endl;
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}
std::ostream &operator<<(std::ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp << ", "
       << vp.nickname << ", "
       << vp.year;
    return os;
}