#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int N = 2010;
int n, m, X, Y, f[N][N], g[N][N];
char s[N][N];
void dfs(int x, int y, int dep) {
  if (f[x][y] != -1) return;
  g[x][y] = dep;
  if (s[x][y] == 'U') {
    if (x == 1)
      f[x][y] = 0;
    else if (g[x - 1][y]) {
      X = x - 1;
      Y = y;
      f[x][y] = dep - g[X][Y];
    } else {
      dfs(x - 1, y, dep + 1);
      if (X) {
        f[x][y] = f[x - 1][y];
        if (x == X && Y == y) X = Y = 0;
      } else
        f[x][y] = f[x - 1][y] + 1;
    }
  }
  if (s[x][y] == 'D') {
    if (x == n)
      f[x][y] = 0;
    else if (g[x + 1][y]) {
      X = x + 1;
      Y = y;
      f[x][y] = dep - g[X][Y];
    } else {
      dfs(x + 1, y, dep + 1);
      if (X) {
        f[x][y] = f[x + 1][y];
        if (x == X && Y == y) X = Y = 0;
      } else
        f[x][y] = f[x + 1][y] + 1;
    }
  }
  if (s[x][y] == 'L') {
    if (y == 1)
      f[x][y] = 0;
    else if (g[x][y - 1]) {
      X = x;
      Y = y - 1;
      f[x][y] = dep - g[X][Y];
    } else {
      dfs(x, y - 1, dep + 1);
      if (X) {
        f[x][y] = f[x][y - 1];
        if (x == X && Y == y) X = Y = 0;
      } else
        f[x][y] = f[x][y - 1] + 1;
    }
  }
  if (s[x][y] == 'R') {
    if (y == m)
      f[x][y] = 0;
    else if (g[x][y + 1]) {
      X = x;
      Y = y + 1;
      f[x][y] = dep - g[X][Y];
    } else {
      dfs(x, y + 1, dep + 1);
      if (X) {
        f[x][y] = f[x][y + 1];
        if (x == X && Y == y) X = Y = 0;
      } else
        f[x][y] = f[x][y + 1] + 1;
    }
  }
  g[x][y] = 0;
}
void Work() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      f[i][j] = -1;
      g[i][j] = 0;
      s[i][j] = getchar();
      while (s[i][j] < 'A' || s[i][j] > 'Z') s[i][j] = getchar();
    }
  int xx = 0, yy = 0;
  f[0][0] = -2333;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dfs(i, j, 1);
      if (f[i][j] > f[xx][yy]) xx = i, yy = j;
    }
  printf("%d %d %d\n", xx, yy, f[xx][yy] + 1);
}
int main() {
  freopen("data.txt", "r", stdin);
  int T = 1;
  scanf("%d", &T);
  while (T--) Work();
  return 0;
}
