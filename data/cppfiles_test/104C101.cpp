#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> minp(pair<long long, long long> p, long long m) {
  long long maxi = min(p.first, m);
  return {maxi, m - maxi};
}
long long minv(pair<long long, long long> p, long long m) {
  auto s = minp(p, m);
  return p.first - s.first - (p.second - s.second);
}
pair<long long, long long> maxp(pair<long long, long long> p, long long m) {
  long long maxi = min(p.second, m);
  return {m - maxi, maxi};
}
long long maxv(pair<long long, long long> p, long long m) {
  auto s = maxp(p, m);
  return p.first - s.first - (p.second - s.second);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> a(n);
    for (int i = 0, ggdem = n; i < ggdem; ++i) cin >> a[i].first >> a[i].second;
    long long l = 0, r = 0;
    for (auto i : a) {
      l += minv(i, m);
      r += maxv(i, m);
    }
    long long val;
    if (l >= 0)
      val = l;
    else if (r <= 0)
      val = r;
    else {
      if (l & 1)
        val = 1;
      else
        val = 0;
    }
    cout << abs(val) << "\n";
    long long dif = val - l;
    for (auto i : a) {
      long long d = maxv(i, m) - minv(i, m);
      long long mini = min(d, dif);
      dif -= mini;
      auto pa = minp(i, m);
      pa.first -= mini / 2;
      pa.second += mini / 2;
      cout << pa.first << " " << pa.second << "\n";
    }
  }
  return 0;
}
