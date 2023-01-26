#include <bits/stdc++.h>
using namespace std;
char a[2010][2010];
int n, m;
int dp[2010][2010];
int c[2010][2010];
int ans;
int num;
void dfs(int x, int y) {
  c[x][y] = 1;
  num++;
  int nx = x, ny = y;
  if (a[x][y] == 'L') ny--;
  if (a[x][y] == 'R') ny++;
  if (a[x][y] == 'U') nx--;
  if (a[x][y] == 'D') nx++;
  if (dp[nx][ny]) {
    dp[x][y] = 1 + dp[nx][ny];
    ans += dp[x][y];
    c[x][y] = 0;
    return;
  }
  if (ny <= 0 || nx <= 0 || ny > m || nx > n) {
    dp[x][y] = 1;
    ans += dp[x][y];
    c[x][y] = 0;
    return;
  }
  if (!dp[nx][ny] && !c[nx][ny])
    dfs(nx, ny);
  else {
    dp[x][y] = num;
    ans++;
    c[x][y] = 0;
    return;
  }
  ++ans;
  dp[x][y] = ans;
  c[x][y] = 0;
}
signed main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] + 1;
    for (int i = 0; i <= n + 2; i++) {
      for (int j = 0; j <= m + 2; j++) {
        dp[i][j] = 0;
        c[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j]) continue;
        num = 0;
        ans = 0;
        dfs(i, j);
      }
    }
    int mmax = 0, ansx, ansy;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] <= mmax) continue;
        mmax = dp[i][j];
        ansx = i, ansy = j;
      }
    }
    cout << ansx << " " << ansy << " " << mmax << endl;
  }
  return 0;
}
