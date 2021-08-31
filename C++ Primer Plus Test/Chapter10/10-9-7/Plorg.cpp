#include <iostream>
#include <cstring>
#include "Plorg.h"

plorg::plorg(const char name[], int CI)
{
    strncpy(m_name, name, Len);
    m_CI = CI;
}
plorg::~plorg() {}

void plorg::setCI(int CI)
{
    m_CI = CI;
}

void plorg::show() const
{
    using std::cout;
    using std::endl;
    cout << "name: " << m_name << ", CI: " << m_CI << endl;
}
