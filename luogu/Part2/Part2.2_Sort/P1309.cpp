// https://www.luogu.com.cn/problem/P1309
#include <algorithm>
#include <iostream>

struct athlete {
  int id;
  int score;
  int w;
};

inline bool cmp(const athlete& a1, const athlete& a2) {
  if (a1.score > a2.score || (a1.score == a2.score && a1.id < a2.id))
    return true;
  else
    return false;
}

void merge(athlete* arr, int* win, int* lose, int N,
           bool (*cmp)(const athlete& a1, const athlete& a2)) {
  athlete* temp = new athlete[2 * N];
  int i = 0, j = 0, k = 0;
  while (i < N && j < N) {
    if (cmp(arr[win[i]], arr[lose[j]])) {
      temp[k] = arr[win[i]];
      ++i;
    } else {
      temp[k] = arr[lose[j]];
      ++j;
    }
    ++k;
  }
  while (i < N) temp[k++] = arr[win[i++]];
  while (j < N) temp[k++] = arr[lose[j++]];
  for (int p = 0; p < 2 * N; ++p) arr[p] = temp[p];
  delete[] temp;
}

void one_round(athlete* arr, int N) {
  static int* win = new int[N];
  static int* lose = new int[N];
  for (int i = 0; i < N; ++i) {
    if (arr[2 * i].w > arr[2 * i + 1].w) {
      ++arr[2 * i].score;
      win[i] = 2 * i;
      lose[i] = 2 * i + 1;
    } else {
      ++arr[2 * i + 1].score;
      win[i] = 2 * i + 1;
      lose[i] = 2 * i;
    }
  }
  merge(arr, win, lose, N, cmp);
}

int main() {
  int N, R, Q;
  scanf("%d%d%d", &N, &R, &Q);
  athlete* arr = new athlete[2 * N];
  for (int i = 0; i < 2 * N; ++i) arr[i].id = i;
  for (int i = 0; i < 2 * N; ++i) scanf("%d", &arr[i].score);
  for (int i = 0; i < 2 * N; ++i) scanf("%d", &arr[i].w);

  std::sort(arr, arr + 2 * N, cmp);
  for (int i = 0; i < R; ++i) one_round(arr, N);
  printf("%d\n", arr[Q - 1].id + 1);

  delete[] arr;
  return 0;
}