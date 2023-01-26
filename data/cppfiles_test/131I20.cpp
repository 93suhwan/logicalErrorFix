#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int up = 30 * n + 10;
  vector<vector<int>> g(up);
  map<int, int> mp;
  int cnt = 0;
  vector<int> ok(up, 0);
  vector<int> t(up, 0);
  auto add = [&](int x, int y) {
    if (!mp.count(x)) mp[x] = ++cnt;
    if (!mp.count(y)) mp[y] = ++cnt;
    g[mp[x]].push_back(mp[y]);
  };
  for (int i = 1; i <= n; i++) {
    if (!mp.count(a[i])) mp[a[i]] = ++cnt;
    t[mp[a[i]]] = i;
    while (a[i] > 0) {
      for (int j = 0;; j++)
        if ((1 << j) >= a[i]) {
          add((1 << j) - a[i], a[i]);
          a[i] = (1 << j) - a[i];
          break;
        }
    }
  }
  int x = -1, y = -1, m = 0;
  vector<int> mx_dep(up, 0);
  vector<int> id(up, 0);
  function<void(int, int)> dfs = [&](int u, int d) {
    if (ok[u] == 1) return;
    ok[u] = 1;
    mx_dep[u] = d;
    id[u] = t[u];
    int mx1 = -1, id1 = -1;
    int mx2 = -1, id2 = -1;
    for (auto v : g[u]) {
      if (ok[v] == 1) continue;
      dfs(v, d + 1);
      if (mx_dep[v] > mx_dep[u]) {
        mx_dep[u] = mx_dep[v];
        id[u] = id[v];
      }
      if (mx_dep[v] > mx1) {
        mx2 = mx1;
        id2 = id1;
        mx1 = mx_dep[v];
        id1 = id[v];
      } else if (mx_dep[v] > mx2) {
        mx2 = mx_dep[v];
        id2 = id[v];
      }
    }
    if (mx1 != -1 && mx2 == -1 && mx1 - d > m) {
      x = t[u];
      y = id1;
      m = mx1 - d;
    }
    if (mx1 != -1 && mx2 != -1 && mx1 + mx2 - d * 2 > m) {
      x = id1;
      y = id2;
      m = mx1 + mx2 - d * 2;
    }
  };
  dfs(mp[0], 1);
  cout << x << ' ' << y << ' ' << m << '\n';
  return 0;
}
