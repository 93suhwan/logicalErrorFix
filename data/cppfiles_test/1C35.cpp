#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const double eps = 1e-6;
const double pi = acos(-1);
int sgn(double x) { return x < -eps ? -1 : x > eps; }
struct Point {
  double x, y;
  double Len2() const { return x * x + y * y; }
  double Len() const { return sqrt(x * x + y * y); }
} a[N];
int n, K;
struct node {
  double x;
  int v;
  bool operator<(const node &s) const { return x < s.x; }
} b[N * 4];
int m = 0;
void add(double l, double r) {
  if (sgn(l - (-pi)) < 0) {
    add(l + pi * 2, pi);
    add(-pi, r);
  } else if (sgn(r - pi) > 0) {
    add(l, pi);
    add(-pi, r - pi * 2);
  } else {
    b[++m] = (node){l, 1};
    b[++m] = (node){r + eps, -1};
  }
}
bool check(double r) {
  m = 0;
  for (int i = (1), _t = (n); i <= _t; ++i) {
    if (sgn(4 * r * r - a[i].Len2()) < eps) {
      continue;
    }
    double p = atan2(a[i].y, a[i].x);
    double delt = acos(a[i].Len() / 2 / r);
    add(p - delt, p + delt);
  }
  sort(b + 1, b + m + 1);
  int t = 0;
  if (t >= K) return 1;
  for (int i = (1), _t = (m); i <= _t; ++i) {
    t += b[i].v;
    if (t >= K) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &K);
  int c = 0;
  for (int i = (1), _t = (n); i <= _t; ++i) {
    ++c;
    scanf("%lf%lf", &a[c].x, &a[c].y);
    if (sgn(a[c].x) == 0 && sgn(a[c].y) == 0) {
      --c;
      --K;
    }
  }
  n = c;
  double L = 0, R = 5e5;
  while (R - L > eps) {
    double mid = (L + R) / 2;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  printf("%lf\n", L);
  return 0;
}
