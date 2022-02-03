// https://www.luogu.com.cn/problem/P2141
#include <iostream>
#include <unordered_set>

int main() {
  int n;
  scanf("%d", &n);
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) scanf("%d", arr + i);

  std::unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = arr[i] + arr[j];
      for (int k = 0; k < n; ++k)
        if (arr[k] == x) {
          s.insert(x);
          break;
        }
    }
  }
  printf("%ld\n", s.size());
  delete[] arr;
  return 0;
}