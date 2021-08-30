#include <iostream>
#include "sales.cpp"
int main()
{
    SALES::Sales test;
    double ar[] = {1.2, 4.1, 32.4, 4.5};
    int n = 4;
    SALES::setSales(test);
    SALES::showSales(test);
    return 0;
}