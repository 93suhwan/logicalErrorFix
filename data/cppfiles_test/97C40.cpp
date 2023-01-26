#include <bits/stdc++.h>
using namespace std;
int n, q, V, c[200015], par[200015], ans[200015], dfn[200015], siz[200015],
    son[200015], dep[200015], clk, top[200015];
vector<int> e[200015];
vector<pair<int, int>> que[200015];
struct node {
  int c, m;
  bool operator<(const node &rhs) const {
    return (long long)(c - 1) * (rhs.m + 1) > (long long)(rhs.c - 1) * (m + 1);
  }
  node operator+(const node &rhs) const { return (node){c + rhs.c, m + rhs.m}; }
};
node sum[200015];
namespace seg {
node tr[200015 << 2], lazy[200015 << 2];
void down(int p, node v) {
  tr[p] = tr[p] + v;
  lazy[p] = lazy[p] + v;
}
void pushdown(int p) {
  down((p << 1), lazy[p]);
  down((p << 1 | 1), lazy[p]);
  lazy[p] = (node){0, 0};
}
void add(int p, int l, int r, int x, int y, node v) {
  if (x <= l && r <= y) return down(p, v);
  pushdown(p);
  int mid = (l + r) >> 1;
  if (x <= mid) add((p << 1), l, mid, x, y, v);
  if (y > mid) add((p << 1 | 1), mid + 1, r, x, y, v);
}
node query(int p, int l, int r, int pos) {
  if (l == r) return tr[p];
  pushdown(p);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    return query((p << 1), l, mid, pos);
  else
    return query((p << 1 | 1), mid + 1, r, pos);
}
};  // namespace seg
using namespace seg;
set<pair<node, int>> S;
int fa[200015];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void dfs(int u, int pa) {
  par[u] = pa;
  dep[u] = dep[pa] + 1;
  siz[u] = 1;
  for (auto v : e[u])
    if (v != pa) {
      c[u]++;
      dfs(v, u);
      siz[u] += siz[v];
      if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int pa, int tp) {
  dfn[u] = ++clk;
  top[u] = tp;
  if (son[u]) dfs2(son[u], u, tp);
  for (auto v : e[u]) {
    if (v == pa || v == son[u]) continue;
    dfs2(v, u, v);
  }
}
void add(int u, int v, node val) {
  while (top[u] != top[v]) {
    add(1, 1, n, dfn[top[u]], dfn[u], val);
    u = par[top[u]];
  }
  add(1, 1, n, dfn[v], dfn[u], val);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) fa[i] = i;
  for (int i = (2); i <= (n); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0, 1);
  for (int i = (1); i <= (n); i++)
    sum[i] = (node){c[i], 0}, add(1, 1, n, dfn[i], dfn[i], sum[i]);
  scanf("%d", &q);
  for (int i = (1); i <= (q); i++) {
    int v, k;
    scanf("%d%d", &v, &k);
    que[k].push_back(make_pair(v, i));
    V = max(V, k);
  }
  for (int i = (1); i <= (n); i++) S.insert(make_pair(sum[i], i));
  for (int k = (V); k >= (0); k--) {
    while (((int)S.size()) > 0) {
      if (S.begin()->first.c - 1 < (long long)(S.begin()->first.m + 1) * k)
        break;
      int u = S.begin()->second;
      S.erase(S.begin());
      if (!par[u]) continue;
      int v = find(par[u]);
      S.erase(make_pair(sum[v], v));
      node val = sum[u] + (node){-1, 1};
      sum[v] = sum[v] + val;
      fa[u] = v;
      add(par[u], v, val);
      if (par[v]) S.insert(make_pair(sum[v], v));
    }
    for (auto x : que[k]) {
      node u = query(1, 1, n, dfn[x.first]);
      ans[x.second] = u.c - u.m * k;
    }
  }
  for (int i = (1); i <= (q); i++) printf("%d\n", ans[i]);
  return 0;
}
