#include <iostream>
#include "Sales.h"

int main()
{
    using namespace SALES;
    double ar[] = {1.2, 4.1, 32.4, 4.5};
    Sales test{ar, 4};
    test.show();
    int n = 4;
    test.set();
    test.show();
    return 0;
}