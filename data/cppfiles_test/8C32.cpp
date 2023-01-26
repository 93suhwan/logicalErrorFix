#include <bits/stdc++.h>
using namespace std;
struct SegTree {
 private:
  long long n;
  vector<long long> t;
  long long query(long long id, long long l, long long r, long long l1,
                  long long r1) {
    if (l1 == r1) return 0;
    if (r == r1 and l == l1) return t[id];
    long long m = (l + r) >> 1;
    return query(id << 1, l, m, min(l1, m), min(r1, m)) +
           query((id << 1) + 1, m, r, max(l1, m), max(r1, m));
  }
  long long update(long long id, long long l, long long r, long long i,
                   long long del) {
    if (i < l or i >= r) return t[id];
    if (r - l == 1) return t[id] += del;
    long long m = (l + r) >> 1;
    return t[id] = update(id << 1, l, m, i, del) +
                   update((id << 1) + 1, m, r, i, del);
  }

 public:
  long long query(long long l, long long r) { return query(1, 0, n, l, r); }
  void update(long long i, long long del) { update(1, 0, n, i, del); }
  SegTree(long long n) {
    this->n = n;
    t.assign(4 * n, 0);
  }
};
long long n, l;
vector<vector<long long>> adj;
vector<long long> a;
long long timer;
vector<long long> tin, tout;
vector<vector<long long>> up;
void dfs(long long v, long long p) {
  tin[v] = timer++;
  up[v][0] = p;
  for (long long i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (long long u : adj[v]) {
    if (u != p) dfs(u, v);
  }
  tout[v] = timer++;
}
bool is_ancestor(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (long long i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void preprocess(long long root) {
  tin.resize(n);
  tout.resize(n);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vector<long long>(l + 1));
  dfs(root, root);
}
void update(long long u, long long k, SegTree& p) {
  k = k < 0 ? -k : k;
  p.update(tin[u], k - a[u]);
  p.update(tout[u], a[u] - k);
  a[u] = k;
}
long long query(long long u, long long v, SegTree& p) {
  long long anc = lca(u, v);
  long long x = p.query(0, tout[u]);
  long long y = p.query(0, tout[v]);
  long long z = p.query(0, tout[anc]);
  return 2 * (x + y - 2 * z + a[anc]) - a[u] - a[v];
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q;
  cin >> n >> q;
  vector<long long> a1(n);
  for (long long& a11 : a1) cin >> a11;
  adj.assign(n, vector<long long>());
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  preprocess(0);
  SegTree p(timer);
  a.assign(n, 0);
  for (long long u = 0; u < n; u++) update(u, a1[u], p);
  while (q--) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (x == 1)
      update(y - 1, z, p);
    else
      cout << query(y - 1, z - 1, p) << '\n';
    ;
  }
  assert(cin);
}
