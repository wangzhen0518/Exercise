// https://www.luogu.com.cn/problem/P1980
#include <iostream>
#include <string>

int main() {
  int n, x;
  int count = 0;
  scanf("%d%d", &n, &x);
  std::string str = "";
  for (int i = 1; i <= n; ++i)
    str += std::to_string(i);
  for (int i = 0; i < str.length(); ++i)
    if (str[i] == x + '0')
      ++count;

  printf("%d\n", count);
  return 0;
}