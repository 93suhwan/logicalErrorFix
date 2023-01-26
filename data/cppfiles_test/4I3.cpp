#include <bits/stdc++.h>
using namespace std;
struct C {
  double x, y, r;
};
vector<pair<double, double>> intersect(const C& c1, const C& c2);
struct xy {
  double x, y;
} a[212121];
int n, k;
vector<pair<double, double>> intersect(const C& c1, const C& c2) {
  double x = c1.x - c2.x, y = c1.y - c2.y, r1 = c1.r, r2 = c2.r,
         R = x * x + y * y;
  double d1 = R - (r1 + r2) * (r1 + r2), d2 = R - (r1 - r2) * (r1 - r2);
  if (d1 > 0 || d2 < 0) return {};
  double tx = x * (R - r1 * r1 + r2 * r2), ty = y * (R - r1 * r1 + r2 * r2);
  double t = sqrt(-(double)d1 * (double)d2);
  return {make_pair(c2.x + (tx - y * t) / (2.0L * R),
                    c2.y + (ty + x * t) / (2.0L * R)),
          make_pair(c2.x + (tx + y * t) / (2.0L * R),
                    c2.y + (ty - x * t) / (2.0L * R))};
}
struct point {
  double x, y;
  int col, sa;
};
double ccw(point a, point b, point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}
point zero = {0, 0, 0};
double EPS = 1e-14;
int get_sa(point xx) {
  auto [x, y, col, sa] = xx;
  if (x > EPS && -EPS <= y && y <= EPS) return 1;
  if (x > EPS && y > EPS) return 2;
  if (-EPS <= x && x <= EPS && y > EPS) return 3;
  if (x < -EPS && y > EPS) return 4;
  if (x < -EPS && -EPS <= y && y <= EPS) return 5;
  if (x < -EPS && y < -EPS) return 6;
  if (-EPS <= x && x <= EPS && y < -EPS) return 7;
  return 8;
}
bool sort_point(point a, point b) {
  if (a.sa != b.sa) return a.sa < b.sa;
  double c = ccw(zero, a, b);
  if (-EPS <= c && c <= EPS)
    return a.col > b.col;
  else
    return c > EPS;
}
int ck[212121];
int process(double X) {
  int i, j;
  vector<point> L;
  for (i = 0; i < n; i++) {
    ck[i] = 0;
    auto [x, y] = a[i];
    if (x * x + y * y > 4 * X * X) continue;
    C c1, c2;
    c1 = {0, 0, X};
    c2 = {x, y, X};
    auto RES = intersect(c1, c2);
    point p1, p2;
    p1.x = RES[0].first;
    p1.y = RES[0].second;
    p2.x = RES[1].first;
    p2.y = RES[1].second;
    if (ccw(p1, zero, p2) > 0) swap(p1, p2);
    p1.col = +(i + 1);
    p2.col = -(i + 1);
    p1.sa = get_sa(p1);
    p2.sa = get_sa(p2);
    L.push_back(p1);
    L.push_back(p2);
  }
  sort(L.begin(), L.end(), sort_point);
  int now = 0;
  for (auto [x, y, col, sa] : L) {
    int jdc = abs(col);
    if (col < 0 && !ck[jdc]) continue;
    ck[jdc] = 1;
    if (col > 0)
      now++;
    else
      now--;
    if (now >= k) return 1;
  }
  for (auto [x, y, col, sa] : L) {
    int jdc = abs(col);
    if (col < 0 && !ck[jdc]) continue;
    ck[jdc] = 1;
    if (col > 0)
      now++;
    else
      now--;
    if (now >= k) return 1;
  }
  return 0;
}
int main() {
  int i, j;
  double s, e, R;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = {(double)x, (double)y};
  }
  s = 0, e = 2e5 + 1;
  for (int i = 0; i <= 50; i++) {
    double m = (s + e) / 2;
    if (process(m)) {
      e = m;
      R = m;
    } else
      s = m;
  }
  printf("%.10lf\n", R);
  return 0;
}
