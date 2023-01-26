#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 3e5 + 1010;
int p[N];
int sz[N];
int find_set(int v) {
  if (v == p[v]) return v;
  return p[v] = find_set(p[v]);
}
void union_set(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
}
struct edge {
  int u, v, w;
};
vector<vector<pair<int, int>>> g;
const int LOG = 20;
int n, q;
vector<int> lvl;
vector<vector<int>> jump;
vector<int> par;
vector<int> xr;
void dfs1(int v, int p = -1) {
  par[v] = p;
  for (auto to : g[v])
    if (to.first != p) dfs1(to.first, v);
}
void dfs(int v, int level = 0, int p = 0, int xorik = 0) {
  lvl[v] = level;
  jump[v][0] = p;
  xr[v] = xorik;
  for (auto to : g[v])
    if (to.first != p) dfs(to.first, level + 1, v, xorik ^ to.second);
}
void InitJump() {
  for (int j = 1; j < LOG; j++)
    for (int v = 0; v < n; v++) jump[v][j] = jump[jump[v][j - 1]][j - 1];
}
int lca(int u, int v) {
  if (lvl[u] > lvl[v]) swap(u, v);
  for (int k = LOG - 1; k >= 0; k--)
    if (lvl[jump[v][k]] >= lvl[u]) v = jump[v][k];
  if (v == u) return u;
  for (int k = LOG - 1; k >= 0; k--)
    if (jump[v][k] != jump[u][k]) {
      v = jump[v][k];
      u = jump[u][k];
    }
  return jump[u][0];
}
int dist(int u, int v) { return xr[u] ^ xr[v]; }
vector<bool> marked;
void mark_verts(int u, int v) {
  int lc = lca(u, v);
  for (int t = u; t != lc; t = par[t]) marked[t] = true;
  for (int t = v; t != lc; t = par[t]) marked[t] = true;
  marked[lc] = true;
}
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    p[i] = i, sz[i] = 1;
  }
  vector<edge> qr(q);
  vector<edge> norm;
  vector<bool> done(q);
  vector<string> ans(q, "NO");
  for (int i = 0; i < q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    qr[i] = {u, v, w};
    if (find_set(u) != find_set(v)) {
      norm.push_back({u, v, w});
      union_set(u, v);
      done[i] = true;
      ans[i] = "YES";
    }
  }
  g.resize(n);
  xr.resize(n);
  marked.resize(n);
  lvl.resize(n);
  par.resize(n);
  jump = vector<vector<int>>(n, vector<int>(LOG));
  for (auto to : norm) {
    int u = to.u;
    int v = to.v;
    int w = to.w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(0);
  dfs1(0);
  InitJump();
  for (int i = 0; i < q; i++) {
    if (done[i])
      continue;
    else {
      int u = qr[i].u;
      int v = qr[i].v;
      int w = qr[i].w;
      if (marked[v] || marked[u]) {
        continue;
      } else {
        if (dist(u, v) ^ w == 1) {
          mark_verts(u, v);
          ans[i] = "YES";
        } else
          continue;
      }
    }
  }
  for (auto to : ans) cout << to << '\n';
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) solve();
}
