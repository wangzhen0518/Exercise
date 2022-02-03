// https://www.luogu.com.cn/problem/P1047
#include <cstring>
#include <iostream>

int main() {
  int l, m;
  scanf("%d%d", &l, &m);
  int u, v;
  char* visited = new char[l + 1]{0};
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    memset(visited + u, 1, (v - u + 1) * sizeof(char));
  }
  int count = 0;
  for (int i = 0; i <= l; ++i) count += visited[i];
  printf("%d\n", l + 1 - count);
  delete[] visited;
  return 0;
}