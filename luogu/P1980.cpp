#include <iostream>
#include <string>

int main() {
  int n, x;
  int count = 0;
  scanf("%d%d", &n, &x);
  std::string str = "";
  for (int i = 1; i <= n; ++i) {
    str += std::to_string(i);
  }
  for (int i = 0; i < str.length(); ++i)
    if (std::atoi(&str[i]) == x) ++count;
  printf("%d\n", count);
  return 0;
}