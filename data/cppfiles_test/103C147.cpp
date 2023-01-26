#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
int _, n, m;
char g[maxn][maxn];
int vis[maxn][maxn];
int flag;
void dfs(int x, int y) {
  int tx = x, ty = y;
  if (g[x][y] == 'U')
    tx--;
  else if (g[x][y] == 'D')
    tx++;
  else if (g[x][y] == 'L')
    ty--;
  else if (g[x][y] == 'R')
    ty++;
  if (tx <= 0 || tx >= n + 1 || ty <= 0 || ty >= m + 1) {
    vis[x][y] = 1;
    return;
  }
  if (vis[tx][ty] > 0) {
    vis[x][y] = vis[tx][ty] + 1;
    return;
  } else if (vis[tx][ty] < 0) {
    flag = vis[tx][ty] - vis[x][y] + 1;
    vis[x][y] = vis[tx][ty] = flag;
    return;
  }
  vis[tx][ty] = vis[x][y] - 1;
  dfs(tx, ty);
  if (flag) {
    if (vis[x][y] > 0)
      flag = 0;
    else
      vis[x][y] = flag;
  } else
    vis[x][y] = vis[tx][ty] + 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> _; _; _--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> g[i][j], vis[i][j] = 0;
    ;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!vis[i][j]) {
          vis[i][j] = -1;
          dfs(i, j);
        }
    int ansx = 0, ansy = 0, ansdis = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (ansdis < vis[i][j]) {
          ansx = i;
          ansy = j;
          ansdis = vis[i][j];
        }
      }
    }
    cout << ansx << ' ' << ansy << ' ' << ansdis << '\n';
  }
  return 0;
}
