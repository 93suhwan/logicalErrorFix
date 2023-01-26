#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, n, m;
    cin >> n >> k;
    long long a[n + 1];
    for (i = 1; i <= n; i++) cin >> a[i];
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (a[i + 1] == (j + 1))
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
        else
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      }
    }
    long long ans = -1;
    for (i = n; i >= 0; i--) {
      if (dp[n][i] >= k) {
        ans = (n - i);
        break;
      }
    }
    cout << ans << "\n";
  }
}
