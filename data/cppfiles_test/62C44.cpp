#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
bool mp[N][N];
long long dp[N][N][2] = {0}, ans = 0;
int main() {
  int n, m, q, x, y, z;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j > 1) dp[i][j][0] = dp[i][j - 1][1] + 1;
      if (i > 1) dp[i][j][1] = dp[i - 1][j][0] + 1;
      ans += dp[i][j][1] + dp[i][j][0] + 1;
    }
  }
  while (q--) {
    cin >> x >> y;
    mp[x][y] = !mp[x][y];
    z = min(n - x, m - y);
    if (mp[x][y]) {
      ans -= dp[x][y][1] + dp[x][y][0] + 1;
      dp[x][y][1] = dp[x][y][0] = 0;
    } else {
      if (y > 1) dp[x][y][0] = dp[x][y - 1][1] + !mp[x][y - 1];
      if (x > 1) dp[x][y][1] = dp[x - 1][y][0] + !mp[x - 1][y];
      ans += dp[x][y][1] + dp[x][y][0] + 1;
    }
    for (int i = 1;; i++) {
      if ((x + i <= n) && (y + i - 1 <= m) && !mp[x + i][y + i - 1]) {
        ans -= dp[x + i][y + i - 1][1];
        dp[x + i][y + i - 1][1] =
            dp[x + i - 1][y + i - 1][0] + !mp[x + i - 1][y + i - 1];
        ans += dp[x + i][y + i - 1][1];
      }
      if ((x + i - 1 <= n) && (y + i <= m) && !mp[x + i - 1][y + i]) {
        ans -= dp[i + x - 1][y + i][0];
        dp[x + i - 1][y + i][0] =
            dp[x + i - 1][y + i - 1][1] + !mp[x + i - 1][y + i - 1];
        ans += dp[i + x - 1][y + i][0];
      }
      if ((x + i <= n) && (y + i <= m) && !mp[x + i][y + i]) {
        ans -= dp[x + i][y + i][1] + dp[i + x][y + i][0];
        dp[x + i][y + i][0] = dp[x + i][y + i - 1][1] + !mp[x + i][y + i - 1];
        dp[x + i][y + i][1] = dp[x + i - 1][y + i][0] + !mp[x + i - 1][y + i];
        ans += dp[x + i][y + i][1] + dp[i + x][y + i][0];
      }
      if (i > z) break;
    }
    cout << ans << "\n";
  }
  return 0;
}
