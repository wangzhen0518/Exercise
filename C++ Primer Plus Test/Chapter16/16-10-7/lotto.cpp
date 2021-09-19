#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include<time.h>

std::vector<int> Lotto(int ran, int num)
{
    srand(time(NULL));
    using std::vector;
    vector<int> all_num(ran);
    for (int i = 0; i < ran; i++)
        all_num[i] = i + 1;

    std::random_shuffle(all_num.begin(), all_num.end());
    vector<int> r(num);
    std::copy(all_num.begin(), all_num.begin() + num, r.begin());
    std::sort(r.begin(), r.end());
    return r;
}

int main()
{
    using std::vector;
    int ran = 61;
    int num = 10;
    vector<int> winners(Lotto(ran, num));
    std::copy(winners.begin(), winners.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}