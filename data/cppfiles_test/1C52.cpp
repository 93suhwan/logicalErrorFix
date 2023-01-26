#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0L);
const int N = 1e5 + 5;
double a[N], d[N];
int n, k;
bool cmp(const pair<double, bool> &e1, const pair<double, bool> &e2) {
  double a1, a2;
  int t1, t2;
  tie(a1, t1) = e1, tie(a2, t2) = e2;
  if (abs(a1 - a2) > EPS) return a1 < a2;
  return t1 < t2;
}
vector<pair<double, bool> > events;
bool ok(double r) {
  double delta;
  double L, R;
  double dif;
  vector<pair<double, bool> > events;
  for (int i = 0; i < n; ++i) {
    if (d[i] - r > EPS) continue;
    delta = acos(d[i] / r);
    L = a[i] - delta;
    R = a[i] + delta;
    dif = -PI - L;
    if (dif > EPS) {
      events.emplace_back(-PI, 0);
      events.emplace_back(R, 1);
      L = PI - dif;
      R = PI;
    }
    dif = R - PI;
    if (dif > EPS) {
      events.emplace_back(L, 0);
      events.emplace_back(PI, 1);
      R = -PI + dif;
      L = -PI;
    }
    events.emplace_back(L, 0);
    events.emplace_back(R, 1);
  }
  sort(events.begin(), events.end(), cmp);
  double angle;
  bool type;
  int cnt = 0;
  while (events.size()) {
    tie(angle, type) = events.back();
    events.pop_back();
    if (type) {
      ++cnt;
    } else {
      --cnt;
    }
    if (cnt >= k) return true;
  }
  return false;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  long long x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    a[i] = atan2(y, x);
    d[i] = sqrt(x * x + y * y) / 2;
  }
  double L = 0, R = 3e5, M;
  for (int i = 0; i < 50; ++i) {
    M = (L + R) / 2;
    if (ok(M)) {
      R = M;
    } else {
      L = M;
    }
  }
  cout << setprecision(10) << fixed << L;
  return 0;
}
