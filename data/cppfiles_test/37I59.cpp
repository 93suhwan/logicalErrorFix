#include <bits/stdc++.h>
int T, n, m;
bool vis[300005];
signed main() {
  int i, a, b, c;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; ++i) scanf("%d%d%d", &a, &b, &c), vis[b] = true;
    for (i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      b = i;
      for (i = 1; i <= n; ++i)
        if (i != b) printf("%d %d\n", i, b);
      break;
    }
    printf("\n");
  }
}
