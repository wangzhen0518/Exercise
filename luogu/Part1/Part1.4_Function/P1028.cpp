// https://www.luogu.com.cn/problem/P1028
#include <iostream>

int count(int x) {
  int* f = new int[x + 1]{0};
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= i / 2; ++j)
      f[i] += f[j];
    ++f[i];
  }
  return f[x];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", count(n));
  return 0;
}