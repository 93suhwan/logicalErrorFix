#include <bits/stdc++.h>
using namespace std;
struct Dsu {
  int n, m;
  vector<vector<pair<int, int>>> par;
  Dsu(int n_ = 0, int m_ = 0) : n(n_), m(m_) {
    par = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
  }
  bool valid(int x, int y) { return min(x, y) >= 0 && min(n - x, m - y) > 0; }
  pair<int, int> get(int u, int v) {
    auto [p, q] = par[u][v];
    if (p == u) {
      assert(valid(p, q));
      par[u][v] = {u + 1, v};
      return get(p, q);
    }
    if (!valid(p, q)) return {p, q};
    return par[u][v] = get(p, q);
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
      dsu.par[i][j] = {u, v};
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
