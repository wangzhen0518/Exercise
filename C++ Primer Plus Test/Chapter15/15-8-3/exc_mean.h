// exc_mean.h  -- exception classes for hmean(), gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
#include <stdexcept>

class mean_base : public std::logic_error
{
private:
    double _a;
    double _b;

public:
    mean_base(double a = 0.0, double b = 0.0, std::string str = "mean_base error")
        : _a(a), _b(b), logic_error(str) {}
    virtual ~mean_base() {}
    virtual void show_error() const { std::cout << "(" << _a << ", " << _b << ")"
                                                << " error: " << what(); }
};

class bad_hmean : public mean_base
{
public:
    bad_hmean(double a = 0.0, double b = 0.0)
        : mean_base(a, b, "hmean() invalid arguments: a = -b\n") {}
    virtual ~bad_hmean() {}
    virtual void show_error() const
    {
        std::cout << "hmean";
        mean_base::show_error();
    }
};

class bad_gmean : public mean_base
{
public:
    bad_gmean(double a = 0.0, double b = 0.0)
        : mean_base(a, b, "gmean() arguments should be >= 0\n") {}
    ~bad_gmean() {}
    virtual void show_error() const
    {
        std::cout << "gmean";
        mean_base::show_error();
    }
};

#endif
