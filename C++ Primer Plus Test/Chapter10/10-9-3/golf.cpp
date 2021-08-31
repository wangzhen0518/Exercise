#include <iostream>
#include <cstring>
#include "golf.h"

golf::golf(const char *name, int hc)
{
    strncpy(m_fullname, name, Len);
    m_handicap = hc;
}
golf::~golf() {}

bool golf::setgolf()
{
    using std::cin;
    using std::cout;
    char name[Len];
    int hc;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter handicap: ";
    cin >> hc;
    *this = golf(name, hc);
    if (strlen(name) == 0)
        return false;
    else
        return true;
}

void golf::handicap(int hc)
{
    m_handicap = hc;
}

void golf::show() const
{
    using std::cout;
    using std::endl;

    cout << "Name: " << m_fullname << endl;
    cout << "Handicap: " << m_handicap << endl;
}