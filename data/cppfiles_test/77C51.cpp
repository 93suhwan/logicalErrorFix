#include <bits/stdc++.h>
using namespace std;
int n, m, num, cnt;
int dat[1009][1009], ans[1000009];
bool vis[1009][1009];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int wall[4] = {8, 4, 2, 1};
void dfs(int x, int y) {
  if (vis[x][y] || x < 0 || x > n || y < 0 || y > m) return;
  vis[x][y] = 1;
  num++;
  for (int i = 0; i < 4; i++) {
    if ((dat[x][y] & wall[i]) ||
        (dat[x + dx[i]][y + dy[i]] & wall[(i + 2) % 4]))
      continue;
    dfs(x + dx[i], y + dy[i]);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> dat[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        num = 0;
        dfs(i, j);
        ans[++cnt] = num;
      }
    }
  }
  sort(ans + 1, ans + 1 + cnt);
  for (int i = cnt; i > 0; i--) cout << ans[i] << " ";
  return 0;
}
