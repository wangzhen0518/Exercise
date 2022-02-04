// https://www.luogu.com.cn/problem/P5015
#include <iostream>

int main() {
  char str[6];
  std::cin.getline(str, 6);
  int i = 0, count = 0;
  while (str[i]) {
    if (str[i] != '\n' && str[i] != ' ')
      ++count;
    ++i;
  }
  printf("%d\n", count);
  return 0;
}