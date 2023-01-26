#include <bits/stdc++.h>
using namespace std;
struct union_find {
  vector<long long> par, sz;
  union_find(long long n) {
    par.resize(n + 1);
    sz.resize(n + 1);
    for (long long i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  long long find(long long node) {
    if (par[node] == node) {
      return node;
    }
    return par[node] = find(par[node]);
  }
  void unite(long long u, long long v) {
    long long a = find(u);
    long long b = find(v);
    if (a != b) {
      if (size(a) > size(b)) {
        par[b] = a;
        sz[a] += sz[b];
      } else {
        par[a] = b;
        sz[b] += sz[a];
      }
    }
  }
  long long size(long long node) { return sz[find(node)]; }
};
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  union_find uf1(n + 1), uf2(n + 1);
  vector<vector<long long>> g1(n + 1, vector<long long>(n + 1, 0));
  vector<vector<long long>> g2(n + 1, vector<long long>(n + 1, 0));
  for (long long i = 0; i < m1; i++) {
    long long u, v;
    cin >> u >> v;
    g1[u][v] = g1[v][u] = 1;
    uf1.unite(u, v);
  }
  for (long long i = 0; i < m2; i++) {
    long long u, v;
    cin >> u >> v;
    g2[u][v] = g2[v][u] = 1;
    uf2.unite(u, v);
  }
  vector<vector<long long>> ans;
  ans.clear();
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (g1[i][j] || g1[j][i] || g2[i][j] || g2[j][i] ||
          (uf1.find(i) == uf1.find(j)) || (uf2.find(i) == uf2.find(j))) {
        continue;
      }
      uf1.unite(i, j);
      uf2.unite(i, j);
      ans.push_back({i, j});
    }
  }
  cout << ans.size() << endl;
  for (auto p : ans) {
    cout << p[0] << " " << p[1] << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
