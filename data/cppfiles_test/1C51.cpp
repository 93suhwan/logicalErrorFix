#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[100000];
int n, k;
const double eps = 1e-9;
const double PI = 3.14159265358979;
double ang(int x, int y) {
  if (x == 0) {
    if (y > 0) return PI / 2;
    return PI * 3 / 2;
  }
  if (x > 0 && y >= 0) {
    return atan(1.0 * y / x);
  }
  if (x < 0 && y >= 0) {
    return PI - atan(abs(1.0 * y / x));
  }
  if (x < 0 && y <= 0) {
    return PI + atan(1.0 * y / x);
  }
  if (x > 0 && y <= 0) {
    return 2 * PI - atan(abs(1.0 * y / x));
  }
}
bool ok(double m) {
  vector<pair<double, int>> v;
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].first == 0 && p[i].second == 0) {
      now++;
      continue;
    }
    double dist =
        sqrt(1.0 * p[i].first * p[i].first + 1.0 * p[i].second * p[i].second);
    if (dist > 2 * m + eps) continue;
    double theta = acos(dist / (2 * m));
    double A = ang(p[i].first, p[i].second);
    double t1 = A - theta, t2 = A + theta;
    v.push_back({t1, 1});
    v.push_back({t2, -1});
    v.push_back({t1 + 2 * PI, 1});
    v.push_back({t2 + 2 * PI, -1});
  }
  sort(v.begin(), v.end(), [&](pair<double, int> p1, pair<double, int> p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
  });
  for (auto [ignore, c] : v) {
    now += c;
    if (now >= k) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  double l = 0, r = 2e5, ans;
  int T = 40;
  while (T--) {
    double m = (l + r) / 2;
    if (ok(m)) {
      ans = m;
      r = m;
    } else {
      l = m;
    }
  }
  printf("%.6f\n", ans);
  return 0;
}
