#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
char _buf[100000], *_p1 = _buf, *_p2 = _buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
const int maxn = 1e5 + 5;
int c[maxn], n, q;
vector<int> e[maxn];
int dfn[maxn], tot;
struct BIT {
  long long c[maxn];
  inline void update(int x, int v) {
    while (x <= n) c[x] += v, x += x & -x;
  }
  inline long long query(int x) {
    long long ret = 0;
    while (x) ret += c[x], x -= x & -x;
    return ret;
  }
} tree;
inline void init() {}
inline void input() {
  n = gi();
  q = gi();
  for (int i = 1; i <= n; ++i) c[i] = gi(), c[i] = abs(c[i]);
  for (int i = 1; i <= n - 1; ++i) {
    int u = gi(), v = gi();
    e[u].push_back(v), e[v].push_back(u);
  }
}
int fa[maxn][20], Log[maxn], dep[maxn], low[maxn];
inline void dfs(int u) {
  dfn[u] = ++tot;
  dep[u] = dep[fa[u][0]] + 1;
  for (int i = 1; i <= Log[dep[u]]; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : e[u]) {
    if (v == fa[u][0]) continue;
    fa[v][0] = u;
    dfs(v);
  }
  low[u] = tot;
}
inline int LCA(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = Log[dep[v]]; i >= 0; --i)
    if (dep[fa[v][i]] >= dep[u]) v = fa[v][i];
  if (u == v) return u;
  for (int i = Log[dep[v]]; i >= 0; --i)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
inline void solve() {
  for (int i = 2; i <= n; ++i) Log[i] = Log[i >> 1] + 1;
  dfs(1);
  for (int i = 1; i <= n; ++i)
    tree.update(dfn[i], c[i]), tree.update(low[i] + 1, -c[i]);
  for (int i = 1; i <= q; ++i) {
    int opt = gi();
    int u = gi(), v = gi();
    if (opt == 1) {
      v = abs(v);
      tree.update(dfn[u], v - c[u]);
      tree.update(low[u] + 1, c[u] - v);
      c[u] = v;
    } else {
      long long ans = 0;
      int lca = LCA(u, v);
      ans += 2 * tree.query(dfn[u]) + 2 * tree.query(dfn[v]) -
             2 * tree.query(dfn[lca]) - 2 * tree.query(dfn[fa[lca][0]]);
      ans -= c[u] + c[v];
      printf("%lld\n", ans);
    }
  }
}
int main() {
  int T = 1;
  while (T--) {
    init();
    input();
    solve();
  }
  return 0;
}
