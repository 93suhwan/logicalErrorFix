#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int n, k;
const double eps = 1e-6;
struct node {
  double x, y;
} a[maxn];
struct dar {
  double angle;
  int val;
  bool operator<(dar b) const { return angle < b.angle; }
};
struct vec {
  dar c[5100000];
  int cnt;
  void push_back(double x, int val) {
    c[++cnt].angle = x;
    c[cnt].val = val;
  }
  void reset() { cnt = 0; }
  void sot() { sort(c + 1, c + 1 + cnt); }
  bool chk() {
    int x = 0;
    for (int i = 1; i <= cnt; i++) {
      x += c[i].val;
      if (x >= k) return true;
    }
    return false;
  }
};
vec g;
bool check(double r) {
  g.reset();
  for (int i = 1; i <= n; i++) {
    double d = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
    if (d - 2 * r >= eps) continue;
    double alpha = atan2(a[i].y, a[i].x);
    double beta = acos(d / (2 * r));
    if (alpha > beta && alpha > 0) {
      g.push_back(alpha - beta, 1);
      g.push_back(alpha + beta, -1);
    } else if (alpha < beta && alpha > 0) {
      g.push_back(0, 1);
      g.push_back(alpha + beta, -1);
      g.push_back(alpha + 2 * acos(-1) - beta, 1);
      g.push_back(2 * acos(-1), -1);
    } else if (-alpha > beta) {
      alpha += 2 * acos(-1);
      g.push_back(alpha - beta, 1);
      g.push_back(alpha + beta, -1);
    } else {
      g.push_back(0, 1);
      g.push_back(alpha + beta, -1);
      g.push_back(alpha + 2 * acos(-1) - beta, 1);
      g.push_back(2 * acos(-1), -1);
    }
  }
  g.sot();
  return g.chk();
}
signed main() {
  double r = 200008.0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
  }
  double l = 0.0;
  while (r - l > eps) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", r);
  return 0;
}
