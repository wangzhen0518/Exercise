// https://www.luogu.com.cn/problem/P1083
#include <algorithm>
#include <iostream>
#include <vector>

struct Order {
    int id;
    int d, s, t;
};

bool judge(std::vector<int> const& r, std::vector<Order> const& qlist, int k) {
    std::vector<long long> diff(r.size(), 0);  // 记录第i天的需求比第i-1天变换多少
    for (int i = 1; i <= k; ++i) {
        auto const& q = qlist[i];
        diff[q.s] += q.d;
        if (q.t + 1 < r.size())
            diff[q.t + 1] -= q.d;
    }
    long long sum = 0;
    for (int i = 1; i < r.size(); ++i) {
        sum += diff[i];
        if (sum > (long long)(r[i]))
            return false;
    }
    return true;
}

int search(std::vector<int> const& r, std::vector<Order> const& qlist) {
    int L = 1, R = qlist.size() - 1;
    int res = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (judge(r, qlist, mid)) {
            res = mid;
            L = mid + 1;
        } else
            R = mid - 1;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> r(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &r[i]);
    std::vector<Order> qlist(m + 1);
    qlist[0].id = qlist[0].d = qlist[0].s = qlist[0].t = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &qlist[i].d, &qlist[i].s, &qlist[i].t);
        qlist[i].id = 1;
    }
    int id = search(r, qlist);
    if (id != m)
        printf("-1\n%d", id + 1);
    else
        printf("0");
    return 0;
}