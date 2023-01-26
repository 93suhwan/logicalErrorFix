#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2001][2001];
int v[2000][2000], vdx;
int c[2000][2000];
void next(int& x, int& y) {
  if (s[x][y] == 'U')
    x--;
  else if (s[x][y] == 'D')
    x++;
  else if (s[x][y] == 'L')
    y--;
  else if (s[x][y] == 'R')
    y++;
}
void cycle(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || c[x][y]) return;
  if (v[x][y] == vdx) {
    int count = 0;
    for (int i = x, j = y;;) {
      next(i, j), count++;
      if (i == x && j == y) break;
    }
    for (int i = x, j = y;;) {
      next(i, j), c[i][j] = count;
      if (i == x && j == y) break;
    }
  } else if (v[x][y] == 0) {
    v[x][y] = vdx;
    next(x, y);
    cycle(x, y);
  }
}
int dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  if (c[x][y]) return c[x][y];
  int nx = x, ny = y;
  next(nx, ny);
  return c[x][y] = dfs(nx, ny) + 1;
}
void solve() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) v[i][j] = c[i][j] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (v[i][j] == 0) {
        ++vdx;
        cycle(i, j);
      }
  ++vdx;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!c[i][j]) dfs(i, j);
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (c[x][y] < c[i][j]) x = i, y = j;
  printf("%d %d %d\n", x + 1, y + 1, c[x][y]);
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    solve();
  }
}
