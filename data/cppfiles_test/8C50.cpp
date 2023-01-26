#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Segtree {
 private:
  long long n;
  vector<T> tree;
  T identity;
  T merge(T a, T b) { return a + b; }
  T __query(long long node, long long seg_l, long long seg_r, long long q_l,
            long long q_r) {
    if (seg_l >= q_l && seg_r <= q_r) return tree[node];
    if (seg_l > q_r || seg_r < q_l) return identity;
    long long mid = seg_l + (seg_r - seg_l) / 2;
    return merge(__query(2 * node, seg_l, mid, q_l, q_r),
                 __query(2 * node + 1, mid + 1, seg_r, q_l, q_r));
  }
  void build(vector<T> &arr) {
    long long sz = (long long)arr.size();
    n = 1 << (32 - __builtin_clz(sz - 1));
    tree.resize(2 * n);
    for (long long i = 0; i < sz; i++) tree[n + i] = arr[i];
    for (long long i = sz; i < n; i++) tree[n + i] = identity;
    for (long long i = n - 1; i >= 1; i--)
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }

 public:
  Segtree(vector<T> &arr, T id) {
    identity = id;
    build(arr);
  }
  T query(long long l, long long r) { return __query(1, 0, n - 1, l, r); }
  void update(long long node, T value) {
    tree[n + node] = value;
    for (long long i = (n + node) / 2; i >= 1; i /= 2)
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  }
};
class LCA {
 private:
  long long n;
  vector<vector<long long> > lift;
  vector<long long> dep;
  void mark_parents(long long node, vector<vector<long long> > &adj,
                    long long p) {
    for (auto x : adj[node]) {
      if (x == p) continue;
      dep[x] = dep[node] + 1;
      mark_parents(x, adj, node);
      lift[x][0] = node;
    }
  }
  void precomp_LCA(vector<vector<long long> > &tree, long long root) {
    long long n = (long long)tree.size();
    lift.assign(n, vector<long long>(32, root));
    dep.assign(n, 0);
    dep[root] = 0;
    mark_parents(root, tree, -1);
    for (long long i = 1; i < 32; i++)
      for (long long j = 0; j < n; j++)
        lift[j][i] = lift[lift[j][i - 1]][i - 1];
  }

 public:
  LCA() = default;
  LCA(vector<vector<long long> > &tree, long long root) {
    precomp_LCA(tree, root);
  }
  void make(vector<vector<long long> > &tree, long long root) {
    precomp_LCA(tree, root);
  }
  long long getLCA(long long a, long long b) {
    if (dep[a] < dep[b]) swap(a, b);
    long long diff = dep[a] - dep[b];
    for (long long i = 31; i >= 0; i--)
      if (diff & (1 << i)) a = lift[a][i];
    if (a == b) return a;
    for (long long i = 31; i >= 0; i--)
      if (lift[a][i] != lift[b][i]) a = lift[a][i], b = lift[b][i];
    return lift[a][0];
  }
  long long getAncestor(long long a, long long k) {
    for (long long i = 0; i < 32; i++)
      if (k & (1 << i)) a = lift[a][i];
    return a;
  }
  long long depth(long long a) { return dep[a]; }
};
long long timer = 0;
void dfs(long long node, vector<vector<long long> > &adj, long long p,
         vector<long long> &st, vector<long long> &en) {
  st[node] = ++timer;
  for (auto &to : adj[node]) {
    if (to == p) continue;
    dfs(to, adj, node, st, en);
  }
  en[node] = ++timer;
}
void solve() {
  long long n, q;
  cin >> n >> q;
  vector<long long> arr(n);
  for (auto &x : arr) cin >> x;
  for (long long i = 0; i < n; i++) arr[i] = abs(arr[i]);
  vector<vector<long long> > adj(n);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  LCA oracle(adj, 0);
  vector<long long> st(n);
  vector<long long> en(n);
  dfs(0, adj, -1, st, en);
  vector<long long> sumarr(timer + 10, 0);
  Segtree<long long> seg(sumarr, 0);
  for (long long v = 0; v < n; v++) {
    seg.update(st[v], arr[v]);
    seg.update(en[v], -arr[v]);
  }
  for (long long i = 0; i < q; i++) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long u, c;
      cin >> u >> c;
      u--;
      c = abs(c);
      arr[u] = abs(c);
      seg.update(st[u], c);
      seg.update(en[u], -c);
    } else {
      long long u, v;
      cin >> u >> v;
      u--, v--;
      long long lca = oracle.getLCA(u, v);
      long long udis = seg.query(0, st[u]);
      long long vdis = seg.query(0, st[v]);
      long long lcadis = seg.query(0, st[lca]);
      long long pathdis = udis + vdis - 2 * lcadis;
      pathdis += arr[lca];
      pathdis = pathdis - arr[u] - arr[v];
      pathdis *= 2;
      pathdis = pathdis + arr[u] + arr[v];
      cout << pathdis << endl;
    }
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
