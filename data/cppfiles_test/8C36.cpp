#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
using ll = long long;
int dep[maxn + 10], sz[maxn + 10];
int hson[maxn + 10], fa[maxn + 10];
int top[maxn + 10];
vector<int> edges[maxn + 10];
int n, q;
int dfsn[maxn + 10];
int rdfsn[maxn + 10];
int cnt = 0;
ll a[maxn + 10];
ll a2[maxn + 10];
ll t[maxn + 10];
void dfs1(int p, int fath) {
  int size = 1, mx = 0;
  dep[p] = dep[fath] + 1;
  fa[p] = fath;
  for (auto q : edges[p]) {
    if (q == fath) continue;
    a[q] = max(abs(t[p] + t[q]), abs(t[q] - t[p]));
    dfs1(q, p);
    size += sz[q];
    if (sz[q] > mx) {
      mx = sz[q];
      hson[p] = q;
    }
  }
  sz[p] = size;
}
void dfs2(int p) {
  dfsn[p] = ++cnt;
  rdfsn[cnt] = p;
  a2[cnt] = a[p];
  if (hson[p] != 0) {
    top[hson[p]] = top[p];
    dfs2(hson[p]);
  }
  for (auto q : edges[p]) {
    if (!top[q]) {
      top[q] = q;
      dfs2(q);
    }
  }
}
struct Segtree {
  ll val;
} tree[(maxn << 2) + 10];
void pushup(int rt) {
  tree[rt].val = tree[rt << 1].val + tree[rt << 1 | 1].val;
}
void build(int l = 1, int r = n, int rt = 1) {
  if (l == r) {
    tree[rt].val = a2[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
ll query(int L, int R, int l = 1, int r = n, int rt = 1) {
  if (L > r || R < l) return 0;
  if (L <= l && r <= R) {
    return tree[rt].val;
  }
  int mid = (l + r) >> 1;
  return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}
ll query_path(int x, int y) {
  ll ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = ans + query(dfsn[top[x]], dfsn[x]);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ans = ans + query(dfsn[x] + 1, dfsn[y]);
  return ans;
}
void update(int L, int l = 1, int r = n, int rt = 1) {
  if (L == l && L == r) {
    int cur = rdfsn[L];
    int fath = fa[cur];
    tree[rt].val = max(abs(t[cur] + t[fath]), abs(t[cur] - t[fath]));
    return;
  }
  if (L < l || L > r) {
    return;
  }
  int mid = (l + r) / 2;
  if (L <= mid)
    update(L, l, mid, rt << 1);
  else if (L > mid)
    update(L, mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    edges[i].clear();
    cnt = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }
  dfs1(1, 0);
  top[1] = 1;
  dfs2(1);
  build();
  for (int i = 1; i <= q; i++) {
    int op = 0;
    cin >> op;
    if (op == 1) {
      int u, c;
      cin >> u >> c;
      t[u] = c;
      update(dfsn[u]);
      for (auto q : edges[u]) {
        if (q != fa[u]) update(dfsn[q]);
      }
    } else {
      int u, v;
      cin >> u >> v;
      cout << query_path(u, v) << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
