#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int inf = 2000;
int a[maxn];
int dp[maxn][2010];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i <= 2000; i++) dp[0][i] = inf;
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      for (int j = 0; j <= 2000; j++) dp[i][j] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2000; j++) {
        if (dp[i - 1][j] == inf) continue;
        if (j + a[i] <= 2000)
          dp[i][j + a[i]] = min(dp[i][j + a[i]], max(dp[i - 1][j], j + a[i]));
        if (j >= a[i])
          dp[i][j - a[i]] = min(dp[i][j - a[i]], dp[i - 1][j]);
        else
          dp[i][0] = min(dp[i][0], dp[i - 1][j] + a[i] - j);
      }
    }
    int an = 2000;
    for (int i = 0; i <= 2000; i++) {
      an = min(an, dp[n][i]);
    }
    printf("%d\n", an);
  }
  return 0;
}
