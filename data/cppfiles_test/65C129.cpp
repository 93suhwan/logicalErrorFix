#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long double pi = 3.141592653589793238;
const long long MOD = 998244353;
const long long N = 2e5 + 10;
long long n, m;
pair<long long, long long> a[51];
long long dp[51][N];
long long ans[N] = {0};
long long pre[N];
long long sum(long long l, long long r) {
  if (r < 0) return 0;
  if (l > r) return 0;
  return pre[r] - (l - 1 >= 0 ? pre[l - 1] : 0);
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (long long g = m; g >= 1; g--) {
    long long mx = m / g;
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= mx; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (long long i = 1; i <= n; i++) {
      long long l = (a[i - 1].first + g - 1) / g, r = a[i - 1].second / g;
      pre[0] = dp[i - 1][0];
      for (long long j = 1; j <= mx; j++)
        pre[j] = dp[i - 1][j] + pre[j - 1], pre[j] %= MOD;
      for (long long j = 0; j <= mx; j++) {
        long long nl = j - r;
        long long nr = j - l;
        dp[i][j] = sum(nl, nr);
        dp[i][j] %= MOD;
        dp[i][j] += MOD;
        dp[i][j] %= MOD;
      }
    }
    for (long long j = 1; j <= mx; j++) ans[g] += dp[n][j], ans[g] %= MOD;
    for (long long k = 2; k * g <= m; k++) {
      ans[g] -= ans[k * g];
      ans[g] %= MOD;
      ans[g] += MOD;
      ans[g] %= MOD;
    }
  }
  cout << ans[1];
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
