#include <bits/stdc++.h>
using namespace std;
long long dp[3][100100], a[100100], sum[100100];
int n, ans, now, pre;
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[n - i + 1]);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i <= n; i++) dp[0][i] = 100000000000000, dp[1][i] = -1;
    for (int k = 1; k * (k + 1) <= 2 * n; k++) {
      now = (k % 2);
      pre = (k - 1) % 2;
      for (int i = 0; i + k <= n; i++)
        if (dp[pre][i] > sum[i + k] - sum[i])
          dp[now][i + k] = max(dp[now][i + k], sum[i + k] - sum[i]), ans = k;
      for (int i = 2; i <= n; i++) dp[now][i] = max(dp[now][i], dp[now][i - 1]);
      for (int i = 0; i <= n; i++) dp[pre][i] = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
