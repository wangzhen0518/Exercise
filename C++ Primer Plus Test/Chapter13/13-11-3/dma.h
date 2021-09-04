// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class dmaABC
{
private:
    char *label;
    int rating;

public:
    dmaABC(const char *l = "null", int r = 0);
    dmaABC(const dmaABC &rs);
    virtual ~dmaABC();
    dmaABC &operator=(const dmaABC &rs);
    virtual void View() const = 0;
};

//  Base Class Using DMA
class baseDMA : public dmaABC
{
public:
    baseDMA(const char *l = "null", int r = 0) : dmaABC(l, r) {}
    baseDMA(const baseDMA &rs) : dmaABC(rs) {}
    virtual ~baseDMA() {}
    virtual void View() const { dmaABC::View(); };
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA : public dmaABC
{
private:
    enum
    {
        COL_LEN = 40
    };
    char color[COL_LEN];

public:
    lacksDMA(const char *c = "blank", const char *l = "null",
             int r = 0);
    lacksDMA(const char *c, const dmaABC &rs);
    virtual ~lacksDMA() {}
    virtual void View() const;
};

// derived class with DMA
class hasDMA : public dmaABC
{
private:
    char *style;

public:
    hasDMA(const char *s = "none", const char *l = "null",
           int r = 0);
    hasDMA(const char *s, const dmaABC &rs);
    hasDMA(const hasDMA &hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA &rs);
    virtual void View() const;
};

#endif
