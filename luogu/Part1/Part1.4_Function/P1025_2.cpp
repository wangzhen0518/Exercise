#include <iostream>
#include <vector>

int dp(int n, int k) {
  if (k > n)
    return 0;
  std::vector<std::vector<int>> m(n + 1, std::vector<int>(k + 1, 0));
  for (int j = 1; j <= k; ++j) {
    m[j][j] = 1;
    for (int i = j + 1; i <= n; ++i)
      m[i][j] = m[i - 1][j - 1] + m[i - j][j];
  }
  return m[n][k];
}

int dfs(int n, int k, int sup) {
  if (n == 0 && k == 0)
    return 1;
  if (n == 0 || k == 0) {
    // printf("ERROR n: %d, k: %d\n", n, k);
    return 0;
  }
  int cnt = 0;
  for (int i = std::min(n - k + 1, sup); i >= n / k; --i)
    cnt += dfs(n - i, k - 1, i);
  return cnt;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
//   printf("%d", dfs(n, k, n));
  printf("%d", dp(n, k));
  return 0;
}