#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  vector<vector<int>> dp(n + 1, vector<int>(2001, 10000));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= 2000; j++) {
      if (j + w[i] <= 2000)
        dp[i + 1][j + w[i]] = min(dp[i + 1][j + w[i]], max(dp[i][j], j + w[i]));
      if (j - w[i] >= 0)
        dp[i + 1][j - w[i]] = min(dp[i + 1][j - w[i]], max(dp[i][j], j - w[i]));
      else
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + w[i] - j);
    }
  int ans = 0x3f3f3f3f;
  for (int j = 0; j <= 2000; j++) ans = min(ans, dp[n][j]);
  cout << ans << endl;
}
signed main() {
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
