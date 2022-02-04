// https://www.luogu.com.cn/problem/P5587
#include <iostream>
#include <string>
#include <vector>

void deal_input(std::string& temp) {
  std::string t;
  for (char c : temp) {
    if (c == '<') {
        t.pop_back();
    } else
      t.push_back(c);
  }
  temp = t;
}

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;
  using std::vector;
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  const char* signal = "EOF";

  string temp;
  vector<string> passage;
  vector<string> input;
  getline(cin, temp);
  while (temp != signal) {
    deal_input(temp);
    passage.emplace_back(temp);
    getline(cin, temp);
  }
  getline(cin, temp);
  int n = passage.size();

  while (temp != signal) {
    deal_input(temp);
    input.emplace_back(temp);
    getline(cin, temp);
  }
  cin >> temp;
  int cost = atoi(temp.c_str());

  int i = 0;
  int count = 0;
  for (int i = 0; i < std::min(passage.size(), input.size()); ++i)
    for (int j = 0; j < std::min(passage[i].length(), input[i].length()); ++j) {
      if (passage[i][j] == input[i][j])
        ++count;
    }

  printf("%d\n", int(count * 60.0 / cost + 0.5));
  return 0;
}