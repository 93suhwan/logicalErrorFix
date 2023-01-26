#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;
ld const PI = 4 * atan((ld)1);
constexpr int MAX = 3e5 + 69;
int n, q;
int ds[MAX];
vector<ii> adj[MAX];
inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(x)] = frep(y); }
bool cyc[MAX];
int XOR[MAX], depth[MAX], par[MAX], head[MAX], heavy[MAX], pos[MAX], sz[MAX],
    st[2 * MAX];
inline void dfs_sz(int node) {
  sz[node] = 1;
  int sz_max = 0;
  for (auto [to, w] : adj[node]) {
    if (to != par[node]) {
      par[to] = node;
      depth[to] = depth[node] + 1;
      XOR[to] = XOR[node] ^ w;
      dfs_sz(to);
      sz[node] += sz[to];
      if (sz[to] > sz_max) sz_max = sz[to], heavy[node] = to;
    }
  }
}
static int cur_pos = 0;
inline void dfs_hld(int node, int h) {
  head[node] = h;
  pos[node] = cur_pos++;
  if (heavy[node] != -1) dfs_hld(heavy[node], h);
  for (auto [to, w] : adj[node])
    if (to != heavy[node] && to != par[node]) dfs_hld(to, to);
}
inline int lca(int u, int v) {
  for (; head[u] != head[v]; u = par[head[u]]) {
    if (depth[head[u]] < depth[head[v]]) swap(u, v);
  }
  return depth[u] < depth[v] ? u : v;
}
inline void modify(int p, int val) {
  for (st[p += n] = val; p > 1; p >>= 1) st[p >> 1] = max(st[p], st[p ^ 1]);
}
inline int rmq(int l, int r) {
  int res = 0;
  for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, st[l++]);
    if (r & 1) res = max(res, st[--r]);
  }
  return res;
}
inline int get(int u, int lc) {
  int res = 0;
  for (; head[u] != head[lc]; u = par[head[u]])
    res = max(res, rmq(pos[head[u]], pos[u]));
  if (pos[lc] < pos[u]) res = max(res, rmq(pos[lc] + 1, pos[u]));
  return res;
}
inline int ask(int u, int v) {
  int lc = lca(u, v);
  if (u != lc && v != lc) {
    u = par[u];
    v = par[v];
    return max(max(get(u, lc), get(v, lc)), rmq(pos[lc], pos[lc]));
  } else if (u != lc)
    return get(par[u], lc);
  else
    return get(par[v], lc);
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  iota(ds, ds + MAX, 0);
  cin >> n >> q;
  vector<bool> res(q);
  vector<array<int, 4>> pending;
  for (int i = 0; i < q; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    if (frep(u) != frep(v)) {
      res[i] = true;
      join(u, v);
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    } else
      pending.push_back({u, v, w, i});
  }
  for (int i = 0; i < MAX; ++i) heavy[i] = -1;
  depth[1] = XOR[1] = 0;
  dfs_sz(1);
  dfs_hld(1, 1);
  for (auto &[u, v, w, i] : pending) {
    if (cyc[u] && cyc[v]) continue;
    if ((XOR[u] ^ XOR[v] ^ w) == 1 && ask(u, v) == 0) {
      res[i] = true;
      for (; u != v; u = par[u]) {
        cyc[u] = true;
        modify(pos[u], 1);
        if (depth[u] < depth[v]) swap(u, v);
      }
    }
  }
  string s[2] = {"NO", "YES"};
  for (bool x : res) cout << s[x] << '\n';
  return 0;
}
