#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf &g, const char *name, int hc)
{
    strncpy(g.fullname, name, Len);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using std::cin;
    using std::cout;
    using std::string;
    char name[Len];
    int hc;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter handicap: ";
    cin >> hc;
    setgolf(g, name, hc);
    if (strlen(name) == 0)
        return 0;
    else
        return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    using std::cout;
    using std::endl;

    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}