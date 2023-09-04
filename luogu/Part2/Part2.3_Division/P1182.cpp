#include <algorithm>
#include <iostream>
#include <vector>

bool judge(std::vector<unsigned> const& a, unsigned s, unsigned M) {
    unsigned sum = 0;
    unsigned cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (sum + a[i] > s) {
            sum = 0;
            ++cnt;
        }
        sum += a[i];
    }
    cnt += 1;
    return cnt <= M;
}

unsigned search(std::vector<unsigned> const& a, unsigned M) {
    unsigned l = 0, r = 0;
    long long sum = 0;
    for (int i = 0; i < a.size(); ++i) {
        l = std::max(l, a[i]);
        sum += a[i];
    }
    r = std::min<long long>(sum, 1e9);
    unsigned res = 0;
    while (l <= r) {
        unsigned mid = (l + r) / 2;
        if (judge(a, mid, M)) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

int main() {
    unsigned N, M;
    scanf("%u%u", &N, &M);
    std::vector<unsigned> a(N);
    for (unsigned i = 0; i < N; ++i)
        scanf("%u", &a[i]);
    printf("%u\n", search(a, M));
    return 0;
}