// https://www.luogu.com.cn/problem/P1059
#include <iostream>

int main() {
  int N;
  scanf("%d", &N);
  int x;
  int arr[100];
  int rand_num[1001] = {0};
  for (int i = 0; i < N; ++i) {
    scanf("%d", &x);
    ++rand_num[x];
  }
  int j = 0;
  for (int i = 0; i < 1001; ++i) {
    if (rand_num[i]) arr[j++] = i;
  }
  printf("%d\n", j);
  for (int i = 0; i < j; ++i) printf("%d ", arr[i]);
  printf("\n");
  return 0;
}