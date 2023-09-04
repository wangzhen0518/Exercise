#include <algorithm>
#include <iostream>
#include <vector>

bool judge(std::vector<int> const& origin, int K, int d) {
    int cnt = 0;
    for (int i = 0; i < origin.size() - 1; ++i) {
        cnt += (origin[i + 1] - origin[i] - 1) / d;
        // -1 是为了避免整除时结果需要 -1
    }
    return cnt <= K;
}

int search(std::vector<int> const& origin, int K) {
    int l = 1, r = origin.back();
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(origin, K, mid)) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

int main() {
    int L, N, K;
    scanf("%d%d%d", &L, &N, &K);
    std::vector<int> origin(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &origin[i]);
    printf("%d", search(origin, K));
    return 0;
}