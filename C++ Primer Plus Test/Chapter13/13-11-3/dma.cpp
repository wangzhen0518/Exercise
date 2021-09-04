// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>

//dmaABC methods
dmaABC::dmaABC(const char *l, int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}
dmaABC::dmaABC(const dmaABC &rs)
{
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}
dmaABC::~dmaABC()
{
    delete[] label;
}
dmaABC &dmaABC::operator=(const dmaABC &rs)
{
    if (this != &rs)
    {
        delete[] label;
        label = new char[strlen(rs.label) + 1];
        strcpy(label, rs.label);
        rating = rs.rating;
    }
    return *this;
}
void dmaABC::View() const
{
    using std::cout;
    using std::endl;
    cout << "label: " << label << endl;
    cout << "rating: " << rating << endl;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l, int r)
    : dmaABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const dmaABC &rs)
    : dmaABC(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const
{
    using std::cout;
    using std::endl;
    dmaABC::View();
    cout << "color: " << color << endl;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r)
    : dmaABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const dmaABC &rs)
    : dmaABC(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
    : dmaABC(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    dmaABC::operator=(hs); // copy base portion
    delete[] style;        // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}
void hasDMA::View() const
{
    using std::cout;
    using std::endl;
    dmaABC::View();
    cout << "sytle: " << style << endl;
}