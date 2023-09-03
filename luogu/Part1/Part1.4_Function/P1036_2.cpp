#include <cmath>
#include <iostream>
#include <vector>

bool is_prime(int x) {
  for (int i = 2; i <= std::sqrt(x); ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int dfs(int p,
        int s,
        int e,
        std::vector<int> const& xn,
        std::vector<int>& idx) {
  if (p == 0) {
    int sum = 0;
    for (int i = 0; i < idx.size(); ++i) {
      // printf("%d + ", xn[idx[i]]);
      sum += xn[idx[i]];
    }
    // printf("= %d ", sum);
    int cnt = is_prime(sum);
    // if (cnt == 1)
    //   printf("True\n");
    // else
    //   printf("False\n");
    return cnt;
  }
  if (p > e - s) {
    // printf("error: s:%d, e:%d\n", s, e);
    return 0;
  }
  int cnt = 0;
  for (int i = s; i < e - p + 1; ++i) {
    idx.push_back(i);
    cnt += dfs(p - 1, i + 1, e, xn, idx);
    idx.pop_back();
  }
  return cnt;
}

// 由于 n, k 不大，最多的组合数 C(20, 10)=184756
// 所以可以直接采取遍历所有组合，判断计算出的数是否是质数
int count(std::vector<int> const& xn, int n, int k) {
  std::vector<int> idx;
  int cnt = dfs(k, 0, n, xn, idx);
  return cnt;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> xn(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &xn[i]);
  printf("%d", count(xn, n, k));
  return 0;
}