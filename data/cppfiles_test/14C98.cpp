#include <bits/stdc++.h>
using namespace std;
const int maxn = 2020;
const int mod = 998244353;
int a[maxn], b[maxn], dp[maxn][maxn];
int main() {
  int t, n, m, i, j, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 0; i <= n; i++) memset(dp[i], 0, sizeof(dp[i]));
    memset(b, 0, sizeof(b));
    for (i = 1; i <= n; i++)
      for (j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
        if (j == a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    int ans = 0x3f3f3f3f;
    for (i = n; i >= 0; i--) {
      for (j = 0; j <= i; j++)
        if (dp[i][j] + b[i - j] >= k) ans = min(ans, i - j);
      if (i - a[i] >= 0) b[i - a[i]]++;
    }
    printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
  }
  return 0;
}
