#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
const double inf = 1e100;
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
  double x, y;
  PT() { x = 0, y = 0; }
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &a) const { return PT(x + a.x, y + a.y); }
  PT operator-(const PT &a) const { return PT(x - a.x, y - a.y); }
  PT operator*(const double a) const { return PT(x * a, y * a); }
  friend PT operator*(const double &a, const PT &b) {
    return PT(a * b.x, a * b.y);
  }
  PT operator/(const double a) const { return PT(x / a, y / a); }
  bool operator==(PT a) const {
    return sign(a.x - x) == 0 && sign(a.y - y) == 0;
  }
  bool operator!=(PT a) const { return !(*this == a); }
  bool operator<(PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
  bool operator>(PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
  double norm() { return sqrt(x * x + y * y); }
  double norm2() { return x * x + y * y; }
  PT perp() { return PT(-y, x); }
  double arg() { return atan2(y, x); }
  PT truncate(double r) {
    double k = norm();
    if (!sign(k)) return *this;
    r /= k;
    return PT(x * r, y * r);
  }
};
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline double cross2(PT a, PT b, PT c) { return cross(b - a, c - a); }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, double t) {
  return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t));
}
PT rotatecw(PT a, double t) {
  return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t));
}
double SQ(double x) { return x * x; }
double rad_to_deg(double r) { return (r * 180.0 / PI); }
double deg_to_rad(double d) { return (d * PI / 180.0); }
double get_angle(PT a, PT b) {
  double costheta = dot(a, b) / a.norm() / b.norm();
  return acos(max((double)-1.0, min((double)1.0, costheta)));
}
bool is_point_in_angle(PT b, PT a, PT c, PT p) {
  assert(orientation(a, b, c) != 0);
  if (orientation(a, c, b) < 0) swap(b, c);
  return orientation(a, c, p) >= 0 && orientation(a, b, p) <= 0;
}
vector<PT> circle_circle_intersection(PT a, double r, PT b, double R) {
  if (a == b && sign(r - R) == 0) return {PT(1e18, 1e18)};
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  PT v = (b - a) / d;
  ret.push_back(a + v * x + rotateccw90(v) * y);
  if (y > 0) ret.push_back(a + v * x - rotateccw90(v) * y);
  return ret;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<PT> v(n);
  for (auto &x : v) cin >> x.x >> x.y;
  auto get = [&](double r) {
    vector<pair<double, int>> tms;
    int cnt = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      vector<PT> res = circle_circle_intersection(PT(-r, 0), r, PT(0, 0),
                                                  dist(PT(0, 0), v[i]));
      if (res.size() == 0) continue;
      if (res.size() == 1) res.push_back(res[0]);
      double a[2];
      a[0] = get_angle(v[i], res[0]);
      if (sign(cross(v[i], res[0])) < 0) a[0] = 2 * PI - a[0];
      a[1] = get_angle(v[i], res[1]);
      if (sign(cross(v[i], res[1])) < 0) a[1] = 2 * PI - a[1];
      if (sign(dist(PT(-r, 0), v[i]) - r) <= 0) {
        cnt++;
        mx++;
        if (sign(a[1] - a[0]) <= 0) {
          tms.push_back({a[1], 1});
          tms.push_back({a[0], 0});
        } else {
          tms.push_back({a[0], 1});
          tms.push_back({a[1], 0});
        }
      } else {
        if (sign(a[1] - a[0]) <= 0) {
          tms.push_back({a[0], 1});
          tms.push_back({a[1], 0});
        } else {
          tms.push_back({a[1], 1});
          tms.push_back({a[0], 0});
        }
      }
    }
    sort(tms.begin(), tms.end());
    for (auto [x, y] : tms) {
      if (y == 0) {
        cnt++;
      } else {
        cnt--;
      }
      mx = max(mx, cnt);
    }
    return mx >= k;
  };
  int magic = 70;
  double l = 0, r = 2e5 + 5;
  while (magic--) {
    double mid = (l + r) / 2.0;
    if (get(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(10) << fixed << r << '\n';
}
