#include <bits/stdc++.h>
using namespace std;
int t, n, a[10005], dp[10005][2005];
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
      for (register int o = 0; o <= 2000; o++) {
        dp[i][o + a[i]] = min(dp[i][o + a[i]], max(dp[i - 1][o], o + a[i]));
        dp[i][max(o - a[i], 0)] =
            min(dp[i][max(o - a[i], 0)], dp[i][o] + max(a[i] - o, 0));
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
