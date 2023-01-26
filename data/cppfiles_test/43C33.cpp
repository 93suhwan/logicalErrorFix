#include <bits/stdc++.h>
using std::max;
using std::pair;
using std::vector;
struct Edge {
  int u, v;
  int w;
};
vector<Edge> g[200005];
int e[200005];
Edge edge[200005];
int f[200005][18];
int w[200005][18];
int dep[200005];
int vis[200005];
int p[200005];
int maxE[200005];
int root[200005];
int maxT[200005];
struct Query {
  int u, v;
  int id;
};
Query a[200005];
int ans[200005];
int ansE[200005];
void dfs(int u) {
  vis[u] = 1;
  for (auto ed : g[u]) {
    if (vis[ed.v]) continue;
    int v = ed.v, val = ed.w;
    dep[v] = dep[u] + 1;
    f[v][0] = u;
    w[v][0] = val;
    dfs(v);
  }
  vis[u] = 0;
}
void preWork(int n, int m) {
  dfs(1);
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (f[i][j - 1]) {
        int lst = f[i][j - 1];
        f[i][j] = f[lst][j - 1];
        w[i][j] = max(w[i][j - 1], w[lst][j - 1]);
      }
    }
  }
}
pair<int, int> lca(int x, int y, int m) {
  if (dep[x] > dep[y]) std::swap(x, y);
  auto res = pair<int, int>{-1, -1};
  for (int i = m; i >= 0; i--) {
    if (f[y][i] && dep[f[y][i]] >= dep[x]) {
      res.second = max(res.second, w[y][i]);
      y = f[y][i];
    }
  }
  if (x == y) {
    res.first = x;
    return res;
  }
  for (int i = m; i >= 0; i--) {
    if (f[x][i] && f[y][i] && f[x][i] != f[y][i]) {
      res.second = max(res.second, w[x][i]);
      res.second = max(res.second, w[y][i]);
      x = f[x][i];
      y = f[y][i];
    }
  }
  res.second = max(res.second, w[x][0]);
  res.second = max(res.second, w[y][0]);
  res.first = f[x][0];
  return res;
}
int find(int u) {
  if (p[u] == u)
    return u;
  else
    return p[u] = find(p[u]);
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &e[i]);
  for (int i = 1; i <= n - 1; i++) {
    int u, v, c, t;
    scanf("%d%d%d%d", &u, &v, &c, &t);
    edge[i] = Edge{u, v, c};
    g[u].push_back(Edge{u, v, t});
    g[v].push_back(Edge{v, u, t});
  }
  int m = 17;
  preWork(n, m);
  std::sort(edge + 1, edge + 1 + n - 1,
            [](Edge& u, Edge& v) { return u.w > v.w; });
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    maxE[i] = e[i];
    root[i] = i;
    maxT[i] = 0;
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &a[i].v, &a[i].u);
    a[i].id = i;
  }
  std::sort(a + 1, a + 1 + q, [](Query& u, Query& v) { return u.v > v.v; });
  int ptr = 0;
  for (int i = 1; i <= q; i++) {
    auto cur = a[i];
    while (ptr + 1 <= n - 1 && edge[ptr + 1].w >= cur.v) {
      ptr++;
      int u = edge[ptr].u, v = edge[ptr].v;
      u = find(u), v = find(v);
      if (maxE[u] != maxE[v]) {
        if (maxE[u] < maxE[v]) std::swap(u, v);
        p[v] = u;
      } else {
        int ru = root[u], rv = root[v];
        auto pr = lca(ru, rv, m);
        root[u] = pr.first;
        maxT[u] = max(maxT[u], maxT[v]);
        maxT[u] = max(maxT[u], pr.second);
        p[v] = u;
      }
    }
    int u = find(a[i].u);
    int val = maxT[u];
    auto pr = lca(a[i].u, root[u], m);
    val = max(val, pr.second);
    ans[a[i].id] = val;
    ansE[a[i].id] = maxE[u];
  }
  for (int i = 1; i <= q; i++) printf("%d %d\n", ansE[i], ans[i]);
  return 0;
}
