#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, f[505][505], g[505][505], nxt[666], it, res[666], sb;
bool a[666], b[666];
int main() {
  memset(f, 1, sizeof(f));
  memset(g, 1, sizeof(g));
  memset(res, 1, sizeof(res));
  f[0][0] = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%1d", &a[i]);
  for (i = 1; i <= m; i++) scanf("%1d", &b[i]);
  for (i = 2; i <= m; i++) {
    while (it && b[i] != b[it + 1]) {
      it = nxt[it];
    }
    if (b[i] == b[it + 1]) it++;
    nxt[i] = it;
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j < n - m + 2; j++) {
      for (k = 0; k < m; k++) {
        if (a[i] == b[k + 1]) {
          if (k == m - 1) {
            g[j + 1][nxt[m]] = min(g[j + 1][nxt[m]], f[j][k]);
          } else {
            g[j][k + 1] = min(g[j][k + 1], f[j][k]);
          }
          sb = nxt[k];
          if (a[i] != b[sb + 1]) sb++;
          g[j][sb] = min(g[j][sb], f[j][k] + 1);
        } else {
          if (k == m - 1) {
            g[j + 1][nxt[m]] = min(g[j + 1][nxt[m]], f[j][k] + 1);
          } else {
            g[j][k + 1] = min(g[j][k + 1], f[j][k] + 1);
          }
          sb = nxt[k];
          if (a[i] == b[sb + 1]) sb++;
          g[j][sb] = min(g[j][sb], f[j][k]);
        }
      }
    }
    memcpy(f, g, sizeof(g));
    memset(g, 1, sizeof(g));
  }
  for (i = 0; i <= n - m + 2; i++) {
    for (j = 0; j < m; j++) {
      if (f[i][j] < 114514) {
        res[i] = min(res[i], f[i][j]);
      }
    }
  }
  for (i = 0; i < n - m + 2; i++) {
    printf("%d ", (res[i] >= 114514) ? -1 : res[i]);
  }
}
