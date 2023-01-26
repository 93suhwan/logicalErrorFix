#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 20;
struct edge1 {
  int v, w;
};
struct edge2 {
  int u, v, w;
} e[N];
struct qry {
  int u, w, id;
} q[N];
vector<edge1> G[N];
int n, m, c, a[N], dep[N], ans1[N], ans2[N], f[N][M], g[N][M];
void add(int u, int v, int w) {
  G[u].push_back((edge1){v, w}), G[v].push_back((edge1){u, w});
}
void dfs(int u, int fa) {
  f[u][0] = fa, dep[u] = dep[fa] + 1;
  for (auto e : G[u])
    if (e.v != fa) g[e.v][0] = e.w, dfs(e.v, u);
}
int dist(int x, int y) {
  int ans = 0;
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 18; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) ans = max(ans, g[x][i]), x = f[x][i];
  if (x == y) return ans;
  for (int i = 18; i >= 0; --i)
    if (f[x][i] != f[y][i])
      ans = max(ans, max(g[x][i], g[y][i])), x = f[x][i], y = f[y][i];
  return max(ans, max(g[x][0], g[y][0]));
}
namespace dsu {
int fa[N], sz[N], pl[N], mxw[N], val[N];
void reset() {
  for (int i = 1; i <= n; ++i)
    fa[i] = pl[i] = i, val[i] = a[i], mxw[i] = 0, sz[i] = 1;
}
int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
void Merge(int a, int b) {
  int x = find(a), y = find(b);
  if (sz[x] > sz[y]) swap(x, y);
  if (val[x] > val[y])
    val[y] = val[x], mxw[y] = mxw[x], pl[y] = pl[x];
  else if (val[x] == val[y])
    mxw[y] = max(max(mxw[x], mxw[y]), dist(pl[x], pl[y]));
  fa[x] = y, sz[y] += sz[x];
}
}  // namespace dsu
bool cmp1(edge2 a, edge2 b) { return a.w > b.w; }
bool cmp2(qry a, qry b) { return a.w > b.w; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].w, &c);
    add(e[i].u, e[i].v, c);
  }
  dfs(1, 0);
  for (int j = 1; j <= 18; ++j)
    for (int i = 1; i <= n; ++i)
      f[i][j] = f[f[i][j - 1]][j - 1],
      g[i][j] = max(g[i][j - 1], g[f[i][j - 1]][j - 1]);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &q[i].w, &q[i].u), q[i].id = i;
  sort(e + 1, e + n, cmp1);
  sort(q + 1, q + m + 1, cmp2);
  dsu ::reset();
  for (int i = 1, j = 1; i <= m; ++i) {
    for (; j <= n - 1 && e[j].w >= q[i].w; ++j) dsu ::Merge(e[j].u, e[j].v);
    int res = dsu ::mxw[dsu ::find(q[i].u)];
    res = max(res, dist(q[i].u, dsu ::pl[dsu ::find(q[i].u)]));
    ans1[q[i].id] = dsu ::val[dsu ::find(q[i].u)], ans2[q[i].id] = res;
  }
  for (int i = 1; i <= m; ++i) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
