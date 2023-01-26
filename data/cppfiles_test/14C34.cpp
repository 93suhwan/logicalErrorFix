#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    long long dp[n + 1][n + 1];
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        dp[i][j] = 0;
      }
    }
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++) {
      dp[i][0] = (a[i] == i ? 1 : 0) + dp[i - 1][0];
      for (long long j = 1; j <= i; j++) {
        dp[i][j] = dp[i - 1][j - 1];
        dp[i][j] = max(dp[i][j], (a[i] == i - j ? 1 : 0) + dp[i - 1][j]);
      }
    }
    bool is = false;
    for (long long j = 0; j <= n; j++) {
      if (dp[n][j] >= k) {
        cout << j << endl;
        is = true;
        break;
      }
    }
    if (!is) cout << -1 << endl;
  }
  return 0;
}
