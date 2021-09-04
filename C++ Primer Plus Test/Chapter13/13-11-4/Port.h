#ifndef PORT_H_
#define PORT_H_

#include <iostream>
#include <cstring>

class Port
{
private:
    char *brand;
    char style[20];
    int bottles;

public:
    Port(const char *br = "none", const char *st = "none", int b = 0)
    {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
        strncpy(style, st, 19);
        bottles = b;
    }
    Port(const Port &p)
    {
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    virtual ~Port() { delete[] brand; }
    Port &operator=(const Port &p);
    Port &operator+=(int b);
    Port &operator-=(int b);
    int BottleCount() const;
    virtual void Show() const;
    friend std::ostream &operator<<(std::ostream &os, const Port &p);
};

class VintagePort : public Port
{
private:
    char *nickname;
    int year;

public:
    VintagePort() : Port("none", "vintage", 0)
    {
        nickname = new char[1];
        nickname[0] = '\0';
        year = 0;
    }
    VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b)
    {
        nickname = new char[strlen(nn) + 1];
        strcpy(nickname, nn);
        year = y;
    }
    VintagePort(const VintagePort &vp) : Port(vp)
    {
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
    }
    ~VintagePort() { delete[] nickname; }
    VintagePort &operator=(const VintagePort &vp)
    {
        delete[] nickname;
        Port::operator=(vp);
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        year = vp.year;
        return *this;
    }
    void Show() const;
    friend std::ostream &operator<<(std::ostream &os, const VintagePort &vp);
};
#endif
