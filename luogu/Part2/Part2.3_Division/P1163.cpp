#include <algorithm>
#include <iostream>
#include <vector>

bool is_larger(double eta, unsigned w0, unsigned w, unsigned m) {
  double sum = w0;
  for (int i = 0; i < m; ++i)
    sum = sum * (1 + eta) - w;
  if (sum > 0)
    return true;
  else
    return false;
}

double search(unsigned w0, unsigned w, unsigned m) {
  double l = 0, r = 5;
  double mid = (l + r) / 2;
  while (std::abs(r - l) >= 1e-4) {
    if (is_larger(mid, w0, w, m))
      r = mid;
    else
      l = mid;
    mid = (l + r) / 2;
  }
  return l;
}

int main() {
  unsigned w0, w, m;
  scanf("%u%u%u", &w0, &w, &m);
  printf("%.1lf", 100 * search(w0, w, m));
}