#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e3 + 50;
int a[MAX], dp[MAX][MAX], n, k;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i - 1][0] + (a[i] == i);
      for (int j = 1; j < i; j++) {
        dp[i][j] = max(dp[i - 1][j] + (a[i] == i - j), dp[i - 1][j - 1]);
      }
    }
    int res = -1;
    for (int i = 0; i <= n; i++) {
      if (dp[n][i] >= k) {
        res = i;
        break;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
