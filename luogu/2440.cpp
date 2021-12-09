#include <iostream>

bool judge(int length[], int l, int n, int k) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += length[i] / l;
    if (count >= k)
      return true;
  }
  return false;
}

int cut_log(int length[], int n, int k) {
  int start = 1, end = 0;
  for (int i = 0; i < n; i++)
    if (length[i] > end)
      end = length[i];
  int mid;
  while (start < end - 1) {
    mid = (start + end) / 2;
    if (judge(length, mid, n, k))
      start = mid;
    else
      end = mid;
  }
  return start;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int* length = new int[n];
  for (int i = 0; i < n; i++)
    scanf("%d", length + i);

  printf("%d\n", cut_log(length, n, k));
  delete[] length;
  return 0;
}