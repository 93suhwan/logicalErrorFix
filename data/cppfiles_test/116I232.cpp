#include <bits/stdc++.h>
using namespace std;
int const M = 5e5 + 10, N = 1e7 + 10;
long long const mod = 998244353;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long t, n, s[M], dp[M][3], ans;
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n + 1; ++i) dp[i][1] = 0, dp[i][2] = 0;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i] > 0) dp[s[i]][2] += dp[s[i]][2] + dp[s[i] - 1][1];
      dp[s[i] + 1][1] += dp[s[i]][1] + dp[s[i] + 1][1];
      ans %= mod;
      dp[s[i] + 1][1] %= mod;
    }
    for (int i = 1; i <= n + 1; ++i)
      ans += dp[i][1], ans += dp[i][2], ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
