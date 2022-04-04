// https://www.luogu.com.cn/problem/P1328

#include <iostream>

int judge(int p, int q) {
  static int cp_list[5][5] = {{0, -1, 1, 1, -1},
                              {1, 0, -1, 1, -1},
                              {-1, 1, 0, -1, 1},
                              {-1, -1, 1, 0, 1},
                              {1, 1, -1, -1, 0}};
  return cp_list[p][q];
}

void count_num(int *A_list, int *B_list, int N, int NA, int NB) {
  int A_num = 0, B_num = 0;
  for (int i = 0; i < N; ++i) {
    int A_i = i % NA, B_i = i % NB;
    int cp = judge(A_list[A_i], B_list[B_i]);
    if (cp == 1)
      ++A_num;
    else if (cp == -1)
      ++B_num;
  }
  printf("%d %d\n", A_num, B_num);
}

int main() {
  int N, NA, NB;
  scanf("%d%d%d", &N, &NA, &NB);
  int *A_list = new int[NA];
  int *B_list = new int[NB];
  for (int i = 0; i < NA; ++i) scanf("%d", A_list + i);
  for (int i = 0; i < NB; ++i) scanf("%d", B_list + i);

  count_num(A_list, B_list, N, NA, NB);

  delete[] B_list;
  delete[] A_list;
  return 0;
}