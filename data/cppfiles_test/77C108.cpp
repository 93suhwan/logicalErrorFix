#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], vis[1005][1005];
int ans[10000005];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int w[] = {8, 4, 2, 1};
int n, m;
int dfs(int x, int y) {
  int sum = 1;
  if (vis[x][y] || x < 1 || y < 1 || x > n || y > m) return 0;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    if (a[x][y] & w[i])
      continue;
    else
      sum += dfs(x + dx[i], y + dy[i]);
  }
  return sum;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int tot = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) ans[tot++] = dfs(i, j);
    }
  }
  sort(ans + 1, ans + tot);
  for (int i = tot - 1; i >= 1; i--) cout << ans[i] << " ";
  return 0;
}
