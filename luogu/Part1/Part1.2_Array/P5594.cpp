// https://www.luogu.com.cn/problem/P5594
#include <iostream>

void print_table(int** s, int k, int m) {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < m; ++j) printf("%5d", s[i][j]);
    printf("\n");
  }
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int** s = new int*[k];
  for (int i = 0; i < k; ++i) s[i] = new int[m]{0};

  int x;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &x);
      ++s[x - 1][j];
    }
  }
  int* total = new int[k]{0};
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i][j] != 0) ++total[i];
  // print_table(s, k, m);
  // printf("\n");
  for (int i = 0; i < k; ++i) printf("%d ", total[i]);
  printf("\n");

  delete[] total;
  for (int i = k - 1; i >= 0; --i) delete[] s[i];
  delete[] s;
  return 0;
}