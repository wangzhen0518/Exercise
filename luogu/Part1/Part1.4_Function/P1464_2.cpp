#include <algorithm>
#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

long long w(long long a, long long b, long long c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);

  if (a < b && b < c)
    return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  else
    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
           w(a - 1, b - 1, c - 1);
}

long long special(long long a,
                  long long b,
                  long long c,
                  vector<vector<vector<long long>>> const& record) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  return record[a][b][c];
}

vector<vector<vector<long long>>> compute_w_matrix(long long a,
                                                   long long b,
                                                   long long c) {
  vector<vector<vector<long long>>> record(
      a + 1, vector<vector<long long>>(b + 1, vector<long long>(c + 1, 1)));

  for (int i = 0; i <= a; ++i)
    for (int j = 0; j <= b; ++j)
      for (int k = 0; k <= c; ++k) {
        if (i < j && j < k) {
          record[i][j][k] = special(i, j, k - 1, record) +
                            special(i, j - 1, k - 1, record) -
                            special(i, j - 1, k, record);
        } else {
          record[i][j][k] = special(i - 1, j, k, record) +
                            special(i - 1, j - 1, k, record) +
                            special(i - 1, j, k - 1, record) -
                            special(i - 1, j - 1, k - 1, record);
        }
      }
  return record;
}

long long deal(vector<vector<vector<long long>>> const& w_matrix,
               long long a,
               long long b,
               long long c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;
  if (a > 20 || b > 20 || c > 20)
    return w_matrix[20][20][20];
  return w_matrix[a][b][c];
}

int main() {
  vector<vector<vector<long long>>> w_matrix = compute_w_matrix(20, 20, 20);
  long long a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);
  while (!(a == -1 && b == -1 && c == -1)) {
    printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, deal(w_matrix, a, b, c));
    scanf("%lld%lld%lld", &a, &b, &c);
  }
  return 0;
}