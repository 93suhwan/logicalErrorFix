#include <bits/stdc++.h>
using namespace std;
int t, n, a[10005], dp[10005][1005];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(dp, 63, sizeof dp);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    dp[0][0] = 0;
    for (register int i = 1; i <= n; i++) {
      for (register int j = 0; j <= a[i]; j++) {
        dp[i][0] = min(dp[i][0], dp[i - 1][j] - j + a[i]);
      }
      for (register int o = 1; o < a[i]; o++) {
        dp[i][o] = dp[i - 1][o + a[i]];
      }
      for (register int o = a[i]; o <= 2000 - a[i]; o++) {
        dp[i][o] = min(max(dp[i - 1][o - a[i]], o), dp[i - 1][o + a[i]]);
      }
      for (register int o = 2001 - a[i]; o <= 2000; o++) {
        dp[i][o] = dp[i - 1][o - a[i]];
      }
    }
    int ans = 1e9;
    for (register int i = 0; i <= 2000; i++) {
      ans = min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
