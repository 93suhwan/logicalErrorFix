#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long l[55], r[55];
long long ans[100005];
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (long long x = m / n; x >= 1; x--) {
    long long sz = m / x;
    vector<long long> dp(sz + 1);
    dp[0] = 1;
    for (long long i = 1; i <= n; i++) {
      vector<long long> ndp(sz + 1);
      long long mini = 1e9, maxi = 0;
      for (long long num = 1; num * x <= r[i]; num++) {
        if (num * x < l[i]) continue;
        mini = min(mini, num);
        maxi = max(maxi, num);
      }
      for (long long j = 1; j <= sz; j++) {
        dp[j] = (dp[j] + dp[j - 1]) % mod;
      }
      for (long long j = 0; j <= sz; j++) {
        long long lower = j - maxi, upper = j - mini;
        if (upper < 0) continue;
        if (lower <= 0) {
          ndp[j] = (dp[upper]) % mod;
          continue;
        }
        ndp[j] = (dp[upper] - dp[lower - 1] + mod) % mod;
      }
      dp = ndp;
    }
    for (auto u : dp) ans[x] = (ans[x] + u);
    for (long long num = 2 * x; num <= m; num += x) {
      ans[x] = (ans[x] - ans[num] + mod) % mod;
    }
  }
  cout << ans[1];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) {
    solve();
  }
}
