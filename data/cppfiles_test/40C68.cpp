#include <bits/stdc++.h>
struct Edge {
  int v, next;
} e[600002];
int ecnt, h[300002];
inline void add_edge(int u, int v) {
  e[++ecnt] = {v, h[u]};
  h[u] = ecnt;
  e[++ecnt] = {u, h[v]};
  h[v] = ecnt;
}
int n, m, q;
int f[300002];
int fa[300002], dep[300002];
int u[300002], v[300002];
bool vis[300002];
void dfs(int u, int _fa) {
  vis[u] = 1;
  fa[u] = _fa, dep[u] = dep[_fa] + 1;
  for (int i = h[u]; i; i = e[i].next)
    if (!vis[e[i].v] && e[i].v != _fa) dfs(e[i].v, u);
}
int ans1[300002], ans2[300002], cnt1, cnt2;
inline void out(int u, int v) {
  cnt1 = cnt2 = 0;
  while (dep[u] > dep[v]) ans1[++cnt1] = u, u = fa[u];
  while (dep[u] < dep[v]) ans2[++cnt2] = v, v = fa[v];
  while (u != v) ans1[++cnt1] = u, u = fa[u], ans2[++cnt2] = v, v = fa[v];
  ans1[++cnt1] = u;
  printf("%d\n", cnt1 + cnt2);
  for (int i = 1; i <= cnt1; i++) printf("%d ", ans1[i]);
  for (int i = cnt2; i >= 1; i--) printf("%d ", ans2[i]);
  printf("\n");
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), add_edge(u, v);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++)
    scanf("%d%d", &u[i], &v[i]), f[u[i]] ^= 1, f[v[i]] ^= 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += f[i];
  if (!cnt) {
    printf("YES\n");
    dfs(1, 0);
    for (int i = 1; i <= q; i++) out(u[i], v[i]);
  } else
    printf("NO\n%d", cnt / 2);
  return 0;
}
