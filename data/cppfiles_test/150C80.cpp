#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 200005;
const long long inf = 2000000005;
inline void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  long long ans = inf;
  for (long long i = 0; i <= 3; ++i) {
    for (long long j = 0; j <= 3; ++j) {
      long long mx = 0;
      for (long long c = 0; c < n; ++c) {
        long long pre = inf;
        for (long long o = 0; o <= i; ++o) {
          long long cur = inf;
          for (long long t = 0; t <= j; ++t) {
            long long x = a[c] - o - 2 * t;
            if (x % 3 == 0 && x >= 0) cur = min(cur, x / 3);
          }
          pre = min(pre, cur);
        }
        mx = max(mx, pre);
      }
      ans = min(ans, mx + i + j);
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
