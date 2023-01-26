#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> r(n), p(n), mn(n, 1e18);
  function<long long(long long)> get = [&](long long v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  };
  auto unite = [&](long long a, long long b) {
    a = get(a), b = get(b);
    if (a != b) {
      if (r[a] < r[b]) swap(a, b);
      p[b] = a;
      mn[a] = min(mn[b], mn[a]);
      if (r[a] == r[b]) r[a]++;
    }
  };
  iota(p.begin(), p.end(), 0);
  vector<array<long long, 4>> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    a[i][3] = i;
    mn[i] = a[i][2];
  }
  sort(a.begin(), a.end());
  for (long long i = 1; i < n; i++) {
    if (a[i][0] == a[i - 1][0] && abs(a[i][1] - a[i - 1][1]) <= k) {
      unite(a[i][3], a[i - 1][3]);
    }
  }
  for (long long i = 0; i < n; i++) {
    swap(a[i][0], a[i][1]);
  }
  sort(a.begin(), a.end());
  for (long long i = 0; i < n; i++) {
    swap(a[i][0], a[i][1]);
  }
  for (long long i = 1; i < n; i++) {
    if (a[i][1] == a[i - 1][1] && abs(a[i][0] - a[i - 1][0]) <= k) {
      unite(a[i][3], a[i - 1][3]);
    }
  }
  vector<pair<long long, long long>> possible;
  for (long long i = 0; i < n; i++) {
    long long v = get(i);
    possible.emplace_back(mn[v], v);
  }
  sort(possible.begin(), possible.end());
  possible.resize(unique(possible.begin(), possible.end()) - possible.begin());
  reverse(possible.begin(), possible.end());
  long long res = min(possible[0].first - 1, (long long)possible.size());
  for (long long i = 0; i + 1 < (long long)possible.size(); i++) {
    res = min(res, max(i + 1, possible[i + 1].first - 1));
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc-- > 0) solve();
  return 0;
}
