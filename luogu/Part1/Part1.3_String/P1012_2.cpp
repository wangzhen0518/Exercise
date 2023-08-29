#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool cmp(std::string const& s1, std::string const& s2) {
  return s1 + s2 > s2 + s1;
}

int main() {
  int num;
  std::cin >> num;
  std::vector<std::string> arr(num);
  for (int i = 0; i < num; ++i)
    std::cin >> arr[i];
  std::sort(arr.begin(), arr.end(), cmp);
  std::string s = "";
  for (std::string const& si : arr)
    s += si;
  printf("%s", s.c_str());
  return 0;
}