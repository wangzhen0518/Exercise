#ifndef FRABJOUS_H_
#define FRABJOUS_H_

#include <cstring>
#include<iostream>

class Frabjous
{
private:
    char fab[20];

public:
    Frabjous(const char *s = "C++") { strncpy(fab, s, 19); }
    ~Frabjous() {}
    void tell() { std::cout << fab << std::endl; }
};

class Gloam
{
private:
    int glip;
    Frabjous fb;

public:
    Gloam(int g = 0, const char *s = "C++") : glip(g), fb(s) {}
    Gloam(int g, const Frabjous &f) : glip(g), fb(f) {}
    ~Gloam() {}
    void tell()
    {
        std::cout << "glip: " << glip << std::endl;
        fb.tell();
    }
};

#endif