#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
char a[N][N];
int dfn[N][N], res[N][N], tx, ty, tot;
int dx[27], dy[27], n, m;
inline int read() {
  int ss = 0, ww = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ww = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    ss = (ss << 1) + (ss << 3) + (ch ^ 48), ch = getchar();
  return ss * ww;
}
bool ok(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }
void dfs(int x, int y) {
  if (dfn[x][y]) {
    if (res[x][y]) return;
    tx = x, ty = y;
    res[x][y] = tot - dfn[x][y] + 1;
    return;
  }
  dfn[x][y] = ++tot;
  if (!ok(x + dx[a[x][y] - 'A'], y + dy[a[x][y] - 'A'])) {
    res[x][y] = 1;
    return;
  }
  dfs(x + dx[a[x][y] - 'A'], y + dy[a[x][y] - 'A']);
  if (tx && ty)
    res[x][y] = res[x + dx[a[x][y] - 'A']][y + dy[a[x][y] - 'A']];
  else
    res[x][y] = res[x + dx[a[x][y] - 'A']][y + dy[a[x][y] - 'A']] + 1;
  if (tx == x && ty == y) tx = ty = 0;
}
int main() {
  dx['U' - 'A'] = -1, dx['D' - 'A'] = 1;
  dy['L' - 'A'] = -1, dy['R' - 'A'] = 1;
  int t = read(), x, y, ans;
  while (t--) {
    n = read(), m = read(), tot = ans = 0;
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) dfn[i][j] = res[i][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!dfn[i][j]) {
          tot = 0;
          dfs(i, j);
        }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (ans < res[i][j]) ans = res[i][j], x = i, y = j;
    printf("%d %d %d\n", x, y, ans);
  }
  return 0;
}
