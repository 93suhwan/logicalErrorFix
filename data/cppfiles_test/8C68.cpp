#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const bool hld_type = 0;
const int N = 1e5 + 10;
const int L = 20;
const long long good_value = 0;
long long merge(long long a, long long b) { return a + b; }
struct segment_tree {
  long long t[2 * N + 5];
  void build() {
    for (int i = N - 1; i > 0; i--) {
      t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }
  }
  void update(int pos, long long val) {
    for (t[pos += N] = val; pos > 1; pos >>= 1) {
      t[pos >> 1] = merge(t[pos], t[pos ^ 1]);
    }
  }
  long long get(int l, int r) {
    long long res = good_value;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) res = merge(res, t[l++]);
      if (!(r & 1)) res = merge(res, t[r--]);
    }
    return res;
  }
} tree;
int timer, tree_ptr;
vector<int> g[N];
int in[N], out[N];
int up[N][L], down[N];
int sz[N], depth[N];
int start[N], st_ptr;
int path_st[N], pos[N];
bool is_heavy(int v, int to) { return sz[to] >= (sz[v] + 1) / 2; }
void dfs_hld(int v = 1, int p = 1) {
  in[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i < L; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != p) {
      depth[to] = depth[v] + 1;
      dfs_hld(to, v);
      sz[v] += sz[to];
    }
  }
  bool light = 1;
  for (int to : g[v]) {
    if (to != p && is_heavy(v, to)) {
      light = 0;
      break;
    }
  }
  if (light) {
    start[st_ptr++] = v;
  }
  out[v] = ++timer;
}
bool is_anc(int u, int v) { return in[u] <= in[v] && in[v] <= out[u]; }
int lca(int u, int v) {
  if (is_anc(u, v))
    return u;
  else if (is_anc(v, u))
    return v;
  for (int i = L - 1; i >= 0; i--) {
    if (!is_anc(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
void heavy_light_decomposition(int root = 1) {
  int mem = st_ptr;
  dfs_hld(root, root);
  for (int i = mem; i < st_ptr; i++) {
    int v = start[i];
    while (v != root && is_heavy(up[v][0], v)) {
      down[up[v][0]] = v;
      v = up[v][0];
    }
    int cur_st = v;
    while (v) {
      path_st[v] = cur_st;
      pos[v] = tree_ptr++;
      v = down[v];
    }
  }
}
void update(int v, long long val) { tree.update(pos[v], val); }
long long get(int u, int v, bool flag = 0) {
  if (is_anc(u, v)) {
    long long res = good_value;
    while (path_st[v] != path_st[u]) {
      res = merge(res, tree.get(pos[path_st[v]], pos[v]));
      v = up[path_st[v]][0];
    }
    res = merge(res, tree.get(pos[u] + (hld_type || flag), pos[v]));
    return res;
  } else if (is_anc(v, u)) {
    return get(v, u);
  } else {
    int l = lca(u, v);
    return merge(get(l, u), get(l, v, 1));
  }
}
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  heavy_light_decomposition();
  for (int i = 1; i <= n; i++) {
    tree.t[pos[i] + N] = a[i];
  }
  tree.build();
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v;
      long long val;
      cin >> v >> val;
      update(v, abs(val));
      a[v] = abs(val);
    } else {
      int u, v;
      cin >> u >> v;
      if (u == v) {
        cout << "0\n";
      } else {
        cout << 2 * get(u, v) - a[u] - a[v] << "\n";
      }
    }
  }
  return 0;
}
