#include <bits/stdc++.h>
using namespace std;
const int N = 2010, M = N * N;
int n, m, dist[N][N], deg[N][N], fx[N][N], fy[N][N];
char str[N][N];
pair<int, int> p[M];
int hh, tt;
bool st[N][N];
void get_dist(int& x, int& y, char c) {
  if (c == 'U') x--;
  if (c == 'D') x++;
  if (c == 'L') y--;
  if (c == 'R') y++;
}
void topsort() {
  hh = 0;
  tt = -1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      dist[i][j] = 1;
      fx[i][j] = i;
      fy[i][j] = j;
      if (!deg[i][j]) p[++tt] = {i, j};
    }
  while (hh <= tt) {
    pair<int, int> u = p[hh++];
    int x = u.first, y = u.second, distance = dist[x][y];
    get_dist(x, y, str[x][y]);
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
void dfs(int x, int y) {
  if (st[x][y]) return;
  p[tt++] = {x, y};
  st[x][y] = 1;
  get_dist(x, y, str[x][y]);
  dfs(x, y);
}
int main() {
  int T, res, x, y;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    memset(deg, 0, sizeof deg);
    for (int i = 1; i <= n; ++i) {
      cin >> str[i] + 1;
      for (int j = 1; j <= m; ++j) {
        int x = i, y = j;
        get_dist(x, y, str[i][j]);
        if (x <= 0 || x > n || y <= 0 || y > m) continue;
        deg[x][y]++;
      }
    }
    topsort();
    res = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (res < dist[i][j]) {
          res = dist[i][j];
          x = fx[i][j];
          y = fy[i][j];
        }
    cout << x << ' ' << y << ' ' << res << endl;
  }
  return 0;
}
