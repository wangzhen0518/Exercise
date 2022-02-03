// https://www.luogu.com.cn/problem/P1427
#include <iostream>
#include <stack>

int main() {
  int x;
  std::stack<int> s;
  scanf("%d", &x);
  while (x) {
    s.push(x);
    scanf("%d", &x);
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  return 0;
}