// https://www.luogu.com.cn/problem/P5534
#include <iostream>

int main() {
  long long a1, a2, n;
  scanf("%lld%lld%lld\n", &a1, &a2, &n);
  long long d = a2 - a1;
  long long sum = n * a1 + n * (n - 1) * d / 2;
  printf("%lld\n", sum);
  return 0;
}