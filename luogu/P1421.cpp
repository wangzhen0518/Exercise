#include <iostream>

int main() {
  int a, b;
  int n, m;
  n = 1;
  m = 9;
  int cost0 = n * 10 + m;
  scanf("%d%d", &a, &b);
  int cost1 = a * 10 + b;
  printf("%d\n", cost1 / cost0);
  return 0;
}