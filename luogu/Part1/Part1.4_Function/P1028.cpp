#include <iostream>
#include <vector>

int dfs(int n) {
  if (n < 1)
    return 0;
  if (n == 1) {
    return 1;
  }

  int cnt = 1;
  for (int i = 1; i <= n / 2; ++i) {
    cnt += dfs(i);
  }
  return cnt;
}

int count(int n) {
  std::vector<int> record(n + 1, 0);
  record[1] = 1;
  for (int m = 1; m <= n; ++m) {
    for (int i = 1; i <= m / 2; ++i)
      record[m] += record[i];
    record[m] += 1;
  }
  return record[n];
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%d", count(n));
  return 0;
}