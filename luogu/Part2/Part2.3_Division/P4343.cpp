// https://www.luogu.com.cn/problem/P4343
#include <algorithm>
#include <iostream>
#include <vector>

using llong = long long;

int count(std::vector<int> const& log, llong n) {
    int cnt = 0;
    llong sum = 0;
    for (int i = 0; i < log.size(); ++i) {
        sum = std::max<llong>(sum + log[i], 0);
        if (sum >= n) {
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}

std::pair<llong, llong> search(std::vector<int> const& log, int k) {
    llong L = 1, R = 1e18;
    llong nmax = -1;
    while (L <= R) {
        llong mid = (L + R) / 2;
        int cnt = count(log, mid);
        if (cnt > k) {
            L = mid + 1;
        } else if (cnt < k) {
            R = mid - 1;
        } else {
            nmax = mid;
            L = mid + 1;
        }
    }

    L = 1, R = 1e18;
    llong nmin = -1;
    while (L <= R) {
        llong mid = (L + R) / 2;
        int cnt = count(log, mid);
        if (cnt > k) {
            L = mid + 1;
        } else if (cnt < k) {
            R = mid - 1;
        } else {
            nmin = mid;
            R = mid - 1;
        }
    }
    return std::make_pair(nmin, nmax);
}

int main() {
    int l, k;
    scanf("%d%d", &l, &k);
    std::vector<int> log(l);
    for (int i = 0; i < l; ++i)
        scanf("%d", &log[i]);
    auto res = search(log, k);
    if (res.first == -1 || res.second == -1)
        printf("-1");
    else
        printf("%lld %lld", res.first, res.second);
    return 0;
}