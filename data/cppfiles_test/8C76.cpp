#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct segtree {
  int n;
  vector<long long> t;
  void init(int n, vector<long long>& a) {
    this->n = n;
    t.resize(n * 4);
    build(1, 0, n - 1, a);
  }
  inline void Merge(long long& node, long long& l, long long& r) {
    node = l + r;
  }
  void build(int node, int l, int r, vector<long long>& a) {
    if (l == r) {
      t[node] = a[l];
      return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid, a);
    build(node * 2 + 1, mid + 1, r, a);
    Merge(t[node], t[node * 2], t[node * 2 + 1]);
  }
  void update(int node, int l, int r, int i, int j, long long add) {
    if (l > j || r < i) {
      return;
    }
    if (l >= i && r <= j) {
      t[node] = add;
      return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, j, add);
    update(node * 2 + 1, mid + 1, r, i, j, add);
    Merge(t[node], t[node * 2], t[node * 2 + 1]);
  }
  void update(int l, int r, int add) { update(1, 0, n - 1, l, r, add); }
  long long query(int node, int l, int r, int i, int j) {
    if (l > j || r < i) {
      return 0;
    }
    if (l >= i && r <= j) {
      return t[node];
    }
    int mid = (l + r) / 2;
    long long x = query(node * 2, l, mid, i, j);
    long long y = query(node * 2 + 1, mid + 1, r, i, j);
    return x + y;
  }
  long long query(int l, int r) {
    long long ret = query(1, 0, n - 1, l, r);
    return ret;
  }
};
struct HLD {
  vector<int> parent, depth, heavy, head, pos;
  int cur_pos;
  segtree seg;
  int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
      if (c != parent[v]) {
        parent[c] = v, depth[c] = depth[v] + 1;
        int c_size = dfs(c, adj);
        size += c_size;
        if (c_size > max_c_size) max_c_size = c_size, heavy[v] = c;
      }
    }
    return size;
  }
  void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1) decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
      if (c != parent[v] && c != heavy[v]) decompose(c, c, adj);
    }
  }
  void init(vector<vector<int>> const& adj, vector<long long>& a) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;
    dfs(0, adj);
    decompose(0, 0, adj);
    vector<long long> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[pos[i]] = a[i];
    }
    seg.init(n, tmp);
  }
  long long query(int a, int b) {
    long long res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      long long cur_heavy_path_max = seg.query(pos[head[b]], pos[b]);
      res += cur_heavy_path_max;
    }
    if (depth[a] > depth[b]) swap(a, b);
    long long last_heavy_path_max = seg.query(pos[a], pos[b]);
    res += last_heavy_path_max;
    return res;
  }
  void update(int a, int b, int x) {
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]]) swap(a, b);
      seg.update(pos[head[b]], pos[b], x);
    }
    if (depth[a] > depth[b]) swap(a, b);
    seg.update(pos[a], pos[b], x);
  }
};
int n, q;
vector<vector<int>> adj;
vector<long long> a;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  a.resize(n);
  adj.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  HLD h;
  h.init(adj, a);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      v = abs(v);
      u--;
      h.update(u, u, v);
      a[u] = v;
    } else {
      u--;
      v--;
      if (u == v) {
        cout << "0\n";
        continue;
      }
      long long ans = h.query(u, v);
      ans = ans * 2 - a[u] - a[v];
      cout << ans << "\n";
    }
  }
  return 0;
}
