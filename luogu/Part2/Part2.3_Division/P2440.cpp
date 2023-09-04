#include <algorithm>
#include <iostream>
#include <vector>

bool is_satisfied(std::vector<int> const& length, int l0, int k) {
  int cnt = 0;
  for (int l : length)
    cnt += l / l0;
  return cnt >= k;
}

int search(std::vector<int> const& length, int k) {
  int L = 0, R = 0;
  for (int l : length)
    if (l > R)
      R = l;
  while (L < R) {
    int mid = (L + R + 1) >> 1;
    if (is_satisfied(length, mid, k))
      L = mid;
    else
      R = mid - 1;
  }
  return R;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> length(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &length[i]);
  printf("%d", search(length, k));
  return 0;
}