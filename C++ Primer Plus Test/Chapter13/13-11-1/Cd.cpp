#include <iostream>
#include <cstring>
#include "Cd.h"

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    strncpy(performers, s1, 49);
    strncpy(label, s2, 19);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
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
    strncpy(main_works, s1, 99);
}
Classic::Classic() : Cd()
{
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
        strcpy(main_works, d.main_works);
    }
    return *this;
}