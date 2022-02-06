// https://www.luogu.com.cn/problem/P1464
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

// int w(std::vector<std::vector<std::vector<int>>>& t, int a, int b, int c)
// {
long long w(long long t[21][21][21], long long a, long long b, long long c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return w(t, 20, 20, 20);
  if (!t[a][b][c]) {
    if (a < b && b < c)
      t[a][b][c] =
          w(t, a, b, c - 1) + w(t, a, b - 1, c - 1) - w(t, a, b - 1, c);
    else
      t[a][b][c] = w(t, a - 1, b, c) + w(t, a - 1, b - 1, c) +
                   w(t, a - 1, b, c - 1) - w(t, a - 1, b - 1, c - 1);
  }
  return t[a][b][c];
}

// 如果a≤0 or b≤0 or c≤0就返回值1.
// 如果a>20 or b>20 or c>20就返回w(20,20,20)
// 如果a<b并且b<c
// 就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
// 其它的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)

int main() {
  using std::vector;

  long long a, b, c;
  long long t[21][21][21];
  scanf("%lld%lld%lld", &a, &b, &c);
  t[0][0][0] = 1;
  while (!(a == -1 && b == -1 && c == -1)) {
    memset(t, 0, sizeof(t));
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(t, a, b, c));
    scanf("%lld%lld%lld", &a, &b, &c);
  }
  return 0;
}