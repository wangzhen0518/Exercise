#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int reduce(long ar[], int n)
{
    using namespace std;
    set<long> temp;
    copy(ar, ar + n, insert_iterator<set<long>>(temp, temp.begin()));
    copy(temp.begin(), temp.end(), ar);
    for (int i = temp.size(); i < n; i++)
        ar[i] = 0;
    return temp.size();
}

int main()
{
    long ar[5] = {32, 10, 45, 10, 10};
    reduce(ar, 5);
    for (int i = 0; i < 5; i++)
        std::cout << ar[i] << " ";
    return 0;
}