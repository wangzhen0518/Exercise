// https://www.luogu.com.cn/problem/P1025
#include <iostream>
#include<vector>


int divide(int N, int K) {
  std::vector<std::vector<int>> t(N + 1, std::vector<int>(K + 1, 0));
  for (int i = 0; i <= K; ++i)
    t[i][i] = 1;
  for (int i = 1; i <= N; ++i)
    t[i][1] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 2; j <= std::min(i, K); ++j)
      t[i][j] = t[i - 1][j - 1] + t[i - j][j];
  }
  return t[N][K];
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  printf("%d\n", divide(N, K));
  return 0;
}