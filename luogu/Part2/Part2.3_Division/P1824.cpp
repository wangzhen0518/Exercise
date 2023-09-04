// https://www.luogu.com.cn/problem/P1824
#include <algorithm>
#include <iostream>
#include <vector>

bool check(std::vector<unsigned> const& x, unsigned d, int C) {
    int cnt = 1;
    int pos = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] - x[pos] >= d) {
            ++cnt;
            pos = i;
        }
    }
    return cnt >= C;
}

unsigned search(std::vector<unsigned> const& x, int C) {
    unsigned l = 0, r = x.back() - x.front();
    unsigned res = 0;
    while (l <= r) {
        unsigned mid = (l + r) / 2;
        if (check(x, mid, C)) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return res;
}

int main() {
    int N, C;
    scanf("%d%d", &N, &C);
    std::vector<unsigned> x(N);
    for (int i = 0; i < N; i++) {
        scanf("%u", &x[i]);
    }
    std::sort(x.begin(), x.end());
    printf("%u", search(x, C));
    return 0;
}