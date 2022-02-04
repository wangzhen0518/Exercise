// https://www.luogu.com.cn/problem/P1012
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool compare(std::string& s1, std::string& s2) {
  return s1 + s2 > s2 + s1;
}

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::sort;
  using std::string;
  using std::vector;

  int n;
  scanf("%d\n", &n);
  vector<string> a(n);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), compare);
  std::string output = "";
  for (int i = 0; i < n; ++i)
    output = output + a[i];
  printf("%s\n", output.c_str());
  return 0;
}