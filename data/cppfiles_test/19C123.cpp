#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dp[10005][2005], a[10005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 2000; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 2000; j++) {
        dp[i][j] = INF;
        if (j - a[i] >= 0)
          dp[i][j] = min(dp[i][j], max(j, dp[i - 1][j - a[i]]));
        if (j + a[i] < 2000) dp[i][j] = min(dp[i][j], dp[i - 1][j + a[i]]);
      }
    }
    int res = INF;
    for (int i = 0; i < 2000; i++) res = min(res, dp[n][i]);
    printf("%d\n", res);
  }
}
