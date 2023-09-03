#include <iostream>
#include <vector>

long long merge(std::vector<int>& a, int p, int q, int r) {
  long long cnt = 0;
  std::vector<int> L(q - p + 1);  // 包含 q
  std::vector<int> R(r - q);      // 不含 q
  for (int i = 0; i < L.size(); ++i)
    L[i] = a[p + i];
  for (int i = 0; i < R.size(); ++i)
    R[i] = a[q + i + 1];

  int i = 0, j = 0, k = p;
  while (i < L.size() && j < R.size()) {
    if (L[i] > R[j]) {
      a[k++] = R[j++];
      cnt += L.size() - i;
    } else {
      a[k++] = L[i++];
    }
  }
  while (i < L.size())
    a[k++] = L[i++];
  while (j < R.size())
    a[k++] = R[j++];
  return cnt;
}

long long count(std::vector<int>& a, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    return count(a, l, mid) + count(a, mid + 1, r) + merge(a, l, mid, r);
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  printf("%lld\n", count(a, 0, n - 1));
  return 0;
}