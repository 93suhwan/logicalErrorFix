#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &el : a) cin >> el;
  ;
  vector<vector<long long>> dp(n + 4, vector<long long>(3, 0));
  long long ans = 0;
  for (auto u : a) {
    (dp[u][2] += dp[u][2] + dp[u + 2][0]) %= (long long)(998244353);
    if (u == 0) {
      (dp[0][1] += 1 + dp[0][1] + dp[2][0]) %= (long long)(998244353);
    } else if (u == 1) {
      (dp[1][1] += dp[0][1] + dp[1][1]) %= (long long)(998244353);
      (dp[1][0] += 1 + dp[1][0]) %= (long long)(998244353);
    } else {
      (dp[u][0] += dp[u - 2][1] + dp[u][0]) %= (long long)(998244353);
      (dp[u][1] += dp[u - 1][1] + dp[u][1]) %= (long long)(998244353);
    }
  }
  for (long long i = 0; i <= n; i++) {
    (ans += dp[i][0] + dp[i][1]) %= (long long)(998244353);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) solve();
  return 0;
}
