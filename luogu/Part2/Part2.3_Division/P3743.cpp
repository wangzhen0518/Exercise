#include <algorithm>
#include <iostream>
#include <vector>

const double delta = 1e-4;

bool judge(std::vector<double> const& a,
           std::vector<double> const& b,
           double p,
           double t) {
    double sum = 0;  // 记录需要充电的总时长
    for (int i = 0; i < a.size(); ++i) {
        // 如果 a[i] * t < b[i], 则不需要充电
        sum += std::max<double>((a[i] * t - b[i]) / p, 0);
    }
    return sum <= t;
}

double search(std::vector<double> const& a,
              std::vector<double> const& b,
              double p) {
    double suma = 0, sumb = 0;
    double l = 1e8, r = 0;
    for (int i = 0; i < a.size(); ++i) {
        l = std::min(b[i] / a[i], l);
        suma += a[i];
        sumb += b[i];
    }
    if (suma <= p)
        return -1;
    r = sumb / (suma - p);
    double res = 0;
    while (std::abs(r - l) >= delta) {
        double mid = (l + r) / 2;
        if (judge(a, b, p, mid)) {
            res = mid;
            l = mid;
        } else
            r = mid;
    }
    return res;
}

int main() {
    int n;
    double p;
    scanf("%d%lf", &n, &p);
    std::vector<double> a(n);
    std::vector<double> b(n);
    for (int i = 0; i < n; ++i)
        scanf("%lf%lf", &a[i], &b[i]);
    printf("%.5lf", search(a, b, p));
    return 0;
}