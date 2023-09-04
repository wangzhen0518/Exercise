#include <iostream>
#include <vector>

bool is_satisfied(std::vector<int> const& D, int step, int M) {
    int cnt = 0;
    int pos = 0;
    for (int i = 1; i < D.size(); ++i) {
        if (D[i] - D[pos] < step)
            ++cnt;
        else
            pos = i;
    }
    return cnt <= M;
}

bool is_satisfied2(std::vector<int> const& D, int step, int M) {
    int cnt = 0;
    int i = 0;
    while (i < D.size() - 1) {
        int j = i + 1;
        while (j < D.size() - 1 && D[j] - D[i] < step)
            ++j, ++cnt;
        if (D[j] - D[i] < step)
            return false;
        i = j;
    }
    return cnt <= M;
}

int search(std::vector<int> const& D, int L, int M) {
    int l = 0, r = L;
    int res;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (is_satisfied(D, mid, M)) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    return res;
}

int main() {
    int L, N, M;
    scanf("%d%d%d", &L, &N, &M);

    std::vector<int> D(N + 2);
    D.front() = 0;
    D.back() = L;
    for (int i = 1; i <= N; ++i)
        scanf("%d", &D[i]);
    printf("%d", search(D, L, M));

    return 0;
}
