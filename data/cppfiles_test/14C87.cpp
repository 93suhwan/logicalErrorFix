#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[2005], dp[2005][2005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i - 1; j++) {
        dp[i][j] = dp[i - 1][j] + (int)(i - j == a[i]);
      }
      for (int j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
    int ans = -1;
    for (int i = 0; i <= n - 1; i++) {
      if (dp[n][i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}
