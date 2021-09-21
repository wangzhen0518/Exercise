#include <iostream>

template <typename T>
long double sum_value(T value) { return value; }

template <typename T, typename... Args>
long double sum_value(T value, Args... args)
{
    return value + sum_value(args...);
}

int main()
{
    using namespace std;

    cout << sum_value(52, 34, 98, 101) << endl;
    cout << sum_value('x', 'y', 95, 74, 'Z') << endl;
    cout << sum_value(0.2, 1e2, 54, 'M', '\t') << endl;

    return 0;
}