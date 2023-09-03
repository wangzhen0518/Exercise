// https://www.luogu.com.cn/problem/P1563
#include <iostream>
#include <vector>

void get_input(std::vector<char>& record) {
  char c;
  c = getchar();
  while (c != 'E') {
    if (c == 'W' || c == 'L')
      record.emplace_back(c);
    c = getchar();
  }
}

void deal_cp(std::vector<char>& record, int n) {
  int w = 0, l = 0;
  int len = record.size();
  for (int i = 0; i < len; ++i) {
    if (record[i] == 'W')
      ++w;
    else
      ++l;
    if ((w - l >= 2 || l - w >= 2) && (w >= n || l >= n)) {
      printf("%d:%d\n", w, l);
      w = l = 0;
    }
  }
  printf("%d:%d\n", w, l);
}

void count_score() {
  std::vector<char> record;
  get_input(record);
  deal_cp(record, 11);
  printf("\n");
  deal_cp(record, 21);
}

int main() {
  count_score();
  return 0;
}