#include <iostream>
#include <string>
#include <vector>

struct Toy {
  int direction;
  std::string profession;
};

int search(std::vector<Toy> const& toys, int a, int s, int pos) {
  int n = toys.size();
  switch (toys[pos].direction + a) {
    case 0:
    case 2:
      pos = (pos - s + n) % n;
      break;
    case 1:
      pos = (pos + s) % n;
      break;
    default:
      printf("Error");
      break;
  }
  return pos;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<Toy> toys(n);
  for (int i = 0; i < n; ++i)
    std::cin >> toys[i].direction >> toys[i].profession;
  int pos = 0;
  for (int i = 0; i < m; ++i) {
    int a, s;
    scanf("%d%d", &a, &s);
    pos = search(toys, a, s, pos);
  }
  printf("%s", toys[pos].profession.c_str());
  return 0;
}