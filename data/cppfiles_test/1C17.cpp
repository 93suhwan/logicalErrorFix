#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);
long double DEL = 1e-6;
long long M = 1e9 + 7;
const long long N = 3e5 + 10;
long long cnt, sum, mx, mn, ans, a[N], b[N];
long long n, m, i, j, k, l, p, q, r, t, w, x[N], y[N], z, tc;
string s;
double d[N], theta[N];
bool check(double r) {
  long long cnt = 0;
  vector<pair<double, long long>> s;
  for (long long i = 1; i <= n; i++) {
    if (d[i] > 2 * r) {
      continue;
    }
    double cosa = (((d[i]) * (d[i]))) / (2.0 * r * d[i]);
    double a = acos(cosa);
    if (a < 0) a += PI;
    double lo = theta[i] - a, hi = theta[i] + a;
    if (lo > 2 * PI) {
      lo -= 2 * PI;
    }
    if (hi < 0) {
      hi += 2 * PI;
    }
    if (lo < 0) {
      lo += 2 * PI;
    }
    if (hi > 2 * PI) {
      hi -= 2 * PI;
    }
    s.push_back({lo, -1});
    s.push_back({hi, 1});
    if (lo > hi) {
      s.push_back({2 * PI, 1});
      s.push_back({0, -1});
    }
  }
  sort(s.begin(), s.end());
  for (auto &[a, t] : s) {
    cnt -= t;
    if (cnt >= k) {
      return true;
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    d[i] = sqrt(((x[i]) * (x[i])) + ((y[i]) * (y[i])));
    theta[i] = atan2(y[i], x[i]);
    if (theta[i] < 0) {
      theta[i] += 2 * PI;
    }
  }
  double l = 0, r = 1e6;
  while (l < r - DEL) {
    double m = (l + r) / 2.0;
    if (check(m)) {
      r = m;
    } else {
      l = m + DEL;
    }
  }
  cout << fixed << setprecision(6);
  cout << r;
}
