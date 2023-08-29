#include <iostream>
#include <string>
#include <vector>

std::vector<char> read_line() {
// std::string read_line() {
  std::vector<char> input_line;
  char c = getchar();
  while (c != '\n') {
    if (c == '<') {
      if (!input_line.empty())
        input_line.pop_back();
    } else
      input_line.push_back(c);
    c = getchar();
  }
  // std::string s = "";
  // for (char ci : input_line)
  //   s.push_back(ci);
  return input_line;
  // return s;
}

bool str_equal(std::vector<char> const& s1, const char* s2) {
// bool str_equal(std::string const& s1, const char* s2) {
  int i = 0;
  while (i < s1.size() && s2[i] != '\0' && s1[i] == s2[i])
    i++;
  if (i == s1.size())
    return true;
  else
    return false;
  // return s1 == s2;
}

std::vector<std::vector<char>> read_input() {
// std::vector<std::string> read_input() {
  std::vector<std::vector<char>> input_content;
  // std::vector<std::string> input_content;
  std::vector<char> input_line = read_line();
  // std::string input_line = read_line();
  while (!str_equal(input_line, "EOF")) {
    input_content.push_back(input_line);
    input_line = read_line();
  }
  return input_content;
}

int main() {
  std::vector<std::vector<char>> content = read_input();
  std::vector<std::vector<char>> input = read_input();
  // std::vector<std::string> content = read_input();
  // std::vector<std::string> input = read_input();
  int t;
  scanf("%d", &t);

  int cnt = 0;
  for (int i = 0; i < content.size() && i < input.size(); ++i) {
    for (int j = 0; j < content[i].size() && j < input[i].size(); ++j)
      if (content[i][j] == input[i][j])
        cnt++;
  }
  printf("%d", int(cnt / (t / 60.0) + 0.5));
  return 0;
}