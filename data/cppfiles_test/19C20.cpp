#include <bits/stdc++.h>
using namespace std;
int ai[100010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(n + 1, vector<int>(2001, 0x3f3f3f3f));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &ai[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2000; j++) {
        if (dp[i][j] != 0x3f3f3f3f) {
          if (j + ai[i] <= 2000)
            dp[i + 1][j + ai[i]] =
                min(dp[i + 1][j + ai[i]], max(dp[i][j], j + ai[i]));
          if (j - ai[i] >= 0)
            dp[i + 1][j - ai[i]] =
                min(dp[i + 1][j - ai[i]], max(dp[i][j], j - ai[i]));
          else
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + ai[i] - j);
        }
      }
    }
    int ans = 0x3f3f3f3f;
    for (int j = 0; j <= 2000; j++) ans = min(ans, dp[n][j]);
    cout << ans << endl;
  }
  return 0;
}
