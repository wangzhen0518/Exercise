// https://www.luogu.com.cn/problem/P1085
#include <iostream>

int main() {
  int max = 0;
  int day;
  for (int i = 0; i < 7; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x + y > max) {
      max = x + y;
      day = i;
    }
  }
  if (max > 8)
    printf("%d\n", day + 1);
  else
    printf("0\n");
  return 0;
}