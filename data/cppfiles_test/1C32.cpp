#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(T d) const { return Point(x * d, y * d); }
  Point operator/(T d) const { return Point(x / d, y / d); }
  T dot(Point p) const { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  double angle() const { return atan2(y, x); }
  Point unit() const { return *this / dist(); }
  Point perp() const { return Point(-y, x); }
  Point normal() const { return perp().unit(); }
  Point rotate(double a) const {
    return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, Point p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};
const double pi = acos(-1);
bool circleInter(Point<double> a, Point<double> b, double r1, double r2,
                 pair<Point<double>, Point<double>> &out) {
  if (a == b) {
    assert(r1 != r2);
    return false;
  }
  Point<double> vec = b - a;
  double d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2,
         p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2) return false;
  Point<double> mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  out = {mid + per, mid - per};
  return true;
}
void prec() {}
const double eps = 1e-9;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<Point<double>> pts(n);
  Point<double> O(0, 0);
  for (auto &p : pts) {
    cin >> p.x >> p.y;
    if (p == O) k--;
  }
  double lo = 0, hi = 2e5 + 10;
  for (int it = 0; it < 80; it++) {
    const double mid = (lo + hi) / 2;
    vector<pair<double, int>> ev;
    for (auto p : pts) {
      if (p == O) continue;
      pair<Point<double>, Point<double>> meet;
      if (circleInter(O, p, mid, mid, meet)) {
        double st = meet.second.angle();
        double en = meet.first.angle();
        if (en < st) en += 2 * pi;
        ev.emplace_back(st, -1);
        ev.emplace_back(en + eps, 1);
        ev.emplace_back(st + 2 * pi, -1);
        ev.emplace_back(en + eps + 2 * pi, 1);
      }
    }
    sort(ev.begin(), ev.end());
    int cur = 0;
    for (auto &[_, v] : ev) {
      cur -= v;
      if (cur >= k) break;
    }
    if (cur >= k) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << setprecision(10) << fixed << lo << endl;
  cerr << lo << ' ' << hi << endl;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  prec();
  int t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
