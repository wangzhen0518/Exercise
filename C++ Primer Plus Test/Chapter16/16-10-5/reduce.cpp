#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

template <typename T>
int reduce(T ar[], int n)
{
    using namespace std;
    set<T> temp;
    copy(ar, ar + n, insert_iterator<set<T>>(temp, temp.begin()));
    copy(temp.begin(), temp.end(), ar);
    return temp.size();
}

int main()
{
    std::string ar[5] = {"wangzhen", "wangzhen", "cyl", "cyl", "me"};
    int len = reduce(ar, 5);
    for (int i = 0; i < len; i++)
        std::cout << ar[i] << " ";
    return 0;
}