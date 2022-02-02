#include <iostream>

void print_table(long long **t, int n, int m) {
  printf("%6s", "");
  for (int j = 0; j <= m; ++j) printf("%5d", j);
  printf("\n");
  for (int j = 0; j <= 5 * m + 10; ++j) printf("-");
  printf("\n");
  for (int i = 0; i <= n; ++i) {
    printf("%5d|", i);
    for (int j = 0; j <= m; ++j) printf("%5d", t[i][j]);
    printf("\n");
  }
}

inline bool judge(int i, int j, int n, int m) {
  if ((i == n - 2 && j == m - 1) || (i == n - 2 && j == m + 1) ||
      (i == n - 1 && j == m - 2) || (i == n - 1 && j == m + 2) ||
      (i == n + 1 && j == m - 2) || (i == n + 1 && j == m + 2) ||
      (i == n + 2 && j == m - 1) || (i == n + 2 && j == m + 1) ||
      (i == n && j == m))
    return false;
  else
    return true;
}

long long count_path(int n1, int m1, int n2, int m2) {
  long long **total = new long long *[n1 + 1];
  for (int i = 0; i <= n1; ++i) total[i] = new long long[m1 + 1]{0};

  // first line
  if (judge(0, 1, n2, m2))
    total[0][1] = 1;
  else
    total[0][1] = 0;
  for (int j = 2; j <= m1; ++j)
    if (judge(0, j, n2, m2))
      total[0][j] = total[0][j - 1];
    else
      total[0][j] = 0;

  for (int i = 1; i <= n1; ++i) {
    if (judge(i, 0, n2, m2))
      if (i != 1)
        total[i][0] = total[i - 1][0];
      else
        total[i][0] = 1;
    else
      total[i][0] = 0;
    for (int j = 1; j <= m1; ++j)
      if (judge(i, j, n2, m2))
        total[i][j] = total[i - 1][j] + total[i][j - 1];
      else
        total[i][j] = 0;
  }

  // print_table(total, n1, m1);
  return total[n1][m1];
}

int main() {
  int n1, m1, n2, m2;
  scanf("%d%d%d%d", &n1, &m1, &n2, &m2);
  printf("%lld\n", count_path(n1, m1, n2, m2));
  return 0;
}