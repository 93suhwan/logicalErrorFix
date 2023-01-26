#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  long long int hi = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    hi = max(hi, arr[i]);
  }
  vector<vector<long long int>> dp(n + 1,
                                   vector<long long int>(2 * hi + 1, 1e18));
  dp[0][0] = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j <= 2 * hi; j++) {
      if (dp[i - 1][j] == 1e18) continue;
      dp[i][max((long long int)0, j - arr[i - 1])] =
          min(dp[i][max((long long int)0, j - arr[i - 1])],
              dp[i - 1][j] + arr[i - 1]);
      if (j + arr[i - 1] <= 2 * hi)
        dp[i][j + arr[i - 1]] =
            min(dp[i][j + arr[i - 1]],
                max((long long int)0, dp[i - 1][j] - arr[i - 1]));
    }
  }
  long long int ans = 2 * hi + 1;
  for (long long int i = 0; i <= 2 * hi; i++) {
    ans = min(i + dp[n][i], ans);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cout << fixed << setprecision(20);
  long long int t = 1;
  cin >> t;
  for (long long int tt = 1; tt <= t; tt++) {
    solve();
  }
}
