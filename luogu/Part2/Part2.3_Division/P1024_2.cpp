#include <iostream>
#include <vector>

const double delta = 1e-2;

class MyFunc {
 private:
  double a, b, c, d;

 public:
  MyFunc() {}
  MyFunc(double _a, double _b, double _c, double _d)
      : a(_a), b(_b), c(_c), d(_d) {}
  double operator()(double x) const {
    return a * x * x * x + b * x * x + c * x + d;
  }
};

double search(double l, double r, MyFunc const& f) {
  double mid = (l + r) / 2;
  double fl = f(l), fr = f(r), fmid = f(mid);
  while (r - l > delta) {
    if (fl * fmid < 0) {
      r = mid;
      fr = fmid;
    } else if (fmid * fr < 0) {
      l = mid;
      fl = fmid;
    }
    mid = (l + r) / 2;
    fmid = f(mid);
  }
  return mid;
}

int main() {
  double a, b, c, d;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  MyFunc f(a, b, c, d);

  const double L = -100, R = 100;
  const double step = 0.9;
  std::vector<double> res;
  for (double p = L; p <= R; p += step) {
    if (std::abs(f(p)) < delta)
      res.push_back(p);
    // else if (f(p + delta) * f(p + step - delta) < 0)
    //   res.push_back(search(p + delta, p + step - delta, f));
    else if (f(p) * f(p + step) < 0)
      res.push_back(search(p, p + step, f));
  }
  for (double x : res) {
    printf("%.2lf ", x);
  }
  return 0;
}