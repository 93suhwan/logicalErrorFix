#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 3e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
struct point {
  long double x, y;
  void go(long long x1, long long y1) {
    x = x1;
    y = y1;
  }
  void read() { cin >> x >> y; }
  point operator-(point b) { return point{x - b.x, y - b.y}; }
  point operator+(point b) { return point{x + b.x, y + b.y}; }
};
long double crp(point a, point b) { return a.x * b.y - b.x * a.y; }
long long areaoftriangle(point a, point b, point c) {
  return abs(crp(a, b) + crp(b, c) + crp(c, a));
}
bool pointVSseg(point a, point b, point c) {
  return (crp(b - a, b - c) == 0 && a.x >= min(b.x, c.x) &&
          a.x <= max(b.x, c.x) && a.y >= min(b.y, c.y) && a.y <= max(b.y, c.y));
}
bool pointVSpoint(point a, point b) { return a.x == b.x && a.y == b.y; }
long long orientation(point a, point b, point c) {
  long long val = crp(b - a, c - a);
  if (val == 0)
    return 0;
  else if (val < 0)
    return 1;
  else
    return 2;
}
bool intersection(point p1, point p2, point p3, point p4) {
  if (crp(p2 - p1, p4 - p3) == 0) {
    if (pointVSseg(p1, p3, p4) || pointVSseg(p2, p3, p4)) return 1;
    if (pointVSseg(p3, p1, p2) || pointVSseg(p4, p1, p2)) return 1;
    return false;
  }
  long long sign1 = crp(p2 - p1, p3 - p1);
  long long sign2 = crp(p2 - p1, p4 - p1);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) return false;
  sign1 = crp(p4 - p3, p1 - p3);
  sign2 = crp(p4 - p3, p2 - p3);
  if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) return false;
  return 1;
}
long double fnd_angle(point p) {
  long double len = sqrt(p.x * p.x + p.y * p.y);
  long double angle = acos(fabs(p.x) / len);
  if (p.y < 0) {
    if (p.x >= 0)
      angle = 2 * PI - angle;
    else
      angle += PI;
  } else if (p.x < 0)
    angle = PI - angle;
  return angle;
}
point p[KL];
long long areaofpolygon(int sz) {
  p[sz] = p[0];
  long long ret = 0;
  for (int i = 1; i <= sz; i++) ret += crp(p[i - 1], p[i]);
  return abs(ret);
}
long long pointVSpolygon(point a, int sz) {
  p[sz] = p[0];
  point b;
  b.go(a.x + 1, 1e9 + 10);
  long long cnt = 0;
  for (int i = 1; i <= sz; i++) {
    if (pointVSseg(a, p[i - 1], p[i])) return 2;
    if (intersection(a, b, p[i - 1], p[i])) cnt++;
  }
  if (cnt & 1)
    return 1;
  else
    return 0;
}
int n, k;
vector<point> A;
vector<pair<long double, int>> vec;
vector<pair<long double, long double>> a;
bool ok(long double mid) {
  vec.clear();
  a.clear();
  for (int i = 0; i < n; i++) {
    long double dis = sqrt(A[i].x * A[i].x + A[i].y * A[i].y);
    if (dis > 2 * mid) continue;
    long double angle = fnd_angle(A[i]) * 180 / PI;
    long double angle2 = acos(dis / (2.0 * mid)) * 180 / PI;
    a.push_back({angle - angle2, angle + angle2});
  }
  sort(a.begin(), a.end());
  int sz = a.size();
  for (int i = 0; i < sz; i++)
    a.push_back({a[i].first + 360, a[i].second + 360});
  multiset<long double> s;
  int mx = 0;
  for (int i = 0; i < a.size(); i++) {
    while (s.size() > 0 && *s.begin() < a[i].first) {
      s.erase(s.begin());
    }
    mx = max(mx, (int)s.size() + 1);
    s.insert(a[i].second);
  }
  return (mx >= k);
  return (mx >= k);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    point pp;
    pp.read();
    if (pp.x == 0 && pp.y == 0) {
      k--;
      continue;
    }
    A.push_back(pp);
  }
  n = A.size();
  long double lo = 0.0, hi = 2e5;
  int cnt = 50;
  while (cnt--) {
    long double mid = (lo + hi) / 2.0;
    if (ok(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << fixed << setprecision(8) << lo << "\n";
  return 0;
}
