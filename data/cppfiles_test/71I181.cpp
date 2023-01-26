#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 200001;
long long n, k;
long long x[N], y[N];
vector<pair<pair<long long, long long>, long long>> pts;
long double d(long long i, long long j) {
  return sqrt(long long(x[i] - x[j]) * (x[i] - x[j]) +
              long long(y[i] - y[j]) * (y[i] - y[j]));
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << setprecision(9) << fixed;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    pts.push_back({{x[i], y[i]}, i});
  }
  sort(begin(pts), end(pts));
  auto equal = [&](pair<long long, long long> a,
                   pair<long long, long long> b) -> bool {
    return long long(a.first) * b.second == long long(a.second) * b.first;
  };
  auto line = [&](long long i, long long j) -> pair<long long, long long> {
    return {x[j] - x[i], y[j] - y[i]};
  };
  auto check = [&](long long ex) -> bool {
    vector<long long> vec;
    for (long long i = 0; i < n; i++) {
      if (i == ex) continue;
      vec.push_back(i);
    }
    pair<long long, long long> l = line(pts[vec[0]].second, pts[vec[1]].second);
    for (long long i = 1; i < n - 1; i++) {
      long long a = vec[i];
      long long b = vec[i - 1];
      if (!equal(l, line(pts[b].second, pts[a].second))) return 0;
    }
    return 1;
  };
  long long out;
  if (check(0))
    out = pts[0].second;
  else if (check(n - 1))
    out = pts[n - 1].second;
  else {
    pair<long long, long long> l1 = line(pts[0].second, pts[1].second);
    for (long long i = 1; i <= n - 2; i++) {
      if (!equal(l1, line(pts[i - 1].second, pts[i].second)) &&
          !equal(l1, line(pts[i].second, pts[i + 1].second))) {
        out = pts[i].second;
        break;
      }
    }
  }
  long long i = 0;
  for (i = 0; i < n; i++) {
    if (pts[i].second == out) {
      pts.erase(pts.begin() + i);
      break;
    }
  }
  long long a = pts[0].second;
  long long b = pts[n - 2].second;
  long double ans = 1e9;
  if (k == out) {
    ans = d(a, b) + min(d(k, a), d(k, b));
  } else {
    for (long long i = 0; i < n - 1; i++) {
      if (pts[i].second != k) continue;
      ans =
          min(ans, d(k, a) + d(a, out) +
                       (i == n - 2 ? 0
                                   : min(d(out, pts[i + 1].second), d(out, b)) +
                                         d(pts[i + 1].second, b)));
      ans = min(ans, d(k, b) + d(b, out) +
                         (i == 0 ? 0
                                 : min(d(out, pts[i - 1].second), d(out, a)) +
                                       d(pts[i - 1].second, a)));
      break;
    }
    for (long long i = 0; i < n - 1; i++) {
      if (i < n - 2)
        ans = min(ans, d(k, a) + d(a, pts[i].second) + d(pts[i].second, out) +
                           d(out, pts[i + 1].second) + d(pts[i + 1].second, b));
      if (i)
        ans = min(ans, d(k, b) + d(b, pts[i].second) + d(pts[i].second, out) +
                           d(out, pts[i - 1].second) + d(pts[i - 1].second, a));
    }
  }
  cout << ans;
}
