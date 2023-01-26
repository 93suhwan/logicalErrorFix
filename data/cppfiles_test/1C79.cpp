#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-9, pi = acos(-1);
int n, k, x[N], y[N];
double ang[N], dist[N];
bool ok(double r) {
  vector<pair<double, int>> ve;
  int cnt = 0, mx = 0;
  for (int i = 0; i < (n); ++i) {
    if (dist[i] >= 2 * r - eps) {
      continue;
    }
    double theta = acos(dist[i] / 2 / r);
    double a = ang[i] - theta, b = ang[i] + theta;
    while (a < 0) {
      a += 2 * pi;
    }
    while (b < 0) {
      b += 2 * pi;
    }
    ve.push_back({a, 1});
    ve.push_back({b, -1});
    if (a > b) {
      ++cnt;
    }
  }
  mx = cnt;
  sort(begin(ve), end(ve));
  for (const auto &p : ve) {
    cnt += p.second;
    mx = max(mx, cnt);
  }
  return mx >= k;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> k;
  for (int i = 0; i < (n); ++i) {
    cin >> x[i] >> y[i];
    if (x[i] == 0 && y[i] == 0) {
      --i, --k, --n;
    }
  }
  if (k <= 0) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < (n); ++i) {
    ang[i] = atan2(y[i], x[i]);
    dist[i] = sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
  }
  double lo = 0, hi = 2e5;
  for (int i = 0; i < (50); ++i) {
    double mid = (lo + hi) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << setprecision(20) << lo << '\n';
}
