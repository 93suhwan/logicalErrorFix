#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxlog = 20;
int a[maxn];
struct Node {
  int u, v, c, w;
  bool operator<(const Node a) const { return c > a.c || c == a.c && v > a.v; }
} b[maxn << 1];
int fa[maxn][maxlog], mxval[maxn], mxid[maxn], mxw[maxn], st[maxn][maxlog],
    ffa[maxn], dep[maxn];
pair<int, int> ans[maxn];
vector<pair<int, int>> g[maxn];
void dfs(int u, int f) {
  fa[u][0] = f;
  dep[u] = dep[f] + 1;
  for (int i = 1; i < maxlog; ++i)
    fa[u][i] = fa[fa[u][i - 1]][i - 1],
    st[u][i] = max(st[u][i - 1], st[fa[u][i - 1]][i - 1]);
  for (auto vv : g[u]) {
    int v = vv.first, w = vv.second;
    if (v == f) continue;
    st[v][0] = w;
    dfs(v, u);
  }
}
int getw(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ans = 0;
  for (int i = maxlog - 1; i >= 0; --i) {
    if (dep[fa[u][i]] >= dep[v]) {
      ans = max(st[u][i], ans);
      u = fa[u][i];
    }
  }
  if (u == v) return ans;
  for (int i = maxlog - 1; i >= 0; --i) {
    if (fa[u][i] != fa[v][i]) {
      ans = max(ans, max(st[u][i], st[v][i]));
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  ans = max(ans, max(st[u][0], st[v][0]));
  return ans;
}
int fd(int u) { return u == ffa[u] ? u : (ffa[u] = fd(ffa[u])); }
void merge(int u, int v) {
  u = fd(u), v = fd(v);
  int nxtval = max(mxval[u], mxval[v]), nxtw, nxtid;
  if (mxval[u] != mxval[v]) {
    if (mxval[u] > mxval[v])
      nxtw = mxw[u], nxtid = mxid[u];
    else
      nxtw = mxw[v], nxtid = mxid[v];
  } else {
    nxtw = max(mxw[u], max(mxw[v], getw(mxid[u], mxid[v])));
    nxtid = mxid[u];
  }
  ffa[u] = v;
  mxval[v] = nxtval, mxid[v] = nxtid, mxw[v] = nxtw;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), ffa[i] = i, mxval[i] = a[i], mxid[i] = i;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, c, w;
    scanf("%d%d%d%d", &u, &v, &c, &w);
    b[i] = {u, v, c, w};
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  for (int i = 1; i <= q; ++i) {
    int v, x;
    scanf("%d%d", &v, &x);
    b[i + n - 1] = {x, 0, v, i};
  }
  int m = n - 1 + q;
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= m; ++i) {
    if (b[i].v == 0) {
      int u = fd(b[i].u);
      ans[b[i].w] = {mxval[u], max(mxw[u], getw(b[i].u, mxid[u]))};
    } else {
      merge(b[i].u, b[i].v);
    }
  }
  for (int i = 1; i <= q; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}
