#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int tp, a[1005][1005], qx[1005 * 1005], qy[1005 * 1005], ans[1005 * 1005];
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
void bfs(int, int);
int main() {
  int i, j, n, m;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      a[i][j] ^= 15;
    }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
      if (!vis[i][j]) bfs(i, j);
  sort(ans + 1, ans + tp + 1);
  while (tp) printf("%d ", ans[tp--]);
  return 0;
}
void bfs(int sx, int sy) {
  int k, x, y, nx, ny, hd, tl, cnt = 0;
  vis[qx[hd = 1] = sx][qy[tl = 1] = sy] = 1;
  while (hd <= tl) {
    ++cnt;
    x = qx[hd];
    y = qy[hd];
    for (k = 0; k < 4; ++k)
      if ((a[x][y] & (1 << k)) && !vis[nx = dx[k] + x][ny = dy[k] + y]) {
        vis[nx][ny] = 1;
        qx[++tl] = nx;
        qy[tl] = ny;
      }
    ++hd;
  }
  ans[++tp] = cnt;
}
