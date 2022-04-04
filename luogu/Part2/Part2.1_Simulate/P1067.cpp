// https://www.luogu.com.cn/problem/P1067

#include <iostream>

int main() {
  int n;
  scanf("%d", &n);
  int *a = new int[n + 1];
  for (int i = n; i >= 0; --i) scanf("%d", a + i);
  if (n > 1) {
    if (a[n] == 1)
      printf("x^%d", n);
    else if (a[n] == -1)
      printf("-x^%d", n);
    else
      printf("%dx^%d", a[n], n);
    for (int i = n - 1; i > 1; --i)
      if (a[i] != 0) {
        if (a[i] == 1)
          printf("+x^%d", i);
        else if (a[i] == -1)
          printf("-x^%d", i);
        else
          printf("%+dx^%d", a[i], i);
      }
  }
  if (n > 0) {
    if (a[1] != 0) {
      if (n > 1) {
        if (a[1] == 1)
          printf("+x");
        else if (a[1] == -1)
          printf("-x");
        else
          printf("%+dx", a[1]);
      } else {
        if (a[1] == 1)
          printf("x");
        else if (a[1] == -1)
          printf("-x");
        else
          printf("%dx", a[1]);
      }
    }
    if (a[0] != 0) {
      printf("%+d\n", a[0]);
    }
  } else
    printf("%d\n", a[0]);
  delete[] a;
  return 0;
}