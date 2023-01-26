#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, dep[N], dfn[N], lst[N], cnt, f[N][25], eid, p[N], a[N];
long long tr[N];
struct edge {
  int v, nxt;
} e[N << 1];
inline void addedge(int u, int v) { e[++eid] = (edge){v, p[u]}, p[u] = eid; }
inline int lowbit(int x) { return x & (-x); }
inline void add(int x, long long d) {
  while (x <= n) tr[x] += d, x += lowbit(x);
}
inline void change(int l, int r, long long d) { add(l, d), add(r + 1, -d); }
inline long long query(int x) {
  long long res = 0;
  while (x > 0) res += tr[x], x -= lowbit(x);
  return res;
}
inline void dfs(int u, int fa) {
  f[u][0] = fa, dep[u] = dep[fa] + 1, dfn[u] = ++cnt;
  for (int i = 1; i < 20 && f[u][i - 1]; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = p[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
    if (v != fa) dfs(v, u);
  lst[u] = cnt;
}
inline int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = (19); i >= (0); i--)
    if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (int i = (19); i >= (0); i--)
    if (f[v][i] != f[u][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]), a[i] = max(a[i], -a[i]);
  for (int i = (1); i <= (n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v), addedge(v, u);
  }
  dfs(1, 0);
  for (int i = (1); i <= (n); i++) change(dfn[i], lst[i], a[i]);
  while (q--) {
    int opt, x, y;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      y = max(y, -y);
      change(dfn[x], lst[x], y - a[x]);
      a[x] = y;
    } else {
      int c = lca(x, y);
      long long w1 = query(dfn[x]) + query(dfn[y]);
      long long w2 = query(dfn[c]) + query(dfn[f[c][0]]);
      printf("%lld\n", (w1 - w2) * 2 - a[x] - a[y]);
    }
  }
  return 0;
}
