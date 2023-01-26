#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, L = 23;
vector<int> g[N];
int a[N], n, q;
int timer;
vector<int> tin(N), tout(N);
vector<vector<int>> up(N, vector<int>(L));
int par[N], id[N], _id[N], cid = 0, hvc[N], head[N], sz[N], depth[N];
struct SegmentTree {
  struct node {
    long long val = 0, lz = 0;
    void apply(int l, int r, int d) {
      val = d;
      lz = d;
    }
  };
  node merge(const node &a, const node &b) {
    node res;
    res.val = a.val + b.val;
    return res;
  }
  inline void push(int v, int l, int r) {
    int m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    if (tr[v].lz != 0) {
      tr[v + 1].apply(l, m, tr[v].lz);
      tr[u].apply(m + 1, r, tr[v].lz);
      tr[v].lz = 0;
    }
  }
  int n;
  vector<node> tr;
  void build(int v, int l, int r) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    build(v + 1, l, m), build(u, m + 1, r);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  void build(int v, int l, int r, vector<int> &d) {
    if (l == r) {
      tr[v].apply(l, r, d[l]);
      return;
    }
    int m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    build(v + 1, l, m, d), build(u, m + 1, r, d);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  void udt(int v, int l, int r, int L, int R, int d) {
    if (L <= l and r <= R) {
      tr[v].apply(l, r, d);
      return;
    }
    int m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    push(v, l, r);
    if (L <= m) udt(v + 1, l, m, L, R, d);
    if (R > m) udt(u, m + 1, r, L, R, d);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  node get(int v, int l, int r, int L, int R) {
    if (L <= l and r <= R) return tr[v];
    int m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    push(v, l, r);
    if (R <= m)
      return get(v + 1, l, m, L, R);
    else if (L > m)
      return get(u, m + 1, r, L, R);
    return merge(get(v + 1, l, m, L, R), get(u, m + 1, r, L, R));
  }
  SegmentTree(int _n) : n(_n) {
    assert(n > 0);
    tr.resize(2 * n);
    build(0, 0, n - 1);
  }
  SegmentTree(vector<int> &d) {
    n = d.size();
    assert(n > 0);
    tr.resize(2 * n);
    build(0, 0, n - 1, d);
  }
  long long get(int l, int r) {
    assert(0 <= l and l <= r and r <= n - 1);
    return get(0, 0, n - 1, l, r).val;
  }
  void udt(int l, int r, int d) {
    assert(0 <= l and l <= r and r <= n - 1);
    return udt(0, 0, n - 1, l, r, d);
  }
};
SegmentTree st(N);
void dfs(int v, int p) {
  par[v] = p, sz[v] = 1;
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i < L; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  int mx = 0;
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
    depth[u] = depth[v] + 1;
    sz[v] += sz[u];
    if (sz[u] > mx) {
      mx = sz[u];
      hvc[v] = u;
    }
  }
  tout[v] = ++timer;
}
void decompose(int v) {
  id[v] = cid;
  _id[cid++] = v;
  if (hvc[v] != -1) {
    head[hvc[v]] = head[v];
    decompose(hvc[v]);
  }
  for (auto u : g[v]) {
    if (u == par[v] or u == hvc[v]) continue;
    head[u] = u;
    decompose(u);
  }
}
bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = L - 1; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void update(int v, int x) { st.udt(id[v], id[v], x); }
long long query(int u, int v) {
  long long res = 0;
  while (head[u] != head[v]) {
    if (depth[head[u]] > depth[head[v]]) swap(u, v);
    res += st.get(id[head[v]], id[v]);
    v = par[head[v]];
  }
  if (depth[u] > depth[v]) swap(u, v);
  res += st.get(id[u], id[v]);
  return res;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  memset(hvc, -1, sizeof hvc);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  decompose(0);
  for (int i = 0; i < n; i++) {
    st.udt(id[i], id[i], a[i]);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, x;
      cin >> v >> x;
      --v;
      x = abs(x);
      a[v] = x;
      update(v, x);
    } else {
      int u, v;
      cin >> u >> v;
      --u, --v;
      int l = lca(u, v);
      cout << 2 * (query(0, u) + query(0, v) - 2 * query(0, l) + a[l]) - a[u] -
                  a[v]
           << '\n';
    }
  }
}
