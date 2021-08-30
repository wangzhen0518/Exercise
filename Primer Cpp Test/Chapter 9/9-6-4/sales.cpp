#include <iostream>
#include "sales.h"

void SALES::setSales(Sales &s, const double ar[], int n)
{
    int i = 0;
    double sum = 0;
    s.max = s.min = ar[0];
    for (; i < n && i < QUARTERS; i++)
    {
        s.sales[i] = ar[i];
        sum += ar[i];
        if (ar[i] > s.max)
            s.max = ar[i];
        if (ar[i] < s.min)
            s.min = ar[i];
    }
    if (i < QUARTERS)
    {
        if (s.min > 0)
            s.min = 0;
        for (; i < QUARTERS; i++)
            s.sales[i] = 0;
    }
    s.average = sum / QUARTERS;
}

void SALES::setSales(Sales &s)
{
    using std::cin;
    using std::cout;
    using std::endl;
    double ar[QUARTERS];
    int n = 0;
    cout << "Enter numbers:\n";
    while (cin && n < QUARTERS)
    {
        cin >> ar[n];
        n++;
    }
    while (cin.get() != '\n')
        ;
    cout << "Enter n:\n";
    cin >> n;
    setSales(s, ar, n);
}

void SALES::showSales(const Sales &s)
{
    using std::cout;
    using std::endl;
    cout << "sales: ";
    for (int i = 0; i < QUARTERS; i++)
        cout << s.sales[i] << " ";
    cout << endl;
    cout << "max: " << s.max << endl;
    cout << "min: " << s.min << endl;
    cout << "average: " << s.average << endl;
}
