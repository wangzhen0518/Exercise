// https://www.luogu.com.cn/problem/P1179
#include <iostream>

int count_num(int p,int x){
  int cnt = 0;
  while (p != 0) {
    if (x == p % 10) ++cnt;
    p /= 10;
  }
  return cnt;
}

int main() { int L, R;
  scanf("%d%d", &L, &R);
  int x = 2;
  int cnt = 0;
  for (int i = L; i <= R; ++i) cnt += count_num(i, x);
  printf("%d\n", cnt);
  return 0;
}