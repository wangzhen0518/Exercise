#include <iostream>

template <class T>
T max5(const T arr[])
{
    int max = arr[0];
    for (int i = 1; i < 5; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main()
{
    using std::cout, std::endl;
    int a1[] = {2, 3, 1, 4, 5};
    double a2[] = {2.1, 4.1, 3.2, 4.3, 5.5};
    cout << max5(a1) << endl;
    cout << max5(a2) << endl;
    return 0;
}