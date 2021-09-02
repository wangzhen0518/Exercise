#include <iostream>
#include <cstring>
#include "Cow.h"

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}
Cow::Cow(const char *nm, const char *ho, double wt)
{
    strncpy(name, nm, 20);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow()
{
    delete[] hobby;
}
Cow &Cow::operator=(const Cow &c)
{
    if (this != &c)
    {
        strcpy(name, c.name);
        delete[] hobby;
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
        weight = c.weight;
    }
    return *this;
}
void Cow::ShowCow() const
{
    using std::cout;
    cout << "Name is " << name << ", hobby is " << hobby << '\n';
}
