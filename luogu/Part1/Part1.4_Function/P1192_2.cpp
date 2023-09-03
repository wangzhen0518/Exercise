#include <iostream>
#include <vector>

#define MOD_BASE 100003

int dfs(std::vector<int>& cnt, int n, int k) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  if (cnt[n] == 0) {
    if (n > k) {
      for (int i = 1; i <= k; ++i)
        cnt[n] = (cnt[n] + dfs(cnt, n - i, k)) % MOD_BASE;
    } else {
      for (int i = 1; i < n; ++i)
        cnt[n] = (cnt[n] + dfs(cnt, n - i, k)) % MOD_BASE;
      cnt[n]++;
    }
  }
  return cnt[n];
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  std::vector<int> cnt(N + 1, 0);
  printf("%d", dfs(cnt, N, K));
  return 0;
}