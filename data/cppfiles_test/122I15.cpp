#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  vector<vector<pair<int, int>>> treeadj(n + 1);
  vector<int> col(n + 1, -1);
  for (int i = 0; i < n - 1; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    treeadj[x].push_back({y, v});
    treeadj[y].push_back({x, v});
    if (v > 0) v = v % 2;
    adj[x].push_back({y, v});
    adj[y].push_back({x, v});
  }
  for (int i = 0; i < m; i++) {
    int a, b, p;
    cin >> a >> b >> p;
    adj[a].push_back({b, p});
    adj[b].push_back({a, p});
  }
  bool res = true;
  function<void(int, int)> f = [&](int nd, int tocol) {
    if (col[nd] != -1) {
      if (col[nd] != tocol) {
        res = false;
      }
      return;
    }
    col[nd] = tocol;
    for (auto [j, v] : adj[nd]) {
      if (v == 1) {
        f(j, !tocol);
      } else if (v == 0) {
        f(j, tocol);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1) f(i, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1) col[i] = 0;
  }
  if (!res) {
    cout << "NO\n";
    return;
  } else {
    cout << "YES\n";
    vector<bool> vis(n + 1);
    function<void(int)> g = [&](int nd) {
      vis[nd] = true;
      for (auto [j, v] : treeadj[nd]) {
        if (vis[j]) continue;
        cout << nd << " " << j << " " << (v == -1 ? col[nd] != col[j] : v)
             << endl;
        g(j);
      }
    };
    g(1);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
