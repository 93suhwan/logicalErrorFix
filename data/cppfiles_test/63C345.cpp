#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
const int inf = 1e9;
struct {
  int parent[mxn];
  int sz[mxn];
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
  int findrep(int u) {
    return parent[u] == u ? u : parent[u] = findrep(parent[u]);
  }
  void unite(int u, int v) {
    u = findrep(u);
    v = findrep(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    parent[u] = v;
    sz[v] += sz[u];
  }
} dsu1, dsu2;
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu1.init(n);
  dsu2.init(n);
  for (int i = 1; i <= m1; i++) {
    int u, v;
    cin >> u >> v;
    dsu1.unite(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    int u, v;
    cin >> u >> v;
    dsu2.unite(u, v);
  }
  vector<pair<int, int> > edg;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dsu1.findrep(i) != dsu1.findrep(j) &&
          dsu2.findrep(i) != dsu2.findrep(j)) {
        edg.push_back({i, j});
        dsu1.unite(i, j);
        dsu2.unite(i, j);
      }
    }
  }
  cout << edg.size() << endl;
  for (auto [u, v] : edg) {
    cout << u << " " << v << endl;
  }
}
