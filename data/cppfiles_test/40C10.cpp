#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g, sg;
vector<bool> vis;
void dfs(int u) {
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      sg[u].push_back(v);
      sg[v].push_back(u);
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  sg.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vis.assign(n, 0);
  dfs(0);
  auto find_path = [&](int u, int v) {
    swap(u, v);
    queue<int> qu;
    vector<int> p(n, -1);
    vis.assign(n, 0);
    vis[u] = 1;
    qu.push(u);
    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      for (int y : sg[x]) {
        if (!vis[y]) {
          vis[y] = 1;
          qu.push(y);
          p[y] = x;
        }
      }
    }
    vector<int> ret;
    for (int x = v; x != u; x = p[x]) {
      ret.push_back(x);
    }
    ret.push_back(u);
    return ret;
  };
  int q;
  cin >> q;
  vector<pair<int, int>> queries(q);
  vector<int> deg(n, 0);
  vector<vector<int>> ans(q);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    deg[u]++;
    deg[v]++;
    queries[i] = {u, v};
    ans[i] = find_path(u, v);
  }
  int cnt_odd = 0;
  for (int u = 0; u < n; u++) cnt_odd += deg[u] % 2;
  if (cnt_odd) {
    cout << "NO\n" << cnt_odd / 2 << '\n';
  } else {
    cout << "YES\n";
    for (auto v : ans) {
      cout << v.size() << '\n';
      for (int x : v) cout << x + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}
