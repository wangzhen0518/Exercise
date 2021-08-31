#include <iostream>
#include <cstring>
#include "Person.h"

Person::Person(const std::string &ln, const char *fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}
Person::~Person() {}

void Person::Show() const
{
    using std::cout;
    using std::endl;
    cout << fname << " " << lname << endl;
}
void Person::FormalShow() const
{
    using std::cout;
    using std::endl;
    cout << fname << ", " << lname << endl;
}