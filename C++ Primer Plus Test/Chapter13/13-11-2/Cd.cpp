#include <iostream>
#include <cstring>
#include "Cd.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd &d)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}
Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}
void Cd::Report() const
{
    using std::cout;
    using std::endl;
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}
Cd &Cd::operator=(const Cd &d)
{
    if (this != &d)
    {
        delete[] performers;
        delete[] label;
        performers = new char[strlen(d.performers) + 1];
        label = new char[strlen(d.label) + 1];
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
    }
    return *this;
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x)
    : Cd(s2, s3, n, x)
{
    main_works = new char[strlen(s1) + 1];
    strcpy(main_works, s1);
}
Classic::Classic() : Cd()
{
    main_works = new char[1];
    main_works[0] = '\0';
}
void Classic::Report() const
{
    using std::cout;
    using std::endl;
    Cd::Report();
    cout << "main works: " << main_works << endl;
}
Classic &Classic::operator=(const Classic &d)
{
    if (this != &d)
    {
        Cd::operator=(d);
        delete[] main_works;
        main_works = new char[strlen(d.main_works) + 1];
        strcpy(main_works, d.main_works);
    }
    return *this;
}
Classic::~Classic()
{
    delete[] main_works;
}