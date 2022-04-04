// https://www.luogu.com.cn/problem/P3952
#include <iostream>
#include <vector>
struct program {
  char i;
  char x[4], y[4];
};

void get_input(std::vector<std::string>& input, int n) {}

int judge() {
  int num;
  std::string complex;
  scanf("%d", &num);
  std::cin >> complex;
  std::vector<std::string> input(num);
  get_input(input, num);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int res = judge();
    switch (res) {
      case 0:
        printf("Yes\n");
        break;
      case 1:
        printf("No\n");
      case -1:
        printf("ERR\n");
        break;
    }
  }

  return 0;
}