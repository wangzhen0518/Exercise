// https://www.luogu.com.cn/problem/P1036
#include <cmath>
#include <iostream>

int judge(int x) {
  for (int i = 2; i <= sqrt(x); ++i)
    if (x % i == 0)
      return 0;
  return 1;
}

int count(int k, int sum, int start, int end, int* a) {
  if (k == 0)
    return judge(sum);
  if (k > end - start + 1)
    return 0;
  int n = 0;
  for (int i = start; i <= end; ++i)
    n += // count(k - 1, sum + a[i], start, i - 1, a) +
        count(k - 1, sum + a[i], i + 1, end, a);
  return n;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int* x = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", x + i);
  printf("%d\n", count(k, 0, 0, n - 1, x));
  delete[] x;
  return 0;
}