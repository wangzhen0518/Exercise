#include <iostream>
#include <cstring>

template <class T>
T maxn(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

template <>
char *maxn(char *arr[], int n)
{
    int *length = new int[n];
    for (int i = 0; i < n; i++)
        length[i] = strlen(arr[i]);
    int max = 0;
    for (int i = 1; i < n; i++)
        if (length[i] > length[max])
            max = i;
    delete[] length;
    return arr[max];
}

int main()
{
    using std::cout;
    using std::endl;
    int a1[] = {2, 3, 1, 4, 5};
    double a2[] = {2.1, 4.1, 3.2, 4.3, 5.5, 23.6};
    char *a3[] = {"汪震", "陈禹岚", "我喜欢你"};
    cout << maxn(a1, 5) << endl;
    cout << maxn(a2, 6) << endl;
    cout << maxn(a3, 3) << endl;
    return 0;
}