#include <iostream>
#include <vector>

int main() {
  long long a1, a2, n;
  scanf("%lld%lld%lld", &a1, &a2, &n);
  long long d = a2 - a1;
  long long sum = (2 * a1 + (n - 1) * d) * n / 2;
  printf("%lld", sum);
  return 0;
}