#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long f = 0;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    f += a[i].first + m;
    f -= a[i].second;
    long long l = max(0ll, m - a[i].second), r = min(m, a[i].first);
    a[i] = {l, r};
    f -= l * 2;
  }
  vector<long long> ans(n);
  for (long long i = 0; i < n; ++i) {
    if (f > 0) {
      ans[i] = min(f / 2, a[i].second - a[i].first);
      f -= 2 * ans[i];
    }
  }
  cout << abs(f) << '\n';
  for (long long i = 0; i < n; ++i) {
    long long x = a[i].first + ans[i];
    cout << x << ' ' << m - x << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    solve();
  }
}
