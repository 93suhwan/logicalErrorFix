#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e9;
const long double eps = 1e-9;
const long long MOD = 1e9 + 7;
long long n;
vector<long double> ang;
vector<pair<long long, long long> > v;
long double PI = acosl(-1);
long double dist(pair<long long, long long> &a) {
  return sqrtl(a.first * a.first + a.second * a.second);
}
long long check(long double r) {
  vector<pair<long double, long long> > scan;
  for (long long i = 0; i < n; i++) {
    long double d = dist(v[i]) / 2;
    if (d > r + eps) continue;
    long double cur = acosl(d / r);
    long double lt = ang[i] - cur;
    long double rt = ang[i] + cur;
    if (cur >= PI - eps) {
      scan.push_back({0, -1});
      scan.push_back({2 * PI, 1});
    } else {
      scan.push_back({lt, -1});
      scan.push_back({rt, 1});
      if (lt < -eps) {
        lt += 2 * PI;
        rt += 2 * PI;
        scan.push_back({lt, -1});
        scan.push_back({rt, 1});
      } else if (rt > 2 * PI + eps) {
        lt -= 2 * PI;
        rt -= 2 * PI;
        scan.push_back({lt, -1});
        scan.push_back({rt, 1});
      }
    }
  }
  sort(scan.begin(), scan.end());
  long long ans = 0;
  long long cur = 0;
  for (long long i = 0; i < scan.size(); i++) {
    cur -= scan[i].second;
    if (cur >= ans) ans = cur;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  long long k;
  cin >> n >> k;
  v.resize(n);
  ang.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  for (long long i = 0; i < n; i++) {
    ang[i] = atan2l(v[i].second, v[i].first);
    if (ang[i] < -eps) ang[i] += 2 * PI;
  }
  long double l = 0, r = 2e5;
  for (long long i = 0; i < 60; i++) {
    long double m = (l + r) / 2;
    if (check(m) >= k) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
  return 0;
}
