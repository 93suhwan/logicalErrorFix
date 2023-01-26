#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, MAXN = 3e5 + 5, oo = 3e18;
long long tc, n, m;
long long dsu_par[MAXN], dsu_sz[MAXN];
long long find(long long u) {
  if (dsu_par[u] == u) return u;
  return dsu_par[u] = find(dsu_par[u]);
}
bool join(long long u, long long v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (dsu_sz[u] < dsu_sz[v]) swap(u, v);
  dsu_par[v] = u;
  dsu_sz[u] += dsu_sz[v];
  return true;
}
void dsu() {
  for (int i = 1; i <= n; i++) {
    dsu_sz[i] = 1;
    dsu_par[i] = i;
  }
}
class fenwick {
 private:
  vector<long long> ft;

 public:
  fenwick(long long n) { ft.assign(n + 5, 0); }
  long long ls(long long x) { return x & (-x); }
  long long rsq(long long pos) {
    if (pos == 0) return 0;
    long long res = 0;
    for (; pos; pos -= ls(pos)) {
      res += ft[pos];
    }
    return res;
  }
  void inc(long long pos, long long val) {
    for (; pos < ft.size(); pos += ls(pos)) {
      ft[pos] += val;
    }
  }
};
fenwick ft(MAXN);
vector<pair<long long, long long> > g[MAXN];
long long prefix_xor[MAXN];
long long up[MAXN][20], dep[MAXN], tin[MAXN], tout[MAXN];
bool ans[MAXN];
long long now = 1;
long long get_lca(long long u, long long v) {
  if (dep[u] < dep[v]) swap(u, v);
  long long tmp = dep[u] - dep[v];
  for (int i = 19; i >= 0; i--) {
    if (tmp & (1 << i)) {
      u = up[u][i];
    }
  }
  if (u == v) return v;
  for (int i = 19; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}
void dfs(long long u) {
  tin[u] = now++;
  for (int i = 1; i <= 19; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (pair<long long, long long> cur : g[u]) {
    long long v = cur.first, w = cur.second;
    if (v == up[u][0]) continue;
    dep[v] = dep[u] + 1;
    prefix_xor[v] = prefix_xor[u] ^ w;
    up[v][0] = u;
    dfs(v);
  }
  tout[u] = now;
}
void mark(long long u) {
  ft.inc(tin[u], 1);
  ft.inc(tout[u], -1);
}
void mark_path(long long u, long long v) {
  while (u != v) {
    mark(u);
    u = up[u][0];
  }
}
struct uwu {
  long long u, v, w, id;
};
vector<uwu> edges;
void aurelion_sol() {
  cin >> n >> m;
  dsu();
  for (int i = 1; i <= m; i++) {
    uwu cur;
    cur.id = i;
    cin >> cur.u >> cur.v >> cur.w;
    edges.push_back(cur);
  }
  for (auto cur : edges) {
    if (join(cur.u, cur.v)) {
      ans[cur.id] = true;
      g[cur.u].push_back(make_pair(cur.v, cur.w));
      g[cur.v].push_back(make_pair(cur.u, cur.w));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!tin[i]) {
      dfs(i);
    }
  }
  for (auto cur : edges) {
    if (ans[cur.id]) continue;
    long long u = cur.u, v = cur.v, w = cur.w, id = cur.id;
    long long tmp = prefix_xor[u] ^ prefix_xor[v] ^ w;
    if (tmp != 1) continue;
    long long lca = get_lca(u, v);
    tmp = ft.rsq(tin[u]) + ft.rsq(tin[v]) - 2 * ft.rsq(tin[lca]);
    if (tmp) continue;
    ans[id] = true;
    mark_path(u, lca);
    mark_path(v, lca);
  }
  for (int i = 1; i <= m; i++) {
    if (ans[i]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tc = 1;
  while (tc--) aurelion_sol();
}
