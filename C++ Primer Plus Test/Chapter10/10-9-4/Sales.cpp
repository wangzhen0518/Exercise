#include "Sales.h"
#include <iostream>

namespace SALES
{
    Sales::Sales(const double ar[], int n)
    {
        int i = 0;
        double sum = 0;
        m_max = m_min = ar[0];
        for (; i < n && i < QUARTERS; i++)
        {
            m_sales[i] = ar[i];
            sum += ar[i];
            if (ar[i] > m_max)
                m_max = ar[i];
            if (ar[i] < m_min)
                m_min = ar[i];
        }
        if (i < QUARTERS)
        {
            if (m_min > 0)
                m_min = 0;
            for (; i < QUARTERS; i++)
                m_sales[i] = 0;
        }
        m_average = sum / QUARTERS;
    }
    Sales::~Sales() {}

    void Sales::set()
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
        *this = Sales(ar, n);
    }
    void Sales::show() const
    {
        using std::cout;
        using std::endl;
        cout << "sales: ";
        for (int i = 0; i < QUARTERS; i++)
            cout << m_sales[i] << " ";
        cout << endl;
        cout << "max: " << m_max << endl;
        cout << "min: " << m_min << endl;
        cout << "average: " << m_average << endl;
    }
} // namespace SALES
