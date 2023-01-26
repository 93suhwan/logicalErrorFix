#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int dp[N][N];
char a[N][N];
int vis[N][N];
int n, m, cnt, tip, cha, f, tx, ty;
inline void dfs(short i, short j) {
  if (vis[i][j] == tip) {
    dp[i][j] = cnt - dp[i][j] + 1;
    tx = i;
    ty = j;
    f = 1;
    return;
  }
  if (i < 1 || j < 1 || i > n || j > m) return;
  if (dp[i][j]) return;
  vis[i][j] = tip;
  dp[i][j] = ++cnt;
  if (a[i][j] == 'L') {
    dfs(i, j - 1);
    if (!f)
      dp[i][j] = dp[i][j - 1] + 1;
    else
      dp[i][j] = dp[i][j - 1];
  } else if (a[i][j] == 'R') {
    dfs(i, j + 1);
    if (!f)
      dp[i][j] = dp[i][j + 1] + 1;
    else
      dp[i][j] = dp[i][j + 1];
  } else if (a[i][j] == 'U') {
    dfs(i - 1, j);
    if (!f)
      dp[i][j] = dp[i - 1][j] + 1;
    else
      dp[i][j] = dp[i - 1][j];
  } else {
    dfs(i + 1, j);
    if (!f)
      dp[i][j] = dp[i + 1][j] + 1;
    else
      dp[i][j] = dp[i + 1][j];
  }
  if (i == tx && j == ty) f = 0;
  return;
}
inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int ans = 0, st = 0, ed = 0, cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!dp[i][j]) {
        cnt = 0;
        f = 0;
        tx = 0;
        ty = 0;
        tip++;
        dfs(i, j);
        if (dp[i][j] > ans) ans = dp[i][j], st = i, ed = j;
      }
  cout << st << " " << ed << " " << ans << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = vis[i][j] = 0;
}
signed main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
