#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<vector<int>> e(N, vector<int>());
struct LCA {
  vector<int> tin, tout;
  vector<int> depth;
  vector<vector<int>> lca;
  int time = 1;
  LCA(int n) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    depth.resize(n + 1);
    lca.resize(n + 1);
    int h = (int)log2(n);
    for (int i = 0; i <= n; i++) lca[i] = vector<int>(h + 1);
    dfs(1, 0);
  }
  void dfs(int u, int p) {
    tin[u] = time++;
    for (int v : e[u]) {
      if (v != p) {
        lca[v][0] = u;
        for (int lg = 1; lg < (int)lca[1].size(); lg++) {
          lca[v][lg] = lca[lca[v][lg - 1]][lg - 1];
        }
        depth[v] = depth[u] + 1;
        dfs(v, u);
      }
    }
    tout[u] = time++;
  }
  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int lg = 0; lg < (int)lca[1].size(); lg++) {
      if ((1 << lg) & (depth[v] - depth[u])) {
        v = lca[v][lg];
      }
    }
    assert(depth[u] == depth[v]);
    if (u == v) {
      return u;
    }
    for (int lg = (int)lca[1].size() - 1; lg >= 0; lg--) {
      if (lca[u][lg] != lca[v][lg]) {
        u = lca[u][lg];
        v = lca[v][lg];
      }
    }
    assert(lca[u][0] == lca[v][0]);
    return lca[u][0];
  }
};
struct fenwick {
  vector<int64_t> fen;
  fenwick(int n) { fen.resize(n); }
  void upd(int i, int val) {
    while (i < (int)fen.size()) {
      fen[i] += val;
      i += i & -i;
    }
  }
  int64_t get(int i) {
    int64_t r = 0;
    while (i > 0) {
      r += fen[i];
      i -= i & -i;
    }
    return r;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
    e[i].clear();
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  fenwick *fen = new fenwick(2 * n + 3);
  LCA *lca = new LCA(n);
  for (int i = 1; i <= n; i++) {
    fen->upd(lca->tin[i], a[i]);
    fen->upd(lca->tout[i] + 1, -a[i]);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, c;
      cin >> u >> c;
      c = abs(c);
      int inc = c - a[u];
      fen->upd(lca->tin[u], inc);
      fen->upd(lca->tout[u] + 1, -inc);
      a[u] = c;
    } else {
      int u, v;
      cin >> u >> v;
      int ancestor = lca->query(u, v);
      cout << 2LL * (fen->get(lca->tin[u]) + fen->get(lca->tin[v]) -
                     2 * fen->get(lca->tin[ancestor]) + a[ancestor]) -
                  a[u] - a[v]
           << "\n";
    }
  }
  return 0;
}
