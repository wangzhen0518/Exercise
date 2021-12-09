#include <iostream>
#include <vector>

bool judge(std::vector<int>& piles, int h, int rate) {
  int sum = 0;
  for (size_t i = 0; i < piles.size(); i++) {
    sum += (piles[i] - 1) / rate + 1;
    if (sum > h)
      return false;
  }
  return true;
}

int eat_rate(std::vector<int>& piles, int h) {
  int start = 1, end = 0;
  for (int i : piles)
    if (i > end)
      end = i;
  while (start < end) {
    int mid = (start + end) / 2;
    if (judge(piles, h, mid))
      end = mid;
    else
      start = mid + 1;
  }
  return start;
}

int main() {
  int N, h;
  scanf("%d%d", &N, &h);
  std::vector<int> piles(N);
  for (int i = 0; i < N; i++)
    scanf("%d", &piles[i]);
  printf("%d\n", eat_rate(piles, h));
  return 0;
}