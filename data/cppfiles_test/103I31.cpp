#include <bits/stdc++.h>
using namespace std;
char ch[2005][2005];
struct edge {
  int x, y;
} p, u;
int col[4000005], dp[4000005], s[4000005], cir, n, m, cnt, step;
void dfs(short x, short y) {
  col[x * n + y] = cnt, s[x * n + y] = ++step;
  short nx, ny;
  if (ch[x][y] == 'R') nx = x, ny = y + 1;
  if (ch[x][y] == 'D') nx = x + 1, ny = y;
  if (ch[x][y] == 'L') nx = x, ny = y - 1;
  if (ch[x][y] == 'U') nx = x - 1, ny = y;
  if (nx < 1 || ny < 1 || nx > n || ny > m) {
    dp[x * n + y] = 1;
    return;
  }
  if (col[nx * n + ny]) {
    if (col[nx * n + ny] != cnt)
      dp[x * n + y] = dp[nx * n + ny] + 1;
    else
      cir = dp[x * n + y] = s[x * n + y] - s[nx * n + ny] + 1, u = {nx, ny};
    return;
  }
  dfs(nx, ny);
  if (!cir)
    dp[x * n + y] = dp[nx * n + ny] + 1;
  else if (nx == u.x && ny == u.y)
    dp[x * n + y] = dp[nx * n + ny] + 1, cir = 0;
  else
    dp[x * n + y] = dp[nx * n + ny];
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!col[i * n + j]) {
          cnt++, step = 0, dfs(i, j), u.x = u.y = cir = 0;
        }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (ans < dp[i * n + j]) ans = dp[i * n + j], p.x = i, p.y = j;
      }
    printf("%d %d %d\n", p.x, p.y, ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        col[i * n + j] = dp[i * n + j] = s[i * n + j] = 0;
    p.x = p.y = cnt = 0;
  }
  return 0;
}
