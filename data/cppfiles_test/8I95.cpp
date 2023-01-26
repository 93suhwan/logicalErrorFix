#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, L = 23;
vector<long long> g[N];
long long a[N], n, q;
long long par[N], id[N], _id[N], cid = 0, hvc[N], head[N], sz[N], depth[N];
struct SegmentTree {
  struct node {
    long long val = 0, lz = 0;
    void apply(long long l, long long r, long long d) {
      val = d;
      lz = d;
    }
  };
  node merge(const node &a, const node &b) {
    node res;
    res.val = a.val + b.val;
    return res;
  }
  inline void push(long long v, long long l, long long r) {
    long long m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    if (tr[v].lz != 0) {
      tr[v + 1].apply(l, m, tr[v].lz);
      tr[u].apply(m + 1, r, tr[v].lz);
      tr[v].lz = 0;
    }
  }
  long long n;
  vector<node> tr;
  void build(long long v, long long l, long long r) {
    if (l == r) {
      return;
    }
    long long m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    build(v + 1, l, m), build(u, m + 1, r);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  void build(long long v, long long l, long long r, vector<long long> &d) {
    if (l == r) {
      tr[v].apply(l, r, d[l]);
      return;
    }
    long long m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    build(v + 1, l, m, d), build(u, m + 1, r, d);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  void udt(long long v, long long l, long long r, long long L, long long R,
           long long d) {
    if (L <= l and r <= R) {
      tr[v].apply(l, r, d);
      return;
    }
    long long m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    push(v, l, r);
    if (L <= m) udt(v + 1, l, m, L, R, d);
    if (R > m) udt(u, m + 1, r, L, R, d);
    tr[v] = merge(tr[v + 1], tr[u]);
  }
  node get(long long v, long long l, long long r, long long L, long long R) {
    if (L <= l and r <= R) return tr[v];
    long long m = (l + r) / 2, u = (m - l + 1) * 2 + v;
    push(v, l, r);
    if (R <= m)
      return get(v + 1, l, m, L, R);
    else if (L > m)
      return get(u, m + 1, r, L, R);
    return merge(get(v + 1, l, m, L, R), get(u, m + 1, r, L, R));
  }
  SegmentTree(long long _n) : n(_n) {
    assert(n > 0);
    tr.resize(2 * n);
    build(0, 0, n - 1);
  }
  SegmentTree(vector<long long> &d) {
    n = d.size();
    assert(n > 0);
    tr.resize(2 * n);
    build(0, 0, n - 1, d);
  }
  long long get(long long l, long long r) {
    if (l > r) swap(l, r);
    assert(0 <= l and l <= r and r <= n - 1);
    return get(0, 0, n - 1, l, r).val;
  }
  void udt(long long l, long long r, long long d) {
    assert(0 <= l and l <= r and r <= n - 1);
    return udt(0, 0, n - 1, l, r, d);
  }
};
SegmentTree st(N);
void dfs(long long v, long long p) {
  par[v] = p, sz[v] = 1;
  long long mx = 0;
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
}
void decompose(long long v) {
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
void update(long long v, long long x) { st.udt(id[v], id[v], x); }
long long query(long long u, long long v) {
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
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0);
  decompose(0);
  for (long long i = 0; i < n; i++) {
    st.udt(id[i], id[i], a[i]);
  }
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long v, x;
      cin >> v >> x;
      x = abs(x);
      --v;
      a[v] = x;
      update(v, x);
    } else {
      long long u, v;
      cin >> u >> v;
      --u, --v;
      cout << query(u, v) * 2 - a[u] - a[v] << '\n';
    }
  }
}
