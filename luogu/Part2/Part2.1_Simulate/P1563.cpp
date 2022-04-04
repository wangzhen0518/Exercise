// https://www.luogu.com.cn/problem/P1563
#include <iostream>
#include <vector>

struct position {
  int face;
  char job[10];
};

void circle(std::vector<std::pair<int, std::string>> &list, int n, int m) {
  int p = 0;
  int a, s;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &s);
    if (a + list[p].first == 1)
      p = (p + s) % n;
    else
      p = (p + n - s) % n;
  }
  printf("%s\n", list[p].second.c_str());
}

void circle(position *list, int n, int m) {
  int p = 0;
  int a, s;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &s);
    if (a + list[p].face == 1)
      p = (p + s) % n;
    else
      p = (p + n - s) % n;
  }
  printf("%s\n", list[p].job);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  //   std::vector<std::pair<int, std::string>> list(n);
  //   for (int i = 0; i < n; ++i) std::cin >> list[i].first >> list[i].second;

  position *list = new position[n];
  for (int i = 0; i < n; ++i) scanf("%d%s", &list[i].face, list[i].job);

  circle(list, n, m);

  return 0;
}