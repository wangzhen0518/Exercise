// exc_mean.h  -- exception classes for hmean(), gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
    bad_hmean() : logic_error("hmean() invalid arguments: a = -b\n") {}
    ~bad_hmean() {}
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean() : logic_error("gmean() arguments should be >= 0\n") {}
    ~bad_gmean() {}
};

#endif
