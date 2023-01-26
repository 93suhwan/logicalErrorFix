#include <bits/stdc++.h>
using i64 = long long;
const int MAXN = 100010;
const double PI = 3.14159265358979323846;
struct Pos {
  double x, y;
  Pos() = default;
  Pos(double x_, double y_) : x(x_), y(y_) {}
};
int n, k;
std::vector<Pos> arr;
std::vector<double> pd;
std::vector<double> pa;
bool check(double d) {
  std::vector<std::pair<double, double>> vec;
  vec.reserve(n * 2);
  for (int i = 0; i < n; ++i) {
    if (pd[i] < d) continue;
    double a = pa[i];
    double da = std::acos(d / pd[i]);
    double al = a - da, ar = a + da;
    if (al < 0) vec.emplace_back(al + 2 * PI, 2 * PI), al = 0;
    if (ar > 2 * PI) vec.emplace_back(0, ar - 2 * PI), ar = 2 * PI;
    vec.emplace_back(al, ar);
  }
  std::sort(vec.begin(), vec.end());
  std::priority_queue<double, std::vector<double>, std::greater<double>> pq;
  for (auto&& p : vec) {
    double x = p.first;
    while (!pq.empty() && pq.top() < x) pq.pop();
    pq.push(p.second);
    if (int(pq.size()) >= k) return true;
  }
  return false;
}
int main() {
  std::scanf("%d%d", &n, &k);
  arr.reserve(n);
  pd.reserve(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::scanf("%d%d", &x, &y);
    if (x == 0 && y == 0) {
      --k;
      continue;
    }
    double d = std::sqrt(i64(x) * x + i64(y) * y);
    double f = 1 / (d * d);
    arr.emplace_back(x * f, y * f);
    pd.push_back(1 / d);
    double a = std::atan2(y, x);
    if (a < 0) a += 2 * PI;
    pa.push_back(a);
  }
  n = arr.size();
  if (k <= 0)
    std::printf("%.10f\n", 0.0);
  else {
    double l = 0, r = 2e5;
    while (r - l > 1e-5) {
      double mid = 0.5 * (l + r);
      if (check(0.5 / mid))
        r = mid;
      else
        l = mid;
    }
    double result = 0.5 * (l + r);
    std::printf("%.10f\n", result);
  }
}
