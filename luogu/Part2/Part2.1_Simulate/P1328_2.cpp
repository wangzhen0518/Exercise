#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> score_board = {
      {0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1},
      {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0},
  };
  int N, Na, Nb;
  scanf("%d%d%d", &N, &Na, &Nb);
  std::vector<int> seq_a(Na);
  std::vector<int> seq_b(Nb);
  for (int i = 0; i < Na; i++)
    scanf("%d", &seq_a[i]);
  for (int i = 0; i < Nb; i++)
    scanf("%d", &seq_b[i]);
  int score_a = 0, score_b = 0;
  for (int i = 0; i < N; ++i) {
    int action_a = seq_a[i % Na];
    int action_b = seq_b[i % Nb];
    score_a += score_board[action_a][action_b];
    score_b += score_board[action_b][action_a];
  }
  printf("%d %d", score_a, score_b);
  return 0;
}