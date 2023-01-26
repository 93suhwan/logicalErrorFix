#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m = 0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m = max(m, 2 * a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(m, 10007));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j] == 10007) continue;
        if (dp[i][j] + a[i] < m)
          dp[i + 1][max(0, j - a[i])] =
              min(dp[i][j] + a[i], dp[i + 1][max(0, j - a[i])]);
        if (j + a[i] < m)
          dp[i + 1][j + a[i]] =
              min(max(0, dp[i][j] - a[i]), dp[i + 1][j + a[i]]);
      }
    }
    int ans = 10007;
    for (int i = 0; i < m; i++) ans = min(ans, i + dp[n][i]);
    cout << ans;
    cout << "\n";
  }
  return 0;
}
