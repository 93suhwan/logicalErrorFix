#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005][3];
bool vis[1005][1005];
int main() {
  int n, m, q, ans;
  cin >> n >> m >> q;
  ans = n * m;
  for (int i = 1; i <= n; i++) {
    dp[i][0][0] = -1;
    dp[i][0][1] = -1;
  }
  for (int j = 1; j <= m; j++) {
    dp[0][j][0] = -1;
    dp[0][j][1] = -1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = dp[i][j - 1][1] + 1;
      dp[i][j][1] = dp[i - 1][j][0] + 1;
      vis[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans += dp[i][j][0] + dp[i][j][1];
  while (q--) {
    int x, y;
    bool f1 = 1, f2 = 1;
    cin >> x >> y;
    if (!vis[x][y]) {
      vis[x][y] = 1;
      dp[x][y][0] = dp[x][y - 1][1] + 1;
      dp[x][y][1] = dp[x - 1][y][0] + 1;
      ans += dp[x][y][0] + dp[x][y][1] + 1;
      for (int i = 1; i <= min(n - x, m - y); i++) {
        if (vis[x + i - 1][y + i] && f1) {
          dp[x + i - 1][y + i][0] += dp[x][y][1] + 1;
          ans += dp[x][y][1] + 1;
        } else
          f1 = 0;
        if (vis[x + i][y + i - 1] && f2) {
          dp[x + i][y + i - 1][1] += dp[x][y][0] + 1;
          ans += dp[x][y][0] + 1;
        } else
          f2 = 0;
        if (vis[x + i][y + i] && f2) {
          dp[x + i][y + i][0] += dp[x][y][0] + 1;
          ans += dp[x][y][0] + 1;
        } else
          f2 = 0;
        if (vis[x + i][y + i] && f1) {
          dp[x + i][y + i][1] += dp[x][y][1] + 1;
          ans += dp[x][y][1] + 1;
        } else
          f1 = 0;
      }
      if (n - x > m - y && vis[x + m - y + 1][m] && f2) {
        dp[x + m - y + 1][m][1] += dp[x][y][0] + 1;
        ans += dp[x][y][0] + 1;
      } else if (n - x < m - y && vis[n][y + n - x + 1] && f1) {
        dp[n][y + n - x + 1][0] += dp[x][y][1] + 1;
        ans += dp[x][y][1] + 1;
      }
    } else {
      vis[x][y] = 0;
      ans -= dp[x][y][0] + dp[x][y][1] + 1;
      for (int i = 1; i <= min(n - x, m - y); i++) {
        if (vis[x + i - 1][y + i] && f1) {
          dp[x + i - 1][y + i][0] -= dp[x][y][1] + 1;
          ans -= dp[x][y][1] + 1;
        } else
          f1 = 0;
        if (vis[x + i][y + i - 1] && f2) {
          dp[x + i][y + i - 1][1] -= dp[x][y][0] + 1;
          ans -= dp[x][y][0] + 1;
        } else
          f2 = 0;
        if (vis[x + i][y + i] && f2) {
          dp[x + i][y + i][0] -= dp[x][y][0] + 1;
          ans -= dp[x][y][0] + 1;
        } else
          f2 = 0;
        if (vis[x + i][y + i] && f1) {
          dp[x + i][y + i][1] -= dp[x][y][1] + 1;
          ans -= dp[x][y][1] + 1;
        } else
          f1 = 0;
      }
      if (n - x > m - y && vis[x + m - y + 1][m] && f2) {
        dp[x + m - y + 1][m][1] -= dp[x][y][0] + 1;
        ans -= dp[x][y][0] + 1;
      } else if (n - x < m - y && vis[n][y + n - x + 1] && f1) {
        dp[n][y + n - x + 1][0] -= dp[x][y][1] + 1;
        ans -= dp[x][y][1] + 1;
      }
      dp[x][y][0] = -1;
      dp[x][y][1] = -1;
    }
    cout << ans << endl;
  }
}
