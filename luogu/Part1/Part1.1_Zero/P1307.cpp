// https://www.luogu.com.cn/problem/P1307
#include <iostream>

int main() {
  int N;
  scanf("%d", &N);
  int n = 0;
  while (N) {
    n = n * 10 + N % 10;
    N /= 10;
  }
  printf("%d\n", n);
  return 0;
}