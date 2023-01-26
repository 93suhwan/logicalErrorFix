#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1);
int sign(double k) {
  if (k > eps)
    return 1;
  else if (k < -eps)
    return -1;
  return 0;
}
int cmp(double k1, double k2) { return sign(k1 - k2); }
int inmid(double k1, double k2, double k3) {
  return sign(k1 - k3) * sign(k2 - k3) <= 0;
}
struct point {
  double x, y;
  point operator+(const point &k1) const { return (point){k1.x + x, k1.y + y}; }
  point operator-(const point &k1) const { return (point){x - k1.x, x - k1.y}; }
  point operator*(double &k1) const { return (point){x * k1, y * k1}; }
  point operator/(double &k1) const { return (point){x / k1, y / k1}; }
  int operator==(const point &k1) const {
    return cmp(x, k1.x) == 0 && cmp(y, k1.y) == 0;
  }
  double abs() { return sqrt(x * x + y * y); }
  double abs2() { return x * x + y * y; }
  double dis(point k1) { return ((*this) - k1).abs(); }
};
struct osc {
  double ang;
  int v;
};
bool osccmp(osc a, osc b) {
  int res = cmp(a.ang, b.ang);
  if (res == -1) return 1;
  if (res == 0 && a.v > b.v) return 1;
  return 0;
}
int n, K;
int sz;
osc angle[400050];
point a[100050];
bool check(double R) {
  sz = 0;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    double d = a[i].abs() / 2;
    if (cmp(d, R) == 1) continue;
    double t = atan2(a[i].y, a[i].x);
    if (t < 0) t += 2 * pi;
    double dt = acos(d / R);
    double f = t - dt, s = t + dt;
    if (cmp(f, 0.0) == -1) f += 2 * pi;
    if (cmp(s, 2 * pi) == 1) s -= 2 * pi;
    if (cmp(f, s) == 1 || cmp(f, 0.0) == 0) now++;
    angle[++sz] = (osc){f, 1};
    angle[++sz] = (osc){s, -1};
  }
  sort(angle + 1, angle + sz + 1, osccmp);
  for (int i = 1; i <= sz; i++) {
    now += angle[i].v;
    if (now >= K) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      K--;
      i--;
      n--;
      continue;
    }
    a[i] = (point){(double)x, (double)y};
  }
  if (K <= 0) {
    cout << fixed << setprecision(10) << 0.0 << '\n';
    return 0;
  }
  double l = 0, r = 200000;
  for (int round = 1; round <= 100; round++) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(10) << l << '\n';
  return 0;
}
