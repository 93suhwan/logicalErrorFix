#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2 * mx + 1, inf));
    dp[0][0] = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j <= 2 * mx - a[i]; j++) {
        if (dp[i][j] == inf) continue;
        dp[i + 1][j + a[i]] =
            min(dp[i + 1][j + a[i]], max(dp[i][j] - a[i], 0ll));
        dp[i + 1][max(0ll, j - a[i])] =
            min(dp[i + 1][max(0ll, j - a[i])], dp[i][j] + a[i]);
      }
    }
    long long ans = inf;
    for (long long j = 0; j <= 2 * mx; j++) {
      ans = min(ans, j + dp[n][j]);
    }
    cout << ans << endl;
  }
}
