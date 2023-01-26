#include <bits/stdc++.h>
using namespace std;
long long n, m, k, cnt, ans;
long long dp[1010][1010][2], x, y;
bool ma[1010][1010];
void change(long long x, long long y) {
  if (ma[x][y]) return;
  if (x > n || y > m) return;
  ans -= dp[x][y][1] + dp[x][y][0];
  dp[x][y][1] = dp[x - 1][y][0] + 1;
  dp[x][y][0] = dp[x][y - 1][1] + 1;
  ans += dp[x][y][1] + dp[x][y][0];
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  cnt = n * m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      dp[i][j][1] = dp[i - 1][j][0] + 1;
      dp[i][j][0] = dp[i][j - 1][1] + 1;
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) ans += (dp[i][j][0] + dp[i][j][1]);
  while (k--) {
    scanf("%lld%lld", &x, &y);
    if (!ma[x][y]) {
      cnt--;
      ans -= dp[x][y][0] + dp[x][y][1];
      dp[x][y][0] = dp[x][y][1] = 0;
      ma[x][y] = 1;
    } else {
      cnt++;
      dp[x][y][0] = dp[x][y - 1][1] + 1;
      dp[x][y][1] = dp[x - 1][y][0] + 1;
      ans += dp[x][y][0] + dp[x][y][1];
      ma[x][y] = 0;
    }
    while (x <= n && y <= m) {
      change(x + 1, y);
      change(x, y + 1);
      change(x + 1, y + 1);
      x++;
      y++;
    }
    printf("%lld\n", ans - cnt);
  }
}
