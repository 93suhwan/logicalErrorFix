#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 19;
int n, q, a[N], gr[N], dep[N], fa[N][K], mx[N][K], p[N], mxd[N];
struct Q {
  int u, v, c, t;
} e[N << 1];
struct E {
  int v, t;
};
vector<E> g[N];
pair<int, int> ans[N];
int find(int u) { return gr[u] == u ? u : gr[u] = find(gr[u]); }
void dfs(int u) {
  for (auto e : g[u]) {
    if (e.v == fa[u][0]) continue;
    fa[e.v][0] = u, mx[e.v][0] = e.t, dep[e.v] = dep[u] + 1;
    for (int i = 1; i <= 18; i++) {
      fa[e.v][i] = fa[fa[e.v][i - 1]][i - 1];
      mx[e.v][i] = max(mx[e.v][i - 1], mx[fa[e.v][i - 1]][i - 1]);
    }
    dfs(e.v);
  }
}
int query(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ret = 0;
  for (int i = 18; i >= 0; i--)
    if (dep[fa[u][i]] >= dep[v]) ret = max(ret, mx[u][i]), u = fa[u][i];
  if (u == v) return ret;
  for (int i = 18; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) {
      ret = max(ret, mx[u][i]), u = fa[u][i];
      ret = max(ret, mx[v][i]), v = fa[v][i];
    }
  return max(ret, max(mx[u][0], mx[v][0]));
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), gr[i] = p[i] = i, mxd[i] = 0;
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].c, &e[i].t);
    g[e[i].u].push_back({e[i].v, e[i].t});
    g[e[i].v].push_back({e[i].u, e[i].t});
  }
  dep[1] = 1, dfs(1);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &e[n - 1 + i].c, &e[n - 1 + i].u);
    e[n - 1 + i].t = i;
  }
  sort(e + 1, e + (n - 1 + q) + 1, [&](Q a, Q b) {
    if (a.c != b.c) return a.c > b.c;
    return a.v > b.v;
  });
  for (int i = 1; i <= n - 1 + q; i++) {
    if (e[i].v) {
      int u = find(e[i].u), v = find(e[i].v);
      gr[v] = u;
      if (a[p[u]] == a[p[v]])
        mxd[u] = max(max(mxd[u], mxd[v]), query(p[u], p[v]));
      else if (a[p[v]] > a[p[u]])
        p[u] = p[v], mxd[u] = mxd[v];
    } else {
      int u = find(e[i].u);
      ans[e[i].t] = {a[p[u]], max(mxd[u], query(p[u], e[i].u))};
    }
  }
  for (int i = 1; i <= q; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
