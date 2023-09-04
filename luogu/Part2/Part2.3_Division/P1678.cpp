#include <algorithm>
#include <iostream>
#include <vector>

long long summary(std::vector<int> const& in_score,
                  std::vector<int> const& test_score) {
  long long sum = 0;
  for (int i = 0; i < test_score.size(); ++i) {
    if (test_score[i] < in_score.front()) {
      sum += in_score.front() - test_score[i];
    } else if (test_score[i] > in_score.back()) {
      sum += test_score[i] - in_score.back();
    } else {
      int l = 0, r = in_score.size() - 1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (test_score[i] > in_score[mid])
          l = mid + 1;
        else
          r = mid;
      }
      if (l > 0)
        sum += std::min(in_score[l] - test_score[i],
                        test_score[i] - in_score[l - 1]);
      else
        sum += in_score[l] - test_score[i];
    }
  }
  return sum;
}

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  std::vector<int> in_score(m);
  std::vector<int> test_score(n);
  for (int i = 0; i < m; ++i)
    scanf("%d", &in_score[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &test_score[i]);
  std::sort(in_score.begin(), in_score.end());
  printf("%lld", summary(in_score, test_score));
  return 0;
}