// https://www.luogu.com.cn/problem/P1902
#include <climits>
#include <iostream>
#include <queue>

template <typename T>
T** alloc_matrix(T** matrix, int m, int n) {
  matrix = new T*[m];
  for (int i = 0; i < m; ++i) matrix[i] = new T[n]{0};
  return matrix;
}
template <typename T>
void delete_matrix(T** matrix, int m, int n) {
  for (int i = n - 1; i >= 0; --i) delete[] matrix[i];
  delete[] matrix;
}
// template<typename T>
void print_matrix(int** matrix, int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

bool judge(int** p, int n, int m, int cost) {
  bool** visited = alloc_matrix(visited, n, m);
  static int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
  int x = 0, y = 0;
  std::queue<std::pair<int, int>> q;

  q.push(std::make_pair(x, y));
  visited[x][y] = true;
  while (!q.empty()) {
    x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int xn = x + dx[i], yn = y + dy[i];
      if (xn < 0 || xn >= n || yn < 0 || yn >= m || visited[xn][yn]) continue;
      if (p[xn][yn] > cost) continue;
      if (xn == n - 1)
        return true;
      else {
        q.push(std::make_pair(xn, yn));
        visited[xn][yn] = true;
      }
    }
  }
  return false;
}

int count(int** p, int n, int m) {
  int min = 0, max = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (max < p[i][j]) max = p[i][j];
  int ans;
  int mid;
  while (min <= max) {
    mid = (min + max) >> 1;
    if (judge(p, n, m, mid))
      max = mid - 1, ans = mid;
    else
      min = mid + 1;
  }
  return ans;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int** p = alloc_matrix(p, n, m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &p[i][j]);
  printf("%d\n", count(p, n, m));
  delete_matrix(p, n, m);
  return 0;
}