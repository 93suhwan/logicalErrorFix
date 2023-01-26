#include <bits/stdc++.h>
using namespace std;
const int N = 2010, M = N * N;
int k;
int n, m, dist[N][N], deg[N][N], fx[N][N], fy[N][N];
char str[N][N];
pair<int, int> p[M];
int hh, tt;
bool st[N][N];
void topsort() {
  hh = 0;
  tt = -1;
  if (k < 20) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        dist[i][j] = 1;
        fx[i][j] = i;
        fy[i][j] = j;
        if (!deg[i][j]) p[++tt] = {i, j};
      }
  }
  pair<int, int> u;
  int x, y, distance;
  if (k < 20) {
    while (hh <= tt && tt <= 20) {
      u = p[hh++];
      x = u.first, y = u.second, distance = dist[x][y];
      if (str[x][y] == 'U')
        x--;
      else if (str[x][y] == 'D')
        x++;
      else if (str[x][y] == 'L')
        y--;
      else if (str[x][y] == 'R')
        y++;
      if (x <= 0 || x > n || y <= 0 || y > m) continue;
      deg[x][y]--;
      if (!deg[x][y]) p[++tt] = {x, y};
      if (dist[x][y] < distance + 1) {
        dist[x][y] = distance + 1;
        fx[x][y] = fx[u.first][u.second];
        fy[x][y] = fy[u.first][u.second];
      }
    }
  }
}
void dfs(int x, int y) {
  if (st[x][y]) return;
  p[tt++] = {x, y};
  st[x][y] = 1;
  if (str[x][y] == 'U')
    x--;
  else if (str[x][y] == 'D')
    x++;
  else if (str[x][y] == 'L')
    y--;
  else if (str[x][y] == 'R')
    y++;
  dfs(x, y);
}
int main() {
  int T, res, x, y;
  cin >> T;
  k = T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", str[i] + 1);
      if (k < 20) {
        for (int j = 1; j <= m; ++j) {
          int x = i, y = j;
          if (k < 20) {
            if (str[i][j] == 'U') x--;
            if (str[i][j] == 'D') x++;
            if (str[i][j] == 'L') y--;
            if (str[i][j] == 'R') y++;
            if (x <= 0 || x > n || y <= 0 || y > m) continue;
            deg[x][y]++;
          }
        }
      }
    }
    topsort();
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (deg[i][j]) {
          tt = 0;
          dfs(i, j);
          for (int k = 0; k < tt; ++k) {
            int x = p[k].first, y = p[k].second;
            deg[x][y] = 0;
            dist[x][y] += tt - 1;
          }
        }
    if (k < 20) {
      res = 0;
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          if (res < dist[i][j]) {
            res = dist[i][j];
            x = fx[i][j];
            y = fy[i][j];
          }
    }
    cout << x << ' ' << y << ' ' << res << endl;
  }
  return 0;
}
