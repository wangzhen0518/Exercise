// https://www.luogu.com.cn/problem/P4994
#include <iostream>

int main() {
  int M;
  scanf("%d", &M);
  int n = 1;
  int f2 = 1, f1 = 1, f0 = 0;
  while (!(f1 % M == 0 && f2 % M == 1)) {
    f0 = f1, f1 = f2;
    f2 = (f1 + f0) % M;
    ++n;
  }
  printf("%d\n", n);
  return 0;
}