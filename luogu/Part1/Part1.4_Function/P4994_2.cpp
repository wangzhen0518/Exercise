#include <iostream>
#include <vector>

int fibonacci(int m) {
  int f0 = 0, f1 = 1, f2 = 1;
  int idx = 1;
  while (!(f1 == 0 && f2 == 1)) {
    f0 = f1;
    f1 = f2;
    f2 = (f0 + f1) % m;
    idx++;
  }
  return idx;
}

int main() {
  int m;
  scanf("%d", &m);
  printf("%d", fibonacci(m));
  return 0;
}