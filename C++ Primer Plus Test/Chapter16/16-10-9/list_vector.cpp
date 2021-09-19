#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
#include <time.h>
#include <random>

int main()
{
    using namespace std;
    const int NUM = 1000000;
    srand(time(NULL));
    vector<int> vi0(NUM);
    for (int i = 0; i < NUM; i++)
    {
        vi0[i] = rand();
    }
    vector<int> vi(vi0);
    list<int> li(NUM);
    copy(vi0.begin(), vi0.end(), li.begin());

    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "vi: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    li.sort();
    end = clock();
    cout << "li: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    copy(vi0.begin(), vi0.end(), li.begin());

    start = clock();
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << "copy: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}