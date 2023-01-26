#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int n, m, a[1009][1009], vis[1009][1009];
int tot, ans[1000009];
int qx[1000009], qy[1000009], hx, hy, tx, ty;
int bfs(int nx, int ny) {
  int an = 1;
  vis[nx][ny] = 1;
  hx = 0;
  hy = 0;
  tx = 1;
  ty = 1;
  qx[tx] = nx;
  qy[ty] = ny;
  int cm, px, py;
  while (hx < tx) {
    hx++;
    hy++;
    nx = qx[hx];
    ny = qy[hy];
    cm = a[nx][ny];
    for (int k = 0; k <= 3; k++) {
      px = nx + dx[k], py = ny + dy[k];
      if (!((cm >> k) & 1) && !vis[px][py]) {
        vis[px][py] = 1;
        qx[++tx] = px;
        qy[++ty] = py;
        an++;
      }
    }
  }
  return an;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        ans[++tot] = bfs(i, j);
      }
    }
  }
  sort(ans + 1, ans + tot + 1);
  for (int i = tot; i >= 1; i--) {
    printf("%d ", ans[i]);
  }
  return 0;
}
