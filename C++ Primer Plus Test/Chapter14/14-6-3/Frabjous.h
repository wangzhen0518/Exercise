#ifndef FRABJOUS_H_
#define FRABJOUS_H_

#include <cstring>
#include <iostream>

class Frabjous
{
private:
    char fab[20];

public:
    Frabjous(const char *s = "C++") { strncpy(fab, s, 19); }
    ~Frabjous() {}
    virtual void tell() { std::cout << fab << std::endl; }
};

class Gloam : private Frabjous
{
private:
    int glip;

public:
    Gloam(int g = 0, const char *s = "C++") : glip(g), Frabjous(s) {}
    Gloam(int g, const Frabjous &f) : glip(g), Frabjous(f) {}
    ~Gloam() {}
    virtual void tell()
    {
        std::cout << "glip: " << glip << std::endl;
        std::cout << "Frabjous: ";
        Frabjous::tell();
    }
};

#endif