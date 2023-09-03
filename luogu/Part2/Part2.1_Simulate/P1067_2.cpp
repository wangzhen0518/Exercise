#include <iostream>
#include <vector>

void print_item(int c, int n, int idx) {
  if (c != 0) {
    if (idx == 0) {
      if (n == 0)
        printf("%d", c);
      else if (n == 1) {
        if (c == 1)
          printf("+x");
        else if (c == -1)
          printf("-x");
        else
          printf("%dx", c);
      } else {
        if (c == 1)
          printf("x^%d", n);
        else if (c == -1)
          printf("-x^%d", n);
        else
          printf("%dx^%d", c, n);
      }
    } else {
      if (n == 0)
        printf("%+d", c);
      else if (n == 1) {
        if (c == 1)
          printf("+x");
        else if (c == -1)
          printf("-x");
        else
          printf("%+dx", c);
      } else {
        if (c == 1)
          printf("+x^%d", n);
        else if (c == -1)
          printf("-x^%d", n);
        else
          printf("%+dx^%d", c, n);
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int c;
  std::vector<int> clist(n + 1);
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &c);
    print_item(c, n - i, i);
  }
  // for (int i = 0; i <= n; ++i)
  //   print_item(clist[i], n - i, i);
  return 0;
}