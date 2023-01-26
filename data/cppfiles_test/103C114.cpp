#include <bits/stdc++.h>
using namespace std;
char ch[2005][2005];
struct edge {
  int x, y;
} p, u, s[4000005];
int col[2005][2005], dp[2005][2005];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, cir = 0, cnt = 0, step = 0, ans = 0, t = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!col[i][j]) {
          cnt++, step = 0;
          s[++t] = {i, j};
          while (1) {
            int x = s[t].x, y = s[t].y;
            col[x][y] = cnt, dp[x][y] = ++step;
            int nx, ny;
            if (ch[x][y] == 'R') nx = x, ny = y + 1;
            if (ch[x][y] == 'D') nx = x + 1, ny = y;
            if (ch[x][y] == 'L') nx = x, ny = y - 1;
            if (ch[x][y] == 'U') nx = x - 1, ny = y;
            if (nx < 1 || ny < 1 || nx > n || ny > m) {
              dp[x][y] = 1;
              break;
            }
            if (col[nx][ny]) {
              if (col[nx][ny] != cnt)
                dp[x][y] = dp[nx][ny] + 1;
              else
                cir = dp[x][y] = dp[x][y] - dp[nx][ny] + 1, u = {nx, ny};
              break;
            }
            s[++t] = {nx, ny};
          }
          while (t) {
            int nx = s[t].x, ny = s[t].y;
            t--;
            if (!t) break;
            int x = s[t].x, y = s[t].y;
            if (!cir)
              dp[x][y] = dp[nx][ny] + 1;
            else if (nx == u.x && ny == u.y)
              dp[x][y] = dp[nx][ny] + 1, cir = 0;
            else
              dp[x][y] = dp[nx][ny];
          }
          u.x = u.y = cir = 0;
        }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (ans < dp[i][j]) ans = dp[i][j], p.x = i, p.y = j;
      }
    printf("%d %d %d\n", p.x, p.y, ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) col[i][j] = 0;
    p.x = p.y = cnt = 0;
  }
  return 0;
}
