#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
struct SparseTable {
  int n;
  vector<vector<T>> mn;
  vector<int> lg2;
  SparseTable(){};
  SparseTable(const vector<T>& a) {
    n = (int)(a).size();
    mn.push_back(a);
    for (int k = 1; (1 << k) <= n; ++k) {
      mn.push_back(vector<T>(n));
      for (int i = (1 << k) - 1; i < n; ++i) {
        mn[k][i] = min(mn[k - 1][i], mn[k - 1][i - (1 << (k - 1))]);
      }
    }
    lg2.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      lg2[i] = (31 - __builtin_clz(i));
    }
  }
  T get_min(int l, int r) {
    l = max(l, 0);
    r = min(r, n - 1);
    if (l > r) swap(l, r);
    int k = lg2[r - l + 1];
    return min(mn[k][r], mn[k][l + (1 << k) - 1]);
  }
};
struct LCA {
  vector<pair<int, int>> euler;
  vector<int> pos;
  vector<int> depth;
  vector<int> par;
  vector<int> tin, tout;
  SparseTable<pair<int, int>> RMQ;
  LCA() {}
  LCA(vector<vector<int>>& g, int n, int r = 0) {
    pos.resize(n);
    par.resize(n);
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    euler.clear();
    depth[r] = 0;
    int TIME = 0;
    dfs(g, r, -1, TIME);
    RMQ = SparseTable<pair<int, int>>(euler);
  }
  void dfs(vector<vector<int>>& g, int v, int p, int& TIME) {
    par[v] = p;
    tin[v] = TIME++;
    pos[v] = (int)(euler).size();
    euler.push_back({depth[v], v});
    for (int u : g[v]) {
      if (u != p) {
        depth[u] = depth[v] + 1;
        dfs(g, u, v, TIME);
        euler.push_back({depth[v], v});
      }
    }
    tout[v] = TIME++;
  }
  int get_lca(int u, int v) { return RMQ.get_min(pos[u], pos[v]).second; }
  bool is_parent(int p, int v) {
    return tin[p] <= tin[v] && tout[v] <= tout[p];
  }
};
const int MAGIC = 500;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> newa = a;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  LCA lca(g, n, 0);
  vector<vector<pair<int, int>>> G(n);
  vector<int> parent(n);
  function<void(int, int)> DFS = [&](int v, int p) {
    parent[v] = p;
    for (int u : g[v]) {
      if (u != p) {
        G[v].push_back({lca.tout[u], u});
        DFS(u, v);
      }
    }
  };
  DFS(0, -1);
  auto edge = [&](int u, int v) {
    return max(abs(a[u] + a[v]), abs(a[u] - a[v]));
  };
  auto newedge = [&](int u, int v) {
    return max(abs(newa[u] + newa[v]), abs(newa[u] - newa[v]));
  };
  vector<long long> sum(n, 0);
  auto REBUILD = [&]() {
    a = newa;
    sum[0] = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
      for (int u : g[v]) {
        if (u != p) {
          sum[u] = sum[v] + edge(v, u);
          dfs(u, v);
        }
      }
    };
    dfs(0, -1);
  };
  vector<int> changed;
  vector<int> is_changed(n, false);
  auto solve = [&](int v) {
    long long result = sum[v];
    for (int x : changed) {
      if (lca.is_parent(x, v)) {
        if (x != v) {
          int u = lower_bound((G[x]).begin(), (G[x]).end(),
                              pair<int, int>{lca.tout[v], v})
                      ->second;
          result -= edge(u, x);
          result += newedge(u, x);
        }
        if (x != 0) {
          int u = parent[x];
          if (!is_changed[u]) {
            result -= edge(u, x);
            result += newedge(u, x);
          }
        }
      }
    }
    return result;
  };
  REBUILD();
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, val;
      cin >> u >> val;
      --u;
      newa[u] = val;
      changed.push_back(u);
      is_changed[u] = true;
    } else {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      cout << solve(v) + solve(u) - 2 * solve(lca.get_lca(u, v)) << '\n';
    }
    if ((int)(changed).size() >= MAGIC) {
      for (int x : changed) {
        is_changed[x] = false;
      }
      changed.clear();
      REBUILD();
    }
  }
  return 0;
}
