#include <iostream>

struct Candidate {
  int k;
  int s;
};

bool cmp(Candidate const& c1, Candidate const& c2) {
  if (c1.s == c2.s)
    return c1.k < c2.k;
  else
    return c1.s > c2.s;
}
void quick_sort(Candidate* a, int l, int r) {
  if (l < r) {
    Candidate mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i < j) {
      while (cmp(a[i], mid))
        ++i;
      while (cmp(mid, a[j]))
        --j;
      if (i <= j) {
        std::swap(a[i], a[j]);
        ++i, --j;
      }
    }
    if (l < j)
      quick_sort(a, l, j);
    if (i < r)
      quick_sort(a, i, r);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Candidate* a = new Candidate[n];
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &a[i].k, &a[i].s);

  quick_sort(a, 0, n - 1);

  m = m * 1.5;
  int line = a[m - 1].s;
  while (m < n && a[m].s == line)
    ++m;
  printf("%d %d\n", line, m);
  for (int i = 0; i < m; ++i)
    printf("%d %d\n", a[i].k, a[i].s);
  delete[] a;
  return 0;
}