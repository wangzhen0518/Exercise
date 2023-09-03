#include <algorithm>
#include <iostream>
#include <vector>

struct Player {
  int id;
  int power;
  int score;
};

inline bool cmp(Player const& p1, Player const& p2) {
  if (p1.score == p2.score)
    return p1.id < p2.id;
  else
    return p1.score > p2.score;
}

inline std::vector<Player> merge(std::vector<Player>& a,
                                 std::vector<int>& winner,
                                 std::vector<int>& loser) {
  std::vector<Player> tmp(a.size());
  int k = 0;
  int i = 0, j = 0;
  while (i < winner.size() && j < loser.size()) {
    if (cmp(a[winner[i]], a[loser[j]]))
      tmp[k++] = a[winner[i++]];
    else
      tmp[k++] = a[loser[j++]];
  }
  while (i < winner.size())
    tmp[k++] = a[winner[i++]];
  while (j < loser.size())
    tmp[k++] = a[loser[j++]];
  return tmp;
}

int main() {
  int N, R, Q;
  scanf("%d%d%d", &N, &R, &Q);
  std::vector<Player> a(2 * N);
  for (int i = 0; i < 2 * N; ++i) {
    a[i].id = i + 1;
    scanf("%d", &a[i].score);
  }
  for (int i = 0; i < 2 * N; ++i)
    scanf("%d", &a[i].power);

  std::sort(a.begin(), a.end(), cmp);

  for (int i = 0; i < R; ++i) {
    std::vector<int> winner(N);
    std::vector<int> loser(N);
    for (int j = 0; j < N; ++j) {
      if (a[2 * j].power > a[2 * j + 1].power) {
        ++a[2 * j].score;
        winner[j] = 2 * j;
        loser[j] = 2 * j + 1;
      } else {
        ++a[2 * j + 1].score;
        winner[j] = 2 * j + 1;
        loser[j] = 2 * j;
      }
    }
    a = merge(a, winner, loser);
  }

  printf("%d", a[Q - 1].id);
  return 0;
}