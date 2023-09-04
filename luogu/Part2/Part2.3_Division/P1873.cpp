#include <algorithm>
#include <iostream>
#include <vector>

bool is_enough(std::vector<int> const& height, int H, int M) {
  long long sum = 0;
  for (int h : height)
    sum += std::max(0, h - H);
  return sum >= M;
}

int search(std::vector<int> const& height, int M) {
  int L = 1e9, R = 0;
  for (int h : height) {
    if (h < L)
      L = h;
    if (h > R)
      R = h;
  }
  while (L < R) {
    int mid = (L + R + 1) >> 1;
    if (is_enough(height, mid, M))
      L = mid;
    else
      R = mid + 1;
  }
  return L;
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  std::vector<int> height(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &height[i]);
  printf("%d", search(height, M));
  return 0;
}