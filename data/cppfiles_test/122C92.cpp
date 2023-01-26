#include <bits/stdc++.h>
using namespace std;
int getv(int x) noexcept {
  int r = 0;
  for (int i = 0; i < 30; i++) {
    if (x & (1 << i)) r++;
  }
  return r % 2;
}
void solve() noexcept {
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
    if (v > 0) v = getv(v);
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
  const function<void(int, int)> f = [&](int nd, int tocol) noexcept {
    if (col[nd] != -1) {
      if (col[nd] != tocol) {
        res = false;
      }
      return;
    }
    col[nd] = tocol;
    for (const auto &[j, v] : adj[nd]) {
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
  if (!res) {
    cout << "NO\n";
    return;
  } else {
    cout << "YES\n";
    vector<bool> vis(n + 1);
    const function<void(int)> g = [&](int nd) noexcept {
      vis[nd] = true;
      for (const auto &[j, v] : treeadj[nd]) {
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
  cin.tie(0);
  istream::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}
