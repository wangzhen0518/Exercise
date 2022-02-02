#include <iostream>

int main() {
  int n;
  int cost[3][2];
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) scanf("%d%d", &cost[i][0], &cost[i][1]);
  int num[3];
  for (int i = 0; i < 3; ++i)
    num[i] = (n + cost[i][0] - 1) / cost[i][0] * cost[i][1];
  int min = INT32_MAX;
  for (int i = 0; i < 3;++i)
    if (min > num[i]) min = num[i];
  printf("%d\n", min);
  return 0;
}