// https://www.luogu.com.cn/problem/P1003

#include <iostream>

struct blanket {
  int a, b;
  int g, k;
};

int map_map(blanket* list, int n, int x, int y) {
  for (int p = n - 1; p >= 0; --p) {
    int a = list[p].a, b = list[p].b;
    int g = list[p].g, k = list[p].k;
    if ((x >= a && x <= a + g) && (y >= b && y <= b + k)) return p + 1;
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  blanket* list = new blanket[n];
  for (int i = 0; i < n; ++i)
    scanf("%d%d%d%d", &list[i].a, &list[i].b, &list[i].g, &list[i].k);
  int x, y;
  scanf("%d%d", &x, &y);

  int id = map_map(list, n, x, y);
  printf("%d\n", id);

  delete[] list;
}