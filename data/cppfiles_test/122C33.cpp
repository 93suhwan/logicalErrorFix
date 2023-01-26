#include <bits/stdc++.h>
using namespace std;
class Dsu {
 public:
  int n;
  vector<int> p;
  Dsu(int n) : n(n) {
    p = vector<int>(n);
    iota(p.begin(), p.end(), 0);
  }
  int find(int i) {
    if (i == p[i]) return i;
    return p[i] = find(p[i]);
  }
  void merge(int i, int j) {
    int x = find(i);
    int y = find(j);
    if (x == y) return;
    p[x] = y;
  }
};
struct Edge {
  int u, v, w;
};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> g(n - 1);
  Dsu dsu(2 * n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[i] = {u, v, w};
    if (w != -1) {
      int p = __builtin_popcount(w) & 1;
      if (p) {
        dsu.merge(u, v + n);
        dsu.merge(v, u + n);
      } else {
        dsu.merge(u, v);
        dsu.merge(u + n, v + n);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    u--;
    v--;
    if (x == 1) {
      dsu.merge(u, v + n);
      dsu.merge(v, u + n);
    } else {
      dsu.merge(u, v);
      dsu.merge(u + n, v + n);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ok &= (dsu.find(i) != dsu.find(i + n));
  }
  cout << (ok ? "YES" : "NO") << '\n';
  if (!ok) return;
  for (auto [u, v, w] : g) {
    if (w == -1) {
      if (dsu.find(u) == dsu.find(v)) {
        w = 0;
      } else if (dsu.find(u) == dsu.find(v + n)) {
        w = 1;
      } else {
        w = 0;
        dsu.merge(u, v);
        dsu.merge(u + n, v + n);
      }
    }
    cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
