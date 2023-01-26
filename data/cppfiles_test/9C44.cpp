#include <bits/stdc++.h>
using namespace std;
struct Dsu {
  int n, m;
  vector<vector<pair<int, int>>> par;
  Dsu(int n_ = 0, int m_ = 0) : n(n_), m(m_) {
    par.assign(n, vector<pair<int, int>>(m));
  }
  bool valid(int x, int y) { return min(x, y) >= 0 && min(n - x, m - y) > 0; }
  pair<int, int> pull(int u, int v, const int x) {
    auto [p, q] = par[u][v];
    if ((u == p && v == q) || q != x) return {u, v};
    return par[u][v] = pull(p, q, x);
  }
  pair<int, int> get(int u, int v) {
    auto [p, q] = par[u][v];
    assert(valid(u, v) && valid(p, q));
    if (u == p && v == q) return {u, v};
    if (u == p) {
      par[u][v] = valid(u + 1, v) ? make_pair(u + 1, v) : make_pair(u, v);
    } else {
      assert(v == q);
      pull(u, v, v);
    }
    return get(p, q);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  Dsu dsu(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x, u = i, v = j;
      cin >> x;
      if (x == 1) v++;
      if (x == 2) u++;
      if (x == 3) v--;
      dsu.par[i][j] = dsu.valid(u, v) ? make_pair(u, v) : make_pair(i, j);
    }
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    int k = dsu.get(0, --x).second;
    cout << k + 1 << ' ';
  }
  cout << '\n';
  return 0;
}
