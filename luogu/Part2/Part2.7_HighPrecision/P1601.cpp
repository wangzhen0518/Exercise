// https://www.luogu.com.cn/problem/P1601

#include <iostream>
#include <string>
#include <vector>

void high_pre_add() {
  int *res;
  std::string a, b;
  std::cin >> a >> b;
  int len1 = a.length(), len2 = b.length();

  if (len1 > len2) {
    std::string delta = "";
    while (len2 < len1) {
      delta += '0';
      ++len2;
    }
    b = delta + b;
  } else if (len2 > len1) {
    std::string delta = "";
    while (len1 < len2) {
      delta += '0';
      ++len1;
    }
    a = delta + a;
  }

  int len_max = len1, len_min = len1;
  res = new int[len_max + 1];

  char c = 0;  //进位
  int i = 0;
  int j = len_min - 1;
  for (; i < len_min; ++i, --j) {
    char t = a[j] + b[j] - '0' * 2 + c;
    if (t >= 10) {
      t -= 10;
      c = 1;
    } else
      c = 0;
    res[i] = t;
  }
  if (c != 0) res[i++] = c;

  for (int p = i - 1; p >= 0; --p) printf("%d", res[p]);
  printf("\n");

  delete[] res;
}

int main() {
  high_pre_add();
  return 0;
}