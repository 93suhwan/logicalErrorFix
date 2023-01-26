#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> x(n - 1);
    vector<int> y(n - 1);
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> x[i] >> y[i] >> v[i];
      --x[i];
      --y[i];
      if (v[i] != -1) {
        int c = (int)__builtin_popcount(v[i]);
        g[x[i]].emplace_back(y[i], c & 1);
        g[y[i]].emplace_back(x[i], c & 1);
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    bool flag = true;
    vector<int> color(n, -1);
    function<bool(int, int)> dye = [&](int u, int c) -> bool {
      if (color[u] != -1) {
        return color[u] == c;
      }
      color[u] = c;
      for (auto &[v, t] : g[u]) {
        if (!dye(v, c ^ t)) {
          return false;
        }
      }
      return true;
    };
    for (int i = 0; i < n; i++) {
      if (color[i] == -1 && !dye(i, 0)) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) {
      if (v[i] == -1) {
        if (color[x[i]] == color[y[i]]) {
          v[i] = 0;
        } else {
          v[i] = 1;
        }
      }
      cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << v[i] << '\n';
    }
  }
  return 0;
}
