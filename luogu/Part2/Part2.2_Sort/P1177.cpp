// https://www.luogu.com.cn/problem/P1177
#include <iostream>

void qsort(int arr[], int l, int r)  //应用二分思想
{
  int mid = arr[(l + r) / 2];
  int i = l, j = r;
  while (i < j) {
    while (arr[i] < mid) ++i;
    while (arr[j] > mid) --j;
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      ++i, --j;
    }
  }
  if (l < j) qsort(arr, l, j);
  if (i < r) qsort(arr, i, r);
}

int main() {
  int n;
  scanf("%d", &n);
  int *a = new int[n];
  for (int i = 0; i < n; ++i) scanf("%d", a + i);

  qsort(a, 0, n - 1);
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");

  delete[] a;
  return 0;
}