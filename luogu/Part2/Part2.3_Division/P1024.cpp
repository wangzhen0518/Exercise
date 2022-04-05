// https://www.luogu.com.cn/problem/P1024
#include <cmath>
#include <iostream>

const static double precision = 1E-3;
double a, b, c, d;

inline double f(double x) { return a * x * x * x + b * x * x + c * x + d; }

double count(double l, double r, double (*f)(double x)) {
  double mid = (l + r) / 2;
  double l_f = f(l);
  double r_f = f(r);
  double mid_f = f(mid);
  while (r - l > precision) {
    if (mid_f * l_f < 0) {
      r = mid;
      r_f = mid_f;
    } else if (mid_f * r_f < 0) {
      l = mid;
      l_f = mid_f;
    }
    mid = (l + r) / 2;
    mid_f = f(mid);
  }
  return mid;
}

int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  int k = 0;
  double x[3] = {0.0};
  double i_f, ii_f;
  int i = -5;
  i_f = f(i);
  ii_f = f(i + 1);
  while (i < 5) {
    if (i_f == 0.0)
      x[k++] = i;
    else if (i_f * ii_f < 0)
      x[k++] = count(i, i + 1, f);
    ++i;
    i_f = ii_f;
    ii_f = f(i + 1);
    if (k == 3) break;
  }
  if (k < 3 && i_f < precision && i_f > -precision) x[k++] = i;
  for (int i = 0; i < k; ++i) printf("%.2lf ", x[i]);
  printf("\n");
  return 0;
}