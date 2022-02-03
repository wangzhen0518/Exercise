// https://www.luogu.com.cn/problem/P1046
#include <iostream>
int main() {
  int h[10];
  int h0;
  for (int i = 0; i < 10; ++i) scanf("%d", h + i);
  scanf("%d", &h0);
  h0 += 30;

  int count = 0;
  for (int i = 0; i < 10; ++i)
    if (h[i] <= h0) ++count;
  printf("%d\n", count);
  return 0;
}