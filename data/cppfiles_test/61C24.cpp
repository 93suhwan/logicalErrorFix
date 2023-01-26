#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  vector<long long> ad[n + 1], bd[n + 1];
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    ad[a[i]].push_back(b[i]);
    bd[b[i]].push_back(a[i]);
  }
  long long ans = (n * (n - 1) * (n - 2)) / 6;
  for (long long i = 1; i <= n; i++) {
    long long as = ad[i].size() - 1;
    for (auto i : ad[i]) {
      long long bs = bd[i].size() - 1;
      ans -= as * bs;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _t;
  cin >> _t;
  while (_t--) solve();
  return 0;
}
