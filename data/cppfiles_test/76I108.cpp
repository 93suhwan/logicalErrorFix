#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = LLONG_MAX;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0), pre(n + 2, 0);
  dp[1] = 1;
  long long sum1 = dp[1];
  long long sum2 = 0;
  for (long long j = 2; j <= n; j++) {
    pre[j] += dp[1];
    long long ed = min(n + 1, j + j);
    pre[ed] -= dp[1];
  }
  for (long long i = 2; i <= n; i++) {
    sum2 = (sum2 + pre[i]) % m;
    dp[i] = (sum1 + sum2) % m;
    sum1 = (sum1 + dp[i]) % m;
    for (long long j = 2; i * j <= n; j++) {
      pre[i * j] = (pre[i * j] + dp[i]) % m;
      long long ed = min(n + 1, i * j + j);
      pre[ed] = (pre[ed] - dp[i]) % m;
    }
  }
  cout << dp[n];
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1, count = 1;
  while (t--) {
    solve();
  }
  return 0;
}
