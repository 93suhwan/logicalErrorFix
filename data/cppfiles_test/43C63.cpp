#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
const int N = 2e5 + 5, L = 18;
struct edge {
  int t, c, u, v;
  edge(int _t = 0, int _c = 0, int _u = 0, int _v = 0)
      : t(_t), c(_c), u(_u), v(_v) {}
  bool operator<(const edge &o) const { return c != o.c ? c > o.c : t > o.t; }
};
int n, q, enj[N], res_enj[N], res_tol[N];
vector<pair<int, int>> adj[N];
int h[N];
pair<int, int> jmp[N][L];
void pre_dfs(int u, int p = 0) {
  h[u] = h[p] + 1;
  for (int i = 1; i < 18; i++) {
    auto [v1, w1] = jmp[u][i - 1];
    auto [v2, w2] = jmp[v1][i - 1];
    jmp[u][i] = {v2, max(w1, w2)};
  }
  for (auto [v, w] : adj[u])
    if (v != p) {
      jmp[v][0] = {u, w};
      pre_dfs(v, u);
    }
}
inline int get_toll(int u, int v) {
  int res = 0;
  if (h[u] < h[v]) swap(u, v);
  for (int i = 17; ~i; i--)
    if (h[u] - h[v] >> i & 1) {
      auto [nu, wu] = jmp[u][i];
      u = nu, res = max(res, wu);
    }
  if (u == v) return res;
  for (int i = 17; ~i; i--)
    if (jmp[u][i].first ^ jmp[v][i].first) {
      auto [nu, wu] = jmp[u][i];
      u = nu, res = max(res, wu);
      auto [nv, wv] = jmp[v][i];
      v = nv, res = max(res, wv);
    }
  return max({res, jmp[u][0].second, jmp[v][0].second});
}
int par[N], max_enj[N], max_pos[N], toll_in[N];
struct disjoint_set {
  disjoint_set(int n = N) {
    iota(par, par + n, 0);
    copy(enj, enj + n, max_enj);
    iota(max_pos, max_pos + n, 0);
  }
  inline int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
  inline void merge(int u, int v) {
    assert((u = find(u)) != (v = find(v)));
    par[v] = u;
    if (max_enj[u] < max_enj[v]) {
      max_enj[u] = max_enj[v];
      max_pos[u] = max_pos[v];
      toll_in[u] = toll_in[v];
    } else if (max_enj[u] == max_enj[v]) {
      toll_in[u] =
          max({toll_in[u], toll_in[v], get_toll(max_pos[u], max_pos[v])});
    }
  }
};
void Hollwo_Pelw() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> enj[i];
  vector<edge> queries(n + q - 1);
  for (int i = 0, u, v, c, t; i < n - 1; i++) {
    cin >> u >> v >> c >> t;
    adj[u].emplace_back(v, t);
    adj[v].emplace_back(u, t);
    queries[i] = edge(t, c, u, v);
  }
  for (int i = 0, u, c; i < q; i++) {
    cin >> c >> u;
    queries[i + n - 1] = {0, c, u, i};
  }
  pre_dfs(1);
  sort(queries.begin(), queries.end());
  disjoint_set dsu(n + 1);
  for (auto [t, c, u, v] : queries) {
    if (t) {
      dsu.merge(u, v);
    } else {
      int pu = dsu.find(u);
      res_enj[v] = max_enj[pu];
      res_tol[v] = max(toll_in[pu], get_toll(u, max_pos[pu]));
    }
  }
  for (int i = 0; i < q; i++) cout << res_enj[i] << ' ' << res_tol[i] << '\n';
}
