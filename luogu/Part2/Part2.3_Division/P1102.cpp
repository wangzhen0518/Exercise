#include <algorithm>
#include <iostream>
#include <vector>

long long count(std::vector<long long> const& a, long long C) {
  long long cnt = 0;
  for (int i = 0; i < a.size(); ++i) {
    int l0, l1;
    int l = i + 1, r = a.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] - a[i] < C)
        l = mid + 1;
      else
        r = mid;
    }
    if (a[l] - a[i] == C) {
      l0 = l;
      l = l0 - 1, r = a.size() - 1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] > a[l0])
          r = mid - 1;
        else
          l = mid;
      }
      l1 = l;
      cnt += l1 - l0 + 1;
    }
  }
  return cnt;
}

int main() {
  long long N, C;
  scanf("%lld%lld", &N, &C);
  std::vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    scanf("%lld", &a[i]);
  std::sort(a.begin(), a.end());
  printf("%lld", count(a, C));
  return 0;
}