#include <bits/stdc++.h>
using namespace std;
bool ls(long double a, long double b) { return b - a > 1e-9; }
bool eq(long double a, long double b) { return !ls(a, b) && !ls(b, a); }
struct pt {
  long double x, y;
  pt() {}
  pt(long double xx, long double yy) : x(xx), y(yy) {}
  pt operator-(pt A) { return pt(x - A.x, y - A.y); }
  pt operator+(pt A) { return pt(x + A.x, y + A.y); }
  long double cross(pt A) { return x * A.y - y * A.x; }
  long double dot(pt A) { return x * A.x + y * A.y; }
  pt operator*(long double k) { return pt(x * k, y * k); }
  pt perp() { return pt(-y, x); }
  pt rev() { return pt(-x, -y); }
  pt norm() {
    long double z = sqrt(x * x + y * y);
    return pt(x / z, y / z);
  }
  long double dist(pt A) {
    return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
  }
};
const int N = 1e5 + 7;
const long double PI = acos(-1);
int n, k;
pt P[N];
pt O = pt(0, 0);
pt base = {1, 0};
long double getAngle(pt A) {
  if (eq(A.dot(base), 0)) return 0;
  long double alpha = atan2(base.cross(A), base.dot(A));
  if (ls(alpha, 0)) alpha = 2 * PI + alpha;
  return alpha;
}
bool check(long double r) {
  int cnt00 = 0;
  vector<pair<long double, int>> events;
  for (int i = 0; i < n; ++i) {
    if (eq(O.dist(P[i]), 0)) {
      ++cnt00;
      continue;
    }
    if (ls(2 * r, O.dist(P[i]))) {
      continue;
    }
    long double h = O.dist(P[i]) / 2.0;
    pt v = (P[i] - O).norm();
    pt H = O + v * h;
    v = v.perp();
    long double l = sqrt(r * r - h * h);
    pt A = H - v * l;
    pt B = H + v * l;
    events.push_back({getAngle(A), 1});
    events.push_back({getAngle(B), -1});
    if (ls(getAngle(B), getAngle(A))) events.push_back({getAngle(base), 1});
  }
  sort((events).begin(), (events).end());
  int cnt = cnt00;
  for (auto event : events) {
    cnt += event.second;
    if (cnt >= k) return true;
  }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> P[i].x >> P[i].y;
  }
  long double l = 0, r = 2e5;
  for (int i = 0; i < 70; ++i) {
    long double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(20) << fixed << r << "\n";
  return 0;
}
