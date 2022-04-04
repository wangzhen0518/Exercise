// https://www.luogu.com.cn/problem/P2615
#include <iostream>

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

void fill_matrix(int** matrix, int N) {
  matrix[0][N / 2] = 1;
  int x_k = 0, y_k = N / 2;
  int x_kp = (x_k - 1 + N) % N, y_kp = (y_k + 1) % N;
  for (int k = 2; k <= N * N; ++k) {
    if (matrix[x_kp][y_kp] != 0) x_kp = x_k + 1, y_kp = y_k;
    x_k = x_kp, y_k = y_kp;
    x_kp = (x_k - 1 + N) % N, y_kp = (y_k + 1) % N;
    matrix[x_k][y_k] = k;
  }
}
void show_matrix(int** matrix, int m, int n) {
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

int main() {
  int N;
  scanf("%d", &N);
  int** matrix = alloc_matrix(matrix, N, N);
  fill_matrix(matrix, N);
  show_matrix(matrix, N, N);
  delete_matrix(matrix, N, N);
  return 0;
}