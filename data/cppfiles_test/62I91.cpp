#include <bits/stdc++.h>
using namespace std;
long long n, m, q, dp[1005][1005][2], flag[1005][1005];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = dp[i][j][1] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i > 1) dp[i][j][0] += dp[i - 1][j][1];
      if (j > 1) dp[i][j][1] += dp[i][j - 1][0];
      flag[i][j] = 1;
    }
  }
  long long res = 0, tot = n * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      res += dp[i][j][0] + dp[i][j][1];
    }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    flag[x][y] ^= 1;
    if (flag[x][y] == 0) {
      tot--;
      res -= dp[x][y][0] + dp[x][y][1];
      dp[x][y][0] = dp[x][y][1] = 0;
    } else {
      tot++;
      res -= dp[x][y][0] + dp[x][y][1];
      dp[x][y][0] = dp[x][y][1] = 1;
      if (x > 1) dp[x][y][0] += dp[x - 1][y][1];
      if (y > 1) dp[x][y][1] += dp[x][y - 1][0];
      res += dp[x][y][1] + dp[x][y][0];
    }
    while (y <= n && x <= m) {
      if (x < n) {
        res -= dp[x + 1][y][0];
        if (flag[x + 1][y])
          dp[x + 1][y][0] = 1 + dp[x][y][1];
        else
          dp[x + 1][y][0] = 0;
        res += dp[x + 1][y][0];
      }
      if (y < m) {
        res -= dp[x][y + 1][1];
        if (flag[x][y + 1])
          dp[x][y + 1][1] = 1 + dp[x][y][0];
        else
          dp[x][y + 1][1] = 0;
        res += dp[x][y + 1][1];
      }
      if (x < n && y < m) {
        res -= dp[x + 1][y + 1][1] + dp[x + 1][y + 1][0];
        if (flag[x + 1][y + 1])
          dp[x + 1][y + 1][0] = 1 + dp[x][y + 1][1];
        else
          dp[x + 1][y + 1][0] = 0;
        if (flag[x + 1][y + 1])
          dp[x + 1][y + 1][1] = 1 + dp[x + 1][y][0];
        else
          dp[x + 1][y + 1][1] = 0;
        res += dp[x + 1][y + 1][1] + dp[x + 1][y + 1][0];
      }
      x++, y++;
    }
    printf("%lld\n", res - tot);
  }
}
