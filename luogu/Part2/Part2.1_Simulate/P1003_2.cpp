#include <algorithm>
#include <iostream>
#include <vector>

struct Carpet {
  int id;
  int x;
  int y;
  int a;
  int b;
  int area;
  Carpet() {}
  Carpet(int _id, int x1, int x2, int x3, int x4)
      : id(_id), x(x1), y(x2), a(x3), b(x4), area(x3 * x4) {}
};

void print_matrix(std::vector<std::vector<int>> const& map) {
  for (auto const& line : map) {
    for (auto const& x : line) {
      printf("%d ", x);
    }
    printf("\n");
  }
  printf("\n");
}

int search(std::vector<Carpet> const& clist, int x, int y) {
  for (auto const& c : clist)
    if (x >= c.x && x <= c.x + c.a && y >= c.y && y <= c.y + c.b)
      return c.id;
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<Carpet> clist(n);
  int x_min = 1000000, x_max = 0;
  int y_min = 1000000, y_max = 0;
  for (int i = 0; i < n; ++i) {
    int a, b, g, k;
    scanf("%d%d%d%d", &a, &b, &g, &k);
    x_min = std::min(x_min, a);
    y_min = std::min(y_min, b);
    x_max = std::max(x_max, a + g);
    y_max = std::max(y_max, b + k);
    clist[i] = Carpet(i + 1, a, b, g, k);
  }
  int x, y;
  scanf("%d%d", &x, &y);

  std::sort(clist.begin(), clist.end(), [](Carpet const& c1, Carpet const& c2) {
    if (c1.area == c2.area)
      return c1.id > c2.id;
    else
      return c1.area > c2.area;
  });
  printf("%d", search(clist, x, y));
  return 0;
}