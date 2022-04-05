// https://www.luogu.com.cn/problem/P2678
#include <iostream>

inline bool judge(int* D, int N, int M, int distance) {
  int cnt = 0;
  for (int i = 0; i < N + 2;) {
    int j = i + 1;
    while (j < N + 2 && D[j] - D[i] < distance) ++j, ++cnt;
    i = j;
  }
  if (cnt > M)
    return false;
  else
    return true;
}
int remove(int* D, int N, int M) {
  int min = 0, max = D[N + 1];
  int mid;
  int res;
  while (max >= min) {
    mid = (min + max) / 2;
    if (judge(D, N, M, mid)) {
      res = mid;
      min = mid + 1;
    } else
      max = mid - 1;
  }
  return res;
}

int main() {
  int L, N, M;
  scanf("%d%d%d", &L, &N, &M);
  int* D = new int[N + 2];
  D[0] = 0, D[N + 1] = L;
  for (int i = 1; i <= N; ++i) scanf("%d", D + i);
  printf("%d\n", remove(D, N, M));
  return 0;
}