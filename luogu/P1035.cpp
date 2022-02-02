#include <iostream>

int main() {
  int k;
  scanf("%d", &k);
  double sum = 0.0;
  int i = 0;
  while (sum <= k) {
    ++i;
    sum += 1.0 / i;
  }
  printf("%d\n", i);
  return 0;
}