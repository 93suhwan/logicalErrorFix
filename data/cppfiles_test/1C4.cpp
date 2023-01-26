#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 100;
const int ITERS = 60;
const double eps = 1e-9;
double sqr(double x) { return x * x; }
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
  friend point operator/(const point& p, double d) {
    return point(p.x / d, p.y / d);
  }
  friend point operator+(const point& a, const point& b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point& a, const point& b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator*(const point& p, double d) {
    return point(p.x * d, p.y * d);
  }
  double norm() const { return sqrt(sqr(x) + sqr(y)); }
};
int n, k;
vector<pair<point, pair<int, int>>> p;
bool can[N];
double x[N], y[N];
void init() {}
bool eq(double a, double b) { return fabs(a - b) < eps; }
int half(const point& p) {
  if (p.y > -eps) {
    return 0;
  }
  return 1;
}
double vec(const point& a, const point& b) { return a.x * b.y - b.x * a.y; }
bool vec_cmp(const pair<point, pair<int, int>>& a,
             const pair<point, pair<int, int>>& b) {
  int ha = half(a.first), hb = half(b.first);
  if (ha != hb) {
    return ha < hb;
  }
  double v = vec(a.first, b.first);
  if (v > eps) {
    return true;
  }
  if (v < -eps) {
    return false;
  }
  return a.second < b.second;
}
void build_inter(point p, double r, point* res) {
  point mid = p / 2;
  double d = sqrt(max(sqr(r) - sqr(mid.x) - sqr(mid.y), 0.0));
  if (eq(d, 0.0)) {
    res[0] = res[1] = mid;
    return;
  }
  point v(mid.y, -mid.x);
  v = v / v.norm();
  res[0] = mid + v * d;
  res[1] = mid - v * d;
}
bool check(double r) {
  p.clear();
  for (int i = 0; i < n; ++i) {
    can[i] = false;
    if (eq(x[i], 0) && eq(y[i], 0)) {
      continue;
    }
    if (sqr(x[i]) + sqr(y[i]) - 4 * sqr(r) > eps) {
      continue;
    }
    point inter[2];
    build_inter(point(x[i], y[i]), r, inter);
    assert(eq(inter[0].norm(), r));
    assert(eq(inter[1].norm(), r));
    assert(eq((inter[0] - point(x[i], y[i])).norm(), r));
    assert(eq((inter[1] - point(x[i], y[i])).norm(), r));
    p.push_back(make_pair(inter[0], make_pair(i, 0)));
    p.push_back(make_pair(inter[1], make_pair(i, 1)));
  }
  sort((p).begin(), (p).end(), vec_cmp);
  int nk = k;
  for (int it = 0; it < 2; ++it) {
    int i = 0;
    while (i < ((int)(p).size())) {
      int j = i;
      while (j + 1 < ((int)(p).size()) && eq(p[i].first.x, p[j + 1].first.x) &&
             eq(p[i].first.y, p[j + 1].first.y)) {
        ++j;
      }
      for (int k = i; k <= j; ++k) {
        if (p[k].second.second == 0) {
          if (!can[p[k].second.first]) {
            can[p[k].second.first] = true;
            --nk;
            if (nk <= 0) {
              return true;
            }
          }
        }
      }
      for (int k = i; k <= j; ++k) {
        if (p[k].second.second == 1) {
          if (can[p[k].second.first]) {
            can[p[k].second.first] = false;
            ++nk;
          }
        }
      }
      i = j + 1;
    }
  }
  return false;
}
void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lf %lf", x + i, y + i);
    if (eq(x[i], 0) && eq(y[i], 0)) {
      --k;
    }
  }
  if (k <= 0) {
    printf("0\n");
    return;
  }
  double l = 0, r = 2e5;
  for (int it = 0; it < ITERS; ++it) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.09lf\n", (l + r) / 2);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
