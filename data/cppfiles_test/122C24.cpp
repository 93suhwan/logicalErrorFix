#include <bits/stdc++.h>
using namespace std;
class TwoSat {
 private:
  int n;
  vector<vector<int>> rG, G, sccs;
  vector<int> ord, idx;
  vector<bool> vis, result;
  void dfs(int u) {
    vis[u] = true;
    for (int v : G[u])
      if (!vis[v]) dfs(v);
    ord.push_back(u);
  }
  void rdfs(int u) {
    vis[u] = false;
    idx[u] = sccs.size() - 1;
    sccs.back().push_back(u);
    for (int v : rG[u])
      if (vis[v]) rdfs(v);
  }

 public:
  void init(int n_) {
    n = n_;
    G.clear();
    G.resize(n);
    rG.clear();
    rG.resize(n);
    sccs.clear();
    ord.clear();
    idx.resize(n);
    result.resize(n);
  }
  void add_edge(int u, int v) {
    G[u].push_back(v);
    rG[v].push_back(u);
  }
  void orr(int x, int y) {
    if ((x ^ y) == 1) return;
    add_edge(x ^ 1, y);
    add_edge(y ^ 1, x);
  }
  bool solve() {
    vis.clear();
    vis.resize(n);
    for (int i = 0; i < n; ++i)
      if (not vis[i]) dfs(i);
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
      if (!vis[u]) continue;
      sccs.push_back(vector<int>());
      rdfs(u);
    }
    for (int i = 0; i < n; i += 2)
      if (idx[i] == idx[i + 1]) return false;
    vector<bool> c(sccs.size());
    for (size_t i = 0; i < sccs.size(); ++i) {
      for (size_t j = 0; j < sccs[i].size(); ++j) {
        result[sccs[i][j]] = c[i];
        c[idx[sccs[i][j] ^ 1]] = !c[i];
      }
    }
    return true;
  }
  bool get(int x) { return result[x]; }
  inline int get_id(int x) { return idx[x]; }
  inline int count() { return sccs.size(); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e(n - 1);
    for (auto &[u, v, k] : e) cin >> u >> v >> k;
    TwoSat sat2;
    sat2.init(n * 2);
    while (m--) {
      int a, b, p;
      cin >> a >> b >> p;
      --a, --b;
      if (p == 0) {
        sat2.orr(a * 2 + 1, b * 2);
        sat2.orr(a * 2, b * 2 + 1);
      } else {
        sat2.orr(a * 2, b * 2);
        sat2.orr(a * 2 + 1, b * 2 + 1);
      }
    }
    sat2.orr(1, 1);
    for (auto [a, b, k] : e) {
      if (k == -1) continue;
      --a, --b;
      int p = __builtin_popcount(k) & 1;
      if (p == 0) {
        sat2.orr(a * 2 + 1, b * 2);
        sat2.orr(a * 2, b * 2 + 1);
      } else {
        sat2.orr(a * 2, b * 2);
        sat2.orr(a * 2 + 1, b * 2 + 1);
      }
    }
    if (not sat2.solve()) {
      cout << "NO\n";
      continue;
    }
    vector<tuple<int, int, int>> ans;
    for (auto [u, v, k] : e) {
      --u, --v;
      int p = sat2.get(u * 2) ^ sat2.get(v * 2);
      if (k == -1) {
        ans.emplace_back(u + 1, v + 1, p);
      } else {
        ans.emplace_back(u + 1, v + 1, k);
      }
    }
    if (ans.size() != e.size()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto [u, v, k] : ans) cout << u << ' ' << v << ' ' << k << '\n';
  }
  return 0;
}
