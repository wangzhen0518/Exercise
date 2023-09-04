// https://www.luogu.com.cn/problem/P1314

#include <algorithm>
#include <iostream>
#include <vector>

long long calculate(std::vector<int> const& w,
                    std::vector<int> const& v,
                    std::vector<std::pair<int, int>> const& interval,
                    long long s,
                    int W0) {
    long long y = 0;
    std::vector<long long> w_record(w.size(), 0);
    std::vector<long long> wv_record(w.size(), 0);
    for (int i = 1; i < w.size(); ++i) {
        int w_tmp = (w[i] >= W0);
        int wv_tmp = (w[i] >= W0) * v[i];
        w_record[i] = w_record[i - 1] + w_tmp;
        wv_record[i] = wv_record[i - 1] + wv_tmp;
    }
    for (auto const& p : interval) {
        int l = p.first, r = p.second;
        y +=
            (w_record[r] - w_record[l - 1]) * (wv_record[r] - wv_record[l - 1]);
    }
    return y;
}

long long search(std::vector<int> const& w,
                 std::vector<int> const& v,
                 std::vector<std::pair<int, int>> const& interval,
                 long long s) {
    // 同时找出 y <= s 的最大值, 这对应 W1
    // y > s 的最小值, 这对应 W2
    // W1 >= W2
    int l = 1e9, r = 0;
    for (int i = 1; i < w.size(); ++i) {
        l = std::min(l, w[i]);
        r = std::max(r, w[i]);
    }
    int w1 = 0, w2 = 0;
    long long w1s = 1e12, w2s = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        long long y = calculate(w, v, interval, s, mid);
        if (y <= s) {
            w1 = mid;
            w1s = s - y;
            r = mid - 1;
        } else {
            w2 = mid;
            w2s = y - s;
            l = mid + 1;
        }
    }
    if (w1s < w2s)
        return w1s;
    else
        return w2s;
}

int main() {
    int n, m;
    long long s;
    scanf("%d%d%lld", &n, &m, &s);
    std::vector<int> w(n + 1, 0);
    std::vector<int> v(n + 1, 0);
    std::vector<std::pair<int, int>> interval(m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &w[i], &v[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &interval[i].first, &interval[i].second);
    printf("%lld", search(w, v, interval, s));
    return 0;
}