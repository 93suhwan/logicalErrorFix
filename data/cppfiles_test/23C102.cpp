#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 4010, INF = 1e18;
int n, m, a[MAXN];
int st[MAXN], top;
int root, lc[MAXN], rc[MAXN];
int sz[MAXN];
long long f[MAXN][MAXN], ans;
void build() {
  for (int i = (1); i <= (n); i++) {
    int j = 0;
    while (top && a[st[top]] > a[i]) {
      j = st[top];
      top--;
    }
    if (!top)
      root = i;
    else
      rc[st[top]] = i;
    lc[i] = j;
    st[++top] = i;
  }
}
void dfs1(int u) {
  if (!u) return;
  sz[u] = 1;
  dfs1(lc[u]);
  dfs1(rc[u]);
  sz[u] += sz[lc[u]];
  sz[u] += sz[rc[u]];
}
void dfs2(int u) {
  if (!u) return;
  dfs2(lc[u]);
  dfs2(rc[u]);
  for (int i = (0); i <= (min(m, sz[lc[u]])); i++) {
    for (int j = (0); j <= (min(m - i, sz[rc[u]])); j++) {
      f[u][i + j] = max(
          f[u][i + j], f[lc[u]][i] + f[rc[u]][j] - (long long)i * j * 2 * a[u]);
    }
  }
  for (int i = (m); i >= (1); i--) {
    f[u][i] = max(f[u][i], f[u][i - 1] + (long long)(m - 1) * a[u] -
                               (long long)(i - 1) * 2 * a[u]);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  build();
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) f[i][j] = -INF;
  dfs1(root);
  dfs2(root);
  for (int i = (1); i <= (n); i++) ans = max(ans, f[i][m]);
  printf("%lld\n", ans);
  return 0;
}
