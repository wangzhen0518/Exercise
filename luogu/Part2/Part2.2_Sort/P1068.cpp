// https://www.luogu.com.cn/problem/P1068
#include <iostream>

struct com {
  int k, s;
};

inline bool judge(const com& c1, const com& c2) {
  if (c1.s > c2.s || (c1.s == c2.s && c1.k < c2.k))
    return true;
  else
    return false;
}

void quick_sort(com* arr, int l, int r) {
  com mid = arr[(l + r) / 2];
  int i = l, j = r;
  while (i < j) {
    while (judge(arr[i], mid)) ++i;
    while (judge(mid, arr[j])) --j;
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      ++i, --j;
    }
  }
  if (l < j) quick_sort(arr, l, j);
  if (i < r) quick_sort(arr, i, r);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  com* p = new com[n];
  for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].k, &p[i].s);

  quick_sort(p, 0, n - 1);

  int num = m * 1.5;
  int score = p[num - 1].s;
  while (num < n && p[num].s == score) ++num;
  printf("%d %d\n", p[num - 1].s, num);
  for (int i = 0; i < num; ++i) printf("%d %d\n", p[i].k, p[i].s);

  delete[] p;
  return 0;
}