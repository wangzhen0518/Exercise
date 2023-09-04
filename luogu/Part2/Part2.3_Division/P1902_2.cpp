#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

bool judge(std::vector<std::vector<int>> const& p, int n, int m, int s) {
    const static std::vector<std::pair<int, int>> move = {
        std::make_pair(0, -1),  // up
        std::make_pair(-1, 0),  // left
        std::make_pair(1, 0),   // right
        std::make_pair(0, 1),   // down
    };

    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    std::vector<std::pair<int, int>> stack;
    stack.emplace_back(std::make_pair(0, 0));
    visited[0][0] = true;
    while (!stack.empty()) {
        int x = stack.back().first, y = stack.back().second;
        stack.pop_back();
        for (auto const& mv : move) {
            int xn = x + mv.first, yn = y + mv.second;
            if ((xn >= 0 && xn <= n - 1) && (yn >= 0 && yn <= m - 1) &&
                !visited[xn][yn] && p[xn][yn] <= s) {
                if (xn == n - 1)
                    return true;
                else {
                    stack.emplace_back(std::make_pair(xn, yn));
                    visited[xn][yn] = true;
                }
            }
        }
    }
    return false;
}

int search(std::vector<std::vector<int>> const& p, int n, int m) {
    int l = 1e6, r = 0;
    for (int i = 1; i < p.size() - 1; ++i)
        for (int j = 0; j < p[i].size(); ++j) {
            l = std::min(l, p[i][j]);
            r = std::max(r, p[i][j]);
        }
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (judge(p, n, m, mid)) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &p[i][j]);
    printf("%d\n", search(p, n, m));
    return 0;
}