#include <bits/stdc++.h>
using namespace std;
int n, a[10005], dp[10005][2005];
signed main() {
  int Test;
  scanf("%d", &Test);
  while (Test--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int maxX = 0;
    for (int i = 1; i <= n; i++) maxX = max(maxX, a[i]);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= 2 * maxX; j++) dp[i][j] = 0x3f3f3f3f;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2 * maxX; j++) {
        if (dp[i - 1][j] == 0x3f3f3f3f) continue;
        dp[i][max(0, j - a[i])] =
            min(dp[i][max(0, j - a[i])], dp[i - 1][j] + a[i]);
        if (j + a[i] <= 2 * maxX)
          dp[i][j + a[i]] = min(dp[i][j + a[i]], max(0, dp[i - 1][j] - a[i]));
      }
    }
    int ans = 0x3f3f3f3f;
    for (int j = 0; j <= 2 * maxX; j++) ans = min(ans, dp[n][j] + j);
    printf("%d\n", ans);
  }
  return 0;
}
