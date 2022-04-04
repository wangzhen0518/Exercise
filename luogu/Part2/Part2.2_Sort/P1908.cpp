// https://www.luogu.com.cn/problem/P1908

#include <iostream>

long long merge(int* arr, int l, int m, int r) {
  long long cnt = 0;
  int* temp = new int[r - l + 1];
  int i = l, j = m + 1, k = 0;
  while (i <= m && j <= r) {
    if (arr[i] > arr[j]) {
      temp[k++] = arr[j++];
      cnt += m - i + 1;
    } else
      temp[k++] = arr[i++];
  }
  while (i <= m) temp[k++] = arr[i++];
  while (j <= r) temp[k++] = arr[j++];
  for (i = l, k = 0; i <= r; ++i, ++k) arr[i] = temp[k];
  delete[] temp;
  return cnt;
}
long long merge_sort(int* arr, int l, int r) {
  long long cnt = 0;
  if (l < r) {
    int mid = (l + r) / 2;
    cnt += merge_sort(arr, l, mid);
    cnt += merge_sort(arr, mid + 1, r);
    cnt += merge(arr, l, mid, r);
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) scanf("%d", arr + i);
  long long cnt = merge_sort(arr, 0, n - 1);
  printf("%lld\n", cnt);
  delete[] arr;
  return 0;
}