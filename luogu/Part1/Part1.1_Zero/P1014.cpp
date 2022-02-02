// https://www.luogu.com.cn/problem/P1014
#include <cmath>
#include <iostream>

int main() {
  int n, N;
  scanf("%d", &N);
  n = (sqrt(8 * N + 1) - 1) / 2;
  N -= n * (n + 1) / 2;
  if (N == 0) {
    if (n % 2 == 0)
      printf("%d/%d\n", n, 1);
    else
      printf("%d/%d\n", 1, n);
  } else {
    if (n % 2 == 0)
      printf("%d/%d\n", n + 2 - N, N);
    else
      printf("%d/%d\n", N, n + 2 - N);
  }
  return 0;
}