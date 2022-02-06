// https://www.luogu.com.cn/problem/P1192
#include <iostream>

const int res = 100003;

int count(int N, int K) {
  int* t = new int[N + 1];
  t[0] = t[1] = 1;
  for (int i = 2; i <= N; ++i)
    for (int j = 1; j <= std::min(i, K); ++j)
      t[i] = (t[i] + t[i - j]) % res;
  return t[N];
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  printf("%d\n", count(N, K));
  return 0;
}